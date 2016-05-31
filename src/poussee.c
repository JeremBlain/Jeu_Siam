#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "poussee.h"


/* Algorithme (fonction recursive):
	on regarde aux coordonnees si la piece est une case vide
	si oui : on renvoie le type case_vide
	si non :
		on sauvegarde le type de la piece
		on se deplace d'une case dans la direction de la poussee
		si on est toujours dans le plateau, on rapelle la même fonction (appel récursif)
		si on est en dehors, le type enregistré précédemment est celui de la ernie piece, on le renvoie	
*/

type_piece piece_etre_derniere_poussee(const plateau_siam *plateau,
                                                         int x, int y,
                                                         orientation_deplacement orientation)
{
    assert(plateau!=NULL);
    assert(coordonnees_etre_dans_plateau(x,y));
    assert(orientation_etre_integre_deplacement(orientation));

    const piece_siam *piece = plateau_obtenir_piece_info(plateau,x,y);

    if(piece->type==case_vide)
        return case_vide;


    type_piece type = piece->type;
    coordonnees_appliquer_deplacement(&x,&y,orientation);

    if(coordonnees_etre_dans_plateau(x,y)==1)
        return piece_etre_derniere_poussee(plateau,x,y,orientation);

    return type;

}


/* Algorithme :
	Si les coordonnes ne sont pas dans le plateau, que l'orientation de deplacement n'est pas la même 
	que l'orientation finale de la piece ou que la piece visée est une case_vide, 
	la poussée n'est pas valide (renvoie 0).

	on initialise ensuite un compteur à 1 (le pousseur).
	TANT QUE l'on est dans le plateau ET que la case où l'on regarde n'est pas une case vide :
		Si l'orientation de la piece dans la case où l'on se situe est la même que l'orientation du pousseur
			On augmente le compteur de 2.
		Si l'orientation de la piece dans la case où l'on se situe est inverse de l'orientation du pousseur
			On diminue le compteur de 2.
		Si la piece dans la case où l'on se situe est un roccher
			On diminue le compteur de 1.
		
		Si le compteur est inférieur à 0 (trop de rochers ou de pieces opposées), 
		alors la pousse n'est pas possible (on renvoie 0)
	
		Sinon, on regarde la piece suivante
	FIN Tant que

	Une fois que l'on est arrivé à une case_vide ou un bord du plateau sans que le compteur 
	ne soit inférieur à 0, la poussée est valide (on renvoie 1).
*/

int poussee_etre_valide(const plateau_siam *plateau,int x, int y,
                        orientation_deplacement deplacement,
                        orientation_deplacement orientation)


{
    assert(plateau!=NULL);

    if(coordonnees_etre_dans_plateau(x,y) != 1)
        return 0;

    if(deplacement != orientation)
        return 0;

    const piece_siam *piece = plateau_obtenir_piece_info(plateau,x,y);

    if(piece->type == case_vide)
	return 0;

    int compteur = 1;


    while (coordonnees_etre_dans_plateau(x,y)!=0 && piece->type!=case_vide)
    {

        if(piece->orientation==orientation)
            compteur = compteur+2;
        if(piece->orientation == orientation_inverser(orientation))
            compteur= compteur -2;
        if(piece->type==rocher)
            compteur--;

	if(compteur<0)
            return 0;

        coordonnees_appliquer_deplacement(&x, &y, orientation);
        if(coordonnees_etre_dans_plateau(x,y)==1)
            piece = plateau_obtenir_piece_info(plateau,x,y);        
    }

    return 1;
}



/*fonction recursive :
*	on regarde si la poussée est valide, si oui, on se déplace de piece en piece,
*	jusqu'à arriver à la fin du plateau ou à une case vide,
* 	puis on deplace les pieces une par une dans la bonne direction.
*/
void poussee_realiser(plateau_siam *plateau,int x, int y,
                                         orientation_deplacement deplacement,
                                         orientation_deplacement orientation,
                                         condition_victoire_partie* condition_victoire )


