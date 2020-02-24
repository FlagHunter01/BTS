#include<stdlib.h>
#include<stdio.h>

int main()
{
        printf("\tTP4 - Exercice 3\n\n");
        int tab[20] = {4,-2,-23,4,34,-67,8,9,-10,11,4,12,-53,19,11,-60,24,12,89,19};
        int i;
        printf("\n");
        for(i=0; i<20; i++)
        {
                printf("\t%d",tab[i]);
                if((i == 4) | (i == 9) | (i == 14) | (i == 19))
                {
                        printf("\n");
                }
        }
        printf("\n");
        return 0;
}
