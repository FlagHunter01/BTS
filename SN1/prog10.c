#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

unsigned int verifhexa(int retour, unsigned int entree)
{
        while(retour == 0)
        {
                while(getchar() != '\n');
                printf("\n!!! Saisie non valide. veuillez rentrer de l'hexa uniquement !!!\n");
                retour = scanf("%2x", &entree);
                printf("nouvelle saisie: %x | Scanf: %d \n", entree, retour);

        }
        return entree;
}

void octet()
{
        int retour;
        unsigned int entree;
        printf("\n\n    OCTET\n\nSaisissez un nombre hexa sur un octet: \n");
        retour = scanf("%2x", &entree);
        entree = verifhexa(retour, entree);
        printf(" - Saisie: %x | Scanf: %d \n", entree, retour);
}

void mot()
{
        int retour;
        unsigned int entree;
        printf("\n\n    MOT\n\nSaisissez un nombre hexa sur un mot: \n");
        retour = scanf("%4x", &entree);
        entree = verifhexa(retour, entree);
        printf(" - Saisie: %x | Scanf: %d \n", entree, retour);
}

void motdouble()
{
        int retour;
        unsigned int entree;
        printf("\n\n    MOT DOUBLE\n\nSaisissez un nombre hexa sur un mot double: \n");
        retour = scanf("%8x", &entree);
        entree = verifhexa(retour, entree);
        printf(" - Saisie: %x | Scanf: %d \n", entree, retour);
}

int Menu()
{
        int menu;
        printf("\n\n    MENU\n\nMenu principal. Choisissez une option pour continuer.\n");
        printf("| octet | mot | double mot | SORTIR |\n");
        printf("|   1   |  2  |      3     |    0   |\n\n");
        printf("Sélection: ");
        scanf("%d", &menu);
        return menu;
}

int main()
{
        bool sortie = false;
        int menu;
        while(!sortie)
        {
                menu = Menu();
                switch(menu)
                {
                        case 0: sortie = true;        break;
                        case 1: octet();              break;
                        case 2: mot();                break;
                        case 3: motdouble();          break;
                        //default : printf("Problème majeur\n"); sortie = true;
                }
        }
        printf("\n\nLe programme va se terminer\n\n");
        return 0;
}

