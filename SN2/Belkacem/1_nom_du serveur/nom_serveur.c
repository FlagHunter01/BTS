// Programme CGI permettant d'afficher le nom du serveur web sur lequel il est execute
#include <stdlib.h>
#include <stdio.h>
int main()
{
	// Indication du type de fichier retourne
	printf("Content-type: text/html\n\n");
	// Affichage du resultat
	printf("<html><header><title>Nom du serveur</title></header><body>");
	printf("<b>Nom du serveur</b> : %s </body></html>", getenv("SERVER_NAME"));
	return 0;
}
