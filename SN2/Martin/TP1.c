#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

// Nombre d'affichages
#define NB_AFFICHAGE 10
// Temporisation ralentissement du processus
#define TEMPO 1000000

// Code à exécuter si le processus est parent
bool Parent(pid_t id);
// Code à exécuter su le processus est enfant
int Child();

int main()
{
    printf("\n\tTP1\n\n");
    printf("Clonnage du programme ...\n");
    usleep(TEMPO);
    // PID obtenu du fork()
    pid_t id = fork();
    if (id == -1)
    { // Le fork() a signalé une erreur
        perror("LE FORK A ECHOUE.\n\n");
        exit(EXIT_FAILURE);
    }
    if (id)
    { // On est dans le processus père
        if (Parent(id))
        { // Si le code parent s'est exécuté correctement, fin du programme
            printf("\n\nLe programme s'est execute correctement.\nFin du programme.\n\n\n");
            usleep(TEMPO);
        }
        else
        { // Si le code parent à rencontré une erreur, message d'erreur
            printf("Le programme a renconte un probleme.\nFin du programme.\n\n\n");
            usleep(TEMPO);
        }
        return 0;
    }
    else
    { // Si le PID n'est pas > 0
        exit(Child());
    }
    // Le fork() est négatif
    printf("Echec du fork(). Fin du programme\n\n\n");
    return 0;
}

bool Parent(pid_t id)
{
    // Compteur
    int i;
    // Conteneur du statut du fils
    int status;
    // Valeur du message de fin du fils
    int exit_status;
    // Boucle d'affichage des PID
    for (i = 0; i < NB_AFFICHAGE; i++)
    {
        printf("PID = %d; PID FILS = %d\n", getpid(), id);
        usleep(TEMPO); // Ralentissement pour mettre en évidence l'entrelacement des processus: fin du quantum
    }
    printf("ATTENTE DU FILS ...\n\n");
    // Attente de la fin du processus fils
    waitpid(id, &status, NULL);
    // Vérification qu le fils s'est terminé avec exit()
    if (WIFEXITED(status))
    { // Si le fils s'est terminé avec exit()
        // On récupère la valeur de son statut
        exit_status = WEXITSTATUS(status);
        printf("LE FILS S'EST ARRETE AVEC LE STATUT %d.\n", exit_status);
        return true;
    }
    else
    { // Si le fils s'est terminé sans exit()
        printf("LE FILS NE S'EST PAS ARRETE NORMALEMENT.\n");
        return false;
    }
}

int Child()
{
    // Compteur
    int i;
    // Déphasage d'une demi-seconde par rapport au père
    usleep(TEMPO / 2);
    // Boucle d'affichage des PID
    for (i = 0; i < NB_AFFICHAGE; i++)
    {
        printf("\tpid = %d; pid pere = %d\n\n", getpid(), getppid());
        usleep(TEMPO);
    }
    // Retourne EXIT_SUCCESS
    printf("\tterminaison du fils.\n\n");
    return EXIT_SUCCESS;
}
