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

void Counter(char * table, int n)
{
        int i;
        int j = 0;
        int k = 0;
        for(i=0; i<n; i++)
        {
                if(table[i] == 'e')
                {
                        j++;
                }
                if(table[i] == ' ')
                {
                        k++;
                }
        }
}

int  main()
{
        printf("\n\tTP 4 - Exercice 6\n\n");
        int n;
        printf("Combien d'entrées (max: 50)?: ");
        scanf("%d", &n);
        printf("\n");
        char table[n];
        Table(table, n);
        Counter(table, n);
        printf("\n");
        return 0;
}
