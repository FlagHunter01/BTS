/* TODO:
 - Penser a faire des boucles qui relancent plusieurs fois les fonctions qui ont échoué
 - Enregister l'ancienne configuration pour la restaurer à la fin du programme
 - Si cedrtaines configurations ont échoué, essayer de continuer en failproof le programme de management du feu
*/

#include <stdio.h>
#include <stdbool.h>   // bool
#include <termios.h>   // speed_t, tcflag_t ...
#include <unistd.h>    // access(), write(), usleep()
#include <sys/types.h> //open()
#include <sys/stat.h>  //open()
#include <fcntl.h>     //open()

// CONNECT - Connexion au port
int Connect(char *file_path, speed_t speed, tcflag_t size, tcflag_t parity);
bool SearchPort(char *file_path);                                                // Recherche le port et écrit son adresse dans file_path
int OpenPort(char *file_path);                                                   // Retourne le descripteur
bool Config(speed_t speed, tcflag_t size, tcflag_t parity, int file_descriptor); // Configure la connexion
// DISCONNECT - Déconnexion du port
bool Disconnect(int file_descriptor);
// VERIFY CONNECTION - Vérifie la connection et tente de se reconnecter si elle est perdue
bool VerifyConnection(int *file_descriptor, char *file_path, speed_t speed, tcflag_t size, tcflag_t parity);
// SWITCHOFF - Extinction du feu
bool SwitchOff(int file_descriptor);

int main()
{
    printf("\n############### FEU 2 ###############\n\n");

    /* On sort les variables suceptibles d'être changées au début
    pour pouvoir les modifier facilement */
    char file_path[] = "/dev/ttyUSBX";
    speed_t speed = B9600;    // 9 600 baud
    tcflag_t size = CS8;      // 8 bits
    tcflag_t parity = IGNPAR; // Ignorer la parité
    // La quantité de bits de stop est de 1 par défaut.
    int file_descriptor = Connect(file_path, speed, size, parity); // On obtient le descripteur de fichiers
    if (file_descriptor != -1)
    { // Si le descripteur ne contient pas d'erreur
        printf("\n### EXTINCTION DU FEU ###\n\n");
        if (SwitchOff(file_descriptor))
        { // Si on réussit à éteindre le feu
            if (!VerifyConnection(&file_descriptor, file_path, speed, size, parity))
            { // Si la connection est perdue définitivement
                printf("Connection perdue!\n");
            }
            printf("Le feu s'est eteint correctement.\n\n");
            printf("### DECONNECTION ###\n\n");
            if (Disconnect(file_descriptor))
            {
                printf("\tDeconnection reussie\n\n");
            }
            else
            {
                printf("\tEchec lors de la deconnection.\n\n");
            }
            return 0;
        }
        else
        { // Si on ne réussit pas à etteindre le feu
            printf("Le feu ne s'est pas eteint correctement.\n\n");
            return 0;
        }
    }
    else
    { // Si le descripteur obtenu contient une erreur
        printf("Echec lors de la connexion. Fin du programme.\n\n\n");
        return 0;
    }
}

bool SearchPort(char *file_path)
{
    char i = '2'; // Compteur
    for (; i >= '0'; i--)
    { // On remplace le X dans '/dev/ttyUSBX' par i allant de '2' à '0'
        file_path[11] = i;
        printf("\tRecherche du port %s ...\n", file_path);
        if ((access(file_path, F_OK)) == 0)
        { // Si le fichier existe
            printf("\t\t%s trouve.\n", file_path);
            if ((access(file_path, R_OK)) == 0)
            { // Si on a les droits de lecture
                printf("\n\tDroits de lecture accordes\n");
                if ((access(file_path, W_OK)) == 0)
                { // Si on a les droits d'écriture
                    printf("\t\tDroits d'ecriture acordes\n");
                    return true; // On a trouvé un port viable
                }
                else
                { // Si on n'a pas les droits d'écriture
                    printf("\t\tDroits d'ecriture refuses\n");
                }
            }
            else
            { // Si on n'a pas les droits de lecture
                printf("\t\tDroits de lecture refuses\n");
            }
        }
        else
        { // Si le fichier n'existe pas
            printf("\t\tImpossible d'acceder a %s\n", file_path);
        }
    }
    printf("\tAucun port corrspondant trouve.\n");
    return false; // Aucun port trouvé entre USB2 et USB0
}

int OpenPort(char *file_path)
{
    printf("\tOuverture du port ...\n");
    int file_descriptor = open(file_path, O_RDWR); // On obtient le descripteur
    if (file_descriptor >= 0)
    { // S'il n'y a pas de code d'erreur
        printf("\tOuverture reussie.\n");
    }
    else
    { // S'il y a un code d'erreur
        printf("\tEchec lors de l'ouverture.\n");
    }
    return file_descriptor;
}

