# PRA (résumé)

???- note "Notes de mise à jour"
    ???+ note "Mis en ligne le 09/12/2020"
         - [X] Informations sur l'épreuve
             - [X] Consignes
             - [X] Problèmes
         - [ ] Préparation
             - [X] Instalation de l'OS 
             - [ ] Paramétrage
         - [ ] Web
             - [X] Apache
             - [ ] WiFi
         - [X] DNS
         - [ ] DHCP
             - [X] Configuration réseau
             - [ ] Configuration du service
         - [ ] Proxy

## Informations sur l'épreuve

### Consignes
 
Ceci est une interprétation des consignes données basée sur les documents distribués et les vérifications entreprises par le professeur lors de la fin de l'épreuve.

| Consignes | Chapitre correspondant |
|---|---|
| Préparer le matériel, installer le système et faire en sorte qu'il soit à jour et fonctionnel | [Préparation](#preparation) |
| Faire un site consultable depuis le réseau par ethernet et par WiFi | [Web](#web)|
| Faire un service DNS normal et inversé | [DNS](#dns) |
| Faire un service DHCP sur une plage donnée | [DHCP](#dhcp) |
| Faire un proxy et pouvoir l'utiliser pour le web et les mises à jour | [Proxy](#proxy) |
| Configurer les logs et savoir les utiliser pour tous les services | Tous les chapitres |

???- info "Documents obtenus relatifs aux consignes"
     - Document originel

    ![Notation](/img/notation.jpg)

     - Sujet distribué au début de l'épreuve
    
    ![Sujet 1](/img/sujet1.jpg)
    ![Sujet 2](/img/sujet2.jpg)

     - Sujet distribué vers le milieu de l'épreuve
    
    ![Sujet 3](/img/sujet3.jpg)
 
### Problèmes (8)

Liste des problèmes à résoudre.

!!!fail "On ne sait pas comment configurer le WiFi ([Web](#web))"

!!!fail "On ne sait pas comment configurer le proxy ([Proxy](#proxy))"

!!!warning "L'écriture de l'image prend trop de temps ([Préparation](#preparation))"
    Préparer une image vierge sur clé USB en avance 

!!!warning "5 blocs de code doivent être vérifiés dans [Préparation](#preparation), [DHCP](#dhcp) et [Proxy](#proxy)"

!!!info "Pièges possibles"
    1. Câbles défectueux (un des fils est cassé et non visible) (couche 1)
    2. L'accès Wifi défectueux et/ou non connecté (couche 1)
    3. Erreurs dans l'association entre l'adresse MAC et l'adresse IP (couche 2)
    4. Erreurs dans la table de routage (couche 3)
 
## Préparation

!!!quote "Consignes"
     - [X] Préparer le matériel 
     - [X] Installer le système
     - [ ] Mettre à jour le système et le configurer

### Instalation de l'OS

Matériel à demander en début d'épreuve :

| Quantité | Description |
|---|---|
| 4 | Raspberry Pi 2 ou plus récent avec alimentation |
| 4 | Cartes SD d'au moins 8Go |
| 1+ | Adaptateur SD-USB|
| 1+ | Adaptateur HDMI-VGA |
| 4 | Câbles ethernet |
| 1 | Commutateur avec alimentation |

 - Instaler le [Raspberry Pi Imager](https://downloads.raspberrypi.org/imager/imager_1.4.exe).
 - Télécharger [Raspberry Pi OS Lite](https://downloads.raspberrypi.org/raspios_lite_armhf/images/raspios_lite_armhf-2020-12-04/2020-12-02-raspios-buster-armhf-lite.zip) pour les machines qui hébergeront un service et [Raspberry Pi OS with desktop](https://downloads.raspberrypi.org/raspios_armhf/images/raspios_armhf-2020-12-04/2020-12-02-raspios-buster-armhf.zip) pour la machine client.

!!!warning "Perte de temps"
    Cette opération prend beaucoup de temps à cause du téléchargement des images. Penser à apporter sur clé USB une image vierge. Si ceci est interdit, ne télécharger qu'une image et la distribue à l'aide de clés USB.

 - Insérer la carte SD dans l'ordinateur à l'aide de l'adaptateur et copier l'image dessus grâce au Raspberry Pi Imager.

### Paramétrage

Première identification :
 
```
login: pi
passwd: raspberry
```
 
???- info "Clavier QWERTY"
    Par défaut, le layout du clavier est en **anglais**.
 
    ![layout](/img/layout.png)
 
Définition d'un mot de passe pour `root` :
 
```
$ sudo passwd root

919294
919294
```

!!!warning "Le bloc de code suivant est à vérifier"

Paramétrages de base:
 
```
# raspi-config

4. Localisation options
keyboard layout
Other
French - French
The default for the keyboard layout
No compose key
No
1. Change user password
919294
3. boot options
command line with login
2. Net options
Hostname
raspberrypiapcN
5 Interfacing Options
P2 SSH
YES
<finish>
```

Le serveur temps est nécessaire pour communiquer correctement sur le réseau:
 
???- note "`/etc/systemd/timesyncd.conf`"

    !!!warning "Le bloc de code suivant doit être vérifié"

    Lignes 14 à 15 :

    ```
    [Time]
    NTP=172.20.81.252
    ```
 
Mise à jour:
 
```
# apt-get update
# apt-get upgrade

Y
```
 
Logiciel de traitement de texte Vim:
 
```
# apt-get install vim
```
 
???- tip "Utilisation"
     - `i` pour passer en mode édition
     - `ESC` pour passer en mode commande
     - `:x` pour sauvegarder et quitter
     - `:w` pour sauvegarder sans quitter
     - `:q!` pour quitter sans sauvegarder
     - Garder `d` enfoncé pour supprimer ligne par ligne
     - `U` remplace `CTRL`+`Z`.
     - `SHIFT`+ `INSER` pour coller **dans le mode édition**
 
???- note "vim /etc/vim/vimrc"
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
 
Configuration du terminal :

???- note "`/home/pi/.bashrc`"
    !!!warning "Le bloc de code suivant est à vérifier"

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
???- note "`/root/.bashrc`"
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
        PS1='${debian_chroot:+($debian_chroot)}\[\033[01;31m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
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

    ```
 
Il faut ouvrir un autre terminal pour voir les modifications :

```
$ bash
```
 
Pour se connecter en SSH, déterminer l'adresse du Raspberry Pi :
 
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
 
!!!quote "Consignes"
     - [X] Faire un site
     - [X] Consultable depuis le réseau
     - [ ] Consultable par WiFi

### Apache
 
```
# apt-get install apache2
```

???- note "`/var/www/html/index.html`"
    ```html
    <html>
        <head>
            <title>
                APC
            </title>
        </head>
        <body>
            <h1>
                Bienvenue sur APC.com !
            </h1>
        </body>
    </html>
    ```

Vérifier que le site est accessible en entrant l'adresse du Pi dans le navigateur d'une machine ==dans le même réseau==. 

???- note "`/etc/apache2/apache2.conf`"
    A la ligne 143: `LogLevel debug`

Les logs peuvent être consultés dans `/var/log/apache2/`.
 
### WiFi

!!!info "Etapes théoriques"
     - Avoir un interface WiFi
     - Configurer l'interface
     - Configurer AdHoc, HostAPD ou autre pour puvoir créer des connexions
     - Ajouter une (ou des ?) zones DNSpour le nouveau interface
     - Configurer le DHCP pour le nouveau interface
     - S'assurer qu'on accède au serveur Apache

!!!tip "Chercher comment avoir un max de logs à chaque étape!"

Après avoir configuré le WiFi, redémarrer Apache pour qu'il écoute sur les deux interfaces:

```
systemctl restart apache2.service
```

!!!fail "On ne sait pas comment configurer le WiFi"

## DNS
 
!!!quote "Consignes"
     - [X] Résolution directe
     - [X] Résolution inversée

Télécherger Bind9 et dnsutils:

```
# apt-get install bind9
# apt-get install dnsutils
```
 
???- note "`/etc/bind/named.conf.local`"
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

    zone "16.172.in-addr.arpa" {
            type master;
            allow-transfer {172.16.130.2; 172.16.130.3;};
            file "/etc/bind/16.172.in-addr.arpa";
            notify yes;
    };

    // Consider adding the 1918 zones here, if they are not used in your
    // organization
    include "/etc/bind/zones.rfc1918";

    ```

???-note "`/etc/bind/zones.rfc1918`"
    Supprimer la ligne:

    ```
    zone "16.172.in-addr.arpa"  { type master; file "/etc/bind/db.empty"; };
    ```

???- note "`/etc/bind/db.apc.com`"
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

???- note "`/etc/bind/16.172.in-addr.arpa`" 
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

???- note "`/etc/bind/named.conf.options`"
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

???- info "Sur les serveurs secondaires"
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

    zone "16.172.in-addr.arpa" {
        type slave;
        file "/etc/bind/16.172.in-addr.arpa";
        masters {172.16.130.1;};
    };

    // Consider adding the 1918 zones here, if they are not used in your
    // organization
    //include "/etc/bind/zones.rfc1918";
    ```

    Ensuite, redémarrer le service

Redémarrer Bind et vérifier son bon fonctionnement:

```
# systemctl restart bind9
# systemctl status bind9
$ nslookup
> server localhost
> apc.com
> 172.16.130.1
> exit
```

Des informations détaillées peuvent être consultées dans `/var/log/named/default.log`. 

## DHCP
 
!!!quote "Consignes"
     - [X] Faire un service DHCP sur une plage donnée

Télécharger DHCP Server de ISC:

```
# apt-get install isc-dhcp-server
# apt-get install isc-dhcp-server-ldap
```

!!!danger "Isoler la machine du réseau du lycée"
 
### Configuration réseau
 
Configuration manuelle de l'IP fixe:
 
???- note "`/etc/dhcpcd.conf`"
    ```bash
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
 
???- note "`/etc/dhcp/dhcpd.conf`" 
    !!!warning "Le bloc de code suivant doit être vérifié"

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
Redémarrer le démon et vérifier qu'il fonctionne correctement:
 
```
# systemctl start isc-dhcp-server
# systemctl status isc-dhcp-server
```
 
## Proxy

!!!quote "Consignes"
     - [ ] Faire un proxy et pouvoir l'utiliser pour le web et les mises à jour

Installer Squid 3:

```
# apt-get install squid
```
 
???- note "`/etc/squid/squid.conf`"
     - Commenter les lignes 1188 à 1207.
     - Remplacer la ligne 1192 `#acl localnet src 172.16.0.0/12 # RFC 1918` par ce qui suit:

    ```
    acl localnet src 172.16.130.0/24 # RFC 1918
    ```

     - Remplacer la ligne 1198 `#acl Safe_ports port 80 # http` par ce qui suit:

    ```
    acl Safe_ports port 8080 # http
    ```

     - Décommenter la ligne 1407 `http_access allow localnet`.
     - Commenter la ligne suivante `http_access allow localhost`.
     - Remplacer la ligne 1907 `http_port 3128` par ce qui suit:

    ```
    http_port 8080
    ```

???- note "`/etc/squid/squid.conf`"
     - ligne 4159: `logformat squid`. 

     - Ligne 4559 ajouter une ligne: `debug_options ALL, 8`

Les logs peuvent être consultés dans `/var/log/squid/`.

???- note "`/etc/apt/apt.conf.d/proxy.conf`"
    !!!warning "Le bloc de code qui suit doit être vérifié"

    ```
    Acquire {
        HTTP::proxy "http://172.16.130.3:8080";
        HTTPS::proxy "http://172.16.130.3:8080";
    }
    ```

!!!fail "On n'arrive pas à faire fonctionner le proxy"
