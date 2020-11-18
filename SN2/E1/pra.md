# PRA - Raspberry Pi

!!!danger "Obsolescence"
    Cette page a été relue mais pas vérifiée par la pratique.

???+ info "Prochaine MAj prévue le 19/11"
	 - Nouvelles corrections prenant en compte le cahier des charges
	 - Complétion de certains chapitres
		 - Inventaire
		 - WiFi
		 - Web
		 - DHCP
		 - DNS
	 - Ajout d'autres consignes en fonction du cahier des charges (?)
	 - Les parties B et C du poly auront probablement chacun sa page

???+note "MAJ le 18/11 par Tim."
	!!!danger "Fait sans connaissance du cahier des charges"

	 - [X] Créé "Questions pour le prof"
	 - [ ] Corrections pour s'adapter au nouveau sujet
	 	 - [X] Ajout des consignes dans chaque chapitre
		 - [ ] Materiel > Inventaire
			 - [X] Inventaire
			 - [ ] Gestion numérique des documents
		 - [ ] Installation de l'OS > Préparation du Pi
			 - [X] OS
			 - [X] Paramétrage de base
			 - [X] Vim
			 - [X] Bash
			 - [X] SSH
			 - [ ] WiFi 
		 - [ ] Apache > Web
		 - [ ] DHCP
		 - [X] Important > Pièges (?)
	 - [ ] DNS

!!!note "(Re)mis en ligne le 13/11."

!!!tip "Il y a un bouton pour copier en haut à droite des cases de code, mais il est noir sur noir."

!!!tip "Commandes"
	Les commandes sont en noir et prennent toute la largeur
	```
	(Comme ca)
	```
	Elles commencent par `#` si elles doivent être exécutées en root, sinon `$`.

## Questions pour le prof

