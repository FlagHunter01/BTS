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

void hexa()
{
        int retour;
        unsigned int entree;
        printf("\nSaisissez un nombre hexa sur un octet: \n");
        retour = scanf("%2x", &entree);
        entree = verifhexa(retour, entree);
        printf(" - Saisie: %x | Scanf: %d \n", entree, retour);
}

int main()
{
        char menu;
        bool sortie = false;
        while(!sortie)
        {
                printf("\n\n    MENU\n\nExécuter le programme ? (y/n)");
                scanf("%c", &menu);
                if((menu == 'Y') | (menu == 'y'))
                {
                        hexa();
                }
                else
                {
                        if((menu == 'N') | (menu == 'n'))
                        {
                                printf("\nLe programme va se terminer\n\n");
                                sortie = true;
                        }
                        else
                        {
                                printf("\nCe programme est incomplet et fonctionne mal. Il ne sait pas gérer les réponses innatendues.\n\n");
                        }
                }
        }
        return 0;
}

