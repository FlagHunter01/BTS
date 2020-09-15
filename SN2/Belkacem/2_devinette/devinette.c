#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    printf("Content-type: text/html\n\n");                  // Declaration du type de document
    printf("<HTML><HEAD><TITLE>Resultat</TITLE></HEAD>\n"); // Debut du document HTML
    printf("<BODY BGCOLOR=\"#FFFFFF\">\n");                 // Declaration du body avec couleur de fond
    printf("<H1>Resultat du traitement du formulaire</H1>\n");
    printf("<H2>Chaine de donnees recue par le CGI</H2>");
    if (strcmp(getenv("REQUEST_METHOD"), "POST") == 0)
    {                                                       // Si la variable REQUEST_METHOD est identique a "POST"
        printf("STDIN (Methode POST) <B>");                 // Indiquer que c'est la methode POST
        while ((c = getchar()) != EOF)
        {                                                   // Tant qu'on n'a pas atteint le EOF
            printf("%c", c);                                // Afficher les caracteres
        }
        printf("</B>");
    }
    if (strcmp(getenv("REQUEST_METHOD"), "GET") == 0)
    {                                                       // Si la vaiable REQUEST_METHOD est identique a "GET"
        printf("QUERY_STRING (Methode GET) <B>%s</B>", getenv("QUERY_STRING")); // Afficher la variable d'envi QUERY_STRING
    }
    printf("</BODY></HTML>\n");                             // Fin du document HTML
    return 0;
}



