#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct student * Attach(struct student * last)
{
        struct student * a = malloc(sizeof(struct student));
        char name[20];
        char lastname[20];
        int mark;
        int late;
        if(last)
        {
                printf("Prénom: ");
                scanf("%s", &name);
                printf("Nom: ");
                scanf("%s", &lastname);
                printf("Moyenne: ");
                scanf("%d", &mark);
                printf("Retards: ");
                scanf("%d", &late);
                a->name = name;
                a->lastanme = lastname;
                a->mark = mark;
                a->late = late;
                a->prev = last;
                a->next = 0;
                last->next = a;
                return a;
        }
        else
        {
                printf("Pas encore d'élèves dans la classe. Création d'une nouvelle classe.\n");
                printf("Prénom: ");
                scanf("%s", &name);
                printf("Nom: ");
                scanf("%s", &lastname);
                printf("Moyenne: ");
                scanf("%d", &mark);
                printf("Retards: ");
                scanf("%d", &late);
                a->name = name;
                a->lastanme = lastname;
                a->mark = mark;
                a->late = late;
                a->prev = last;
                a->next = 0;
                last->next = a;
                return a;
        }
}

int main()
{
        struct student
        {
                char name[20];
                char lastname[20];
                int mark;
                int late;
                struct student * prev;
                struct student * next;
        };
        struct student * last = 0;
        printf("Etudiant: prénom (20),nom (20), moyenne, retards.\n");
        printf("Entrer la quantité d'étudiants a saisir puis entrer les valeurs pour chaque étudiant.\n");
        int quantity;
        scanf("%d", &quantity);
        int i;
        for(i = 0, i <quantity, i++)
        {
                printf("Etudiant n %d:\n", i+1;)
                last = Attach(struct student * last);
        }
        return 0;
}
