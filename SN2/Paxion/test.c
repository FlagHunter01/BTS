/* TODO:
 - Penser a faire des boucles qui relancent plusieurs fois les fonctions qui ont échoué
 - Enregister l'ancienne configuration pour la restaurer à la fin du programme
 - Si cedrtaines configurations ont échoué, essayer de continuer en failproof le programme de management du feu

 CONFIG:
 	// control mode flags
	newtio.c_cflag = BAUDRATE | CSTOPB | CREAD | CS8 | CLOCAL;
	// input mode flags
	newtio.c_iflag = IGNBRK;
	// output mode flags
	newtio.c_oflag = 0;
	// local mode flags
	newtio.c_lflag = 0;
	// flush all data
	if(tcflush(serfd, TCIOFLUSH)
*/

/*
 - Ouvrir port
 - Configurer Port
 - Fermer port
 */

#include <stdio.h>
#include <stdbool.h>   // bool
#include <termios.h>   // speed_t, tcflag_t ...
#include <unistd.h>    // access()
#include <sys/types.h> //open()
#include <sys/stat.h>  //open()
#include <fcntl.h>     //open()

bool OpenPort();
bool ConfigPort();
bool ClosePort();

int main()
{
    printf("\n\t########## FEU 1 ##########\n\n\n");

    char file_path[] = "/dev/ttyUSBX";
    printf("Ouverture\n");
    int file_descriptor = open(file_path, O_RDWR); // On ouvre un descripteur
    printf("file descriptor = %d\n", file_descriptor);
    if (file_descriptor)
    { // Si on a obtenu le descripteur
        if (close(file_descriptor) == 0)
        {
            printf("Port ferme correctement.\n");
        }
        else
        {
            printf("Port mal ferme.\n");
        }
    }
    else
    { // Si on n'a pas obtenu le descripteur
        printf("Echec lors de l'ouverture du port.\nFin du programme.\n\n\n");
        return 0;
    }
    return 0;
}
