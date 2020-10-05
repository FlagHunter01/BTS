#include <sys/wait.h> // wait()
#include <stdlib.h>   // exit()
#include <stdbool.h>  // bool
#include <stdio.h>    // perror()
#include <errno.h>    // perror()
#include <unistd.h>   // exelc()

void Parent(int pid);

void Child();

int main()
{
    printf("\n\n\tTest primitives de recouvrement\n\n\n");
    printf("Ce programme sera remplacé par 'ls -l'.\n");
    printf("\n---------------------------------------------------------------------------\n");
    // PID du processus
    int pid;
    pid = fork();
    if (pid == -1)
    { // fork() a rencontré une erreur
        perror("Erreur lors du clonage du programme.\n\n");
        exit(EXIT_FAILURE);
    }
    if (pid)
    { // Le processus est parent
        Parent(pid);
    }
    if (pid == 0)
    { // Le processus est enfant
        Child();
    }
    perror("Erreur inconnue.\n\n");
    exit(EXIT_FAILURE);
}

void Parent(int pid)
{
    // Conteneur du statut du fils
    int statusContainer;
    // On attend que le processus fils se termine
    waitpid(pid, &statusContainer, 0);
    printf("---------------------------------------------------------------------------\n\n");
    if (WIFEXITED(statusContainer))
    { // Le fils s'est arrêté avec un statut
        // Statut du fils
        int status;
        status = WEXITSTATUS(statusContainer);
        printf("Le processus fils s'est terminé avec le statut %d.\n\n", status);
        exit(EXIT_SUCCESS);
    }
    else
    { // Le fils s'est arrêté sans statut
        printf("Le processus fils s'est terminé sans statut.\n\n");
        exit(EXIT_SUCCESS);
    }
}

void Child()
{
    // Exécuter ls -l
    execl("/bin/ls", "ls", "-l", NULL);
}
