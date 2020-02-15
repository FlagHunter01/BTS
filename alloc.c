#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Informations sur l'élève + pointeurs vers élèves adjascents. */
struct student
{
        char   name[20];
        char   lastname[20];
        float  mark;
        float  late;
        struct student * prev;
        struct student * next;
};

/* Informations sur la classe: qté d'élèves, moyenne et abscentéisme moyen. */
struct stats
{
        int   quantity;
        float markMean;
        float lateMean;
};

/* Crée un étudiant et retourne son adresse. */
struct student * CreateStudent()
{
        struct student * newStudent = malloc(sizeof(struct student));
        newStudent->prev = 0;
        newStudent->next=0;
        printf("\n      Entrez les informations concernant l'élève.\n\n");
        printf(" - Prénom: ");
        scanf("%s", newStudent->name);
        printf(" - NOM: ");
        scanf("%s", newStudent->lastname);
        printf(" - Moyenne: ");
        scanf("%a", &newStudent->mark);
        printf(" - Retards: ");
        scanf("%a", &newStudent->late);
        printf("\n%s %s enregistré avec une moyenne de %f et %f retards.\n", newStudent->name, newStudent->lastname, newStudent->mark, newStudent->late);
        return newStudent;
}

/* Crée de nouveaux étudiants tant que l'utilisateur le désire et retourne l'adresse du premier étudiant */
struct student *  ReadInput()
{
        struct student * first = CreateStudent();
        struct student * last = first;
        bool more = false;
        char trash;
        scanf("%c", &trash);
        printf("\nSouhaitez-vous ajouter un autre étudiant? (o/n) ");
        char c = getchar();
        if(c == 'o' || c == 'O')
        {
                more = true;
        }
        while(more)
        {
                struct student * tmp = CreateStudent();
                last->next = tmp;
                tmp->prev = last;
                last = tmp;
                scanf("%c", &trash);
                printf("\nSouhaitez-vous ajouter un autre étudiant? (o/n) ");
                c = getchar();
                if(c == 'o' || c == 'O')
                {
                        more = true;
                }
                else
                {
                        more = false;
                }
        }
        return first;
}

/* Lit les variables de chaque étudiant et les ajoute puis fait la moyenne.
Stoque dans un struct dont elle retourne la valeur. */
struct stats Calculate(struct student * s)
{
        struct stats studentStats;
        int quantity = 0;
        float markTotal = 0;
        float lateTotal = 0;
        if(!s)
        {
                printf("Erreur: il n'y a pas d'élèves. Toutes les valeurs seront nulles.\n");
        }
        while(s)
        {
                quantity ++;
                markTotal += s->mark;
                lateTotal += s->late;
                s = s->next;
        }
        studentStats.quantity = quantity;
        studentStats.markMean = markTotal / quantity;
        studentStats.lateMean = lateTotal / quantity;
        return studentStats;
}

/* Affiche la struct statistique à l'écran. */
void Display(struct stats * a)
{
        printf("\n      Il y a %i étudiants enregistrés.\nLa moyenne est de %f et le nombre de retards moyen est de %f par élève.\n\n", a->quantity, a->markMean, a->lateMean);
}

/* Supprime toute la mémoire allouée.*/
void Erase(struct student * pointer)
{
        while(pointer)
        {
                struct student * temp = pointer;
                pointer = pointer->next;
                free(temp);
        }
}


int main()
{
        struct student * first = ReadInput();
        struct stats a = Calculate(first);
        Display(&a);
        Erase(first);
        return 0;
}

