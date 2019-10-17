#include <stdio.h>
#include <stdlib.h>

int winner (int a, int j, char* nom1, int n)
{
        //printf("Fonction winner \n");
        int win = 0;
        if (a<=n)
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

int tirage(int x, int a, int n)
{
        //printf("Fonction tirage");
        scanf("%i", &x);
        while (x<1 || x>n)
        {
                printf("Il faut entrer une valeur entre 1 et %d! Reessayez:\n", n);
                scanf("%i", &x);
        }
        a = a-x;
        return a;
}

int ordi (int a, int n)
{
        //printf("Fonction ordi\n");
        int x = a/(n+1);
        //printf("Il y a %i paquets", x);
        x = a-(x*(n+1));
        //printf("x=%d", x);
        if (x == 0)
        {
                x = 1;
        }
        if (x<1 || x>n)
        {
                printf("Erreur fatale.");
                return 0;
        }
        a = a - x;
        printf("L'ordinateur prend %i . Il reste %i. \n\n", x, a);
        return a;
}

int main()
{
        char nom1[15]; // Nom du joueur
        int a;         // Quantité d'allumettes
        int x = 0;     // Quantité d'allumettes tirées
        int n = 0;     // Quantité maximale d'allumettes tirées
        int j = 0;     // Dernier joueur a avoir joué (1 ou 2)
        int win = 0;   // Gagnant (1 ou 2)
        printf("### JEU DES ALLUMETTES       ##################################################################\n\n");
        printf("Ceci est la version PVE. Vous jouerez contre l'ordinateur.\n\n");
        printf("### REGLES                   ##################################################################\n\n");
        printf(" - Chaque joueur prend tour à tour entre 1 et n allumettes (vous pourrez choisir cette valeur).\n");
        printf(" - Le joueur qui prend la derniere allumette perd la partie.\n");
        printf(" - Le joueur 1 commence.\n\n");
        printf("### Parametrage de la partie ##################################################################\n\n");
        printf("Comment vous appelez-vous ? \n");
        scanf("%s", nom1);
        printf("Choisissez la quantité maximale d'allumettes qu'on peut tirer: \n");
        scanf("%d", &n);
        printf("Choisissez la quantité initiale d'allumettes: \n");
        scanf("%i", &a);
        while (a<n*3)
        {
                printf("Choisissez une valeur au moins trois fois plus grande que la quantité qu'on peut tirer: \n");
                scanf("%i", &a);
        }
        printf("\n### PLACE AU JEU!          ####################################################################\n\n");
        printf("\n\nC'est parti! Indiquez le nombre d'allumlettes que vous tirez.\n");
        while (1==1)
        {
                j=1;
                printf("%s :", nom1 );
                a = tirage (x, a, n);
                printf("\nIl reste %i allumettes.\n\n", a);
                win = winner(a, j, nom1, n);
                if (win == 1)
                {
                        return 0;
                }

                j=2;
                a = ordi (a, n);
                if (a ==0)
                {
                        system("PAUSE");
                        return 0;
                }
                win = winner(a, j, nom1, n);
                if (win == 1)
                {
                        return 0;
                }
        }
        system("PAUSE");
        return 0;
}

