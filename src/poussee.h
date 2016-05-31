
#include "api_siam.h"
#include"plateau_siam.h"
#include "plateau_modification.h"

/**
*
Fonction piece_etre_derniere_poussee:
*
*************************
*
* permet de donner la derniere piece quand une poussee est effectuée : 
* Si jamais la piece se trouve au bord du plateau, on renvoie le type de la piece au bord
* Si la dernière piece n'est pas au bord, on renvoie le case vide qui se trouve après cette piece
* La fonction nous servira à determiner si la dernière piece de la poussee est un rocher au bord du plateau
* (qui amène donc la victoire). Si jamais la piece n'est pas au bord du plateau, on se fiche du type, c'est pour ça que
* le fait qu'elle renvoie un type case_vide n'est pas dramatique.
* 
* Necessite :
*	- un pointeur sur un plateau non vide et non modifiable
*	- deux coordonnées dans le plateau	
*	- une orientation integre à un deplacement (haut, bas, gauche ou droite)
*
* Garantie :
* 	-un renvoie d'un type de piece, soit une case vide si jamais la derniere piece n'est aps au bord du plateau
*	 soit un autre type (elephant, rhinoceros ou rocher) si la derniere piece est à un bord du plateau
*/

type_piece piece_etre_derniere_poussee(const plateau_siam *plateau,
                                                        int x, int y,
                                                        orientation_deplacement orientation);
/**
*
Fonction poussee_etre_valide:
*
*************************
*
* Verifie  si il est possible de realiser  une poussee qui debute
* aux coordonnees (x,y) dans l'orientation definie.
* Note:  Les coordonnees (x,y) designent la premiere piece rencontree
* dans la poussee.
*
* la poussee est valide s'il la case est non vide, si on est bien dans le plateau
* si l'orientation et la direction de deplacement sont les mêmes
* s'il n'y a pas trop de piece à pousser ou des animaux en sens opposé
*
* Necessite:
* - Un pointeur non NULL vers un plateau integre non modifiable.
* - Deux coordonnees entieres (x,y) designant une piece non
*   vide integre du plateau.
* - Une orientation de poussee designant une direction integre
*  Garantie:
* - Un retour valant 1 si la poussee est possible.
* - Un retour valant 0 sinon.
*
* L'algorithme de poussée nous a été donné par le groupe de Maxime Di-Folco
*
*/
int poussee_etre_valide(const plateau_siam *plateau,int x, int y, orientation_deplacement deplacement,
                        orientation_deplacement orientation);



/**
*
Fonction poussee_realiser:
*
*************************
*Realise une poussee sur un plateau en supposant que celle-ci est realisable.
*
*    Necessite:
*        - Un pointeur non NULL vers un plateau integre modifiable.
*        - Deux coordonnees entieres (x,y) designant une piece non
*          vide integre du plateau.
*       - Un type d'animal a deplacer.
*       - Une orientation de poussee designant une direction integre.
*       - Un pointeur non NULL vers une condition de victoire modifiable.
*   Garantie:
*       -  Un plateau integre mis a jour en ayant realise la poussee.**/
void poussee_realiser(plateau_siam *plateau,int x, int y, orientation_deplacement deplacement,
                                                orientation_deplacement orientation,
                                                condition_victoire_partie* condition_victoire );


/**
*Fonctions de test
**/

void test_poussee_etre_valide();
void test_poussee_realiser();
void test_piece_etre_derniere_poussee();
