# TP1 - Processus & threads

!!!note "Mis à jour le 14/09/20"

!!!tip "Copier-coller"
    Le code a un bouton "copier" en haut à droite, mais il est noir sur noir.

## Commandes shell

| Commande  | Description                                                                                            |
| --------- | ------------------------------------------------------------------------------------------------------ |
| `ps -u`   | Donne les processus et leur consommation des ressources en fonction de l'utilisateur.                  |
| `ps –ex`  | Donne l'environnement à la suite de la commande, en affichant les processus qui n'ont pas de terminal. |
| `ps –aux` | Donne les processus de tous les utilisateurs,  en affichant les processus qui n'ont pas de terminal.   |
| `ps –ef`  | Donne l'environnement à la suite de la commande en affichant l'arbre généalogique des processus.       |
| `pstree`  | Affiche les processus en cours d'exécution sous la forme d'un arbre                                    |
| `top`     | Affiche l'activité dans le système de manière dynamique.                                               |

## Programmation processus

### Structure du programme

Le programme est divisé en trois parties logiques:

 - Création du processus fils
 - Comportement s'il s'identifie comme parent
 - Comportement s'il s'identifie comme enfant

J'ai donc créé trois fonctions qui représentent les trois parties logiques:

```c
pid_t CloneThread(bool *parent); // Création du fils
bool Parent(pid_t id);           // Comportement parent
bool Child();                    // Comportement fils
``` 
Le statut parent/enfant est choisi par `CloneThread()`, en fonction du résultat de `fork()`. Elle stoque son choix dans `bool parent`, auquel elle a accès grâce à un pointeur. 

!!!info "Parenthèses"
    Les parenthèses servent à distinguer les fonctions des variables.

Grâce à un `if`, on exécute la fonction `Parent()` ou `Child()` en fonction de `bool parent`. On peut ensuite fermer le programme. 

On obtient ainsi la structure suivante:

```c
pid_t CloneThread(bool *parent);
bool Parent(pid_t id);
bool Child();

int main()
{
    bool parent;                    // Va contenir le choix parent/enfant
    pid_t id = CloneThread(&parent) // Obtenir le PID et faire le choix parent/enfant en fonction
    if (parent)                     // Si choix = parent
    {
        Parent(id);                 // Execution de Parent()
        return 0;                   // Fin du programme
    }
    else                            // Si choix = enfant
    {
        return Child();             // On rend l'etat de Child()
    }
}
```

### CloneThread

D'après la documentation, `fork()` prend la valeur du PID de l'enfant dans le programme père, la valeur `0` dans le programme fils, et retourne `-1` si elle n'a pas pu s'exécuter correctement. Le PID est contenu dans une variable de type `pid_t`. On a donc de quoi identifier s'il s'agit du programme père ou fils.

Il suffit donc de faire une petite fonction qui appelle `fork()` et, en fonction de la réponse, décide si le programme est parent ou enfant:

```c
pid_t CloneThread(bool *parent)
{
    pid_t id = fork();                  // On appelle fork()
    if (id)                             // Si on recoit le PID de l'enfant
    {
        *parent = true;                 // On est parent
    }
    else                                // Sinon 
    {
        if (id == 0)                    // Si on recoit un PID nul
        {
            *parent = false;            // On est enfant
        }
        else                            // Si on recoit un code erreur
        {
            *parent = true;             // On est restés parent
            printf("Problème de fork"); // Et on a un problème
        }
    }
}
```

### Parent

En tant que parent, on doit donner son PID 10 fois, attendre la mort du fils puis afficher son statut.

En faisant quelques recherches, je suis tombé sur les bibliothèques système `#include <sys/types.h>` et `#include <sys/wait.h>`, qui permettent de travailler avec le statut d'un processus fils:

 - Grâce à `wait(&statut)`, on peut attendre la mort d'un processus fils et écrire son statut.
 - Grâce à `WEXITSTATUS(status)`, on peut interpréter le statut.

Ces bibliothèques proposent beaucoup plus de fonctions, allez les voir sur les docus officielles.

