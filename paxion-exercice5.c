#include<stdlib.h>
#include<stdio.h>

void Table(char * table, int n)
{
        int i;
        char trash;
        for(i=0; i<n; i++)
        {
                scanf("%c", &trash);
                printf(" - Entrée %d: ", i+1);
                scanf("%c", &table[i]);
        }
        printf("\n");
}

void Print(char * table, int n)
{
        int i;
        for(i=0; i<n+1; i++)
        {
                printf(" - Valeur %d: %c - adresse: %d\n", i+1, table[i], &table[i]);
        }
}

int  main()
{
        printf("\n\tTP 4 - Exercice 5\n\n");
        int n;
        printf("Combien d'entrées (max: 50)?: ");
        scanf("%d", &n);
        printf("\n");
        char table[n];
        Table(table, n);
        Print(table, n);
        printf("\n");
        return 0;
}
