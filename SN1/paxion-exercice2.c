#include<stdlib.h>
#include<stdio.h>

int main()
{
        printf("\tTP4 - Exercice 2\n\n");
        int tab[10] = {4,12,53,19,11,60,24,12,89,19};
        printf("\n\nLes adresses des valeurs du tableau sont: ");
        int i;
        for(i=0; i<10; i++)
        {
                printf("%d ", &tab[i]);
        }
        printf("\n\n");
        return 0;
}
