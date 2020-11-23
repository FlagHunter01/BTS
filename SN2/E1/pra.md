# PRA - Raspberry Pi

???+ note "MAJ le 23/11 par Tim."
	 - [X] Supprimé WiFi
		 - [X] Supprimé de l'inventaire
	 - [ ] DHCP
		 - [X] Corrigé et complété
		 - [ ] Service hautement disponible
	 - [ ] DNS
		 - [X] Corrigé et complété
		 - [ ] Service hautement disponible
	 - [X] Simplifié Vim
	 - [X] Simplifié SSH
	 - [X] Corrigé parametrage de base (`dhcpcd.conf`)
	 - [ ] Ajouté Consignes
	 - [ ] Ajouté Proxy

???- note "MAj le 22/11 par Tim."
	!!!success "Vérifié par application."
		Sauf ce qui touche au DHCP puisqu'il faut avoir un réseau isolé avec d'autres utilisateurs dessus.
	
	 - [ ] OS:
		 - [X] Remplacé le tuto Rufus par l'imager officiel de RaspberryPi
		 - [X] Précisé que formatter la carte SD et écrire l'image dessus prend beaucoup de temps
    	 - [X] Ajout de la mise à l'heure
		 - [X] Changement de l'@
	 - [ ] Parametrage de base:
		 - [X] Changement du mot de passe
		 - [X] Retiré le proxy
		 - [X] Supprimé une répétition
		 - [X] Changé l'@ dans dhcpcd
     - [X] SSH: 
		 - [X] Changé l'@
		 - [X] Changé les identifiants dans Putty
	 - [X] Web:
		 - [X] Nom d'hôte fixé
		 - [X] Applications installées
	 - [ ] DHCP: 
		 - [X] Correction des paquets à installer
		 - [X] Changé les @
		 - [ ] Correction de la configuration
	 - [X] Remplacé `aptitude` par `apt-get` dans toute la page

???- note "MAJ le 18/11 par Tim."
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

!!!question "2 - Dans T2: “Nom d’hôte fixé” et “Applications installées” et "OS conforme au cahier des charges""
	Ca veut dire quoi? Quel cahier des charges?

!!!question "3 - Dans T3: “Service hautement disponible”"
	Concrètement, ca veut dire quoi?

!!!question "4 - Combien de Raspberry Pi seront à configurer le jour de l'épreuve?"

!!!question "5 - Confirmer qu'on ne fait que le A de la feuille distribuée"

!!!question "6 - On fait le WiFi? Si oui, il va nous donner le module?"

## Consignes

!!!warning "A compléter"

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

!!!info "Les quantités indiquées sont *minimales*."

!!!warning "Vérifier l'inventaire."

!!!success "Réaliser l'inventaire du matériel"

!!!fail "gestion numérique des documents"
	Consigne mal comprise.

!!!fail "Gestion numérique des documents"

## Préparation du Pi

### OS

!!!warning "Gestion du temps"
	Attention, formatter et écrire l'image sur la carte SD peut prendre plus d'une heure.

 - Télécharger l'[imager de Raspberry Pi officiel](https://downloads.raspberrypi.org/imager/imager_1.4.exe). 
 - Insérer la carte SD dans l'ordinateur grâce à l'adaptateur SD - USB. 
 - Ouvrir l'imager une fois qu'il est téléchargé
     - Choisir la première image proposée dans `Choose OS`. Choisir la carte SD dans `Choose SD card`. 

!!!danger "Vérifier que c'est le bon périférique!"
    Si le disque dur du PC est sélectionné, il sera détruit.

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
919294
919294
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
 - Ensuite ```1. Change user password``` pour entrer un mot de passe plus sur (`919294`)
 - Ensuite ```3. boot options``` 
	 - Choisir ```desktop with login``` pour avoir une interface graphique et demander un mdp.
 - Sortir du menu. Une fois cette opération terminée, ==**redémarrer le Pi**==.
 - Options réseau dans```2. Net options```:
	 - "N1 Hostname": ```raspberrypiapc1```. 
	 - Sortir du menu.

Par défaut, le Pi tente d'obtenir une adresse IP par DHCP. Puisqu'il nous faut une adresse IP fixe, il faut faire une configuration manuelle. 

!!!info "On part du principe que le Pi est isolé du réseau du lycée et se comportera comme serveur DHCP."

