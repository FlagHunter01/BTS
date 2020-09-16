#include <stdio.h> // methode POST
#include <stdlib.h>
#include <string.h>

int main()
{
    char Prenom[30];
    char *chaineRecue, *index;
    int i, lgChaine;
    lgChaine = atoi(getenv("CONTENT_LENGTH"));  // recupere le nombre de caracteres envoyes par le navigateur
    chaineRecue = (char *)malloc(lgChaine + 1); //determine la taille du tableau chaine recu
    scanf("%s", chaineRecue);                  // lecture des caracteres envoyes par le navigateur
    //strcpy(chaineRecue, getenv("QUERY_STRING")); // lecture des caracteres envoyes par le navigateur
    printf("Content-type:text/html\n\n"); //Initialisation du navigateur Web
    printf("<html><head>\n<meta http-equiv=\"Content-Type\"content=\"text/html; charset=iso-8859-1\">\
            <title>CGI : methode POST</title></head><body>");
    printf("Chaine reeue <b>%s</b> de %d caracteres", chaineRecue, lgChaine);
    index = chaineRecue;
    index = strchr(chaineRecue, '=');
    index++;
    for (i = 0; *index != '&'; i++)
    {
        Prenom[i] = *(index++);
    }
    printf("<br>Bonjour %s, aimes-tu les CGI ?", Prenom);
    printf("<br>Exemple du professeur O. BELKACEM</body></html>");
    free(chaineRecue);
}
