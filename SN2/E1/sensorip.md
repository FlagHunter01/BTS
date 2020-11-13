# Notes

!!!note "Création le 10/11 par Tim"
     - [X] Logiciels utilisés: liste des logiciels nécessaires.
     - [X] Recherche de l'@ du Sensor IP: Procédure de recherche de l'@.

## Logiciels utilisés

!!!warning "Tableau a vérifier"

| Logiciel | Description (supposée) |
| --- | --- |
| IIS de microsoft | pour l'interface web avec "dashboard" |
| SensorIP | interface avec le snesorip (?) |
| IPSentry | superviseur snmp |

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
