#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

// Code à exécuter si le processus est parent
void Parent(pid_t id, int print_quantity, int tempo);
// Code à exécuter su le processus est enfant
void Child(int print_quantity, int tempo);

int main()
{
    // Nombre d'affichages
    int print_quantity = 10;
    // Temporisation ralentissement du processus
    int tempo = 1000000;
    printf("\n\tTP1\n\n");
    printf("Clonnage du programme ...\n");
    usleep(tempo);
    // PID obtenu du fork()
    pid_t id = fork();
    if (id == -1)
    { // Le fork() a signalé une erreur
        perror("LE FORK A ECHOUE.\n\n");
        exit(EXIT_FAILURE);
    }
    if (id)
    { // On est dans le processus père
        Parent(id, print_quantity, tempo);
    }
    else
    { // On est dans le processus fils
        Child(print_quantity, tempo);
    }
    // Ce code ne doit jamais s'exécuter
    printf("Erreur inconnue.\n\n\n");
    exit(EXIT_FAILURE);
}

void Parent(pid_t id, int print_quantity, int tempo)
{
    // Compteur
    int i;
    // Conteneur du statut du fils
    int status;
    // Valeur du message de fin du fils
    int exit_status;
    // Boucle d'affichage des PID
    for (i = 0; i < print_quantity; i++)
    {
        printf("PID = %d; PID FILS = %d\n", getpid(), id);
        usleep(tempo); // Ralentissement pour mettre en évidence l'entrelacement des processus: fin du quantum
    }
    printf("ATTENTE DU FILS ...\n\n");
    // Attente de la fin du processus fils
    waitpid(id, &status, 0);
    // Vérification qu le fils s'est terminé avec exit()
    if (WIFEXITED(status))
    { // Si le fils s'est terminé avec exit()
        // On récupère la valeur de son statut
        exit_status = WEXITSTATUS(status);
        printf("LE FILS S'EST ARRETE AVEC LE STATUT %d.\n", exit_status);
        usleep(tempo);
        exit(EXIT_SUCCESS);
    }
    else
    { // Si le fils s'est terminé sans exit()
        printf("LE FILS NE S'EST PAS ARRETE NORMALEMENT.\n");
        usleep(tempo);
        exit(EXIT_FAILURE);
    }
}

void Child(int print_quantity, int tempo)
{
    // Compteur
    int i;
    // Déphasage d'une demi-seconde par rapport au père
    usleep(tempo / 2);
    // Boucle d'affichage des PID
    for (i = 0; i < print_quantity; i++)
    {
        printf("\tpid = %d; pid pere = %d\n\n", getpid(), getppid());
        usleep(tempo);
    }
    // Retourne EXIT_SUCCESS
    printf("\tterminaison du fils.\n\n");
    usleep(tempo);
    exit(EXIT_SUCCESS);
}
