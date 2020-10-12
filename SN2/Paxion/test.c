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
#include <unistd.h>	   // access()
#include <sys/types.h> //open()
#include <sys/stat.h>  //open()
#include <fcntl.h>	   //open()

bool OpenPort();
void ConfigPort();
bool ClosePort();

int main()
{
	printf("\n\t########## FEU 1 ##########\n\n\n");

	char file_path[] = "/dev/ttyUSBX";

	if (OpenPort())
	{
		ConfigPort();
		if (ClosePort())
		{
			return EXIT_SUCCESS;
		}
		else
		{
			return EXIT_FAILURE;
		}
	}
	return EXIT_FAILURE;
}
