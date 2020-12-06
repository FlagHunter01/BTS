# PRA - Raspberry Pi

???+ note "MAJ le 06/12/2020 par Tim"
     - [X] Corrigé la configuration du DNS inverse
     - [X] Ajouté en annotation la configuration des logs sur Bind
     - [X] Supprimé configurations relatives à nftables
     - [X] Apporté des précisions pour Téléchargements
     - [X] WiFi
         - [X] Déplacé WiFi vers Web
         - [X] Complété WiFi
     - [X] MAJ l'image du sujet
     - [X] Changé de place DNS

???- note "MAJ le 03/12/2020 par Tim"
    !!!info "Configuration recommancée sur matériel personnel"
     - [X] Web
         - [X] Ajouté redémarrage du service nftables à la fin
     - [X] DNS
         - [X] Corrigé la configuration
         - [X] Corrigé la configuration inversée
         - [X] Ecrit la configuration du NS secondaire
     - [X] Proxy
     - [X] Créé Problèmes
     - [X] Modifié Pièges
     - [X] Supprimé Firewall
     - [X] Adopté une structure plus logique pour le site
     - [X] Modifications pour prendre en compte le sujet qui a leak

???- note "MAJ le 25/11/2020 par Tim"
	 - [X] Orthographe
	 - [X] Relecture
     - [ ] Ajouté WiFi

???- note "MAJ le 24/11/2020 par Tim et Aline"
     - [X] Corrigé DHCP
     - [X] Complété DNS
     - [X] Autres corrections mineures
     - [X] Enlevé la configuration réseau du Paramétrage de base pour la déplacer dans DHCP
     - [X] Créé Téléchargements
     - [X] Amélioré la lisibilité et enlevé des explications (ceci est un tutoriel et non une doc)
     - [X] Aline a fini Consignes (je faisais la vaisselle)
     - [X] Vérifié les consignes
 
???- note "MAJ le 23/11/2020 par Tim"
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
 
???- note "MAj le 22/11/2020 par Tim"
    !!!success "Vérifié par application."
        Sauf ce qui touche au DHCP puisqu'il faut avoir un réseau isolé avec d'autres utilisateurs dessus.
    
     - [ ] OS:
         - [X] Remplacé le tuto Rufus par l'imager officiel de Raspberry Pi
         - [X] Précisé que formatter la carte SD et écrire l'image dessus prend beaucoup de temps
         - [X] Ajout de la mise à l'heure
         - [X] Changement de l'@
     - [ ] Paramétrage de base:
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
 
???- note "MAJ le 18/11/2020 par Tim"
    !!!danger "Fait sans connaissance du cahier des charges"
 
     - [X] Créé "Questions pour le prof"
     - [ ] Corrections pour s'adapter au nouveau sujet
         - [X] Ajout des consignes dans chaque chapitre
         - [ ] Matériel > Inventaire
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
 
!!!note "(Re)mis en ligne le 13/11/2020"
 
!!!tip "Commandes"
    Les commandes sont en noir et prennent toute la largeur
    ```
    (Comme ca)
    ```
    Elles commencent par `#` si elles doivent être exécutées en root, sinon `$`.
 
    Il y a un bouton pour copier en haut à droite des cases de code, mais il est noir sur noir.

## Informations sur l'épreuve
 
### Consignes
 
| Partie | Description |
|--- |---|
| T1 - Gestion du patrimoine informatique : Réaliser l'inventaire du matériel et gestion numérique des documents | - Fournir l'inventaire détaillé sous forme numérique (feuille tableur). |
|    | - L'ensemble des documents produits doit être accessible depuis le "cloud" (drive) | 
| T2 - Installer et configurer un serveur Web sur Raspberry Pi | Configuration conforme au cahier des charges : |
|    | - Carte SD reformatée |
|    | - OS conforme au cahier des charges |
|    | - Nom d'hôte fixé |
|    | - Configuration IP OK |
|    | - Applications installées |
| T3 - Installer et configurer un serveur DHCP sur Raspberry Pi | Configuration conforme au cahier des charges : |
|    | - Service DHCP opérationnel : bail correctement délivré avec bonnes valeurs d'étendues |
|    | - Service hautement disponible |
| T4 - Installer et configurer serveur DNS sur Raspberry Pi | Configuration conforme au cahier des charges : |
|    | - Service DNS opérationnel  Alias, résolution directe et inversée |
|    | - Service hautement disponible |

De plus, voici la leak du sujet:

![Sujet recto](/img/sujet1.jpg)

![Sujet verso](/img/sujet2.jpg)

### Problèmes

