#include <stdio.h>
#include <stdlib.h>

/* Celui-la c'est pour calculer le nombre de secondes entre le debut de la journee et l'heure indiquee. */

/* Cette fonction demande de rentrer [name] a l'utilisateur (heures, minutes ou secondes),
la lit et verifie qu'elle est positive et inferieure a [max] (23 ou 59). Si l'entree est bonne,
elle la retourne a la fonction principale. */

int EnterEntireNumber(char* name, int max)
{
  /* Variable utilisee en interne */
  int a;
  
  /* Message de demande */
  printf ("%s:", name);
  
  /* Lecture de la reponse */
  scanf ("%d", &a);
  
  /* Verification de la reponse et renouvellement de la question si besoin*/
  while (a < 0 || a > max) {
        printf ("Les %s doivent etre positives et inferieures à %d. Veuillez saisir a nouveau: \n", name, max);
        scanf ("%d", &a);
  }
  
  /* Retour de la reponse a la fonction principale */
  return a;
}

/* Fonction principale */
int main()
{
  /* Declaration des variables heures, minutes, secondes et temps */
  int h,m,s,t;

  /* Demande des variables au client avec la fonction EnterEntireNumber */
  h = EnterEntireNumber("Heures", 23);
  m = EnterEntireNumber("Minutes", 59);
  s = EnterEntireNumber("Secondes", 59);

  /* Operation de conversion */
  t = h*3600 + m*60 + s;

  /* Affichage du resultat */
  printf ("Cette heure correspond a %d secondes.", t);
  
  /* Fin du programme */
  system("PAUSE");	
  return 0;
}




