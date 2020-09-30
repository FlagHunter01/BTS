# TP3

1) Graphique dessiné de manière vectorielle.

2) Avec `rand()`, des nombres sont générés. Ils sont aléatoires entre eux, mais sont identiques à chaque exécution. 
   A l'inverse, `srand()` génère des nombres différents à chaque lancement.

3) Un cercle noir de fond rouge apparait.

4) Le graphe de la température en fonction du temps de la station météo apparait.

5) 

```c
#include <stdio.h>  // CGI sous WAMP
#include <stdlib.h> // T[20] = values[20], CH = canvasHeight, CW= canvasWidth, buf = buffer
#include <time.h>   // SW = segmentWidth  SH = segmentHeight  L = length
#define PT 20       // PADDING_TOP
#define PL 30       // PADDING_LEFT
#define PB 30       // PADDING_BOTTOM
#define PR 20       // PADDING_RIGHT
#define N 20        // nValues
unsigned short T[N], CH = 400, CW = 600;

void cgiFunction()
{
    static char buf[10240];
    unsigned short L, maxValue = 0, SW, SH, i;
    // Start SVG code
    L = sprintf(buf,
                "Content-type:text/xml\n\n"
                "<?xml version=\"1.0\" encoding=\"ISO-8859-1\" standalone=\"no\" ?>\n"
                "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/graphics/svg/1.1/DTD/svg11dtd\">\n"
                "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%u\" height=\"%u\" version=\"1.1\" >\n",
                CW, CH);
    // TITRE
    L += sprintf(buf + L,
                 "<text x=\"230\" y=\"30\"  font-size=\"20\" font-family=\"Arial\" fill=\"red\" text-anchor=\"middle\">Station meteo</text>"); // TITRES :  station meteo Arial 20 rouge
    for (i = 0; i < N; ++i)
    {
        T[i] = rand() % 50; // variables aleatoires
    }
    maxValue = T[i]; // Determine maximum value and segment width and height

    //SH = (CH - PT - PB) / maxValue;
    SW = (CW - PL - PR) / (N - 1);
    // Paint graph
    for (i = 0; i < N - 1; ++i){
        L += sprintf(buf + L,
                     "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"green\" />\n",
                     i * SW + PL, CH - PB - T[i] * SH, (i + 1) * SW + PL, CH - PB - T[i + 1] * SH);
    }

    //-------------------============   ordonnees  ============-------------------
    L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"blue\" />\n",
                 PL, CH - PB, PL, PT); // axe des ordonnees
    L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"blue\" />\n",
                 PL - 5, PT - 10, PL, PT); // fleche gauche  (5x10 pixels)
    L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"blue\" />\n",
                 PL + 5, PT + 10, PL, PT); // fleche droite  (5x10 pixels)
                                           // Label coordinate system   ordonnees
    for (i = 0; i < maxValue; i += ((SH > 15) ? 1 : 5))
    {
        L += sprintf(buf + L, "<text x=\"%u\" y=\"%u\" fill=\"blue\" font-size=\"12\">%u</text>\n",
                     7, CH - PB - i * SH + 5, i);
        L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"blue\" />\n",
                     PL - 2, CH - PB - i * SH, PL + 2, CH - PB - i * SH);
    }

    L += sprintf(buf + L, "<text x=\"%d\" y=\"%d\" fill=\"blue\" font-family=\"Arial\" font-size=\"12\">T (°C)</text>\n", PL + 5, PT); // unite de l'axe  T (°C)  en Arial 12

    //-------------------============   abscisses  ============-------------------
    L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"red\" />\n",
                 PL, CH - PB, CW - PR, CH - PB); // axe des abscisses
    L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"red\" />\n",
                 CW - PR - 10, CH - PB - 5, CW - PR, CH - PB); // fleche haute  (5x10 pixels)
    L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"red\" />\n",
                 CW - PR - 10, CH - PB + 5, CW - PR, CH - PB); // fleche basse  (5x10 pixels)
    for (i = 0; i < N - 1; i += ((SW > 15) ? 1 : 5))
        L += sprintf(buf + L, "<text x=\"%u\" y=\"%u\"  font-size=\"12\">%u</text>\n",
                     i * SW + PL - 2, CH - PB + 16, i); // valeurs des temps
    for (i = 0; i < N; i += ((SW > 15) ? 1 : 5))
        L += sprintf(buf + L, "<line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke=\"black\" />\n",
                     i * SW + PL, CH - PB - 2, i * SW + PL, CH - PB + 2);
    L += sprintf(buf + L, "<text x=\"%d\" y=\"%d\" font-family=\"Arial\" font-size=\"13\">t(s)</text>", CW - PR, CH - PB + 5); // unite de l'axe  t(s)   en Arial 13
    L += sprintf(buf + L, "<text x=\"%d\" y=\"%d\"  font-size=\"13\" font-family=\"Arial\" fill=\"blue\" >%d octets dans cette page</text>",
                 CW / 2, 5, sizeof(buf)); // L + taille de </svg>
    // Finish SVG code */
    L += sprintf(buf + L, "</svg>");
    printf(buf); // envoie de la page
}

int main()
{
    srand(time(NULL)); // Initialise random number generator
    cgiFunction();
    return 0;
}

```

6) Il faut remplacer `#define PT 20`  par `#define PT 40`.

7) Une boucle `for()` est déclarée. Elle uilise un compteur `i`, qui a pour valeur initiale `0`.
   La boucle tourne tant que `i` est inférieur à `maxValue`.
   `i` est incrémenté de la façon suivante: si SH > 15, `i` est incrémenté de 1; sinon `i` est incrémenté de 5.

   On crée un programme pour les tests:
   
   ```c
   #include <stdio.h>

   int main()
   {
       const int max = 20;
       const int SH = 15;
       int i;
       for (i = 0; i < max; if (SH > 15) { i += 1 } else {i += 5})
       {
           printf("%d", i);
       }
       return 0;
   }
   ```

   Le compilateur n'autorise pas la déclaration de `if()` dans la boucle `for()`.

   Ainsi, l'opérateur ternaire permet d'écrire des conditions au sein des boucles.
