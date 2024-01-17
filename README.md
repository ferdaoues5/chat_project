# Projet ESE  — Robot chat/souris

## Résumé 
Le but du projet est de concevoir un robot capable de se déplacer sur une table (sans tomber de la table), évitant les obstacles, et détectant les autres robots se trouvant sur la table. 
Le robot se trouvant avec d'autres robots sur la table joue soit le rôle de chat ou soit le rôle de souris (jeu du chat et de la souris).

Une liste de composants nous a été imposée.

## 1. Schéma architectural de notre robot
![alt text](https://github.com/ferdaoues5/chat_project/blob/main/architectural.PNG?raw=true)

**Liste du matériel**

On utilise le microcontroleur STM32G070RBT6 pour récupérer les données provenants des capteurs, commander les moteurs...

| Capteurs  | Actionneurs | IHM | Horloge |
| ------------- | ------------- | ------------- | ------------- |
| Détection des autres robots : YDLIDAR X4  | 2 Drivers moteurs : ZXBM5210-S | Interrupteur ON/OFF| Quartz 16 MHz |
| Capteurs de bordure (table) : Sharp GP2Y0D805Z0F  | 2 moteurs : DfRobot FIT0520 ou FIT0521 | LEDs indicatives du rôle (chat ou souris)  |  |
| Bumpers (détection de collision)  | | Led de débogage |  |
|Encodeur (pour mesurer vitesse moteur il me semble) | | |  |

## Deadlines

**Entre la toussaint et noel**

- Bibliothèques logicielles
- Drivers
- Organisation du code
- Stratégie et comportements
  
Vacances noel : Samedi 23 décembre au Dimanche 7 janvier  

**Après noel**  
Dernière séance : stratégie et comportements  
TP d’Introduction à la robotique  

**Challenge** le vendredi 12 janvier

Fin du semestre : Samedi 13 janvier  

## Objectifs restants 
**23/11/2023** On a fini le PCB, soudé tous les composants qu'il fallait. Il nous reste maintenant à nous occuper de l'architecture logicielle dans le microcontroleur.
1 niveau d'objectifs au minimum doit être accompli par semaine.

**Niveau 0 :**
Le robot se déplace,
Il ne tombe pas de la table.

**Niveau 1 :**
Il détecte et se dirige vers un objet,
Ou s’en éloigne s’il n’est pas le chat.

**Niveau 2 :**
Il change de comportement (proie/prédateur) après un contact,
Il fonctionne avec plusieurs robots sur la table.

**Niveau 3 :**
Il n’est pas affecté par les obstacles hors de la table,
Il est donc capable de se localiser.

## Problèmes rencontrés

### - Mauvaise liaison du 5V entre la broche du Lidar et un autre point du circuit sensé recevoir 5V aussi

__Résolution du problème__ : en soudant un câble entre ces deux points.


### - Pas de capteurs réfléchissants pour la bordure (Sharp GP2Y0D805Z0F)

Il n'y avait plus de capteurs réfléchissants. Heureusement, on nous a suggeré d'utiliser les switchs, et cela est fonctionnel. En fait le robot quand il est sur la table, la languette est près du switch vu que le sol exerce une force vers le haut sur la languette du switch. On a cablé le switch de sorte à ce qu'il soit "normally opened" et donc qu'il transmette une tension que quand la languette s'ouvre.

### - Le contrôle des moteurs
On était tellement tous concentrés sur l'aspect de programmation qu'on en a oublié de tester le bon fonctionnement des composants de notre carte. Résultat, on s'est rendu compte bien trop tard qu'on ne pouvait pas générer de la PWM sur les broches du microcontroleurs reliées aux drivers. Du coup, on ne pouvait seulement contrôler les moteurs en tout ou rien. Il aurait fallu prévoir de mettre une PWM sur Vref des drivers comme ça on aurait été capable de contrôler la vitesse des moteurs dans le cas où la PWM ne serait pas générée pour les entrées du driver. Le problème n'était pas software puisqu'on a réussi à générer de la PWM sur d'autres broches (ex : celle qui était reliée à la broche M_SCTR du LIDAR). On a même essayé de voir à l'oscillo si on avait de la PWM directement sur les broches du STM32. A un moment, une PWM est soudainement apparu sur la broche FWD du driver, puis elle a disparue. 

### - Le Lidar
Un coup, lors du scan, le lidar ne nous donnait pas les 2 octets marquant le début de la trame (0xA55A), un coup il faisait. C'est quelque chose que je ne comprenais. Finalement, le problème venait peut-être du fait d'utiliser l'alimentation continue bleue car bizarrement quand on utilisait la batterie 7.2V NiMH on avait plus de problème de perturbation de la tension et on arrivait à obtenir une trame correcte.

Pas trop de problèmes rencontrés pour la commande health check.

## Au final...

Le robot peut effectivemment "se déplacer" mais comme il le fait à toute vitesse : à cause de son inertie, quand le capteur de bordure lui enverra l'info comme quoi il y a du vide, il tombera dans le vide, même s'il s'arrête.

## Leçons à tirer

- Tester tous les composants et s'assurer de leur bon fonctionnement avant de passer à la partie software
- Mieux communiquer et bien répartir le travail
- Discuter davantage avec d'autres élèves lorsque l'on rencontre des problèmes pour savoir si eux aussi on rencontré les mêmes problèmes