Remplacer le contenu de `/etc/dhcpcd.conf` par ce qui suit:

```
# A sample configuration for dhcpcd.
# See dhcpcd.conf(5) for details.

# Allow users of this group to interact with dhcpcd via the control socket.
#controlgroup wheel

# Inform the DHCP server of our hostname for DDNS.
hostname raspberrypiapc1

# Use the hardware address of the interface for the Client ID.
clientid
# or
# Use the same DUID + IAID as set in DHCPv6 for DHCPv4 ClientID as per RFC4361.
# Some non-RFC compliant DHCP servers do not reply with this set.
# In this case, comment out duid and enable clientid above.
#duid

# Persist interface configuration when dhcpcd exits.
persistent

# Rapid commit support.
# Safe to enable by default because it requires the equivalent option set
# on the server to actually work.
option rapid_commit

# A list of options to request from the DHCP server.
#option domain_name_servers, domain_name, domain_search, host_name
#option classless_static_routes
# Respect the network MTU. This is applied to DHCP routes.
option interface_mtu

# Most distributions have NTP support.
#option ntp_servers

# A ServerID is required by RFC2131.
require dhcp_server_identifier

# Generate SLAAC address using the Hardware Address of the interface
#slaac hwaddr
# OR generate Stable Private IPv6 Addresses based from the DUID
slaac private

# Static IP configuration:
interface eth0
static ip_address=172.20.181.1/24
#static ip6_address=fd51:42f8:caae:d92e::ff/64
static routers=172.20.181.254
#static domain_name_servers=192.168.0.1 8.8.8.8 fd51:42f8:caae:d92e::1

# It is possible to fall back to a static IP if DHCP fails:
# define static profile
#profile static_eth0
#static ip_address=192.168.1.23/24
#static routers=192.168.1.1
#static domain_name_servers=192.168.1.1

# fallback to static profile on eth0
#interface eth0
#fallback static_eth0
```

Redémarrer le Raspberry Pi.
Une fois connecté, vérifier que le Pi a la bonne adresse (`172.20.181.1`):

```
$ ip a
```

!!!success "T2: Configuration IP"

Le Raspberry Pi doit mettre son horloge à l'heure quand il se connecte au réseau, mais celui du lycée n'a pas de serveur NTP. 

Dans `/etc/systemd/timesyncd.conf`, remplacer la ligne 15 par:

```
NTP=172.20.81.252
```

Il faut mettre à jour les paquets installés avant de continuer:

```
# apt-get update
# apt-get upgrade
Y
```

!!!warning "Cette opération prend beaucoup de temps"

### Vim

Installer ```Vim```, le meilleur logiciel de traitement de texte:

```
# apt-get install vim
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

Remplacer le contenu du fichier par ce qui suit:

```
" All system-wide defaults are set in $VIMRUNTIME/debian.vim and sourced by
" the call to :runtime you can find below.  If you wish to change any of those
" settings, you should do it in this file (/etc/vim/vimrc), since debian.vim
" will be overwritten everytime an upgrade of the vim packages is performed.
" It is recommended to make changes after sourcing debian.vim since it alters
" the value of the 'compatible' option.

"colorscheme
"colorscheme darkblue
"colorscheme default
"colorscheme delek
"colorscheme desert
"colorscheme elflord
"colorscheme evening
"colorscheme koehler
"colorscheme morning
"colorscheme murphy
"colorscheme pablo
"colorscheme peachpuff
"colorscheme ron
"colorscheme shine
"colorscheme slate
colorscheme torte
"colorscheme zellner

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
runtime! debian.vim

" Vim will load $VIMRUNTIME/defaults.vim if the user does not have a vimrc.
" This happens after /etc/vim/vimrc(.local) are loaded, so it will override
" any settings in these files.
" If you don't want that to happen, uncomment the below line to prevent
" defaults.vim from being loaded.
let g:skip_defaults_vim = 1

" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes numerous
" options, so any other options should be set AFTER setting 'compatible'.
"set compatible

" Vim5 and later versions support syntax highlighting. Uncommenting the next
" line enables syntax highlighting by default.
syntax on

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
set background=dark

" Uncomment the following to have Vim jump to the last position when
" reopening a file
au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif

" Uncomment the following to have Vim load indentation rules and plugins
" according to the detected filetype.
"filetype plugin indent on

" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.
set showcmd             " Show (partial) command in status line.
set showmatch           " Show matching brackets.
set ignorecase          " Do case insensitive matching
set smartcase           " Do smart case matching
set incsearch           " Incremental search
"set autowrite          " Automatically save before commands like :next and :make
"set hidden             " Hide buffers when they are abandoned
set mouse=a             " Enable mouse usage (all modes)

" Source a global configuration file if available
if filereadable("/etc/vim/vimrc.local")
source /etc/vim/vimrc.local
endif

set smartindent
set nu
```

### Bash

Le paramétrage du terminal se fait dans ```.bashrc``` dans le répertoire de l'utilisateur dont on configure le terminal. 

Remplacer son contenu par ce qui suit:

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
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\0                                                                                                                                                             33[01;34m\]\w\[\033[00m\]\$ '
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
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dirco                                                                                                                                                             lors -b)"
    alias ls='ls --color=auto'
    alias dir='dir --color=auto'
    alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi

# colored GCC warnings and errors
export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quo                                                                                                                                                             te=01'

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
```

### Firewall

Avant d'exposer la machine en ligne, il faut la protéger avec un pare feu. 

Si ```iptables``` est installé par défaut, il faut le désisntaller car il est obsolète:

```
# apt-get purge iptables
```

Par la suite, installer ```nftables```:

```
# apt-get install nftables
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

Remplacer le contenu de ```/etc/nftables.conf``` par ce qui suit:

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

    chain SSH {
        ip saddr 192.168.8.0/24 accept
        drop
    }
}

```
Déterminer l'adresse du Raspberry Pi avec:

```
$ ip a
```
Coté client, télécharger [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html).

Dans putty, entrer cette adresse et appuyer sur "Open". Entrer ensuite les identifiants choisis lors de la configuration:

```
pi
919294
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

## Web

!!!quote "T2"
	 - [X] Carte SD reformatée
	 - [ ] OS conforme au cahier des charges
	 - [X] Nom d'hôte fixé
	 - [X] Configuration IP
	 - [ ] Applications installées

Nous allons utiliser Apache pour mettre en ligne une sauvegarde du site de APC.

```
# apt-get install apache2
```
!!!success "Applications installées"

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
# apt-get install isc-dhcp-server
# apt-get install isc-dhcp-server-ldap
```

Remplacer le contenu de `/etc/dhcp/dhcpd.conf` par ce qui suit:

```
# dhcpd.conf
#
# Sample configuration file for ISC dhcpd
#

# option definitions common to all supported networks...
option domain-name "apc.com";
option domain-name-servers 172.20.181.1, 172.20.181.2; 

default-lease-time 600;
max-lease-time 3600;

# The ddns-updates-style parameter controls whether or not the server will
# attempt to do a DNS update when a lease is confirmed. We default to the
# behavior of the version 2 packages ('none', since DHCP v2 didn't
# have support for DDNS.)
ddns-update-style none;

# If this DHCP server is the official DHCP server for the local
# network, the authoritative directive should be uncommented.
authoritative;

# Use this to send dhcp log messages to a different log file (you also
# have to hack syslog.conf to complete the redirection).
#log-facility local7;

# No service will be given on this subnet, but declaring it helps the
# DHCP server to understand the network topology.

#subnet 10.152.187.0 netmask 255.255.255.0 {
#}

# This is a very basic subnet declaration.

#subnet 10.254.239.0 netmask 255.255.255.224 {
#  range 10.254.239.10 10.254.239.20;
#  option routers rtr-239-0-1.example.org, rtr-239-0-2.example.org;
#}

# This declaration allows BOOTP clients to get dynamic addresses,
# which we don't really recommend.

#subnet 10.254.239.32 netmask 255.255.255.224 {
#  range dynamic-bootp 10.254.239.40 10.254.239.60;
#  option broadcast-address 10.254.239.31;
#  option routers rtr-239-32-1.example.org;
#}

# A slightly different configuration for an internal subnet.
subnet 172.20.181.0 netmask 255.255.255.0 {
  range 172.20.181.10 172.20.181.253;
  option domain-name-servers 172.20.181.1 172.20.181.2;
  option domain-name "apc.com";
  option routers 172.20.181.254;
  option broadcast-address 172.20.181.255;
  default-lease-time 600;
  max-lease-time 3600;
}

# Hosts which require special configuration options can be listed in
# host statements.   If no address is specified, the address will be
# allocated dynamically (if possible), but the host-specific information
# will still come from the host declaration.

#host passacaglia {
#  hardware ethernet 0:0:c0:5d:bd:95;
#  filename "vmunix.passacaglia";
#  server-name "toccata.example.com";
#}

# Fixed IP addresses can also be specified for hosts.   These addresses
# should not also be listed as being available for dynamic assignment.
# Hosts for which fixed IP addresses have been specified can boot using
# BOOTP or DHCP.   Hosts for which no fixed address is specified can only
# be booted with DHCP, unless there is an address range on the subnet
# to which a BOOTP client is connected which has the dynamic-bootp flag
# set.
#host fantasia {
#  hardware ethernet 08:00:07:26:c0:a5;
#  fixed-address fantasia.example.com;
#}

# You can declare a class of clients and then do address allocation
# based on that.   The example below shows a case where all clients
# in a certain class get addresses on the 10.17.224/24 subnet, and all
# other clients get addresses on the 10.0.29/24 subnet.

#class "foo" {
#  match if substring (option vendor-class-identifier, 0, 4) = "SUNW";
#}

#shared-network 224-29 {
#  subnet 10.17.224.0 netmask 255.255.255.0 {
#    option routers rtr-224.example.org;
#  }
#  subnet 10.0.29.0 netmask 255.255.255.0 {
#    option routers rtr-29.example.org;
#  }
#  pool {
#    allow members of "foo";
#    range 10.17.224.10 10.17.224.250;
#  }
#  pool {
#    deny members of "foo";
#    range 10.0.29.10 10.0.29.230;
#  }
#}
```

