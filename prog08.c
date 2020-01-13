#include <stdlib.h>
#include <stdio.h>

unsigned int verif(int retour, unsigned int entree)
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

int main()
{
        int retour;
        unsigned int entree;
        printf("\n      ^C POUR QUITTER\n");
        while(1)
        {
                printf("\nSaisissez un nombre hexa sur un octet: \n");
                retour = scanf("%2x", &entree);
                entree = verif(retour, entree);
                printf(" - Saisie: %x | Scanf: %d \n", entree, retour);
        }
        return 0;
}

