#include<stdlib.h>
#include<stdio.h>

/* Cette fonction classe en le tableau
par ordre croissant en utilisant la technique de la 'bulle' */

int main()
{
        printf("\n\tTri par ordre croissant d'un tableau\n\n");
        int longueur;
        printf("Quantité de valeurs:");
        scanf("%d", &longueur);
        int tableau[longueur];
        int i;
        printf("\nVeuillez saisir les valeurs:\n");
        for (i = 0; i < longueur; i++)
        {
                printf(" - Valeur %d: ", i+1);
                scanf("%d", &tableau[i]);
        }
        printf("\nTableau saisi:\n");
        for (i = 0; i < longueur; i++)
        {
                printf(" - %d\n", tableau[i]);
        }
        int compteur;
        do
        {
                compteur = 0;
                for (i = 0; i < longueur - 1; i++)
                {
                        if (tableau[i] > tableau[i+1])
                        {
                                int tampon = tableau[i];
                                tableau[i] = tableau[i+1];
                                tableau[i+1] = tampon;
                                compteur++;
                        }
                }
        }
        while (compteur > 0);
        printf("\nTableau trié: \n");
        for (i = 0; i < longueur; i++)
        {
                printf(" - %d\n", tableau[i]);
        }
        printf("\n\n");
        return 0;
}

