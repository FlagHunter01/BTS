#include<stdlib.h>
#include<stdio.h>

void Table(char * table, int n)
{
        int i;
        for(i=0; i<n; i++)
        {
                printf(" - Entrée %d: ", i+1);
                scanf("%i", &table[i]);
        }
        printf("\n");
}

void PrintForward(char * table, int n)
{
        int i;
        printf("\nOrdre d'entrée:\n\n");
        for(i=0; i<n; i++)
        {
                printf(" - %i\n", table[i]);
        }
}

void PrintBackwards(char * table, int n)
{
        int i;
        printf("\nOrdre inverse:\n\n");
        for(i=n-1; i>=0; i--)
        {
                printf(" - %i\n", table[i]);
        }
}

int  main()
{
        printf("\n\tTP 4 - Exercice 4\n\n");
        int n;
        printf("Combien d'entrées (max: 50)?: ");
        scanf("%d", &n);
        printf("\n");
        char table[n]; //TODO Faire un tableau de longueur fixe ?
        Table(table, n);
        PrintForward(table, n);
        PrintBackwards(table, n);
        printf("\n");
        return 0;
}
