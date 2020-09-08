#include<stdlib.h>
#include<stdio.h>

void Table(float * table, int n)
{
        int i;
        for(i=0; i<n; i++)
        {
                printf(" - Entrée %d: ", i+1);
                scanf("%f", &table[i]);
        }
        printf("\n");
}

float Sum(float * table, int n)
{
        int i;
        float sum = 0;
        for(i=0; i<n; i++)
        {
                sum = sum+table[i];
        }
        return sum;
}

float Mean(float sum, int n)
{
        float mean = sum/n;
        return mean;
}

int  main()
{
        printf("\tTP 4 - Exercice 1 bis\n\n");
        int n;
        printf("Combien d'entrées (consigne: 10, max: 50)?: ");
        scanf("%d", &n);
        printf("\n");
        float table[50];
        Table(table, n);
        float sum = Sum(table, n);
        float mean = Mean(sum, n);
        printf("La somme des entrées fait %f et leur moyenne fait %f. \n\n", sum, mean);
        return 0;
}