On fait donc une boucle qui affiche 10 fois le PID du programme et le PID du fils, on attend qu'il meurt et on affiche son statut.

!!!tip "`bool`"
    Le type `bool` de la fonction parent sert pour le debogage: si elle s'est exécutée correctement, elle est `true`, sinon `false`.

J'ai donc écrit le code suivant:

```c 
bool Parent(pid_t id)
{
    if (id < 0)                                            // Si fork() a donné une erreur
    {
        printf("Le fork a échoué");                        // Il n'y a pas de fils
        return false;                                      // Donc arrêt avec erreur
    }
    for (int i = 0; i < 10; i++)                           // A 10 reprises
    {
        printf("PID = %d; PID FILS = %d\n", getpid(), id); // On affiche les PID
        usleep(2000000);                                   // On attend 2 secondes
    }
    int status;                                            // Va stocker le statut du fils
    wait(&status);                                         // Attend la mort du fils et enregistre son statut
    int exit_status = WEXITSTATUS(status);                 // Décrypte le statut
    printf("LE FILS S'EST ARRETE AVEC LE STATUT %d.\n", exit_status); // Affichage
    return true;                                           // On s'arrête normalement
}
```

### Child

Pour finir, l'enfant. Il doit juste afficher les PID 10 fois puis retourner son statut:

```c
bool Child()
{
    usleep(1000000);                        // Déphasage avec le parent
    for (int i = 0; i < 10; i++)            // A 10 rprises
    {
        printf("\tpid = %d; pid pere = %d\n\n", getpid(), getppid()); // On affiche les PID
        usleep(2000000);                    // On attend 2 secondes
    }
    return true;                            // On retourne true
}
```

### Programme fini

Code sans interruption, avec les `#include` nécessaires, beaucoup plus de verbose (j'aime bien) et quelques failproof-isations en plus:

???note "`TP1.c`"
    ```c
    #include <unistd.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/wait.h>

    pid_t CloneThread(bool *parent);
    bool Parent(pid_t id);
    bool Child();

    int main()
    {
        printf("\n\tTP1\n\n");
        bool parent;
        printf("Clonnage du programme ...\n");
      usleep(1000000);
       pid_t id = CloneThread(&parent);
        if (parent)
        {
           if (Parent(id))
           {
               printf("\n\nLe programme s'est execute correctement.\nFin du programme.\n\n\n");
               usleep(10000000);
          }
          else
           {
               printf("Le programme a renconte un probleme.\nFin du programme.\n\n\n");
              usleep(10000000);
          }
           return 0;
       }
        else
       {
           return Child();
       }
       printf("Erreur inconnue. Fin du programme.\n\n\n");
       return 0;
    }

    pid_t CloneThread(bool *parent)
    {
        pid_t id = fork();
       if (id)
       {
            *parent = true;
            printf("PROGRAMME PERE.\n");
        }
        else
        {
            if (id == 0)
            {
                *parent = false;
               printf("\tprogramme fils.\n\n");
            }
            else
            {
                *parent = true;
                printf("Echec lors de la création du fils.\n\n");
                return id;
            }
        }
        return id;
    }

    bool Parent(pid_t id)
    {
       if (id < 0)
        {
            printf("LE FORK A ECHOUE.\n\n");
            return false;
        }
        for (int i = 0; i < 10; i++)
        {
            printf("PID = %d; PID FILS = %d\n", getpid(), id);
            usleep(2000000);
        }
        printf("ATTENTE DU FILS ...\n\n");
        int status;
        wait(&status);
        int exit_status = WEXITSTATUS(status);
        printf("LE FILS S'EST ARRETE AVEC LE STATUT %d.\n", exit_status);
        return true;
    }

    bool Child()
    {
        usleep(1000000);
        for (int i = 0; i < 10; i++)
        {
            printf("\tpid = %d; pid pere = %d\n\n", getpid(), getppid());
            usleep(2000000);
        }
       printf("\tterminaison du fils.\n\n");
       return true;
    }
    ```

!!!warning "A finir"
