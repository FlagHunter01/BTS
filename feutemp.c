/* TODO:
 - Penser a faire des boucles qui relancent plusieurs fois les fonctions qui ont échoué
 - Enregister l'ancienne configuration pour la restaurer à la fin du programme
 - Si cedrtaines configurations ont échoué, essayer de continuer en failproof le programme de management du feu
 - bzero(&newConf, sizeof(newConf));

*/

#include <stdio.h> // perror()
#include <stdbool.h>   // bool
#include <termios.h>   // speed_t, tcflag_t ...
#include <unistd.h>    // access()
#include <sys/types.h> //open()
#include <sys/stat.h>  //open()
#include <fcntl.h>     //open()
#include <stdlib.h> // exit()

int OpenPort(char *file_path);                                                   // Retourne le descripteur
bool ConfigPort(int file_descriptor, struct termios *oldConf); // Configure la connexion
bool ClosePort(int file_descriptor, struct termios *oldConf); // Restore l'ancienne configuration et ferme de descripteur

int main()
{
    printf("\n\t########## FEU 1 ##########\n\n\n");

    /* On sort les variables suceptibles d'être changées au début
    pour pouvoir les modifier facilement */
    char file_path[] = "/dev/ttyUSBX\0";

    // Descripteur de fichiers
    int file_descriptor = OpenPort(file_path);

    // Ancienne configuration
    struct termios oldConf;

    if (file_descriptor > 0)
    {
        if (ConfigPort(file_descriptor, &oldConf)){
            if(ClosePort(file_descriptor, &oldConf)){
                exit(EXIT_SUCCESS);
            }
            exit(EXIT_FAILURE);
        }
        else{
            if(ClosePort(file_descriptor, &oldConf)){
                exit(EXIT_FAILURE);
            }
            exit(EXIT_FAILURE);
        }
        perror("\nCe code ne doit jamais s'exécuter.");
        exit(EXIT_FAILURE);
    }
    else
    { 
        exit(EXIT_FAILURE);
    }
    perror("\nCe code ne doit jamais s'exécuter.");
        exit(EXIT_FAILURE);
}

int OpenPort(char *file_path){
    // Compteur
    char i = '2';

    // Descripteur de fichiers
    int file_descriptor;

    printf("Ouverture du port ...\n");
    for (; i >= '0'; i--){
        //file_path[sizeof(file_path) - 2] = i; // Pk sizeof(file_path) ne prend pas la taille du pointeur ?!
        file_path[11] = i;
        file_descriptor = open((char *)&file_path, O_RDWR | O_NOCTTY );
        printf("FD = %d\n", file_descriptor);
        if (file_descriptor > 0){
            printf("\tOuverture réussie de %s .\n", file_path);
            return file_descriptor;
        }
        else{
            printf("\tEchec lors de l'ouverture de %s .\n", file_path);
        }
    }
    perror("\tAucun port n'a pu être ouvert.");
            return file_descriptor;
}

bool ConfigPort(int file_descriptor, struct termios *oldConf)
{
    printf("Configuration de la connexion ...\n");
    if (tcgetattr(file_descriptor, oldConf) == 0)
    {
        // Nouvelle configuration à soumettre
        struct termios newConf;

    /* 
    B9600: Set bps rate. You could also use cfsetispeed and cfsetospeed.
    CRTSCTS : output hardware flow control (only used if the cable has
	    all necessary lines. See sect. 7 of Serial-HOWTO)
    CS8     : 8n1 (8bit,no parity,1 stopbit)
    CLOCAL  : local connection, no modem contol
    CREAD   : enable receiving characters
    */
    newConf.c_cflag = B9600 | CRTSCTS | CS8 | CLOCAL | CREAD;
         
    /*
    IGNPAR  : ignore bytes with parity errors
    ICRNL   : map CR to NL (otherwise a CR input on the other computer
		will not terminate input)
		otherwise make device raw (no other input processing)
    */
    newConf.c_iflag = IGNPAR | ICRNL;
         
    /*
    Raw output.
    */
    newConf.c_oflag = 0;
         
    /*
    ICANON  : enable canonical input
	disable all echo functionality, and don't send signals to calling program
    */
    newConf.c_lflag = ICANON;
         
    /* 
    initialize all control characters 
    default values can be found in /usr/include/termios.h, and are given
    in the comments, but we don't need them here
    */
    newConf.c_cc[VINTR]    = 0;     /* Ctrl-c */ 
    newConf.c_cc[VQUIT]    = 0;     /* Ctrl-\ */
    newConf.c_cc[VERASE]   = 0;     /* del */
    newConf.c_cc[VKILL]    = 0;     /* @ */
    newConf.c_cc[VEOF]     = 4;     /* Ctrl-d */
    newConf.c_cc[VTIME]    = 0;     /* inter-character timer unused */
    newConf.c_cc[VMIN]     = 1;     /* blocking read until 1 character arrives */
    newConf.c_cc[VSWTC]    = 0;     /* '\0' */
    newConf.c_cc[VSTART]   = 0;     /* Ctrl-q */ 
    newConf.c_cc[VSTOP]    = 0;     /* Ctrl-s */
    newConf.c_cc[VSUSP]    = 0;     /* Ctrl-z */
    newConf.c_cc[VEOL]     = 0;     /* '\0' */
    newConf.c_cc[VREPRINT] = 0;     /* Ctrl-r */
    newConf.c_cc[VDISCARD] = 0;     /* Ctrl-u */
    newConf.c_cc[VWERASE]  = 0;     /* Ctrl-w */
    newConf.c_cc[VLNEXT]   = 0;     /* Ctrl-v */
    newConf.c_cc[VEOL2]    = 0;     /* '\0' */

        tcflush(file_descriptor, TCIFLUSH);

        if(tcsetattr(file_descriptor, TCSANOW, &newConf) == 0){
            printf("\tConfiguration réussie.\n");
            return true;
        }
        else{
            perror("\tEchec lors de la configuration du port.");
            return false;
        }
        perror("\tCe code ne doit jamais s'exécuter.");
        return false;
    }
    else
    {
        perror("\tEchec lors du téléchargement de l'ancienne configuration du port.");
        return false;
    }
    perror("\tCe code ne doit jamais s'exécuter.");
    return false;
}

bool ClosePort(int file_descriptor, struct termios *oldConf){
    printf("Fermeture du port ...\n");
    if (tcsetattr(file_descriptor,TCSANOW, oldConf) == 0){
        printf("\tRestauration de la configuration initiale réussie.\n");
        if (close(file_descriptor) == 0)
        {
            printf("\tFermeture du descripteur réussie.\n");
            return true;
        }
        else{
            perror("\tEchec lors de la fermeture du descripteur de fichiers.");
            return false;
        }
        perror("\tCe code ne doit jamais s'exécutrer.");
        return false;
    }
    else{
        perror("\tEchec lors de la restauration de l'ancienne configuration.");
        if (close(file_descriptor) == 0)
        {
            printf("\tFermeture du descripteur réussie.\n");
            return false;
        }
        else{
            perror("\tEchec lors de la fermeture du descripteur de fichiers.");
            return false;
    }
    }
}
