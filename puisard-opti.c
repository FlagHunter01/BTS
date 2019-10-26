#include <stdio.h>
#include <stdlib.h>

enum variables {capteurBas, capteurMoyen, capteurHaut, capteurMax, pompe1, pompe2, voyantFonc, voyantAlerte, enumMax};
const char mask[enumMax] = {0b10000000, 0b01000000, 0b00100000, 0b00000000, 0b00001000, 0b00000100, 0b00000010, 0b00000001};

void InitData(char input, bool* data)
{
        for (int i=0; i<capteurMax; i++) {data[i] = input & mask[i];}
        for (int i=capteurMax; i<enuMax; i++) {data[i] = 0;} // Remise à 0 des autres variables
}

void DecisionAlgo(bool* data)
{
        if (data[capteurBas]){data[pompe1] = true; data[voyantFonc] = true;}
        if (data[capteurMoyen]){data[pompe2] = true;}
        if (data[capteurHaut]){data[voyantAlerte] = true;}
        if (data[capteurMoyen]>data[capteurBas] || data[capteurHaut]>data[capteurMoyen] || data[capteurHaut]>data[capteurBas]){data[pompe1] = true; data[pompe2] = false; data[voyantFonc] = true; data[voyantAlerte] = true;}
        // TODO: On peut mettre toutes les variables qui sont "true" sur la même ligne séparés par une virgule ou un truc comme ca ? pompe1, voyantF, voyant1 = true
}

unsigned char OutputData(bool* data)
{
        unsigned char output = 0;
        for (int i=0; i<enumMax; i++){output = output&data[i];}
        return output;
}

int main()
{
        bool data[enumMax];
        unsigned char input;
        printf("Input: ");
        scanf("%hhu", &input); // %hhu : unsigned char (TODO: vérifier)
        // TODO: faire vérificateur scanf
        InitData(input, data); // data == &data[0] . Need enuMax, wich is global so not transmitted here.
        DecisionAlgo(data);
        unsigned char output = OutputData(data);
        printf("\nOutput: %hhu \n", output);
        return 0;
}

