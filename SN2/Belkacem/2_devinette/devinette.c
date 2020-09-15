#include <stdio.h>
#include <stdlib.h>
main()
{
    int c;
    printf("Content-type: text/html\n\n");
    printf("<HTML><HEAD><TITLE>Resultat</TITLE></HEAD>\n");
    printf("<BODY BGCOLOR=\"#FFFFFF\">\n");
    printf("<H1>Resultat du traitement du formulaire</H1>\n");
    printf("<H2>Chaine de donnees recue par le CGI</H2>");
    if (strcmp(getenv("REQUEST_METHOD"), "POST") == 0)
    {
        printf("STDIN (Methode POST) <B>");
        while ((c = getchar()) != EOF)
            printf("%c", c);
        printf("</B>");
    }
    if (strcmp(getenv("REQUEST_METHOD"), "GET") == 0)
    {
        printf("QUERY_STRING (Methode GET) <B>%s</B>", getenv("QUERY_STRING"));
    }
    printf("</BODY></HTML>\n");
}
