#include <stdio.h> // methode GET
#include <stdlib.h>
#include <string.h>
int main()
{
  char Prenom[30];
  char *chaineRecue, *index;
  int i, lgChaine; //copie la taille du contenu de la variable d'environnement QUERY_STRING
  lgChaine = strlen(getenv("QUERY_STRING"));
  chaineRecue = (char *)malloc(lgChaine + 1);
  strcpy(chaineRecue, getenv("QUERY_STRING")); //copie le contenu de la variable d'environnement QUERY_STRING
  //Initialisation du navigateur Web
  puts("Content-type:text/html\n\n\
	     <html><head>\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\">\
         <title>CGI : methode GET</title></head><body>\
		 <font color=\"#0000FF\"><h3>Script CGI avec la methode GET</h3></font>\
		 Voici la chaine envoyee par votre navigateur :<br>");
  //Affiche la chaine recue
  printf("Chaine recue: %s, de longueur %d.", chaineRecue, lgChaine);
  index = strchr(chaineRecue, '=');
  index++; // cherche position caractere apres = ds chaineRecue
  for (i = 0; *index != '&'; i++)
  {
    Prenom[i] = *(index++);
  }
  printf("<BR>Bonjour %s, aimes-tu les CGI ?</b>", Prenom);
  printf("</body></html>");
  free(chaineRecue);
}
