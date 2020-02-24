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

void PrintForward(float * table, int n)
{
        int i;
        printf("\nOrdre d'entrée:\n\n");
        for(i=0; i<n; i++)
        {
                printf(" - %f\n", table[i]);
        }
}

void PrintBackwards(float * table, int n)
{
        int i;
        printf("\nOrdre inverse:\n\n");
        for(i=n; i>0; i--)
        {
                printf(" - %f\n", table[i]);
        }
}

int  main()
{
        printf("\n\tTP 4 - Exercice 4\n\n");
        int n;
        printf("Combien d'entrées (max: 50)?: ");
        scanf("%d", &n);
        printf("\n");
        float table[n];
        Table(table, n);
        PrintForward(table, n);
        PrintBackwards(table, n);
        printf("\n");
        return 0;
}
