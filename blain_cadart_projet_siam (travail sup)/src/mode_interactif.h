
/**
 * **************************************************
 * **************************************************
 *   _____ _____  ______   _
 *  / ____|  __ \|  ____| | |
 * | |    | |__) | |__    | |    _   _  ___  _ __
 * | |    |  ___/|  __|   | |   | | | |/ _ \| '_ \
 * | |____| |    | |____  | |___| |_| | (_) | | | |
 *  \_____|_|    |______| |______\__, |\___/|_| |_|
 *                                __/ |
 *                               |___/
 * **************************************************
 * **************************************************
 *
 *
 * Role general de ce fichier
 * --------------------------------------------------------------
 * Le mode interactif permet d'interfacer le jeu de siam avec
 *  la commande d'utilisateur en ligne de commande.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions proposee dans le mode interactifs permettent de
 *  demarer le controle du jeu en ligne de commande.
 * Les fonctions du mode interactif ont pour but de dialoguer avec
 *  un utilisateur (potentiellement non programmeur). Elles
 *  affichent donc les messages de dialogue avec l'utilisateur.
 * Le mode interactif vient egalement realiser la synchronisation
 *  des fonctions de gestion du jeu (demande d'action, realisation
 *  d'actions, affichage informatif, enregistrement et lecture
 *  a partir de fichiers et affichage du vainqueur).
 * Comme les fonctions traitent de demandent utilisateurs elles
 *  ne peuvent pas presuposer de contraintes de type "assertions"
 *  sur les variables completees interactivement.
 *
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Ce niveau d'abstraction a pour role de realiser l'interface entre
 *  une entree sous forme de demande utilisateur vers l'API du programme.
 * Le mode interactif ne vient utiliser que des fonctions de hauts
 *  niveaux du jeu qu'il utilise comme une librairie externe.
 */



#ifndef MODE_INTERACTIF_H
#define MODE_INTERACTIF_H

#include "jeu_siam.h"
#include "AI.h" //pour faire jouer l'IA


/**
 * Fonction mode_interactif_lancer:
 * *****************
 * Affiche les instructions à suivre par l'utilisateur pour realiser une action.
 * Initialise le jeu et l'action a realiser.
 * Sauvegarde le jeu courant.
 * Tant que le jeu n'est pas fini et qu'il n'y a pas de vainqueur, affiche le plateau du jeu, recupere ce que
 * l'utilisateur tape dans la ligne de commande, modifie l'action a realiser selon ce que l'utilisateur a entre et
 * applique celle ci.
 *
 * Necessite :
 *  - rien
 * Garantie :
 *  - La realisation des actions
 *  - L'affichage de l'evolution du plateau
 *  - La fin du jeu lorsque un joueur est gagnant.
 */
void mode_interactif_lancer();

/**
 * Fonction mode_interactif_introduire_nouvelle_piece:
 * *****************
 * Vérifie :
 *      - que les coordonnées sont dans le plateau, et que l'orientation est integre
 *      - que le coup : introduction de la piece, est possible
 *
 *
 * Necessite :
 *      - Un pointeur vers jeu non NULL modifiable
 *      - Un pointeur vers victoire non NULL modifiable
 *      - Deux coordonnées entières
 *      - Une orientation
 * Garantie :
 *      - l'affichage de l'action que l'utilisateur a entre
 *      - la sauvegarde du jeu après l'action d'introduction d'une piece
 *      - la mise a jour et l'affichage du vainqueur si victoire il y a
 *      - l'affichage d'un message d'erreur si le coup n'est pas valide
 *
 */

void mode_interactif_introduire_nouvelle_piece(jeu_siam* jeu,int x,int y,orientation_deplacement orientation,int* victoire);

/**
 * Fonction mode_interactif_deplacer_piece:
 * *****************
 * Vérifie :
 *      - que les coordonnées sont dans le plateau, et que l'orientation est integre
 *      - que le coup : deplacement de la piece, est possible
 *
 * Necessite :
 *      - Un pointeur vers jeu non NULL modifiable
 *      - Un pointeur vers victoire non NULL modifiable
 *      - Deux coordonnées entières
 *      - Une orientation et un deplacement
 * Garantie :
 *      - l'affichage de l'action que l'utilisateur a entre
 *      - la sauvegarde du jeu après l'action de deplacement
 *      - la mise a jour et l'affichage du vainqueur si victoire il y a
 *      - l'affichage d'un message d'erreur si le coup n'est pas valide
 *
 */
void mode_interactif_deplacer_piece(jeu_siam* jeu,int x,int y,orientation_deplacement deplacement,orientation_deplacement orientation,int* victoire);
/**
 * Fonction mode_interactif_changer_orientation:
 * *****************
 * Vérifie que les coordonnées sont dans le plateau, et que l'orientation est integre.
 * Deplace la piece par le moyen de la fonction api (qui verifie elle meme si le deplacement est possible)
 *
 * Necessite :
 *      - Un pointeur vers jeu non NULL modifiable
 *      - Deux coordonnées entières
 *      - Une orientation
 * Garantie :
 *      - l'affichage de l'action que l'utilisateur a entre
 *      - la sauvegarde du jeu après l'action de changement d'orientation
 *      - l'affichage d'un message d'erreur si le coup n'est pas valide
 *
 */


void mode_interactif_changer_orientation(jeu_siam* jeu,int x,int y,orientation_deplacement orientation);

/**
 * Fonction mode_interactif_sauvegarder_jeu_fichier:
 * *****************
 * Sauvegarde dans un fichier le plateau du jeu courant.
 * Necessite :
 *      - Un pointeur vers jeu non NULL non modifiable et integre.
 * Garantie :
 *      - un fichier mis a jour.
 *
 *
 */


void mode_interactif_sauvegarder_jeu_fichier(const jeu_siam* jeu);



void mode_interactif_lire_fichier(jeu_siam* jeu,const char* filename);
int mode_interactif_parametres_etre_valides(const jeu_siam* jeu,int x,int y,orientation_deplacement orientation);


#endif
