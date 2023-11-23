# Projet ESE  — Robot chat/souris

## Résumé 
Le but du projet est de concevoir un robot capable de se déplacer sur une table (sans tomber de la table), évitant les obstacles, et détectant les autres robots se trouvant sur la table. 
Le robot se trouvant avec d'autres robots sur la table joue soit le rôle de chat ou soit le rôle de souris (jeu du chat et de la souris).

Une liste de composants nous a été imposée.

## 1. Schéma architectural de notre robot
![alt text](https://github.com/ferdaoues5/chat_project/blob/main/architectural.PNG?raw=true)

**Liste du matériel**

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

