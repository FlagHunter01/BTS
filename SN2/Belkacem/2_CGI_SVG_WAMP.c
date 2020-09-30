// CGI sous WAMP
#include <stdio.h>
// T[20] = values[20], CH = canvasHeight, CW= canvasWidth, buf = buffer
#include <stdlib.h>
// SW = segmentWidth  SH = segmentHeight  L = length
#include <time.h>
// padding-top
#define PT 40
// padding-left
#define PL 30
// padding-bottom
#define PB 30
// padding-right
#define PR 20
// Quantité de mesures
#define N 20
// Tableau contenant les valeurs des mesures aléatoires
unsigned short T[N];
// Hauteur du canvas (Canvas Height)
unsigned short CH = 400;
// Largeur du canvas (Canvas Width)
unsigned short CW = 600;

// Fonction qui dessine le graphique
void cgiFunction()
{
    // Chaine contenant le code HTML de la page (buffer)
    static char buf[10240];
    // Longueur du code déjà écrit
    unsigned short L = 0;
    // Plus grande valeur prise par les mesures aléatoires
    unsigned short maxValue = 0;
    // Longueur d'une unité en abscisses (Segment Width)
    unsigned short SW;
    // Longueur d'une unité en ordonnées (Segment Height)
    unsigned short SH;
    // Compteur
    unsigned short i = 0;
    /* sprintf() met les caractères dans la chaine indiquée (ici, buf)
    Elle retourne la quantité de caractères écrits, qu'on met dans L.
    Ainsi, on sait que buf[L] suit le dernier caractère écrit.
    On utilise L pour pointer vers l'endroit où il faut écrire dans buf. */
    // Début du document XML et ouverture cu canvas SVG
    L = sprintf(buf,
                "Content-type:text/xml\n\n"
                "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\" ?>\n"
                "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/graphics/svg/1.1/DTD/svg11dtd\">\n"
                "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%u\" height=\"%u\" version=\"1.1\" >\n",
                CW, CH); // Largeur et hauteur du canvas
    // Ecriture du titre "Station meteo" en Arial 20 rouge
    L += sprintf(buf + L,
                 "<text x=\"%d\" y=\"%d\"  font-size=\"20\" font-family=\"Arial\" fill=\"red\" text-anchor=\"middle\">Station meteo</text>",
                 200, PT + 5);
    // Génération des valeurs des mesures aléatoires
    for (i = 0; i < N; ++i)
    {
        // Mesure prend la valeur du reste de la division de rand() par 50
        unsigned short mesure = (unsigned short)rand() % 50; // rand() retourne un int, qu'on transforme en unsigned short
        T[i] = mesure;
        // Si mesure > maxValue, maxValue prend la valeur de mesure. Sinon, elle prend la valeur maxValue (garde sa valeur)
        maxValue = mesure > maxValue ? mesure : maxValue;
    }
    // Unité des abscisses = hauteur du graphique / valeur de la plus grande mesure
    SH = (CH - PT - PB) / maxValue;
    // Unité des ordonnées = longueur du graphique / quantité de mesures
    SW = (CW - PL - PR) / (N - 1);
    // Dessin du graph de mesure à mesure, en reliand leur coordonnées
    for (i = 0; i < N - 1; ++i)
    {
        L += sprintf(buf + L,
                     "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"green\" />\n",
                     i * SW + PL, CH - PB - T[i] * SH, (i + 1) * SW + PL, CH - PB - T[i + 1] * SH);
    }

    /* Dessin de l'axe des ordonnées*/
    // Axe des ordonnées
    L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"blue\" />\n",
                 PL, CH - PB, PL, PT);
    // Fleche de gauche  (5x10 pixels)
    L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"blue\" />\n",
                 PL - 5, PT + 10, PL, PT);
    // Fleche de droite  (5x10 pixels)
    L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"blue\" />\n",
                 PL + 5, PT + 10, PL, PT);
    // Label des ordonnées
    for (i = 0; i < maxValue; i += ((SH > 15) ? 1 : 5))
    {
        // Ecriture de la valeur toutes les 5 unités
        L += sprintf(buf + L, "<text x=\"%u\" y=\"%u\" fill=\"blue\" font-size=\"12\">%u</text>\n",
                     7, CH - PB - i * SH + 5, i);
        // Dessin de la graduation
        L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"blue\" />\n",
                     PL - 2, CH - PB - i * SH, PL + 2, CH - PB - i * SH);
    }
    // Ecriture de l'unite de l'axe  "T (°C)""  en Arial 12
    L += sprintf(buf + L, "<text x=\"%d\" y=\"%d\" fill=\"blue\" font-family=\"Arial\" font-size=\"12\">T (°C)</text>\n", PL + 5, PT);

    /* Dessin de l'axe des abscisses*/
    // Dessin de l'axe des abscisses
    L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"red\" />\n",
                 PL, CH - PB, CW - PR, CH - PB);
    // Flèche du haut (10x5 pixels)
    L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"red\" />\n",
                 CW - PR - 10, CH - PB - 5, CW - PR, CH - PB);
    // Flèche du bas (10x5 pixels)
    L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"red\" />\n",
                 CW - PR - 10, CH - PB + 5, CW - PR, CH - PB);
    // Ecriture de la valeur du temps à chaque unité
    for (i = 0; i < N - 1; i += ((SW > 15) ? 1 : 5))
    {
        L += sprintf(buf + L, "<text x=\"%u\" y=\"%u\"  font-size=\"12\">%u</text>\n",
                     i * SW + PL - 2, CH - PB + 16, i);
    }
    // Dessin des graduations
    for (i = 0; i < N; i += ((SW > 15) ? 1 : 5))
    {
        L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"black\" />\n",
                     i * SW + PL, CH - PB - 2, i * SW + PL, CH - PB + 2);
    }
    // Ecriture de l'unité de l'axe "t(s)" en Arial 13
    L += sprintf(buf + L, "<text x=\"%d\" y=\"%d\" font-family=\"Arial\" font-size=\"13\">t(s)</text>", CW - PR, CH - PB + 5);
    // Affichage de la taille de la page
    L += sprintf(buf + L, "<text x=\"%d\" y=\"%d\"  font-size=\"13\" font-family=\"Arial\" fill=\"blue\" >%d octets dans cette page</text>",
                 CW / 2, PT + 5, L + sizeof("</svg>"));
    // Fermeture du canvas SVG
    L += sprintf(buf + L, "</svg>");
    // Affichage de la page
    printf(buf);
}

int main()
{
    // Génère un nombre en fonction du temps actuel qui sera utilis&é par rand()
    srand(time(NULL));
    cgiFunction();
    return 0;
}
