#include <stdio.h>
#include <stdlib.h>

int main ()
{
        struct date
        {
                int         jour;
                int         mois;
                int         annee;
        };
        struct information
        {
                char        nom       [40];
                char        prenom    [40];
                char        naissance [10];
                char        classe    [20];
                int         num;
                float       notes     [10];
                char        comm      [200];
                struct date absent    [15];
        };
        struct information snir1[29];
        struct information e[3];
        int i, j, k;
        printf("\n      ### SAISIE DES NOTES ###\n\n");
        printf("   *Appuillez sur <Entrée> pour valider chaque valeur.*\n");
        for (i = 0; i < 4; i ++)
        {
                printf(" - Notes de %s %s", e[i].prenom, e[i].nom);
                for (j = 0; j < 2; j ++)
                {
                        scanf("%f", &e[i].notes[j]);
                }
                float moyenne = 0;
                for (j = 0; j < 2; j ++)
                {
                        moyenne = moyenne + e[i].notes[j];
                }
                moyenne = moyenne/2;
                printf("   %s %s a une moyenne de %f.\n",e[i].prenom, e[i].nom, moyenne);
                printf("   Absences de %s (j/m/a, 0 pour quitter):", e[i].prenom);
                for (k = 0; k < 16; k ++)
                {
                        scanf("%i", &e[i].absent[k].jour);
                        if (e[i].absent[k].jour == 0)
                        {
                                return 0;
                        }
                        printf("/");
                        scanf("%i", &e[i].absent[k].mois);
                        printf("/");
                        scanf("%i", &e[i].absent[k].annee);
                }
        }
}