!!!warning "8.8.8.8"
	Si on a plusieurs Pi, en mettre un comme ns2. Ca ne marchera sans doute pas avec `8.8.8.8`.

Redémarrer le démon et vérifier qu'il fonctionne correctement:

```bash
# systemctl restart dhcpd.service
# systemctl status dhcpd.service
```

!!!success "Service DHCP opérationnel: bail correctement délivré avec bonnes valeurs d'étendues"

???- note "Ignorer, sera bientôt supprimé"
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

```
# apt-get install bind9
```

Remplacer le contenu du fichier `/etc/bind/named.conf.local` par ce qui suit:

```
//
// Do any local configuration here
//

zone "apc.com" {
        type master;
        file "/etc/bind/db.apc.com";
};

// Consider adding the 1918 zones here, if they are not used in your
// organization
include "/etc/bind/zones.rfc1918";
```

Créer le fichier `/etc/bind/db.apc.com`. Y mettre le contenu suivant:
```
$ORIGIN .
$TTL    1D
apc.com.       IN      SOA     ns.apc.com. admin.apc.com.  (
                                        1               ; Serial
                                        1h              ; Refresh
                                        1h              ; Retry
                                        2h              ; Expire
                                        1h              ; Minimum
)

        A               172.20.181.1

        NS              ns.apc.com.
        NS              ns2.apc.com.

$ORIGIN apc.com.

ns                 A           172.20.181.1
ns2                A           172.20.181.2
www                CNAME       apc.com.
; EOF
```

Créer le fichier `/etc/bind/db.apc.com.inv`. Y mettre le contenu suivant:

!!!warning "Le contenu est du BS pour l'instant."

```
$ORIGIN .
$TTL    1D
apc.com.       IN      SOA     ns.apc.com. admin.apc.com.  (
                                        1               ; Serial
                                        1h              ; Refresh
                                        1h              ; Retry
                                        2h              ; Expire
                                        1h              ; Minimum
)

        A               apc.com (?)

        NS              172.20.181.1
        NS              172.20.181.2

$ORIGIN apc.com.

ns                 A           ns.apc.com
ns2                A           ns2.apc.com
www                CNAME       172.20.181.0
; EOF
```

Redémarrer Bind et vérifier son bon fonctionnement:
```
# systemctl restart bind9
# systemctl status bind9
```

!!!success "Alias"
!!!success "Résolution directe"
!!!success "Résolution inversée"

!!!warning "Compléter pour le NS secondaire"

!!!fail "Service hautement disponible"

## Proxy

!!!warning "A compléter"

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
