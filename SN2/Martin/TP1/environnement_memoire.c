#include <sys/wait.h> // wait()
#include <stdlib.h>   // exit()
#include <stdbool.h>  // bool
#include <stdio.h>    // perror()
#include <errno.h>    // perror()
#include <unistd.h>   // exelc()

void Parent(int pid, int z);

void Child(int z);

int main()
{
    printf("\n\n\tTest d'une variable commune\n\n\n");
    // PID du processus
    int pid;
    // Variable "commune" à incrémenter
    int z = 0;
    pid = fork();
    if (pid == -1)
    { // fork() a rencontré une erreur
        perror("Erreur lors du clonage du processus.\n\n");
        exit(EXIT_FAILURE);
    }
    if (pid)
    { // Le processus est parent
        Parent(pid, z);
    }
    if (pid == 0)
    { // Le processus est enfant
        Child(z);
    }
    perror("Erreur inconnue.\n\n");
    exit(EXIT_FAILURE);
}

void Parent(int pid, int z)
{
    // Conteneur du statut du fils
    int statusContainer;
    // Déphasage avec le fils
    usleep(500000);
    for (int i = 0; i < 10; i++)
    {
        z += 1000;
        printf("Parent: %d\n", i);
        usleep(1000000);
    }
    // On attend que le processus fils se termine
    waitpid(pid, &statusContainer, 0);
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

void Child(int z)
{
    for (int i = 0; i < 10; i++)
    {
        z++;
        printf("\tEnfant: %d\n", i);
        usleep(1000000);
    }
    exit(EXIT_SUCCESS);
}
