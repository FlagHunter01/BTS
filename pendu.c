#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* TODO KNOWN ISSUES TODO
 - jumps turns
 - prints BS when selecting 10 char long words */

int main()
{
        printf("Initialisation ...\n");
        char word[10][11];            //10 tablaux de 11 char
        strcpy(word[0], "banane");
        strcpy(word[1], "truand");
        strcpy(word[2], "onomatope");
        strcpy(word[3], "voyou");
        strcpy(word[4], "siphon");
        strcpy(word[5], "sonometre");
        strcpy(word[6], "entonoir");
        strcpy(word[7], "jument");
        strcpy(word[8], "clavicule");
        strcpy(word[9], "baricentre");
        int choice;                    // choix tu mot
        int turns = 20;                // tours restants
        char entry;                    // lettre entrée
        int i = 0;                     // compteur
        bool left = true;              // il reste des inconnues
        printf("\n      JEU DU PENDU\n\n");
        printf("Vous avez 20 essais pour deviner toutes les lettres d'un mot.");
        printf(" Entrez un nombre entre 1 et 10 pour choisir un mot.\n");
        printf("Entrée: ");
        scanf("%d", &choice);
        while((choice<1) || (choice>10))
        {
                printf("Entrez un nombre entier entre 1 et 10 svp!\nEntrée: ");
                scanf("%d", &choice);
        }
        // TODO: while((getchar()) != '\n');
        printf("\n");
        choice --;                            // pour matcher le tableau
        int lenth = strlen(word[choice]) + 1; // longueur du mot
        char unknown[lenth];
        strcpy(unknown, word[choice]);        // inconnu du joueur: mot complet
        char known[lenth];                    // connu du joueur
        for(i = 0; i < lenth-1; i++)          // au début, '--------'
        {
                known[i] = '-';
        }
        for(turns = 20; turns > 0; turns--)  // tant qu'il reste des tours
        {
                i = 0;
                int active;                  // tour en cours =21- tours restants
                active  = 21 - turns;
                printf("\n\n    TOUR %d\n", active);
                printf(" - Mot: %s\n", known);
                printf(" - Votre choix:");
                // TODO: while((getchar()) != '\n');
                scanf("%c", &entry);
                for(i = 0; i < lenth-1; i++)
                {
                        if(unknown[i] == entry)
                        {
                                known[i] = unknown[i];
                                printf("Trouvé à la lettre %d\n", i);
                        }
                }
                printf(" - Nouveau mot: %s\n", known);
                left = false;  // On part du principe que tout est trouvé
                // et on change d'avis si on trouve '-'
                for(i = 0; i < lenth-1; i++)
                {
                        if(known[i] == '-')
                        {
                                left = true;
                        }
                }
                if(!left)
                {
                        printf("\n      Vous avez trouvé toutes les lettres en %d tours, bravo!", active);
                        return 0;
                }
        }
        printf("\n      Vous avez épuisé tous vos tours ...\nVous aurez plus de chance la prochaine fois!\n\n");
        return 0;
}

