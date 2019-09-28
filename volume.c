#include <stdio.h>
#include <stdlib.h>

/* Cette fonction calcule le volume d'un pave a partir de mesures indiquees. */

/* Fonction de demande et de verification*/
float Ask(char* name)
{
        float n;
        printf ("Renseignez la %s : \n ", name);
        scanf ("%f", &n);
        
        /* Verification du signe (longueur positive) */
        while (n <= 0)
        {
                printf ("Entrez une valeur positive. \n");
                scanf ("%f", &n);
        }
        
        /* Retour de l'entree a la fonction principale. */
        return n;
}

/* Fonction principale */
int main()
{
        /* Message d'intro */
        printf ("Calcul du volume d'un pave. Ses longueur, largeur et hauteur vous seront demandes.\n");

        /* Lecture des variables */
        float lon = Ask("longueur");
        float lar = Ask("largeur");
        float h = Ask("hauteur");

        /* Calcul du volume */
        float v = lon * lar * h;

        /* Affichage du volume */
        printf ("Le volume de ce pave est %f .", v);
        
        /* Fin du programme */
        system("PAUSE");
        return 0;
}

