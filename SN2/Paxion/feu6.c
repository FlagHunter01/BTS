/* 
TODO:
 - Penser a faire des boucles qui relancent plusieurs fois les fonctions qui ont échoué
 - Enregister l'ancienne configuration pour la restaurer à la fin du programme
 - Si cedrtaines configurations ont échoué, essayer de continuer en failproof le programme de management du feu
 - bzero(&newConf, sizeof(newConf));

*/

#include <stdio.h>     // perror()
#include <stdbool.h>   // bool
#include <termios.h>   // speed_t, tcflag_t ...
#include <unistd.h>    // access()
#include <sys/types.h> // open()
#include <sys/stat.h>  // open()
#include <fcntl.h>     // open()
#include <stdlib.h>    // exit()
#include <string.h> // strcmp(), strcpy()

int OpenPort(char *file_path);                                 // Retourne le descripteur
bool ConfigPort(int file_descriptor, struct termios *oldConf); // Configure la connexion
bool ClosePort(int file_descriptor, struct termios *oldConf);  // Restore l'ancienne configuration et ferme de descripteur
void Command(int file_descriptor); // Communique les commandes au feu
void Send(int file_descriptor, char *command, char *answer); // Sert a envoyer / verifier reception des commandes

int main()
{
    printf("\n\t########## FEU 6 ##########\n\n\n");

    /* On sort les variables suceptibles d'être changées au début
    pour pouvoir les modifier facilement */
    char file_path[] = "/dev/ttyUSBX\0";

    // Descripteur de fichiers
    int file_descriptor = OpenPort(file_path);

    // Ancienne configuration
    struct termios oldConf;

    if (file_descriptor > 0)
    {
        if (ConfigPort(file_descriptor, &oldConf))
        {
            Command(file_descriptor);
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
    for (; i >= '0'; i--)
    {
        //file_path[sizeof(file_path) - 2] = i; // Pk sizeof(file_path) ne prend pas la taille du pointeur ?!
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

    // On efface et on active les parametres

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
        return false;
        printf("\n\n");
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

void Command(int file_descriptor){
    char command[5];
    char needed_answer[8];
    
    int intensity;
    char intensity_str[3];
    int i;
    for (i = 0; i < 26; i++){
        strcpy(command, "a");
    strcpy(needed_answer, "tout");
        intensity = 5 + 10*i;
        sprintf(intensity_str, "%d", intensity);
        strcat(command, intensity_str);
        strcat(command, "\n");
        strcat(needed_answer, intensity_str);
        strcat(needed_answer, "\n");
        Send(file_descriptor, command, needed_answer);
        usleep(100000);
    }
    for (i = 0; i < 26; i++){strcpy(command, "a");
    strcpy(needed_answer, "tout");
        intensity = 255 - 10*i;
        sprintf(intensity_str, "%d", intensity);
        strcat(command, intensity_str);
        strcat(command, "\n");
        strcat(needed_answer, intensity_str);
        strcat(needed_answer, "\n");
        Send(file_descriptor, command, needed_answer);
        usleep(100000);
    }
    strcpy(command, "a0\n");
    strcpy(needed_answer, "tout0\n");
    Send(file_descriptor, command, needed_answer);
}

void Send(int file_descriptor, char *command, char *answer){
    char buf_answer[24];
    int dif = -1;
    int i = 3;
    int n;

    // Tantr que buf_answer et needed_answer ne correspondent pas & 3 fois maximum
    while (dif && i>0){
        for (n=0;n<24;n++) buf_answer[n]=0; // On efface le buf
        printf("Envoi commande %s...\n", command);
        write(file_descriptor, command, sizeof(command));
        usleep(100000);
        read(file_descriptor, &buf_answer, sizeof(buf_answer));
        dif = strcmp(buf_answer,answer);
        printf("\tDifference: %d | Reponse: %s/n", dif, buf_answer);
   i-=1;
    }
    if (dif){
        printf("\nLe feu ne repond pas convenablement.\n");
    }
}
