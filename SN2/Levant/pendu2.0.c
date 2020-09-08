#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    printf("\n\n\tLE JEU DU PENDU\n\n");
    char original[9] = "autoclave"; // Mot a trouver
    char *p_original = &original;   // Pointeur vers le mot a trouver
    char found[9] = "---------";    // Mot devine
    char *p_found = &found;         // Pointeur vers le mot devine
    int tries = 20;                 // Nombre de tours restants
    char entry;                     // Lettre entree
    int i = 0;                      // Compteur
    char *pointer1 = 0;             // Pointeur temporaire 1
    char *pointer2 = 0;             // pointeur temporaire 2
    bool victory = false;           // Condition de victoire
    // Le programme s'arrete quand les essais sont epuises
    while (tries > 0)
    {
        tries--; // On enleve un essai a chaque essai
        // On scanne une lettre dans la variable de stockage
        printf("Entrez une lettre: ");
        scanf("%c", &entry);
        // On efface le reste du presse-papiers
        while ((getchar()) != '\n')
            ;
        // On compare chaque caractere de l'original
        // avec l'entree
        for (i = 0; i < 9; i++)
        {
            pointer1 = p_original + i;
            // Si l'entree correspond a l'original
            // on remplace le caractere corrspondant
            // dans le mot trouve
            if (entry == *pointer1)
            {
                pointer2 = p_found + i;
                *pointer2 = *pointer1;
            }
        }
        // Verification des conditions de victoire.
        // On concidere qu'on a gagne tant qu'on n'a pas
        // trouve de divergence.
        victory = true;
        for (i = 0; i < 9; i++)
        {
            pointer1 = p_original + i;
            pointer2 = p_found + i;
            // Si divergence, alors conditions non respectees
            if (*pointer1 != *pointer2)
            {
                victory = false;
            }
        }
        printf("\n");
        // On affiche le mot trouve
        for (i = 0; i < 9; i++)
        {
            pointer2 = p_found + i;
            printf("%c", *pointer2);
        }
        // On affiche la quantite d'essais restants
        printf("\nIl vous reste %d essais.\n", tries);
        printf("\n");
        // On sort de la boucle en cas de victoire
        if (victory)
        {
            printf("\n\tVICTOIRE! Vous avez trouve toutes les lettres!\n\n\n");
            return 0;
        }
    }
    // Si on a fini la boucle, c'est la defaite
    printf("\n\tOH NON! Vous avez epuise tous vos essais ...\n\n\n");
    return 0;
}
