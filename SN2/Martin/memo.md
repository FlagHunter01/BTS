## Réseaux

### Procédure de test réseau

 - `ifconfig`
 - ping une URL
 - ping 8.8.8.8
 - ping du serveur
 - ping de la passerelle
 - ping adresse locale

```
ifconfig
ping example.com
ping 8.8.8.8
ping 172.23.0.1:3128
ping 172.16.128.254
ping ?
```

### Configuration réseau

```
# /etc/init.d/network-manager stop
# nano /etc/network/interfaces

auto eth0
iface lo inet loopback

iface eth0 inet static
    address 172.16.135.(100+x)   
    netmask 255.255.240.0
    network  172.16.128.0
    gateway 172.16.128.254

# nano /etc/apt/apt.conf

Acquire::http::Proxy "http://172.23.0.1:3128";

# /etc/init.d/networking stop
# /etc/init.d/networking start
```
## Programmation multitâche

### Fonctions utiles

```c
#include <unistd.h>

pid_t fork(void);
```

`fork()` duplique le processus. La seule chose qu'il ne duplique pas est sa valeur, qui prend:

 - `-1` s'il a échoué, 
 - `<PID du fils>` s'il renvoie sa valeur au processus père,
 - `0` s'il renvoie la valeur au fils. 

```c
#include <stdlib.h>

void exit(int status);
```

`exit(status)` permet de teminer un processus avec un message de fin renvoyé au système. Par convention, ce message est soit `EXIT_SUCCESS`soit `EXIT_FAILURE `. 

```c
#include <sys/types.h>
#include <sys/wait.h>

int status;

pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, 0); 
```

`wait(&status)` attend que le premier processus fils se termine et enregistre son statut (dans un format bizarre). 

`waitpid(pid, &status, NULL)` attend qu'un processus particulier se termine et enregistre son statut. A priori, c'est toujours lui qu'on doit utiliser. 

```c
#include <sys/types.h>
#include <sys/wait.h>

bool WIFEXITED(status)
```

`WIFEXITED(status)` renvoie `true` si le fils s'est terminé par un `exit()`, et renvoie `false`dands le cas contraire. 

```c
#include <sys/types.h>
#include <sys/wait.h>

int WEXITSTATUS(status)
```

`WEXITSTATUS(status)` renvoie la valeur que le fils a donné à `exit()` ou l'argument d'une commande de retour dans `main()`. 
