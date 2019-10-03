#include <stdio.h>
#include <stdlib.h>

/* Fonction "winner" qui définit le vainqueur en fonction du dernier joueur a avoir
fait le tour et au nombre d'allumettes restantes. */
int winner (int a, int j)
{
       /* Par défaut personne n'a gagné */
       int win = 0;
       
       /* Si il reste plus de 4 allumettes, on ne cherche pas a savoir
       si quelqu'un gagne. */
       if (a>4)
       {
              /* La fonction retourne donc win, qui est égal à 0 bar défaut. */
               return win;
       }
       
       /* Si'l reste 4 allumettes ou moins, on peut déterminer le winner.
       En effet, le joeur suivant va tirer les allumettes de telle sorte qu'il
       n'en reste qu'une. C'est donc le joueur actuel qui perd et l'autre
       joueur qui gagne. */
       else
       {
            /* Si le joueur actuel est le n°1, alors le winner est n°2. */
            if (j == 1)
            {
                  return 2;
            }
              
            /* Si le joueur actuel est le n°2, alors le winner est ne n°1. */
            if (j == 2)
            {
                  return 1;
            }
       }
}


int main()
{
    printf("### JEU DES ALLUMETTES ###\n\n Il faut deux joueurs.\n\n### REGLES ###\n\n - Il y a 20 allumettes au depart.\n - Chaque joueur prend tour à tour entre 1 et 3 allumettes.\n - Le joueur qui prend la derniere allumette perd la partie.\n - Le joueur 1 commence.\n\n### Place au jeu! ###\n");
    printf("Le joueur 1 s'appelle: ");
    char nom1[15];
    scanf("%s", &nom1[15]);
    printf("\n\nLe joueur 2 s'appelle: ");
    char nom2[15];
    scanf("%s", &nom2[0]);
    printf("\n\nIndiquez le nombre d'allumlettes que vous tirez.\n");
    /* Nombre d'allumettes au départ */
    int a = 20;
    
    /* Nombre d'allumettes tirées */
    int x = 0;
       
    /* Joueur actif (qui a fait le dernier tour) */
    int j = 0;
       
    /* Winner */
    int win = 0;
       
    /* Le jeu continue indéfiniment. C'est l'évennement de victoire qui doit casser
    la boucle. C'est pour ca que le paramètre de la boucle est toujours vrai (1=1). */
    while (1==1)
    {
          /* On commence par le joueur 1 */
          j=1;
          printf("%s :", nom1 );
          scanf("%i", &x);
          /*ATTENTION! Normalement il faut vérifier que la quantité est bien comprise entre 1 et 3!
          J'ai enlevé la véréfication pour plus de clareté, mais il faut la faire!
          Je mets à la fin du programme une boucle qui pzut faire le taff. */
          
          /* On calcule la quantité d'allumettes restantes */
          a = a-x;
          printf("\nIl reste %i allumettes.\n\n", a);
          
          /* On regarde si on ne peut pas déterminer un winner */
          win = winner(a, j);
           
          /* Si'l y a un winner, on affiche le message de fin et on tue le programme.*/
          if (win == 1)
          {
                  printf("%s a gagne!\n", nom1);
                  system("PAUSE");
                  return 0;
          }
          if (win == 2)
          {
                  printf("%s a gagne!\n", nom2);
                  system("PAUSE");
                  return 0;
          }
          /* Si la condition de victoire ne s'est pas déclenchée, on continue avec 
          le joueur n°2 et on refait exactement parreil. */
          j=2;
          printf("%s: ", nom2);
          scanf("%i", &x);
          a = a-x;
          printf(" \nIl reste %i allumettes.\n\n", a);
          win = winner(a, j);
          if (win == 1)
          {
                  printf("%s a gagne!\n", nom1);
                  system("PAUSE");
                  return 0;
          }
          if (win == 2)
          {
                  printf("%s a gagne!\n", nom2);
                  system("PAUSE");
                  return 0;
          }
    }
    /* Et voila c'est tout ^^ */
    system("PAUSE");
    return 0;
}

/* Vérification de la saisie: 
while (x<1 || x>3)
{
       printf("Il faut entrer une valeur entre 1 et 3! Reessayez:\n");
       scanf("%i", &x);
}
*/
