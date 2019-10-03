#include <stdio.h>
#include <stdlib.h>

int winner (int a, int j)
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
    printf("### JEU DES ALLUMETTES ###\n\n Il faut deux joueurs.\n\n### REGLES ###\n\n - Il y a 20 allumettes au depart.\n - Chaque joueur prend tour à tour entre 1 et 3 allumettes.\n - Le joueur qui prend la derniere allumette perd la partie.\n - Le joueur 1 commence.\n\n### Place au jeu! ###\n");
    printf("Le joueur 1 s'appelle: ");
    char nom1[15];
    scanf("%s", &nom1[15]);
    printf("\n\nLe joueur 2 s'appelle: ");
    char nom2[15];
    scanf("%s", &nom2[0]);
    printf("\n\nIndiquez le nombre d'allumlettes que vous tirez.\n");
    int a = 20;
    int x = 0;
    int j = 0;
    int win = 0;
    while (1==1)
    {
          j=1;
          printf("%s :", nom1 );
          scanf("%i", &x);
          a = a-x;
          printf("\nIl reste %i allumettes.\n\n", a);
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
    system("PAUSE");
    return 0;
}

