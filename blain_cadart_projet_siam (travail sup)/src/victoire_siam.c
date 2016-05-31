
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


#include "victoire_siam.h"

/* Algorithme
	on ne se sert de cette fonction que si un rocher est au bord du plateau

	TANT QUE on est dans le plateau, on se déplace dans le sens de la poussée
	(on se trouve alors en dehors du plateau)

	on applique un déplacement inverse pour revenir sur la plateau et on récupère un pointeur
	sur la piece courante (qui est donc un rocher)
	
	TANT QUE la piece courante n'a pas la même orientation que la direction de poussée
		on revient en arrière (déplacement inverse de la poussée)
		on récupère un pointeur sur la nouvelle pièce courante
	Fin tant que

	on renvoie un pointeur sur la première piece de même orientation que la poussée rencontrée
*/

const piece_siam *premiere_piece_meme_orientation_poussee(const plateau_siam* plateau, int x, int y,
                                                   orientation_deplacement orientation)
{

    assert(plateau!=NULL);
    assert(orientation_etre_integre_deplacement(orientation));
   
    while(coordonnees_etre_dans_plateau(x,y)==1)
    {
     coordonnees_appliquer_deplacement(&x,&y,orientation);
    }

    coordonnees_appliquer_deplacement(&x,&y,orientation_inverser(orientation));
    const piece_siam *piece = plateau_obtenir_piece_info(plateau,x,y);

    while(piece->orientation != orientation)
    {
        coordonnees_appliquer_deplacement(&x,&y,orientation_inverser(orientation));
        piece = plateau_obtenir_piece_info(plateau,x,y);
    }


return piece;


/*Algorithme
	on initialise une condition de victoire partie
	on cherche le type de la derniere piece de la poussée
	Si c'est un rocher (ce qui veut dire que c'est un rocher en bord de plateau, 
			    si c'est un rocher non au bord, alors le type renvoyé est une case vide !!)
		on recherche la piece la plus proche du rocher qui a la même orientation que la poussée
		on modifie la condition victoire partie initialisée au début pour qu'elle indique le bon joueur gagnant
		et qu'il y a un vainqueur

	on retourne la condition de victoire 
*/

}

condition_victoire_partie verification_condition_victoire_valide(jeu_siam *jeu,int x, int y,orientation_deplacement orientation)
{
    assert(jeu!=NULL);
    assert(orientation_etre_integre_deplacement(orientation));
    assert(coordonnees_etre_dans_plateau(x,y));

    condition_victoire_partie condition;
    condition_victoire_initialiser(&condition);

    type_piece type = piece_etre_derniere_poussee(&(jeu->plateau),x,y,orientation);
    if(type==rocher)
    {
        const piece_siam *piece = premiere_piece_meme_orientation_poussee(&(jeu->plateau),x,y,orientation);

        condition.joueur = joueur_obtenir_numero_animal(piece->type);
        condition.victoire = 1;
    }
    return condition;
}