bool Config(speed_t speed, tcflag_t size, tcflag_t parity, int file_descriptor)
{
    printf("\tConfiguration de la connexion ...\n");
    struct termios tty; // Contient la configuration complète
    if (tcgetattr(file_descriptor, &tty) != 0)
    { // Si on ne peut pas obtenir la configuration actuelle
        printf("\tEchec du telechargement de la configuration\n");
        return false; // La configuration a échoué
    }
    if ((cfsetospeed(&tty, speed)) != 0)
    { // Si la vitesse ne correspond pas au standard termios (failproofing)
        printf("\tEchec du parametrage de la vitesse\n");
        return false; // La configuration a échoué
    }
    tty.c_cflag = size;   // On remplace la valeur de la taille
    tty.c_iflag = parity; // On remplace la valeur de la parité
    if ((tcsetattr(file_descriptor, TCSANOW, &tty)) == 0)
    { // Si pas d'erreur lors de la soumission de la nouvelle configuration
        printf("\tParametrage du port effectue\n");
        return true; // Parametrage réussi
    }
    else
    { // S'il y a un code d'erreur
        printf("\tEchec du parametrage du port\n");
        return false; // Parametrage échoué
    }
    printf("\tErreur inconnue\n");
    return false; // Si on n'est entré dans aucun des if
}

int Connect(char *file_path, speed_t speed, tcflag_t size, tcflag_t parity)
{
    printf("\n### CONNECTION AU PORT ###\n\n");
    printf("Recherche du port correspondant ...\n");
    if (SearchPort(file_path))
    { // Si le port a été trouvé
        printf("Ouverture du port ...\n");
        int file_descriptor = OpenPort(file_path); // On ouvre un descripteur
        if (file_descriptor != -1)
        { // Si on a obtenu le descripteur
            printf("Configuration du port ...\n");
            if (Config(speed, size, parity, file_descriptor))
            { // Si la configuration a réussi
                printf("Port ouvert avec succes.\n");
                return file_descriptor;
            }
            else
            { // Si la configuration a échoué
                printf("Echec de la configuration du port.\nFermeture du port ...\n");
                if (Disconnect(file_descriptor))
                { // Si on arrive à fermer normalement
                    printf("Port ferme.\n");
                    return -1;
                }
                else
                {                           // Si on n'arrive pas à fermer
                    close(file_descriptor); // On ferme brusquement
                    printf("Port ferme avec erreurs.\n");
                    return -1;
                }
                printf("Erreur inconnue.\n");
                return -1; // On arrête le programme
            }
        }
        else
        { // Si on n'a pas obtenu le descripteur
            printf("Echec lors de l'ouverture du port.\n");
            return -1;
        }
    }
    else
    { // Si le port n'a pas été trouvé
        printf("Port non trouve.\n");
        return -1;
    }
}

bool Disconnect(int file_descriptor)
{
    printf("\tFermeture du port ...\n");
    struct termios tty; // Contient la configuration complète
    if (tcgetattr(file_descriptor, &tty) != 0)
    { // Si on ne peut pas obtenir la configuration actuelle
        printf("\tEchec du telechargement de la configuration\n");
        close(file_descriptor); // Fermeture du port
        return false;           // La configuration a échoué
    }
    if ((cfsetospeed(&tty, B0)) != 0)
    { // Si la vitesse ne correspond pas au standard termios (failproofing)
        printf("\tEchec du parametrage de la vitesse\n");
        close(file_descriptor); // Fermeture du port
        return false;           // La configuration a échoué
    }
    if ((tcsetattr(file_descriptor, TCSANOW, &tty)) == 0)
    { // Si pas d'erreur lors de la soumission de la nouvelle configuration
        printf("\tNotification de fermeture envoyee\n");
        close(file_descriptor); // Fermeture du port
        return true;
    }
    else
    {
        printf("\tEchec de la notification de fermeture");
        close(file_descriptor); // Fermeture du port
        return false;
    }
    printf("\tErreur inconnue\n");
    close(file_descriptor); // Fermeture du port
    return false;
}

bool VerifyConnection(int *file_descriptor, char *file_path, speed_t speed, tcflag_t size, tcflag_t parity)
{
    if (isatty(*file_descriptor))
    {                // Si le descripteur est associé à un port ouvert
        return true; // Tout va bien
    }
    else
    { // Si le descripteur n'est pas associé à un port ouvert
        printf("La connection a ete interrompue.\n");
        int i = 0;
        int new_file_descriptor;
        for (i = 0; i < 2; i++)
        {
            printf("\tTentative de reconnection.\n\n");                    // On attend 5 secondes
            new_file_descriptor = Connect(file_path, speed, size, parity); // On réouvre on nouveau descripteur
            if (new_file_descriptor >= 0)
            {                                           // Si le descripteur ne contient pas d'erreur
                *file_descriptor = new_file_descriptor; // On définit le nouveau descripteur comme descripteur pour toutes les fonctions
                printf("\tConnection retablie\n");
                return true; // Tout va bien
            }
            else // Si on n'arrive pas a ouvrir un nouveau descripteur
            {
                printf("\tConncection non retablie.\n\tNouvel essai dans 0,5 secondes.\n");
                usleep(500000);
                i++;
            }
        }
    }
    printf("\tErreur inconnue.\n");
    return false; // Si le descripteur n'est ni fonctionnel ni endommagé
}

bool SwitchOff(int file_descriptor)
{
    printf("\tExtinction du feu ...\n");
    char command[] = "a0\n\0"; // String qui éteint tout le feu
    if (write(file_descriptor, &command, sizeof(command)))
    { // Si on arrive à envoyer la commande
        printf("\tExtinction reussie.\n\n");
        return true;
    }
    else
    { // Si on n'arrive pas à envoyer la commande
        printf("\tEchec lors de l'extinction\n\n");
        return false;
    }
    printf("\tProbleme inconnu.\n");
    return false; // Si on ne réussit pas et on n'échoue pas non plus
}
