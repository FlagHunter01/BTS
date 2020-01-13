#include <stdlib.h>
#include <stdio.h>

int main()
{
        int retour;
        unsigned int entree;
        printf("\n      ^C POUR QUITTER\n");
        while(1)
        {
                printf("\nSaisissez un nombre hexa sur un octet: \n");
                retour = scanf("%2x", &entree);
                printf(" - Saisie: %x | scanf: %d \n", entree, retour);
                usleep(2000000);
        }
        return 0;
}

