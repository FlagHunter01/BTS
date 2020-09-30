#include <stdbool.h> // bool
#include <stdio.h> // printf()

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
void Victory(char tableau[7][6]);

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
        Victory(tableau);
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

bool Place(bool player, int column, char tableau)
{
    int line = SearchFreeLine(column, tableau);
    if (line == -1)
    {
        return false;
    }
    else
    {
        if (player)
        {
            tableau[column][line] = 'X'
        }
        else
        {
            tableau[column][line] = 'O';
        }
    }
    return true;
}

bool FreePlace(char tableau[7][6])
{
    // Compteur
    int column;
    // Compteur
    int line;
    // Il reste une place
    bool freePlace = false;
    for (column = 0; column < 6; column++ 0)
    {
        for (line = 0; line < 5; line++)
        {
            if (tableau[column][line] == ' ')
            {
                return true;
            }
        }
    }
    return false;
}

void PrintTableau(char tableau[7][6])
{
    // Compteur
    int column;
    // Compteur
    int line;
    for (column = 0; column < 6, column++)
    {
        for (line = 0; line < 5; line++)
        {
            printf("|%s", tableau[column][line]);
        }
        printf("|\n");
    }
}

void Victory(char tableau[7][6])
{
    // Compteur
    int column;
    // Compteur
    int line;
    // Quantité de pions de même couleur
    int same = 0;
    // Joueur qu'on vient de vérifier
    bool oldPlayer = false;
    // Joueur qu'on vérifie
    bool newPlayer;
    // Victoire dans une ligne
    for (column = 0; column < 6; column++)
    {
        for (line = 0; line < 5; line++)
        {
            if (tableau[column][line] == 'O')
            {
                newPlayer = false;
            }
            if (tableau[column][line] == 'X')
            {
                newPlayer = true;
            }
            if (tableau[column][line] == ' ')
            {
                same=0;
                newPlayer = ( ( oldPlayer == true ) ? false : true ); // on inverse le joueur pour ne pas comptabiliser les points d'avant
            }
            if (oldPlayer == newPlayer)
            {
                same++;
                if (same == 4)
                {
                    printf("Victoire de joueur%d", newPlayer + 1)
                }
            }
            else
            {
                same = 1;
            }
        }
    }
}
