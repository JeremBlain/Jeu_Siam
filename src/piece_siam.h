
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
 * Role general de ce fichier
 * --------------------------------------------------------------
 * Un piece du jeu de siam designe un piece possible du plateau.
 * Chaque piece est definie par un type ('elephant','rhinoceros',
 *   'rocher','case_vide'), ainsi que par l'orientation de la piece.
 * Un animal doit avoir une orientation de type 'gauche','droite',
 *   'haut','bas', alors qu'une case vide ou un rocher ne doivent
 *   pas avoir d'orientation.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions de ces fichiers sont en mesure de manipuler
 *   une piece et de realiser des verifications avec les informations
 *   de type et d'orientation.
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Il n'y a pas de notion de positionnement ni de regles du jeu a
 *   ce niveau d'abstraction.
 * La piece correspond a un element fondamental du jeu que l'on
 *   viendra manipuler dans les niveaux d'abstractions plus eleves.
 *
 *
 */



#ifndef PIECE_SIAM_H
#define PIECE_SIAM_H


#include "type_piece.h"
#include "orientation_deplacement.h"


/** Une piece du jeu de siam est definie par son type et son
 *    orientation.
 */
typedef struct
{
    type_piece type; // elephant,rhinoceros,rocher,case_vide
    orientation_deplacement orientation; //haut,bas,gauche,droite,aucune_orientation

}piece_siam;


/**
 * Fonction piece_etre_integre:
 * *************************
 *    Verifie qu'une piece correspond a la definition donnee.
 *    Une piece est integre si:
 *     - Il s'agit d'un animal (elephant ou rhinoceros) et que
 *         son orientation vaut gauche,droite,haut ou bas.
 *     - Il s'agit d'un rocher ou d'une case vide et son orientation vaut
 *         aucune_orientation.
 *    Toute autre combinaison correspond a une piece non integre.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une piece_siam non modifiable.
 *    Garantie:
 *      - Un retour valant 1 si la piece correspond a la definition donnee.
 *      - Un retour valant 0 sinon.
 */
int piece_etre_integre(const piece_siam* piece);


/**
 * Fonction piece_initialiser:
 * *************************
 *    Initialise une piece passee en argument avec des valeurs par defaut.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une piece_siam modifiable.
 *    Garantie:
 *      - La piece est initialisee a une valeur integre.
 *
 */
void piece_initialiser(piece_siam* piece);



/**
 * Fonction piece_etre_animal:
 * *************************
 *    Verifie si une piece est un animal ou non.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une piece_siam non modifiable integre.
 *    Garantie:
 *      - Un retour valant 1 si la piece est un elephant ou un rhinoceros.
 *      - Un retour valant 0 sinon.
 */
int piece_etre_animal(const piece_siam* piece);

/**
 * Fonction piece_etre_rocher:
 * *************************
 *    Verifie si une piece est un rocher ou non.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une piece_siam non modifiable integre.
 *    Garantie:
 *      - Un retour valant 1 si la piece est un rocher.
 *      - Un retour valant 0 sinon.
 */
int piece_etre_rocher(const piece_siam* piece);

/**
 * Fonction piece_etre_case_vide:
 * *************************
 *    Verifie si une piece est une case vide ou non.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une piece_siam non modifiable integre.
 *    Garantie:
 *      - Un retour valant 1 si la piece est une case vide.
 *      - Un retour valant 0 sinon.
 */
int piece_etre_case_vide(const piece_siam* piece);


/**
 * Fonction piece_definir:
 * *************************
 *    Definis les elements d'une piece directement a l'aide d'un
 *      type et d'une orientation.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une piece_siam modifiable.
 *      - Un type integre.
 *      - Une orientation integre.
 *    Garantis:
 *      - Une piece mise a jour avec le nouveau type et orientation.
 *      - La piece doit etre integre.
 */
void piece_definir(piece_siam* piece,type_piece type,orientation_deplacement orientation);

/**
 *       Définis une piece comme etant un rocher à l'aide de la fonction piece_definir.
 *
 *       Necessite :
 *          - Un pointeur non NULL vers une piece_siam modifiable.
 *       Garantis :
 *          - Une piece mise a jour comme un rocher sans orientation.
 *          - La piece doit etre integre.
 */
void piece_definir_rocher(piece_siam* piece);

/**
   Définis une piece comme etant une case vide à l'aide de la fonction piece_definir.
 *
 * Necessite :
 *          - Un pointeur non NULL vers une piece_siam modifiable.
 *
 *  Garantis :
 *          - Une piece mise a jour comme une case vide sans orientation.
 *          - La piece doit etre integre.
 */
void piece_definir_case_vide(piece_siam* piece);


/**
 * Fonction piece_recuperer_orientation_animal:
 * *************************
 *    Recupere l'orientation d'une piece designant un animal.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une piece_siam non modifiable.
 *      - La piece est integre et designe un animal.
 *    Garantie:
 *      - Une piece mise a jour est une case vide.
 *      - La piece est integre.
 */
orientation_deplacement piece_recuperer_orientation_animal(const piece_siam* piece);


/**
 * Fonction piece_afficher:
 * *************************
 *    Affiche de maniere lisible sur la console le type et l'orientation
 *      d'une piece.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une piece_siam non modifiable.
 *    Garantie:
 *      - Affichage sur la console de la piece.
 */
void piece_afficher(const piece_siam* piece);

/**
 * Fonction piece_afficher_nom_cours_debug:
 * *************************
 *    Affiche de maniere lisible sur la console le type et l'orientation
 *      d'une piece par une chaine de caractere courte.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une piece_siam non modifiable.
 *    Garantie:
 *      - Affichage sur la console de la piece par une chaine de
 *         caractere courte.
 */
void piece_afficher_nom_cours(const piece_siam* piece);

/**
 *
 * Fonction piece_correspondre_nom_cours:
 * ****************
 *       Affecte un type et une orientation d'une piece correspondant au nom cours envoyé en parametre.
 *       Necessite:
 *          -Un pointeur non NULL sur un tableau de caractère, non modifiable.
 *       Garantis :
 *          - retourne une piece avec un type et une orientation correspondant au tableau de caractère
 *            nom cours envoyé en paramètre.
 *          - affiche une erreur si le nom cours envoyé est éronné.
 */
piece_siam piece_correspondre_nom_cours(const char* nom_cours);

/** Fonctions test
 * ******************
 * */

void test_piece_etre_integre();
void test_piece_definir();
void test_piece_etre_case_vide();
void test_piece_etre_rocher();
void test_piece_etre_animal();
void test_piece_correspondre_nom_cours();

#endif