[Version la plus à jour sur Google Drive](https://docs.google.com/document/d/1aQBZPgJlJ4PjMPPeGDiXHZ35Th1j_xfLXR6E7vqa2oU/edit?usp=sharing)

!!!question "1 - T1: Gestion du patrimoine informatique: Réaliser l'inventaire du matériel et gestion numérique des documents."
	C’est quoi la gestion numérique des documents?

!!!question "2 - Dans T2: “Nom d’hôte fixé” et “Applications installées”"
!!!question "3 - Dans T3: “Service hautement disponible”"



## Inventaire

!!!quote "T1"
	Gestion du patrimoine informatiqe: Réaliser l'inventaire du matériel et gestion numérique des documents.

| Quantité | Description |
| --- | --- |
| 1 | Raspberry Pi |
| 1 | Chargeur |
| 1 | Carte SD de 8Go|
| 1 | Adaptateur SIM - USB|
| 1 | Ecran avec câble HDMI |
| 1 | Clavier |
| 1 | Souris |
| 3 | Cable Ethernet |
| 1 | Switch |
| (?) | Module WiFi |

!!!info "Les quantités indiquées sont *minimales*."

!!!warning "Vérifier l'inventaire."

!!!success "Réaliser l'inventaire du matériel"

!!!fail "gestion numérique des documents"
	Consigne mal comprise.

!!!fail "Gestion numérique des documents"

## Préparation du Pi

!!!danger "Théoriquement bon, pas vérifié en pratique depuis l'année dernière."

### OS

Télécharger une image de la [dernière version de Raspbian](https://www.raspberrypi.org/downloads/raspbian/) **avec le desktop mais sans les soft recommandés**.

Insérer la carte SD dans l'ordi à l'aide de l'adaptateur puis utiliser [Rufus](https://rufus.ie/) pour écrire l'image sur la carte SD

!!!danger "Ecriture d'images"
	Tout le contenu du périphérique de stockage est **perdu** lors de cette opération. Etape a faire avec **précaution**.

!!!success "T2: Carte SD reformatée"

A présent, insérer la carte SD dans le Pi et effectuer tous les branchements en connectant l'alimentation **en dernier**. Une fois l'alim connectée, le Pi va booter. Il n'enverra pas d'image sur l'écran immédiatement mais des led devraient s'allumer. Après un certain temps, des infos sur le chargement devraient apparaître à l'écran. Si des erreurs apparaissent, il faut probablement réinstaller le système.

Si le Pi demande de s'identifier:

```
login: pi
passwd: raspberry
```

???+tip "Clavier"
    Par défaut, le layout du clavier est en **anglais**.
    
	!!!warning "Image à ajouter"
    	![layout](/img/layout.png)

### Parametrage de base
    
On travaillera principalement dans le terminal. `root` n'est pas accessible car il n'a pas de mot de passe. Il faut donc créer un mot de passe administrateur pour pouvoir se connecter en ```root```:

```
$ sudo passwd root
abc123
abc123
```

On pourra ensuite se connecter en ```root``` quand nécessaire.

Ensuite, pour accéder aux paramétrages de base:

```
# raspi-config
```

1. Commencer par ```4. Localisation options``` pour mettre le layout francais. 
	 - Aller dans ```keyboard layout``` puis choisir le modèle le plus proche. 
	 - Ensuite, pour le keyboard layout, sélectionner ```Other``` puis ```French - French ```. 
	 - Pour "Key to function as AltGr, choisir ```The default for the keyboard layout``` puis choisir ```No compose key```. 
	 - Choisir ```No``` pour "Use Control+Alt+Backspace to terminate the X server?". 
	 - Normalement après confirmation le layout du clavier devient francais.
 - Ensuite ```1. Change user password``` pour entrer un mot de passe plus sur (à communiquer aux employés) [J'ai mis ```abc123```]
 - Ensuite ```3. boot options``` 
	 - Choisir ```desktop with login``` pour avoir une interface graphique et demander un mdp.
 - Sortir du menu. Une fois cette opération terminée, ==**redémarrer le Pi**==.
 - Options réseau
	 - ```2. Net options``` pour le proxy. 
	 - "N1 Hostname": ```raspberrypiapc1```. 
	 - Sortir du menu.

Par défaut, le Pi tente d'obtenir une adresse IP par DHCP. Puisqu'il nous faut une adresse IP fixe, il faut faire une configuration manuelle. 

???-note "Configuration avec `/etc/dhcpd.conf`"

	Modifier le fichier ```/etc/dhcpcd.conf```:
	
	```
	# nano /etc/dhcpcd.conf
	```

	Descendre jusqu'à trouver le passage ci-dessous: 

	```bash
	# Example static IP configuration:
	#interface eth0
	#static ip_adress=192.168.0.10/24
	#static ip6_adress=fd51:42f8:caae:d92e::ff/64
	#static routers=192.168.0.1
	#static domain_name_servers=192.168.0.1 8.8.8.8 fd51:42f8:caae:d92e::1
	```

	Le remplacer par ce qui suit:

	```bash
	# Static IP configuration:
	interface eth0
	static ip_adress=172.16.130.2/24
	static routers=172.16.130.1
	static domain_name_servers=172.16.130.1 8.8.8.8
	```

???+note "Configuration "normale""

	!!!warning "Cette section doit être complétée"

Une fois les données saisies, vérifier que le Pi a la bonne adresse:

```
$ ip a
```

!!!success "T2: Configuration IP"

Il faut mettre à jour les paquets installés avant de continuer. Je préfère le gestionnaire de paquets ```aptitude``` car il permet de **purger** les fichiers des paquets supprimés.

```
# apt-get install aptitude
Y
# aptitude update
# aptitude upgrade
Y
```

!!!info "Un redémarrage sera peut-être demandé"

### Vim

Installer ```Vim```, le meilleur logiciel de traitement de texte:

```
# aptitude install vim
Y
```

???+tip "Utilisation"
	 - `i` pour passer en mode édition
	 - `ESC` pour passer en mode commande
	 - `:x` pour sauvegarder et quitter
	 - `:w` pour sauvegarder sans quitter
	 - `:q!` pour quitter sans sauvegarder
	 - Garder `d` enfoncé pour supprimer ligne par ligne
	 - `U` remplace `CTRL`+`Z`.

Configuration:

```
vim /etc/vim/vimrc
```

**Décommenter** les lignes suivantes:

```bash
syntax on
```
```bash
set background=dark
```
La ligne ==suivant==

```bash
Uncomment the following to have Vim jump to the last position ...
```
```bash
filetype plugin indent on
```
Les lignes ==qui suivent==

```bash
The following are commented out as they cause vim ... (tous les set qui suivent)
```
==Ajouter==

```bash
set nu
```

### Bash

Le paramétrage du terminal se fait dans ```.bashrc``` dans le répertoire de l'utilisateur dont on configure le terminal. L'ouvrir avec Vim:

```
vim .bashrc
```

Ensuite, coller ca:

```bash
# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
case $- in
    *i*) ;;
      *) return;;
esac

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# If set, the pattern "**" used in a pathname expansion context will
# match all files and zero or more directories and subdirectories.
#shopt -s globstar

# make less more friendly for non-text input files, see lesspipe(1)
#[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm-color|*-256color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
# off by default to not distract the user: the focus in a terminal window
# should be on the output of commands, not on the prompt
force_color_prompt=yes

if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
        # We have color support; assume it's compliant with Ecma-48
        # (ISO/IEC-6429). (Lack of such support is extremely rare, and such
        # a case would tend to support setf rather than setaf.)
        color_prompt=yes
    else
        color_prompt=
    fi
fi

if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    alias dir='dir --color=auto'
    alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi

# colored GCC warnings and errors
export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# some more ls aliases
alias ll='ls -l'
alias la='ls -A'
alias l='ls -CF'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi

set nu
```

### Firewall

Avant d'exposer la machine en ligne, il faut la protéger avec un pare feu. 

Si ```iptables``` est installé par défaut, il faut le désisntaller car il est obsolète:

```
# aptitude purge iptables
```

Par la suite, installer ```nftables```:

```
# aptitude install nftables
```

La configuration de ```nftables``` se fait dans le fichier ```/etc/nftables.conf```. L'ouvrir avec ```vim```. On doit y trouver ce qui suit:

```bash
#!/usr/sbin/nft -f

flush ruleset

table inet filter {
        chain input {
                type filter hook input priority 0;
        }
        chain forward {
                type filter hook forward priority 0;
        }
        chain output {
                type filter hook output priority 0;
        }
}

```

Y coller ca:

```bash
#!/usr/sbin/nft -f

flush ruleset

table inet filter {
	chain input {
		type filter hook input priority 0; policy drop
		# Accepter les connections etablies
		ct state {established, related} accept
		# Accepter les loopbacks
		iif lo accept
		# Toutes les autres connections sont drop
	}

	chain forward {
		type filter hook forward priority 0; policy drop;
		# On ne transmet aucune connection
	}

	chain output {
		type filter hook output priority 0; policy accept;
		# On autorise toutes les sorties
	}

}
```


Redémarer le démon (*daemon* pour les puristes) du firewall:

```
# systemctl restart nftables
```

Vérifier que le démon (*daemon* pour les puristes) se porte bien:

```
# systemctl status nftables
```

??? tip "Démons"
	Le principe c'est que tu as beaucoup de démons qui tournent dans ta machine et qu'ils sont contrôlés par le watch dog (*ca explique le titre du jeu*). "Démon" est donc un abus de langage logique :p

### SSH

Autoriser les connections SSH:

```
# raspi-config
5 Interfacing Options
P2 SSH
YES
```

Dans ```/etc/nftables.conf```, ajouter ce qui suit à la chaine input:

```bash
                # Envoyer les connections SSH sur la chaine SSH
                tcp dport 22 jump SSH
```

et créer la chaine SSH à la suite des autres chaines:

```bash

        chain SSH {
                # Accepter les co depuis le reseau local
                ip saddr 172.16.130.0/24 accept
                # Drop tout le reste
                drop
        }

```
Déterminer l'adresse avec

```
$ ip a
```
Coté client, télécharger [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html).

Dans putty, entrer cette adresse et appuyer sur "Open". Entrer ensuite les identifiants choisis lors de la configuration:

```
pi
abc123
```

???- tip "Toi qui a lu jusque là"
	Bravo, t'a su tenir jusque la. En récompense, humour informatique:

	Les versions de Debian sont nommées d'après les personnages de Toy Story:

	| Version | Nom |
	| -- | --|
	| 1.1 | Buzz |
	| 1.2 | Rex |
	| 1.3 | Bo |
	| 2.0 | Hamm |
	| 2.1 | Slink |
	| 2.2 | Potato |
	| 3.0 | Woodi |
	| ... | ...|
	| 10 | Buster |

### WiFi

!!!fail "Le matériel requis était indisponible"

!!!question "Il faut toujours le faire? Il en parle pas dans les consignes"

## Web

!!!quote "T2"
	 - [X] Carte SD reformatée
	 - [ ] OS conforme au cahier des charges
	 - [ ] Nom d'hôte fixé
	 - [X] Configuration IP
	 - [ ] Applications installées

Nous allons utiliser Apache pour mettre en ligne une sauvegarde du site de APC.

```
# aptitude install apache2
```

Mettre la sauvegarde du site dans `/var/www/html/`.

Autoriser le traffic sur le port HTTP. Ajouter ce qui suit à la chaine ```input``` dans ```/etc/nftables.conf```:

```bash
                # Accepter HTTP
                tcp dport 80 accept
                # Accepter HTTPS
                #tcp dport 443 accept
```

???- info "Le fichier complet devrait alors ressembler à ca"
	```bash
	#!/usr/sbin/nft -f

	flush ruleset

	table inet filter {
		chain input {
			type filter hook input priority 0; policy drop	
			# Accepter les connections etablies
			ct state {established, related} accept
			# Accepter les loopbacks
			iif lo accept
			# Envoyer les connections SSH sur la chaine SSH
			tcp dport 22 jump SSH
			# Accepter HTTP
			tcp dport 80 accept
			# Accepter HTTPS
			#tcp dport 443 accept
			# Toutes les autres co sont drop
		}

		chain forward {
			type filter hook forward priority 0; policy drop;
			# On ne transmet aucune connection
		}

		chain output {
			type filter hook output priority 0; policy accept;
			# On autorise toutes les sorties
		}

		chain SSH {
			# Accepter les co depuis le reseau local
			ip saddr 172.16.130.0/24 accept
			# Drop tout le reste
			drop
		}
	}
	```

Vérifier que le site est accessible en entrant l'adresse du Pi dans un navigateur. 

!!!fail "Os conforme au cahier des charges"
!!!fail "Nom d'hôte fixé"
!!!fail "Applications installées"

## DHCP

!!!quote "T3"
	 - Service DHCP opérationnel: bail correctement délivré avec bonnes valeurs d'étendues
	 - Service autement disponible

Installer ISC:

```bash
# aptitude install isc-dhcp-server
```

Configuration dans `/etc/dhcp/dhcpd/dhcpd.conf`:

!!!warning "Section a vérifier"

```bash
# Nome du domaine
option domain-name "apc.com";

# DNS. Il faut configurer bind sur cette machine.
option domain-name-servers 8.8.8.8, 172.16.130.1;

# Definition du domaine d'attribution
subnet 172.16.130.0 netmask 255.255.255.0 {
	range 172.16.130.2 172.16.130.254;
	option subnet-mask 255.255.255.0;
	option broadcast-address 172.16.130.255;
	option routers 172.16.130.1;
}

# Indication d'autorité pour le réseau
authoritative;

# Adresse fixe pour PC1
host PC1 {
	hardware ethernet [adresse matérielle];
	fixed-address 172.16.130.2;
}
```

Interfaces dans `/etc/network/interfaces`

!!!warning "Section a vérifier"

```bash
# L'interface réseau « loopback » (toujours requise)
auto lo
iface lo inet loopback

# Assigner une adresse IP statique pour ce serveur DHCP avec eth0 :
auto eth0
iface eth0 inet static
    address 172.16.130.1
    netmask 255.255.255.0
    broadcast 172.16.130.255
    gateway 172.16.130.1
# Pas sur pour la derniere ligne
```

Redémarrer le démon et vérifier qu'il fonctionne correctement:

```bash
# systemctl restart dhcpd.service
# systemctl status dhcpd.service
```

!!!success "Service DHCP opérationnel"

Sur les clients dans `/etc/network/interfaces`:

```bash
# L'interface réseau « loopback » (toujours requise)
auto lo
iface lo inet loopback

# Obtenir l'adresse IP de n'importe quel serveur DHCP
auto eth0
iface eth0 inet dhcp
```

!!!fail "Service autement disponible"

## DNS

!!!quote "T4"
	 - Alias
	 - Résolution directe
	 - Résolution inversée
	 - Service hautement disponible

!!!warning "A compléter"

!!!fail "Alias"
!!!fail "Résolution directe"
!!!fail "Résolution inversée"
!!!fail "Service hautement disponible"

## Pièges (?)

!!!warning "Ces infos datent de l'année dernière"
	Le prof n'a pas remis ses infos, mais je pense qu'elles sont toujours d'actu ...

???+ danger "Il y a plusieurs pièges dans cette activité"
	!!!warning "1. Câbles défectueux (un des fils est cassé et non visible) (couche 1)"
	!!!warning "2. L'accès Wifi défectueux et/ou non connecté (couche 1)"
	!!!warning "3. Erreurs dans l'association entre l'adresse MAC et l'adresse IP (couche 2)"
	!!!warning "4. Erreurs dans la table de routage (couche 3)"
	!!!warning "5. Des problèmes liés à l’existence d’un serveur Proxy-cache http et / ou un firewall (Couche 7)"
	!!!warning "6. Des problèmes liés à l’existence des Vlan (couche 2) et / ou des commutateurs (Couche 2 et 3)"
