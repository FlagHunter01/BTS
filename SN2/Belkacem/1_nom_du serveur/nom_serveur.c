#include <stdlib.h>
#include <stdio.h>

int main()
{
	printf("Content-type: text/html\n\n");								  // Declaration du type de fichier
	printf("<html><header><title>Nom du serveur</title></header><body>"); // Debut du document HTML
	printf("<b>Nom du serveur</b> : %s", getenv("SERVER_NAME"));		  // Affichage de la variable
	printf("</body></html>");											  // Fin du document HTML
	return 0;
}
