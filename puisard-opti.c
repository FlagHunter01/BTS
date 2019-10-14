#include <stdio.h>
#include <stdlib.h>

//#### Définition des variables ####
// Enumération des variables d'opération
enum variables {capteurBas, capteurMoyen, capteurHaut, capteurMax, pompe1, pompe2, voyantFonc, voyantAlerte, enumMax};
// Masques
const char mask[enumMax] = {0b10000000, 0b01000000, 0b00100000, 0b00000000, 0b00001000, 0b00000100, 0b00000010, 0b00000001};

void InitData (char input, bool* data)
{
        for (int i=0; i<capteurMax; i++) {data[i] = input & mask[i];}
        // equivalent à
        for (bool* i = data; i < &data[capteurMax]; i++) { *i = .... };
        // equivalent à
        const bool* stop = &data[capMax];
        while(data++ != stop) { *data = .... }

        for (int i=capteurMax; i<enuMax; i++) {data[i] = 0;} // Remise à 0 des autres variables
}

int main ()
{
        bool data[enuMax];
        unsigned char input;
        scanf("%hhu", &input); // %hhu : unsigned char (TODO: vérifier)
        // TODO: faire vérificateur scanf
        InitData(input, data); // data == &data[0] . Need enuMax, wich is global so not transmitted here.

        return 0;
}