Recensement des problèmes a résoudre.

!!!fail "T1 - L'inventaire doit être accessible depuis le "cloud" (drive)"
	Nous n'avons pas compris les consignes pour cette partie (question 1).
!!!fail "T3 - OS conforme au cahier des charges"
	On n'a pas compris la consigne de cette partie (question 2).
!!!fail "T3 - Service hautement disponible"
	Nous n'avons pas compris la consigne de cette partie (question 3).
!!!warning "Vérifier l'inventaire"
!!!warning "Le fonctionnement de Proxy n'a pas été vérifié en pratique"
!!!warning "Il faut compléter WiFi"
!!!tip "Formater et écrire la carte SD prend potentiellement du temps"
	Penser a prendre un bon adaptateur et à le brancher en USB3 pour minimiser les pertes de temps.

### Questions pour le prof
 
[Version la plus à jour sur Google Drive](https://docs.google.com/document/d/1aQBZPgJlJ4PjMPPeGDiXHZ35Th1j_xfLXR6E7vqa2oU/edit?usp=sharing)
 
!!!quote "1"
    T1: Gestion du patrimoine informatique: Réaliser l'inventaire du matériel et gestion numérique des documents.
 
!!!question "Qu'est-ce qui est entendu par "gestion numérique"? De quel drive est-il question?"
 
!!!quote "2"
    T2: “Nom d’hôte fixé”, “Applications installées” et "OS conforme au cahier des charges"
 
!!!question "Confirmer que le nom d'hôte doit être fixé dans les paramètres système. Préciser les applications à installer. Référence à un cahier des charges non distribué."

### Pièges

Les problèmes suivants peuvent être rencontrés pendant l'épreuve:

1. Câbles défectueux (un des fils est cassé et non visible) (couche 1)
2. L'accès Wifi défectueux et/ou non connecté (couche 1)
3. Erreurs dans l'association entre l'adresse MAC et l'adresse IP (couche 2)
4. Erreurs dans la table de routage (couche 3)
 
## Inventaire
 
!!!quote "T1 - Gestion du patrimoine informatique : Réaliser l'inventaire du matériel et gestion numérique des documents"
     - [ ] Fournir l'inventaire détaillé sous forme numérique (feuille tableur).
     - [ ] L'ensemble des documents produits doit être accessible depuis le "cloud" (drive)
 
!!!warning "Section a vérifier"
 
| Quantité | Description |
| --- | --- |
| 1 | Raspberry Pi |
| 1 | Chargeur |
| 1 | Carte SD de 8Go|
| 1 | Adaptateur SIM - USB|
| 1 | Ecran avec câble HDMI |
| 1 | Clavier |
| 1 | Souris |
| 3 | Câble Ethernet |
| 1 | Switch |
 
!!!info "Les quantités indiquées sont *minimales*."
    Si plus de Raspberry Pi seront utilisés, il faudra compter au moins 1 chargeur et 1 carte SD pour chaque machine, ainsi que des câbles ethernet en plus.
 
!!!success "T1 - Fournir l'inventaire détaillé sous forme numérique (feuille tableur)"
 
!!!fail "T1 - L'ensemble des documents produits doit être accessible depuis le "cloud" (drive)"
    Nous n'avons pas compris les consignes pour cette partie (question 1).
 
## Préparation du Pi
 
### OS
 
!!!warning "Gestion du temps"
    Attention, formater et écrire l'image sur la carte SD peut prendre plus d'une heure.
 
 - Télécharger l'[imager de Raspberry Pi officiel](https://downloads.raspberrypi.org/imager/imager_1.4.exe). 
 - Insérer la carte SD dans l'ordinateur grâce à l'adaptateur SD - USB. 
 - Ouvrir l'imager une fois qu'il est téléchargé
     - Choisir la première image proposée dans `Choose OS`. Choisir la carte SD dans `Choose SD card`. 
 
!!!danger "Vérifier que c'est le bon périphérique!"
    Si le disque dur du PC est sélectionné, il sera détruit.
 
!!!success "T2 - Carte SD reformatée"
 
A présent, insérer la carte SD dans le Pi et effectuer tous les branchements en connectant l'alimentation **en dernier**. Une fois l'alim connectée, le Pi va booter. Il n'enverra pas d'image sur l'écran immédiatement mais des led devraient s'allumer. Après un certain temps, des infos sur le chargement devraient apparaître à l'écran. Si des erreurs apparaissent, il faut probablement réinstaller le système.
 
Si le Pi demande de s'identifier:
 
```
login: pi
passwd: raspberry
```
 
???+tip "Clavier"
    Par défaut, le layout du clavier est en **anglais**.
 
    ![layout](/img/layout.png)
 
### Paramétrage de base
 
On travaillera principalement dans le terminal. Définir un mot de passe pour `root` :
 
```
$ sudo passwd root
919294
919294
```
Ensuite, accéder aux paramétrages de base:
 
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
 
!!!success "T2 - Nom d'hôte fixé"
 
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
```
 
???+tip "Utilisation"
     - `i` pour passer en mode édition
     - `ESC` pour passer en mode commande
     - `:x` pour sauvegarder et quitter
     - `:w` pour sauvegarder sans quitter
     - `:q!` pour quitter sans sauvegarder
     - Garder `d` enfoncé pour supprimer ligne par ligne
     - `U` remplace `CTRL`+`Z`.
     - `SHIFT`+ `INSER` pour coller **dans le mode édition**
 
Configuration:
 
```
vim /etc/vim/vimrc
```
 
Remplacer le contenu du fichier par ce qui suit:
 
```
" All system-wide defaults are set in $VIMRUNTIME/debian.vim and sourced by
" the call to :runtime you can find below.  If you wish to change any of those
" settings, you should do it in this file (/etc/vim/vimrc), since debian.vim
" will be overwritten every time an upgrade of the vim packages is performed.
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
 
Remplacer le contenu de `.bashrc` dans le répertoire de l'utilisateur pour lequel on configure bash par ce qui suit:
 
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
 
!!!info "Les changements seront pris en compte à l'ouverture d'un nouveau terminal."
    On peut ouvrir un terminal dans le terminal en entrant la commande `bash`.
 
### SSH
 
Autoriser les connections SSH:
 
```
# raspi-config
5 Interfacing Options
P2 SSH
YES
```

Déterminer l'adresse du Raspberry Pi avec:
 
```
$ ip a
```
Côté client, télécharger [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html).
 
Dans putty, entrer cette adresse et appuyer sur "Open". Entrer ensuite les identifiants choisis lors de la configuration:
 
```
pi
919294
```
 
## Web
 
!!!quote "T2"
     - [X] Carte SD reformatée
     - [ ] OS conforme au cahier des charges
     - [X] Nom d'hôte fixé
     - [X] Configuration IP
     - [ ] Applications installées
     - [ ] Configurer le WiFi pour pouvoir accéder au site web depuis les clients.

### Mise en ligne
 
Nous allons utiliser Apache pour mettre en ligne une sauvegarde du site de APC.
 
```
# apt-get install apache2
```
 
!!!success "T2 - Applications installées"

Vérifier que le site est accessible en entrant l'adresse du Pi dans un navigateur. Les pages de la sauvegarde devraient alors apparaître. 
 
### WiFi

!!!info "Etapes"
     - Avoir un interface WiFi
     - Configurer l'interface
     - Configurer AdHoc, HostAPD ou autre pour puvoir créer des connexions
     - Ajouter une (ou des ?) zones DNSpour le nouveau interface
     - Configurer le DHCP pour le nouveau interface
     - S'assurer qu'on accède au serveur Apache

!!!tip "Chercher comment avoir un max de logs à chaque étape!"

???- note "Liens un peu random"
     - [https://www.windtopik.fr/configurer-wifi-raspberry-pi/](https://www.windtopik.fr/configurer-wifi-raspberry-pi/)
     - [https://learn.adafruit.com/adafruits-raspberry-pi-lesson-3-network-setup/setting-up-wifi-with-raspi-config-easy](https://learn.adafruit.com/adafruits-raspberry-pi-lesson-3-network-setup/setting-up-wifi-with-raspi-config-easy)

Insérer la clé WiFi.

Suivre [cette page](https://wiki.debian.org/WiFi/AdHoc) pour configurer une liaisin **ad hoc**.

[HostAPD](https://doc.ubuntu-fr.org/hostapd) permet de créer un spot qui admet plusieurs connexions, a condition que la clé WiFi soit adaptée.

Redémarrer Apache:

```
systemctl restart apache2.service
```

!!!warning "WiFi"

!!!fail "T3 - OS conforme au cahier des charges"
    On n'a pas compris la consigne de cette partie (question 2).

## Téléchargements
 
Dans la partie suivante, la machine sera installée dans un réseau isolé. On télécharge donc dès maintenant tous les paquets nécessaires pour la suite.

???- info "DHCP" 
    ```
    # apt-get install isc-dhcp-server
    # apt-get install isc-dhcp-server-ldap
    ```

???- info "DNS"
    ```
    # apt-get install bind9
    # apt-get install dnsutils
    ```

???- info "Proxy"
    ```
    # apt-get install squid
    ```

## DNS
 
!!!quote "T4 - Installer et configurer serveur DNS sur Raspberry Pi"
     - [ ] Alias
     - [ ] Résolution directe
     - [ ] Résolution inversée
     - [ ] Service hautement disponible
 
Remplacer le contenu du fichier `/etc/bind/named.conf.local` par ce qui suit:
 
```
//
// Do any local configuration here
//

zone "apc.com" {
        type master;
        allow-transfer {172.16.130.2; 172.16.130.3;};
        file "/etc/bind/db.apc.com";
        notify yes;
};

zone "20.172.in-addr.arpa" {
        type master;
        allow-transfer {172.16.130.2; 172.16.130.3;};
        file "/etc/bind/20.172.in-addr.arpa";
        notify yes;
};

// Consider adding the 1918 zones here, if they are not used in your
// organization
include "/etc/bind/zones.rfc1918";

```

Dans `/etc/bind/zones.rfc1918`, supprimer la ligne:

```
zone "20.172.in-addr.arpa"  { type master; file "/etc/bind/db.empty"; };
```

Créer le fichier `db.apc.com`. Y mettre le contenu suivant:
```
$ORIGIN .
$TTL    600
apc.com.       IN      SOA     ns.apc.com. admin.apc.com.  (
                                        1               ; Serial
                                        300             ; Refresh 5 min
                                        60              ; Retry   1 min
                                        600             ; Expire  10 min
                                        300             ; Minimum 5 min
)

        A               172.16.130.1

        NS              ns.apc.com.
        NS              ns2.apc.com.
        NS              ns3.apc.com.

$ORIGIN apc.com.

ns                 A           172.16.130.1
ns2                A           172.16.130.2
ns3                A           172.16.130.3
www                CNAME       apc.com.
; EOF

```

Créer le fichier `20.172.in-addr.arpa`. Y mettre le contenu suivant:
 
```
$TTL    600
@       IN      SOA     ns.apc.com. admin.apc.com.  (
                                        1               ; Serial
                                        300             ; Refresh 5 min
                                        60              ; Retry   1 min
                                        600             ; Expire  10 min
                                        300             ; Minimum 5 min
)

@                            NS              ns.apc.com.
@                            NS              ns2.apc.com.
@                            NS              ns3.apc.com.
1.130.16.172.in-addr.arpa.   PTR             apc.com.
; EOF

```

!!!info "Il faut incrémenter le `Serial` a chaque modification du fichier."

Redémarrer Bind et vérifier son bon fonctionnement:
```
# systemctl restart bind9
# systemctl status bind9
```
 
???+ info "Sur les NS secondaires"

    !!!warning "Cette section n'a pas été vérifiée en pratique"

    Ne modifier que le fichier `/etc/bind/named.conf.local` :
    ```
    //
    // Do any local configuration here
    //

    zone "apc.com" {
        type slave;
        file "/etc/bind/db.apc.com";
        masters {172.16.130.1;};
    };

    zone "20.172.in-addr.arpa" {
        type slave;
        file "/etc/bind/20.172.in-addr.arpa";
        masters {172.16.130.1;};
    };

    // Consider adding the 1918 zones here, if they are not used in your
    // organization
    //include "/etc/bind/zones.rfc1918";
    ```

    Ensuite, redémarrer le service

Vérifier le bon fonctionnement sur toutes les machines DNS à l'aide de `dnsutils`:

```
$ nslookup
> server localhost
> apc.com
> 172.16.130.1
> exit
```
???- notes "Configuration des logs"
    Remplacer le contenu de `/etc/bind/named.conf.options` par ce qui suit:
    ```
    options {
        directory "/var/cache/bind";

        // If there is a firewall between you and nameservers you want
        // to talk to, you may need to fix the firewall to allow multiple
        // ports to talk.  See http://www.kb.cert.org/vuls/id/800113

        // If your ISP provided one or more IP addresses for stable
        // nameservers, you probably want to use them as forwarders.
        // Uncomment the following block, and insert the addresses replacing
        // the all-0's placeholder.

        // forwarders {
        //      0.0.0.0;
        // };

        //========================================================================
        // If BIND logs error messages about the root key being expired,
        // you will need to update your keys.  See https://www.isc.org/bind-keys
        //========================================================================
        dnssec-validation auto;

        listen-on-v6 { none; };
    };

    logging {

        channel default_syslog {
                file "/var/log/named/default.log" size 5m;
                print-time yes;
                severity debug;
        };

        channel audit_log {
                file "/var/log/named/audit.log" size 5m;
                severity debug;
                print-time yes;
        };

        channel query_log {
                file "/var/log/named/query.log" size 10m;
                severity debug;
                print-time yes;
        };

        category default { default_syslog; };
        category general { default_syslog; };
        category security { audit_log; default_syslog; };
        category config { default_syslog; };
        category resolver { audit_log; };
        category xfer-in { audit_log; };
        category xfer-out { audit_log; };
        category notify { audit_log; };
        category client { audit_log; };
        category network { audit_log; };
        category update { audit_log; };
        category queries { query_log; };
        category lame-servers { audit_log; };
    };

    ```

    Des informations détaillées peuvent à présent être consultées dans `/var/log/named/default.log`. 

!!!success "T4 - Alias"
!!!success "T4 - Résolution directe"
!!!success "T4 - Résolution inversée"
!!!success "T4 - Service hautement disponible"

## DHCP
 
!!!quote "T3 - Installer et configurer un serveur DHCP sur Raspberry Pi"
     - [ ] Service DHCP opérationnel: bail correctement délivré avec bonnes valeurs d'étendues
     - [ ] Service hautement disponible
 
### Configuration réseau
 
Configuration manuelle de l'IP fixe.
 
!!!warning "Isoler le Raspberry Pi du réseau du lycée."
    A partir de cette étape, il est indispensable d'isoler le(s) Pi du réseau du lycée pour éviter les conflits d'adressage. Puisque l'IP changera, il faudra ouvrir une nouvelle connexion SSH vers la nouvelle IP le moment venu.
 
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
static ip_address=172.16.130.1/24
#static ip6_address=fd51:42f8:caae:d92e::ff/64
static routers=172.16.130.1
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
Une fois connecté, vérifier que le Pi a la bonne adresse (`172.16.130.1`):
 
```
$ ip a
```
 
### Configuration du service
 
Remplacer le contenu de `/etc/dhcp/dhcpd.conf` par ce qui suit:
 
```
# dhcpd.conf
#
# Sample configuration file for ISC dhcpd
#
 
# option definitions common to all supported networks...
option domain-name "apc.com";
option domain-name-servers 172.16.130.1, 172.16.130.2, 172.16.130.3; 
 
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
subnet 172.16.130.0 netmask 255.255.255.0 {
  range 172.16.130.10 172.16.130.127;
  option domain-name-servers 172.16.130.1 172.16.130.2 172.16.130.3;
  option domain-name "apc.com";
#  option routers 172.16.130.1;
  option broadcast-address 172.16.130.255;
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
 
!!!warning "172.16.130.2"
    Si on a plusieurs Raspberry Pi, on doit en garder un en IP fixe (`172.16.130.2`) et l'utiliser comme DNS secondaire.
    Pour l'instant, le service ne démarre pas si on ne commente pas la deuxième adresse. 
 
Redémarrer le démon et vérifier qu'il fonctionne correctement:
 
```
# systemctl start isc-dhcp-server
# systemctl status isc-dhcp-server
```
 
!!!success "T3 - Service DHCP opérationnel: bail correctement délivré avec bonnes valeurs d'étendues"
 
!!!fail "T3 - Service hautement disponible"
    Nous n'avons pas compris la consigne de cette partie (question 3).
 
## Proxy
 
!!!quote "Installation d'un service Proxy cache HTTP"
    Nous souhaitons ouvrir ce service uniquement pour les postes de travail de l'entreprise.

Dans le fichier `/etc/squid/squid.conf`:

 - Commenter les lignes 1188 à 1207.
 - Remplacer la ligne 1192 `#acl localnet src 172.16.0.0/12 # RFC 1918` par ce qui suit:

```
acl localnet src 172.16.130.0/24 # RFC 1918
```
 - Remplacer la ligne 1198 `#acl Safe_ports port 80 # http` par ce qui suit:

```
acl Safe_ports port 8080 # http
```
 - Commenter la ligne 1388 `http_access deny CONNECT !SSL_ports`.
 - Décommenter la ligne 1407 `http_access allow localnet`.
 - Commenter la ligne suivante `http_access allow localhost`.
 - Remplacer la ligne 1907 `http_port 3128` par ce qui suit:

```
http_port 8080
```

Sur toutes les machines, configurer les navigateurs pour avoir `172.16.130.1` comme proxy.

!!!warning "Le fonctionnement du proxy n'a pas été vérifié en pratique"

!!!warning "Les logs ne sont peut-être pas suffisants par défaut pour voir les connexions"

!!!success "Proxy"