{

    if(coordonnees_etre_dans_plateau(x,y) != 1)
        return;
    piece_siam *piece = plateau_obtenir_piece(plateau, x, y);
    if(piece->type == case_vide)
        return;
    
    int x_copy = x, y_copy = y; //on copie car on modifie les coordonnées après
    coordonnees_appliquer_deplacement(&x, &y, deplacement); //on se deplacer à la case suivante

	//on regarde la poussée à la case suivante (maintenant courante)
    poussee_realiser(plateau, x, y, deplacement, orientation, condition_victoire); 

    piece = plateau_obtenir_piece(plateau, x_copy, y_copy);
	//on déplace la piece
    plateau_modification_deplacer_piece(plateau, x_copy, y_copy, deplacement, piece->orientation, condition_victoire);

}

//fonctions de  tests

void test_poussee_etre_valide()
{
    puts("Test poussee etre valide");

    plateau_siam plateau;
    plateau_initialiser(&plateau);

    //on vérifie que la pousse est non valide si on envoie un déplacement différent de l'orientation
    if( poussee_etre_valide(&plateau, 1, 1, haut, bas) != 0 )
        puts("orientation = deplacement KO");

	//on verifie si deux animaux d'orientation opposee ne peuvent pas se pousser
  

    piece_siam *piece_2_1 = plateau_obtenir_piece(&plateau, 2, 1);
    piece_2_1->type = rhinoceros;
    piece_2_1->orientation = gauche;

    if( poussee_etre_valide(&plateau, 2, 1, droite, droite) != 0 )
        puts("orientation opposee KO");

	//on test si la pousse de deux animaux d'orientation non opposee est possible
    piece_2_1->orientation = haut;

    if( poussee_etre_valide(&plateau, 2, 1, droite, droite) != 1 )
        puts("orientation pas opposee KO");

	//on test si la pousse de deux animaux de même orientation peuvent pousser un animal d'orientation opposee
    piece_siam *piece_1_1 = plateau_obtenir_piece(&plateau, 1, 1);
    piece_1_1->type = elephant;
    piece_1_1->orientation = droite;

      if( poussee_etre_valide(&plateau, 1, 1, droite, droite) != 1 )
        puts("2 animaux meme orientation Vs animal d'orientation opposee  KO");

	//on test si un animal essaye de pousser plus d'un rocher est impossible (rappel, trois rocher en (1,2), (2,2)
	// et (3,2)

     if( poussee_etre_valide(&plateau, 1, 2, droite, droite) != 0 )
        puts("pousser plus de rocher que de pousseur  KO");

}

void test_poussee_realiser()
{
	puts("Test poussee realiser");

	plateau_siam plateau;
	plateau_initialiser(&plateau);
	condition_victoire_partie victoire;
	condition_victoire_initialiser(&victoire);

	poussee_realiser(&plateau, 1, 2, haut, haut, &victoire);

	piece_siam *piece_1_1 = plateau_obtenir_piece(&plateau, 1, 1);
    	piece_1_1->type = rhinoceros;
   	piece_1_1->orientation = gauche;


}

void test_piece_etre_derniere_poussee()
{
	puts("Test piece etre derniere poussee");

	plateau_siam plateau;
	plateau_initialiser(&plateau);


	//test si la fonction renvoie bien un type_case vide si jamais la chaine ne se finis pas au bord

	piece_siam *piece_0_0 = plateau_obtenir_piece(&plateau, 0, 0);
	piece_0_0->type = elephant;
   	piece_0_0->orientation = gauche;

	piece_siam *piece_0_1 = plateau_obtenir_piece(&plateau, 0, 1);
	piece_0_1->type = elephant;
   	piece_0_1->orientation = gauche;
	
	piece_siam *piece_0_2 = plateau_obtenir_piece(&plateau, 0, 2);
	piece_0_2->type = rhinoceros;
   	piece_0_2->orientation = gauche;

	type_piece type_derniere_piece = piece_etre_derniere_poussee(&plateau, 0, 0, haut);

	if(type_derniere_piece != case_vide)
		puts("derniere piece rhino KO");

	//test maintenant si la fonction renvoie le bon type qui est au bord du plateau (la piece (0,0) est au bord, 
	//donc on peut faire le test en descendant vers le bas)
	type_derniere_piece = piece_etre_derniere_poussee(&plateau, 0, 2, bas);
	if(type_derniere_piece != elephant)
		puts("derniere piece bord plateau KO");


}







