#include <stdio.h>
#include <stdlib.h>

/* Fonction qui lit la variable d'entree.
Elle fait un "et" logique entre la variable d'entree
et un masque pour lire un bit specifique. */
int lire (int input, int mask)
{
        // Et logique
        int x = input & mask;
        // Si le resultat est nul, le bit est nul
        if (x == 0)
        {
                return 0;
        }
        // Sinon, le bit est = 1
        else
        {
                return 1;
        }
}


/* Cette fonction fabrique la variable de sortie.
Chaque masque sert a coder un bit specifique de la variable
sans changer les autres. On decide de la valeur de chaque bit,
puis on les additionne pour avoir la variable de sortie. */
int sortie (int b, int m, int h, int P1, int P2, int t, int a)
{
        // Detecteur bas
        int maskb = 0;
        // Detecteur moyen
        int maskm = 0;
        // Detecteur haut
        int maskh = 0;
        // Pompe 1
        int maskP1 = 0;
        // Pompe 2
        int maskP2 = 0;
        // Voyant travail
        int maskt = 0;
        // Voyant alerte
        int maska = 0;
        // Variable de sortie
        int variable;
        // Si le detecteur bas est allume
        if (b)
        {
                maskb = 0b10000000;
        }
        // Si il est eteint
        else
        {
                maskb = 0b00000000;
        }
        // Idem pour le moyen ...
        if (m)
        {
                maskm = 0b01000000;
        }
        else
        {
                maskm = 0b00000000;
        }
        if (h)
        {
                maskh = 0b00100000;
        }
        else
        {
                 maskh = 0b00000000;
        }
        if (P1)
        {
                maskP1 = 0b00001000;
        }
        else
        {
                maskP1 = 0b00000000;
        }
        if (P2)
        {
                maskP2 = 0b00000100;
        }
        else
        {
                maskP2 = 0b00000000;
        }
        if (t)
        {
                maskt = 0b00000010;
        }
        else
        {
                maskt = 0b00000000;
        }
        if (a)
        {
                maska = 0b00000001;
        }
        else
        {
                maska = 0b00000000;
        }
        // La variable est creee en faisant un "ou" logique entre
        // les valeurs de chaque bit
        variable = maskb|maskm|maskh|maskP1|maskP2|maskt|maska;
        return variable;
}

int main()
{
        // Variable d'entree
        int input;
        // Message d'intro
        printf("### VALEURS CORRECTES EN ENTREE ###\n\n");
        printf("  10 000 000 - 128\n");
        printf("  11 000 000 - 192\n");
        printf("  11 100 000 - 224\n\n");
        // Lecture variable d'entree
        printf("Variable d'entree: ");
        scanf ("%i", &input);
        // Verbose (On demande si le programme doit etre bavard ou non
        int v;
        printf ("Executer avec verbose ? 1 / 0 \n");
        scanf ("%i",&v);
        // on ne demandera plus rien au client
        printf("\n\n### EXECUTION DU PROGRAMME ###\n\n");
        // Masque pour lire le voyant bas
        int maskb = 0b10000000;
        // Masque pour lire le voyant moyen
        int maskm = 0b01000000;
        // Masque pour lire le voyant haut
        int maskh = 0b00100000;
        //Etat des pompes 1 et 2
        int P1 = 0;
        int P2 = 0;
        // Etat du voyant "Alerte"
        int a = 0;
        // Etat du voyant "Travail"
        int t = 0;
        // Etat des capteurs bas, moyen et haut
        int b = lire (input, maskb);
        int m = lire (input, maskm);
        int h = lire (input, maskh);
        // La variable qu'on va creer (but du programme)
        int variable;
        // Debut des calculs
        // Si le nombre est plus gros qu'un octet, erreur
        if (input > 0b11111111)
        {
                // Ceci ne s'affiche qu'en mode verbose
                // Ca sert a rien a part encombrer le code ...
                if (v == 1)
                {
                        printf ("Mauvais input, le programme risque de ne pas fonctionner correctement. \n Allumage du voyant 'Alerte' et fin du programme. \n");
                }
                // Allumage du voyant alerte, tout le reste est a 0
                a = 1;
        }
        else
        {
                // Si un detecteur detecte l'eau mais pas celui d'en dessous
                if (m>b || h >b || h>m)
                {
                        // On allume 1 pompe
                        P1 = 1;
                        // On allume le voyant alerte
                        a = 1;
                        // On allume le voyant travail
                        t = 1;
                        // Chaque if (v == 1) c'est pour la verbose
                        if (v == 1)
                        {
                                printf ("Les detecteurs sont defectueux. \n - Allumage du voyant 'Alerte'. \n - Allumage preventif de la pompe no1. \n - Allumage du voyant 'Travail'. \n");
                        }
                }
                else
                {
                        // Si on est dans une situation "normale" (bonne variable en entree, pas de disfonctionnement capteur
                        // Si l'eau est au niveau bas
                        if (b == 1)
                        {
                                // Pompe 1
                                P1 = 1;
                                // Voyant travail
                                t = 1;
                                // Message explicatif
                                if (v == 1)
                                {
                                        printf ("Niveau d'eau bas detecte. \n");
                                        printf ("Allumage de la pompe no 1. \n");
                                        printf ("Allumage du voyant 'Travail'. \n");
                                }
                                // Si niveau moyen ...
                                if (m == 1)
                                {
                                        P2 = 1;
                                        if (v == 1)
                                        {
                                                printf ("Niveau d'eau moyen detecte. \n");
                                                printf ("Allumage de la pompe no 2. \n");
                                        }
                                }
                                // Si niveau haut ...
                                if (h == 1)
                                {
                                        a = 1;
                                        if (v == 1)
                                        {
                                                printf ("Niveau d'eau haut detecte. \n");
                                                printf ("Allumage du voyant alerte.\n");
                                        }
                                }
                        }
                }
        }
        /* On a traite toutes les conditions possibles, donc toutes les variables
        ont leur valeurs definitives. On peut donc lancer la fonction
        d'ecriture de la variable de sortie */
        variable = sortie (b, m, h, P1, P2, t, a);
        // Message de fin avec affichage en hexa de la variable de sortie
        printf("La variable de sortie en hexadecimal est %X .\n\n", variable);
        // Fin du programme
        system("PAUSE");
        return 0;
}

