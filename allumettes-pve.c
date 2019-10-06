#include <stdio.h>
#include <stdlib.h>




int winner (int a, int j, char* nom1)
{
        int win = 0;
        if (a<5)
        {
                if (j == 1)
                {
                        win = 2;
                }
                if (j == 2)
                {
                        win = 1;
                }
        }
        if (win == 1)
        {
                printf("%s a gagne!\n", nom1);
                system("PAUSE");
                return 1;
        }
        if (win == 2)
        {
                printf("L'Ordinateur a gagne!\n");
                system("PAUSE");
                return 1;
        }
        return 0;
}

int tirage(int x, int a)
{
        scanf("%i", &x);
        while (x<1 || x>3)
        {
                printf("Il faut entrer une valeur entre 1 et 3! Reessayez:\n");
                scanf("%i", &x);
        }
        a = a-x;
        return a;
}

int ordi (int a)
{
        a = a-1;
        int x = a/4;
        x = a-(x*4);
        if (x == 0)
        {
                x = 1;
        }
        if (x<1 || x>3)
        {
                printf("Erreur fatale.");
                return 0;
        }
        a = a - x;
        a = a +1;
        printf("L'ordinateur prend %i . Il reste %i. \n\n", x, a);
        return a;
}

int main()
{
        char nom1[15];
        int a = 20;
        int x = 0;
        int j = 0;
        int win = 0;
        printf("### JEU DES ALLUMETTES ###\n\n Il faut deux joueurs.\n\n### REGLES ###\n\n - Chaque joueur prend tour à tour entre 1 et 3 allumettes.\n - Le joueur qui prend la derniere allumette perd la partie.\n - Le joueur 1 commence.\n\n### Place au jeu! ###\n");
        printf("Comment vous appelez-vous ? \n");
        scanf("%s", nom1);
        printf("Choisissez la quantité initiale d'allumettes: \n");
        scanf("%i", &a);
        while (a<6)
        {
                printf("Choisissez une valeur plus grande: \n");
                scanf("%i", &a);
        }
        printf("\n\nC'est parti! Indiquez le nombre d'allumlettes que vous tirez.\n");
        while (1==1)
        {
                j=1;
                printf("%s :", nom1 );
                a = tirage (x, a);
                printf("\nIl reste %i allumettes.\n\n", a);
                win = winner(a, j, nom1);
                if (win == 1)
                {
                        return 0;
                }

                j=2;
                a = ordi (a);
                if (a ==0)
                {
                        system("PAUSE");
                        return 0;
                }
                win = winner(a, j, nom1);
                if (win == 1)
                {
                        return 0;
                }
        }
        system("PAUSE");
        return 0;
}

