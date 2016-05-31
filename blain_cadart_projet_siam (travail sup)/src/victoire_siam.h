

#ifndef VICTOIRE_SIAM_H
#define VICTOIRE_SIAM_H

#include "condition_victoire_partie.h"
#include "coordonnees_plateau.h"
#include "plateau_modification.h"
#include "poussee.h"


/**
*
Fonction : premiere_piece_meme_orientation_poussee
*
*************************
*
* Permet de renvoyer un pointeur sur la dernière piece de la poussée qui a la même direction que le pousseur
* Cela permet de nous donner la piece la plus proche de la fin de la chaine de poussée 
* qui est dans la même orientation que le pousseur, utile donc pour nous dire qui est le gagnant lors d'une poussee
* d'un rocher hors du plateau.
*
* Necessite :
*	- un plateau non NULL et non modiable
* 	- une orientation définissant un déplacement integre
*	- deux coordonnées
*
* Garantie
* 	-un pointeur sur une piece étant la première piece en partant de la fin de la chaine,
*	 qui est dans la meme orientation que le pousseur
*
*/

const piece_siam *premiere_piece_meme_orientation_poussee(const plateau_siam* plateau, int x, int y,
                                                   orientation_deplacement orientation);





/**
*
Fonction : verification_condition_victoire_valide
*
*************************
* Fonction qui permet de définir le gagnant de la partie, s'il y en a un
*
* Necessite :
* 	- un plateau non NULL et non modiable
* 	- une orientation définissant un déplacement integre
*	- deux coordonnées dans le plateau
*
* Garantie :
*	-une condition victoire partie modifier si un joueur est gagnant
*
*/


condition_victoire_partie verification_condition_victoire_valide(jeu_siam *jeu,int x,int y,orientation_deplacement orientation);

#endif
