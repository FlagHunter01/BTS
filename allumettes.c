#include <stdio.h>
#include <stdlib.h>

winner (int a, int j)
{
       int win = 0;
       if (a>4)
       {
               return win;
       }
       else 
       {
            if (j == 1)
            {
                  return 2;
            }
            if (j == 2)
            {
                  return 1;
            }
       }
}
              
            
int main()
{
    printf("### JEU DES ALLUMETTES ###\n\n Il faut deux joueurs.\n\n### REGLES ###\n\nIl y a 20 allumettes au depart. Chaque joueur prend tour à tour entre 1 et 3 allumettes. Le joueur qui prend la derniere allumette perd la partie. Le joueur 1 commence.\n\n### Place au jeu! ###\n\nIndiquez le nombre d'allumlettes que vous tirez.\n");
    int a = 20;
    int x = 0;
    int j = 0;
    int win = 0;
    while (1==1)
    {
          j=1;
          printf("joueur 1:");
          scanf("%i", &x);
          a = a-x;
          printf("il reste %i", a);
          win = winner(a, j);
          if (win == 1)
          {
                  printf("Joueur 1 gagne");
                  system("PAUSE");
                  return 0;
          }
          if (win == 2)
          {
                  printf("Joueur 2 gagne");
                  system("PAUSE");
                  return 0;
          }
          j=2;
          printf("joueur 2:");
          scanf("%i", &x);
          a = a-x;
          printf("il reste %i", a);
          win = winner(a, j);
          if (win == 1)
          {
                  printf("Joueur 1 gagne");
                  system("PAUSE");
                  return 0;
          }
          if (win == 2)
          {
                  printf("Joueur 2 gagne");
                  system("PAUSE");
                  return 0;
          }
    }
    system("PAUSE");
    return 0;
}
