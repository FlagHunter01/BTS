# Notes

???+note "MAJ le 16/11 par Tim"
      - Corrigé Température: valeur de `Rearm`.
      - Précisé Alarme: clarification des conditions d'allumage
      - Complété Ventilation: ajout de consignes pour le jour de l'épreuve
      - Sur le port 3, remplacé le "Relay" par "AC Volt Detector".
      - [ ] Courant

???-note "MAJ le 13/11 par Tim"
      - [X] Configuration du SensorIP
           - [X] Température
           - [X] Humidité
           - [X] Ventilation
           - [X] Alarme
      - [ ] Logiciel de monitoring IPSentry

???-note "Création le 10/11 par Tim"
     - [X] Logiciels utilisés: liste des logiciels nécessaires.
     - [X] Recherche de l'@ du Sensor IP: Procédure de recherche de l'@.

## Logiciels utilisés

!!!warning "Tableau a vérifier"

| Logiciel         | Description (supposée)                |
| ---------------- | ------------------------------------- |
| IIS de microsoft | pour l'interface web avec "dashboard" |
| SensorIP         | interface avec le snesorip (?)        |
| IPSentry         | superviseur snmp                      |

## Recherche de l'@ du Sensor IP

On utilise Wireshark:

 - Quand on branche le Sensor IP, il fait un broadcast de son mac.
 - On capture la trame.
 - On cherche l'@ IP source à l'intérieur de la trame
 - On utilise le filtre `ip.addr==<@ IP>` pour vérifier que toutes les trames provenant de cette @ ont une caractéristique commune (comme le nom de l'émetteur détecté par Wireshark)

 Si il a une @ privée (ex `10.1.1.178`), il faut rajouter une autre @ IP à notre machine (voir l'info qui suit) pour pouvoir dialoguer avec lui.

???+ info "Ajout d'une @ sous Win7"
     - Panneau de configuration
     - Options Internet
     - Centre réseau et partage
     - Connction au réseau local -> Propriétés
     - Protocole IPV4 -> Propriétés 
     - Avancé -> Ajouter

???- danger "Le proxy bloque les @ privées."
    Le proxy qui gère le VLAN SNIR refuse le renvoi d'@ différentes de notre sous-réseau.
    Il faut donc isoler notre sous-réseau en déconnectant le lien ethernet.

!!!tip "@ du Sensor IP: `172.20.81.251`"

## Configuration du SensorIP

### Température

!!!quote "Contraintes"
     - Alerte à 25°C
         - Se désactive automatiquement à 23°C
     - Critique à 28°C
         - Se désactive manuellement en dessous de 26°C

 - Sur l'intrface web, aller à la page d'accueil et trouver le thermomètre (cliquer sur son "type").
 - Dans l'interface, dans l'onglet `Settings`, renseigner les valeurs `Warning high` et `Warning high`. `Rearm` est la différence nécessaire pour enlever le statut d'alerte. Pour nous: 25-24 = 1 (normal a partir de 23).

!!!fail "Pas trouvé comment faire passer la désactivation de critique en manuel."

### Humidité

!!!quote "Contraintes"
     - Alerte à 70%
     - Critique à 85%
    Désactivation automatique.

 - Trouver `humidity` dans l'accueil (cliaquer sur son "type").
 - Dans l'interface, dans l'onglet `Settings`, renseigner les valeurs `Warning high` et `Warning high`. `Rearm` doit à priori être à 0 (risque de spam). 

### Ventilation

!!!quote "Contraintes"
     - Alerte à 80% (le vent est 20% moins fort qu'a la normale)
     - Critique à 50%
     - Si l'air soufflé devient plus chaud, il faut déduire une panne ou un problème de climatisation

 - trouver `Airflow`dans l'accueil (cliaquer sur son "type").
 - `Rearm` à 0 à priori (risque de spam).
 - `Sensitivity` a 50% pourrait servir comme paramètre de seuil d'alerte (?)
 - Allumer le ventilo a environ 75% de la puissance, attendre 2 minutes et faire le calibrage avec `Air State` à 100% dans l'onglet `Calibrate`. 
 - Répéter l'opération après avoir éteint le ventilo et attendu 2 minutes. 

!!!warning "Température"
     Le détecteur de vent détecte la différence de température entre deux résistances thermosensibles (différence de température = vent / absence de différence = pas de vent). 
     Il faut donc refaire le calibrage le jour de l'épreuve pour tenir compte de la température de la salle!

!!!fail "Pas trouvé comment configurer les seuils d'alerte."

!!!fail "Le détecteur pourrait être deffectueux."
     Avec Mr. Paxion, le capteur a été calibré dans des conditions optimum, la direction du vent a été alternée et il n'a jamais détecté de vent (valeur `0` dans le graphique).

!!!fail "Le port pourrait être partiellement défectueux."
     Le port 3 détecte mal le AC voltage (il affiche "Relay"), alors que le port 8 et 7 le détectent correctement.

### Alarme

!!!quote "Contraintes"
     - Ne doit s'allumer qu'en cas d'innondation

Désactiver l'alarme dans tous les détecteurs autres que le détecteur d'innondation dans l'onglet `Siren Control`: Il faut sélectioner `None` pour `This Sensor Controls the Siren on Port`.

Dans les options du module `Siren`, sélectionner `Off` pour `Sensor Normal Siren & Strobe Light State` (dernière option).

Dans les options du module `Liquid Detector`, dans l'onglet `Siren Control`, renseigner le port de l'alarme (6), choisir `Critical` et `Turn On Until Acked` (reste allumée tant quon n'a pas cliqué sur le bouton "ack" (aknowledge) sur la page d'accueil).

### Courant

Détection de problèmes de tension.

!!!fail "Le module ne semble pas fonctionner."

## Logiciel de monitoring IPSentry

Suivre le document `Procédure IPSentry SensorIP.pdf` pour la configuration.

 - Lancer IP Sentry Network Monitor
 - Actions -> Edit Devices
 - ClickD sur `{default}` -> Add New -> Network monitor -> PING
 - Renseigner `IP Address`: 172.20.81.251
 - Décocher `Suspend indefinitely`
 - Apply, OK.
 - Vérifier que le ping passe dans le terminal.
 - ClickD sur `{default}` -> Add New -> Add-Ins -> SNMP Monitor and Alert
 - Configure
 - Avec l'explorateur, copier `sp.mib` depuis SNMP_sensorIP>CD_SensorIP8X20>MIB sur un dossier local de la machine.

!!!warning "Comprendre ce que c'est."

 - Dans IPSentry, ouvrir "Tools" (en haut a gauche) -> Import MIB files -> sélectionner le fichier.
 - Dans la fenêtre de droite (OIDs), trouver sensorProbeTempTable -> sensorProbeTempDegree
 - Edit (Haut droite, fenêtre générale) -> Walk MIB

!!!fail "Tous les items font des queries sur 0.0.0.0"
     Et on ne sait pas pourquoi ni ou ca se configure. La probe ne s'ajoute pas dans le menu global .

!!!warning "A compléter"
