#include <stdio.h>
#include <stdlib.h>

int main()
{
        //### DECLARATION DES VARIABLES #####################################################################################################

        char chain[50];                                 // Chaine pour stocker l'expression
        printf("\nEntrez une chaine pour savoir s'il s'agit d'un palyndrome! Longueur max: 50.\n");
        printf("Entrée: ");
        scanf("%s", chain);                             // "%s", chain   =   "%s", &chain[0]
        int index = 0;                                  // Numéro du caractère qu'on veut traiter
        int value = 1;                                  // Valeur du caractère qu'on veurt traiter
        int lenth = 0;                                  // Longueur de la chaine

        //### CALCUL DE LA LONGUEUR DE LA CHAINE ############################################################################################

        while (value != '\0')
        {
                value = chain[index];                   // Lecture de la valeur du caractère ne n° 'index'
                index ++;
                if (value == '\0')                      // Si le caractère est le caractère de fin de chaine ...
                {
                        lenth = index - 2;              // La longueur est de 'index'+2 (décalage car premier = chain[0] et index ++ avant if)
                }
        }
        index = 0;                                      // On reset l'index

        //### COMPARAISON DES VALEURS ########################################################################################################

        while (index <= lenth/2)                        // Tant que index est plus petit que la moitié de la longueur
        {
                if (chain[index] == chain[lenth-index]) // Si le caractère 0+i est égal au caractère 'longueur'-i
                {                                       // En gros on part du début et de la fin et on resserre jusqu'au milieu
                        index ++;
                        if (lenth-index == index)       // Soit les deux bouts se rejoignent au milieu (si quantité de caractères paire)
                        {
                                printf("\n      C'est un palyndrome!\n\n");
                                return 0;
                        }
                        if (lenth-index == index+1)     // Soit il y a un caractère entre les deux bouts (si quantité impaire)
                        {
                                printf("\n      C'est un palyndrome!\n\n");
                                return 0;
                        }
                }
                else
                {
                        printf("\n      Ce n'est pas un palyndrome ...\n\n");
                        return 0;
                }
        }
        printf("Y'a un bug");                          // Si les caractères ne sont ni iddentiques ni différents
        return 0;                                      // C'est qu'une boucle n'a pas fonctionné
}
