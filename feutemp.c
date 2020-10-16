/* TODO:
 - Penser a faire des boucles qui relancent plusieurs fois les fonctions qui ont échoué
 - Enregister l'ancienne configuration pour la restaurer à la fin du programme
 - Si cedrtaines configurations ont échoué, essayer de continuer en failproof le programme de management du feu
*/

// open("...", O_RDWR | O_NOCTTY)
// file_path[sizeof(file_path)] -2 = '3'-n

#include <stdio.h> // perror()
#include <stdbool.h>   // bool
#include <termios.h>   // speed_t, tcflag_t ...
#include <unistd.h>    // access()
#include <sys/types.h> //open()
#include <sys/stat.h>  //open()
#include <fcntl.h>     //open()

int OpenPort(char *file_path);                                                   // Retourne le descripteur
bool ConfigPort(int file_descriptor, struct termios *oldConf); // Configure la connexion
bool ClosePort(int file_descriptor, struct termios oldConf); // Restore l'ancienne configuration et ferme de descripteur

int main()
{
    printf("\n\t########## FEU 1 ##########\n\n\n");

    /* On sort les variables suceptibles d'être changées au début
    pour pouvoir les modifier facilement */
    char file_path[] = "/dev/ttyUSBX";

    // Descripteur de fichiers
    int file_descriptor = OpenPort(file_path)

    // Ancienne configuration
    struct termios oldConf;

    if (file_descriptor)
    {
        if (ConfigPort(int file_descriptor, struct termios *oldConf)){
            if(ClosePort(file_descriptor, termios oldConf)
                exit(EXIT_SUCCESS);
            }
            exit(EXIT_FAILURE);
        }
        else{
            if(ClosePort(file_descriptor, termios oldConf)
                exit(EXIT_FAILURE);
            }
            exit(EXIT_FAILURE);
        }
    }
    else
    { 
        exit(EXIT_FAILURE);
    }
}

int OpenPort(char *file_path){
    // Compteur
    char i = '2';

    // Descripteur de fichiers
    int file_descriptor;

    printf("Ouverture du port ...\n")
    for (, i >= '0', i--){
        file_path[sizeof(file_path) - 2] = i; // Pk sizeof(file_path) ne prend pas la taille du pointeur ?!
        file_descriptor = open((char *)&nomport, O_RDWR | O_NOCTTY );
        if (file_descriptor){
            printf("\tOuverture réussie.\n")
            return file_descriptor;
        }
        else{
            perror("\tEchec lors de l'ouverture du port.\n\n");
            return file_descriptor;
        }
    }
}

bool ConfigPort(int file_descriptor, struct termios *oldConf)
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

bool ClosePort(int file_descriptor, struct termios oldConf){}
