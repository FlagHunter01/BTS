#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char Prenom[30];                                                    // Va stoquer le prenomchar *chaineRecue;                           // Contiennent l'integralite de la chaine recue
    char *index;                                                        // Sert a se deplacer dans chaineRecue
    int i, lgChaine;                                                    //copie la taille du contenu de la variable d'environnement QUERY_STRING
    lgChaine = strlen(getenv("QUERY_STRING"));                          // On cherche QUERY_STRING, on en prend la taill eet on la stoque dans lgChaine
    char chaineRecue = (char *)malloc(lgChaine + 1);                    // On aloue de la memoire de la taille de QUERY_STRING + 1 pour le caractere de fin
    strcpy(chaineRecue, getenv("QUERY_STRING"));                        //copie le contenu de la variable d'environnement QUERY_STRING
    puts("Content-type:text/html\n\n\
<html><head>\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\">\
<title>CGI : methode GET</title></head><body>\
<font color=\"#0000FF\"><h3>Script CGI avec la methode GET</h3></font>\
Voici la chaine envoyee par votre navigateur :<br>");                   // Initialisation du navigateur Web
    printf("Chaine recue: %s, de longueur %d.", chaineRecue, lgChaine); // Affiche la chaine recue et de sa longueur
    index = strchr(chaineRecue, '=');                                   // On se deplace jusqu'au '=' dans chaineRecue
    index++;                                                            // On va au premier caractere apres le '='
    for (i = 0; *index != '&'; i++)
    {                                                                   // Tant qu'on n'a pas atteint le '&'
        Prenom[i] = *(index++);                                         // Stocker le caractere dans la cellule de Prenom correspondante
    }
    printf("<BR>Bonjour %s, aimes-tu les CGI ?</b>", Prenom);           // Affichage du string Prenom
    printf("</body></html>");                                           // Fin du document HTML
    free(chaineRecue);                                                  // Nettoyage de chaineRecue
    return 0;
}
