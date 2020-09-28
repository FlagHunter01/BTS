/* TODO:
 - Penser a faire des boucles qui relancent plusieurs fois les fonctions qui ont échoué
 - Enregister l'ancienne configuration pour la restaurer à la fin du programme
 - Si cedrtaines configurations ont échoué, essayer de continuer en failproof le programme de management du feu
*/

#include <stdio.h>
#include <stdbool.h>   // bool
#include <termios.h>   // speed_t, tcflag_t ...
#include <unistd.h>    // access()
#include <sys/types.h> //open()
#include <sys/stat.h>  //open()
#include <fcntl.h>     //open()

bool SearchPort(char *file_path);                                                // Recherche le port et écrit son adresse dans file_path
int OpenPort(char *file_path);                                                   // Retourne le descripteur
bool Config(speed_t speed, tcflag_t size, tcflag_t parity, int file_descriptor); // Configure la connexion
bool ClosePort(int file_descriptor);                                             // Ferme le port

int main()
{
    printf("\n\t############### FEU 1 ###############\n\n\n");

    /* On sort les variables suceptibles d'être changées au début
    pour pouvoir les modifier facilement */
    // Chemin d'accès du port
    char file_path[] = "/dev/ttyUSBX";
    // 9 600 baud
    speed_t speed = B9600;
    // 8 bits
    tcflag_t size = CS8;
    // Ignorer la parité
    tcflag_t parity = IGNPAR;
    // La quantité de bits de stop est de 1 par défaut.
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
                printf("Fermeture du port ... \n");
                if (ClosePort(file_descriptor))
                {
                    printf("Port ferme.\n");
                }
                else
                {
                    printf("Port ferme avec erreurs.\n");
                }
                printf("Fin du programme.\n\n\n");
                return 0; // On arrête le programme
            }
            else
            { // Si la configuration a échoué
                printf("Echec de la configuration du port.\nFermeture du port ...\n");
                if (ClosePort(file_descriptor))
                {
                    printf("Port ferme.\n");
                }
                else
                {
                    printf("Port ferme avec erreurs.\n");
                }
                printf("Fin du programme.\n\n\n");
                return 0; // On arrête le programme
            }
        }
        else
        { // Si on n'a pas obtenu le descripteur
            printf("Echec lors de l'ouverture du port.\nFin du programme.\n\n\n");
            return 0;
        }
    }
    else
    { // Si le port n'a pas été trouvé
        printf("Port non trouve.\nFin du programme.\n\n\n");
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
    int file_descriptor;
    printf("\tOuverture du port ...\n");
    // On obtient le descripteur
    file_descriptor = open(file_path, O_RDWR);
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
    // Contient la configuration complète
    struct termios tty;
    printf("\tConfiguration de la connexion ...\n");
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

bool ClosePort(file_descriptor)
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
