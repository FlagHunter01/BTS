#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("### JEU DES ALLUMETTES ###\n\n Il faut deux joueurs.\n\n### REGLES ###\n\nIl y a 20 allumettes au depart. Chaque joueur prend tour à tour entre 1 et 3 allumettes. Le joueur qui prend la derniere allumette perd la partie. Le joueur 1 commence.\n\n### Place au jeu! ###\n\nIndiquez le nombre d'allumlettes que vous tirez.\n");
    int a = 20;
    int x = 0;
    while (a>2)
    {
          printf("Joueur 1: ");
          scanf("%i", &x);
          while (x>3 || x<1)
          {
                printf("Vous devez prendre entre 1 et 3 allumettes!\nRecommencez: ");
                scanf("%i", &x);
          }
          
          a = a-x;
          printf("Le joueur 1 a pris %i allumettes.\n", x);
          printf("Il reste %i allumettes.\n", a);
          if (a==1)
          {
                   printf("Le joueur 1 a gagne! \n");
          }
          if (a>2)
          {
                  printf("Joueur 2:");
                  scanf("%i", &x);
                  while (x>3 || x<1)
                  {
                        printf("Vous devez prendre entre 1 et 3 allumettes!\nRecommencez: ");
                        scanf("%i", &x);
                  }
                  a=a-x;
                  if (a==1)
                  {
                           printf("Le joueur 2 a gagne!\n");
                  }
                  else
                  {
                           printf("Le joueur 2 a pris %i allumettes.\n", x);
                           printf("Il reste %i allumettes\n", a);
                  }
                  if (a==2 || a==3)
                  {
                          printf("Le joueur 1 a gagne! \n");
                  }
          }
    }       
  
  system("PAUSE");	
  return 0;
}
