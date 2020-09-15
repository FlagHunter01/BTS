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
