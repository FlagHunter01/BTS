#include <stdio.h>     // perror()
#include <stdbool.h>   // bool
#include <termios.h>   // speed_t, tcflag_t ...
#include <unistd.h>    // access()
#include <sys/types.h> // open()
#include <sys/stat.h>  // open()
#include <fcntl.h>     // open()
#include <stdlib.h>    // exit()
#include <strings.h>   // bzero()

int OpenPort(char *file_path);                                 // Retourne le descripteur
bool ConfigPort(int file_descriptor, struct termios *oldConf); // Télécharge l'ancienne configuration et configure la connexion
bool ClosePort(int file_descriptor, struct termios *oldConf);  // Restore l'ancienne configuration et ferme de descripteur

int main()
{
    printf("\n\t########## FEU 1 ##########\n\n\n");

    /* On sort les variables suceptibles d'être changées au début
    pour pouvoir les modifier facilement */

    // Emplacement du port
    char file_path[] = "/dev/ttyUSBX\0";

    // Descripteur de fichiers
    int file_descriptor = OpenPort(file_path);

    // Ancienne configuration
    struct termios oldConf;
    bzero(&oldConf, sizeof(oldConf));

    if (file_descriptor > 0)
    {
        if (ConfigPort(file_descriptor, &oldConf))
        {
            if (ClosePort(file_descriptor, &oldConf))
            {
                exit(EXIT_SUCCESS);
            }
            exit(EXIT_FAILURE);
        }
        else
        {
            if (ClosePort(file_descriptor, &oldConf))
            {
                exit(EXIT_FAILURE);
            }
            exit(EXIT_FAILURE);
        }
        perror("\nCe message ne doit jamais s'afficher.");
        exit(EXIT_FAILURE);
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    perror("\nCe message ne doit jamais s'afficher.");
    exit(EXIT_FAILURE);
}

int OpenPort(char *file_path)
{
    // Compteur
    char i = '2';

    // Descripteur de fichiers
    int file_descriptor;

    printf("Ouverture du port ...\n");
    /*
    On essaie d'ouvrir tous les ports entre USB3 et USB0.
    On passe au suivant si on échoue, peu importe la raison.
    */
    for (; i >= '0'; i--)
    {
        // /dev/ttyUSBX
        file_path[11] = i;
        // Ouverture en lecture + ecriture. O_NOCTTY a comprendre.
        file_descriptor = open(file_path, O_RDWR | O_NOCTTY);
        if (file_descriptor > 0)
        {
            printf("\tOuverture réussie de %s.\n\n", file_path);
            return file_descriptor;
        }
        else
        {
            printf("\tEchec lors de l'ouverture de %s.\n\n", file_path);
        }
    }
    perror("\tAucun port n'a pu être ouvert.");
    printf("\n\n");
    return file_descriptor;
}

bool ConfigPort(int file_descriptor, struct termios *oldConf)
{
    printf("Configuration de la connexion ...\n");
    if (tcgetattr(file_descriptor, oldConf) == 0)
    {
        // Nouvelle configuration à soumettre
        struct termios newConf;
        newConf.c_cflag = B9600 | CSTOPB | CS8 | CLOCAL | CREAD;
        newConf.c_iflag = IGNBRK;
        newConf.c_oflag = 0;
        newConf.c_lflag = 0;

        tcflush(file_descriptor, TCIFLUSH);
        if (tcsetattr(file_descriptor, TCSANOW, &newConf) == 0)
        {
            printf("\tConfiguration réussie.\n\n");
            return true;
        }
        else
        {
            perror("\tEchec lors de la configuration du port.");
            return false;
            printf("\n\n");
        }
        perror("\tCe message ne doit jamais s'afficher.");
        return false;
    }
    else
    {
        perror("\tEchec lors du téléchargement de l'ancienne configuration du port.");
        printf("\n\n");
        return false;
    }
    perror("\tCe message ne doit jamais s'afficher.");
    return false;
}

bool ClosePort(int file_descriptor, struct termios *oldConf)
{
    printf("Fermeture du port ...\n");
    if (tcsetattr(file_descriptor, TCSANOW, oldConf) == 0)
    {
        printf("\tRestauration de la configuration initiale réussie.\n");
        if (close(file_descriptor) == 0)
        {
            printf("\tFermeture du descripteur réussie.\n\n");
            return true;
        }
        else
        {
            perror("\tEchec lors de la fermeture du descripteur de fichiers.");
            return false;
            printf("\n\n");
        }
        perror("\tCe code ne doit jamais s'exécutrer.");
        return false;
    }
    else
    {
        perror("\tEchec lors de la restauration de l'ancienne configuration.");
        printf("\n\n");
        if (close(file_descriptor) == 0)
        {
            printf("\tFermeture du descripteur réussie.\n\n");
            return false;
        }
        else
        {
            perror("\tEchec lors de la fermeture du descripteur de fichiers.");
            return false;
            printf("\n\n");
        }
    }
}
