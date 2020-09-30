#include <stdbool.h>

/*
|X|X|X|X|X|X|X|
|X|X|X|X|X|X|X|
|X|X|X|X|X|X|X|
|X|X|X|X|X|X|X|
|X|X|X|X|X|X|X|
|X|X|X|X|X|X|X|
*/

/* TODO: vérifier que la colonne est 0<colonne<7 */

// Renvoie la première ligne disponible d'une colonne
int SearchFreeLine(int column, char tableau[7][6]);

// Ajout d'un pion par un joueur dans un tableau
bool Place(bool player, int column, char tableau[7][6]);

// Vérification des conditions de victoire
void Victory(bool player, char tableau[7][6]);

// Recherche s'il y a la place de continuer le jeu
bool FreePlace(char tableau[7][6]);

// Affichage du tableau
void PrintTableau(char tableau[7][6]);

int main()
{
    // grille de jeu
    char tableau[7][6]; // Mettre à 0!

    // Joueur qui joue actuellement
    bool player = false;

    // joueur qui jouera ensuite
    bool nextplayer;

    // Tant qu'il reste de la place pour jouer
    while (FreePlace(tableau))
    {
        // Colonne choisie par le joueur
        int column;

        // Placement choisi valable
        bool possiblePlacement;

        // Affichage en fonction du joueur
        if (player)
        {
            printf("Joueur 2, choisissez colonne:");
        }
        else
        {
            printf("Joueur 1, choisissez colonne:");
        }
        scanf("%d", &column);
        possiblePlacement = Place(player, column, tableau);
        while (!possiblePlacement)
        {
            printf("Colonne sans place dispo. Choisissez-en une autre:");
            scanf("%d", &column);
            possiblePlacement = Place(player, column, tableau);
        }
        PrintTableau(tableau);
        Victory(player, tableau);
        if (player)
        {
            nextplayer = false;
        }
        else
        {
            nextplayer = true;
        }
    }
    printf("Personne n'a pu gagner");
    return 0;
}

int SearchFreeLine(int column, char tableau[7][6])
{
    // Compteur
    int i;
    for (i = 0; i < 5; i++)
    {
        if (tableau[column][i] == ' ')
        {
            return i;
        }
    }
    return -1; // A chopper dans Place()
}

bool Place(bool player, int column, char tableau[7][6])
{
    int ligne = SearchFreeLine(column, tableau);
    if (ligne == -1)
    {
        return false
    }
}
