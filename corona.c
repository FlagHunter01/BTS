#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
        struct S_Voyageur
        {
                char prenom[20];
                char nom[20];
                int  age;
                bool asie;
                char pays[20];
                bool contact;
                bool symptomes;
                bool malade;
                bool suivi;
                bool quarantine;
        };

        struct S_Pays
        {
                char nom[20];
                int conta;
                int mort;
                int gueri;
                struct S_Pays * suivant;
        };
        struct S_Pays T_Asie[9];
        int i;
        for(i=0; i<5; i++)
        {
                printf("Entrez les informations du pays numero %d:\n", i+1);
                printf(" - Nom: ");
                scanf("%s", T_Asie[i].nom);
                printf(" - Contaminations: ");
                scanf("%i", &T_Asie[i].conta);
                printf(" - Morts: ");
                scanf("%i", &T_Asie[i].mort);
                T_Asie[i].gueri = T_Asie[i].conta - T_Asie[i].mort;
                T_Asie[i].suivant = &T_Asie[i+1];
        }
        int confirmes = 0;
        int mortels = 0;
        for(i=0; i<5; i++)
        {
                confirmes = confirmes + T_Asie[i].conta;
                mortels = mortels + T_Asie[i].mort;
        }
        printf("Total cas confirmés: %d. Total de cas mortels: %d\n\n", confirmes, mortels);
        return 0;
}

