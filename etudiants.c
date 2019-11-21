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
                printf(" - Notes de e%i :", i); // TODO remplacer par nom / Prénom
                for (j = 0; j < 3; j ++)
                {
                        scanf("%f", &e[i].notes[j]);
                }
                float moyenne = 0;
                for (j = 0; j < 3; j ++)
                {
                        moyenne = moyenne + e[i].notes[j];
                }
                moyenne = moyenne/3;
                printf("   e%i a une moyenne de %f.\n", i, moyenne); // TODO remplacer par nom /prenom
                printf("   Absences de e%i (j/m/a, 0 pour quitter):", i); // TODO remplacer par nom / prenom
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

