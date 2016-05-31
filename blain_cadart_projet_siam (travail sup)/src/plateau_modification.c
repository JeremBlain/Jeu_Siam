#include "plateau_modification.h"
#include "coordonnees_plateau.h"


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



int plateau_modification_introduire_piece_etre_possible(const plateau_siam* plateau,
                                                        int x,int y,
                                                        type_piece type,
                                                        orientation_deplacement orientation)
{
    assert(plateau!=NULL);
    assert(orientation_etre_integre_deplacement(orientation));
    assert(type_etre_animal(type));

    if(coordonnees_etre_dans_plateau(x,y)!=1)
    return 0;

    if(coordonnees_etre_bordure_plateau(x,y)!=1)
    return 0;

    type_piece type_derniere_piece_poussee=piece_etre_derniere_poussee(plateau,x,y,orientation);
    if( plateau_denombrer_type(plateau, type)==5 && type_derniere_piece_poussee!=type)
        return 0;


    const piece_siam *piece = plateau_obtenir_piece_info(plateau,x,y);
    if(piece->type == case_vide)
        return 1;



	 //Si la case visee est un animal ou un rocher, on regarde si la poussee est realisable

	//si x=0, on est à gauche sur le plateau, il faut donc que la piece est une orientation droite
	//pour que la poussee soit peut être réalisable
    if(x == 0 && orientation == droite)
    {
	if(poussee_etre_valide(plateau, x, y, orientation, orientation) == 1)
        	return 1;	
    }

	//si x=NBR_CASES, on est à droite sur le plateau, il faut donc que la piece est une orientation gauche
	//pour que la poussee soit peut être réalisable
    if(x == NBR_CASES-1 && orientation == gauche)
    {
	if(poussee_etre_valide(plateau, x, y, orientation, orientation) == 1)
        	return 1;	
    }

	//si y=0, on est en bas sur le plateau, il faut donc que la piece est une orientation haute
	//pour que la poussee soit peut être réalisable
    if(y == 0 && orientation == haut)
    {
        if(poussee_etre_valide(plateau, x, y, orientation, orientation) == 1)
        	return 1;	
    }

	//si y=NBR_CASES, on est en bas sur le plateau, il faut donc que la piece est une orientation basse
	//pour que la poussee soit peut être réalisable
    if(y == NBR_CASES-1 && orientation == bas)
    {
	if(poussee_etre_valide(plateau, x, y, orientation, orientation) == 1)
        	return 1;	
    }
   

    return 0;
}


void plateau_modification_introduire_piece(plateau_siam* plateau,
                                           int x,int y,
                                           type_piece type,
                                           orientation_deplacement orientation,
                                           condition_victoire_partie* condition_victoire)
{

    assert(plateau_modification_introduire_piece_etre_possible(plateau,x,y,type,orientation));
    assert(condition_victoire!=NULL);

    piece_siam *piece = plateau_obtenir_piece(plateau,x,y);


    piece->orientation=orientation;
    piece->type=type;

    assert(type_etre_animal(type));
    assert(plateau_etre_integre(plateau));




}


int plateau_modification_changer_orientation_piece_etre_possible(plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation)
{
	assert(plateau != NULL);
  	assert(orientation_etre_integre_deplacement(orientation));

    if(coordonnees_etre_dans_plateau(x0,y0)!=1)
    return 0;

    piece_siam *piece = plateau_obtenir_piece(plateau,x0,y0);
	
	//si l'orientation n'est pas la même et que le type est bien un animal, c'est bon (on retourne 1)
    if( piece->orientation != orientation && type_etre_animal(piece->type) == 1)
		return 1;

	return 0;
	
}



void plateau_modification_changer_orientation_piece(plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation)
{

    //Realise le changement d'orientation valide d'une piece aux coordonnees envoyees en parametre.
    //On verifie apres modification que l'animal et le plateau sont integres.
    assert(plateau_modification_changer_orientation_piece_etre_possible(plateau,x0,y0,orientation));

    piece_siam *piece = plateau_obtenir_piece(plateau,x0,y0);
    piece->orientation=orientation;

    assert(plateau_etre_integre(plateau));
    assert(type_etre_animal(piece->type));
}


int plateau_modification_deplacer_piece_etre_possible(const plateau_siam* plateau,
                                                      int x0,int y0,
                                                      orientation_deplacement direction_deplacement,
                                                      orientation_deplacement orientation)
{

    assert(plateau!=NULL);
    assert(orientation_etre_integre_deplacement(direction_deplacement));
    assert(orientation_etre_integre(orientation));

    if(coordonnees_etre_dans_plateau(x0,y0) == 0)
        return 0;

    //si la piece à bouger est une case vide, déplacement impossible
    const piece_siam *piece = plateau_obtenir_piece_info(plateau,x0,y0);
    if(piece_etre_case_vide(piece) == 1)
        return 0;

    orientation_deplacement orientation_avant_deplacement=piece->orientation;

    //on regarde si le deplacement est en dehors du plateau (c'est possible)
    coordonnees_appliquer_deplacement(&x0,&y0, direction_deplacement);
    if(coordonnees_etre_dans_plateau(x0,y0) == 0)
        return 1;

    //on va voir s'il y a une case vide a la case visee par la deplacement
    const piece_siam *piece_visee = plateau_obtenir_piece_info(plateau,x0,y0);
    if(piece_etre_case_vide(piece_visee) == 1)
        return 1;
   if(orientation!=orientation_avant_deplacement)
        return 0;


    return 1;
}


void plateau_modification_deplacer_piece(plateau_siam* plateau,
                                         int x0,int y0,
                                         orientation_deplacement direction_deplacement,
                                         orientation_deplacement orientation_final,
                                         condition_victoire_partie* condition_victoire)
{

    assert(plateau_modification_deplacer_piece_etre_possible(plateau,x0,y0, direction_deplacement,orientation_final));
    assert(condition_victoire!=NULL);
    assert(plateau_etre_integre(plateau));
    piece_siam *piece = plateau_obtenir_piece(plateau,x0,y0); 

    type_piece type = piece->type; //on fait une sauvegarde du type de la piece pour pouvoir faire le deplacement
	
	//on remplace la piece par une case _vide (d'où la sauvegarde du type faite précedemment, qui vient d'être perdu)
    piece->type=case_vide;
    piece->orientation=aucune_orientation;

    //on change les coordonnees pour qu'elle corresponde à la case visee par le deplacement
    coordonnees_appliquer_deplacement(&x0,&y0,direction_deplacement);

    if(coordonnees_etre_dans_plateau(x0,y0)!=1)
        return;

    //on récupère un pointeur sur la piece à la nouvelle case
    piece_siam *piece_nouvelle_position = plateau_obtenir_piece(plateau,x0,y0);
    piece_nouvelle_position->type=type;	//et on lui applique le type de la piece qui doit etre deplac
    piece_nouvelle_position->orientation=orientation_final; //et on lui définit l'orientation voulue

    assert(plateau_etre_integre(plateau));
}


//fonctions de test
void test_plateau_modification_changer_orientation_piece_etre_possible()
{
	puts("Test plateau_modification_changer_orientation_piece_etre_possible");

	plateau_siam plateau;
	plateau_initialiser(&plateau);
	
	piece_siam *piece = plateau_obtenir_piece(&plateau, 0, 0);
	piece->type = elephant;
	piece->orientation = droite;

	if(plateau_modification_changer_orientation_piece_etre_possible(&plateau, 5, 6, bas) !=0)
    	puts(" orientation coordonnées non dans le plateau KO");

	if( plateau_modification_changer_orientation_piece_etre_possible(&plateau, 0, 0, bas) != 1 )
		puts("orientation bas elephant KO");

	if( plateau_modification_changer_orientation_piece_etre_possible(&plateau, 0, 0, droite) != 0 )
		puts("meme orientation elephant KO");

	piece->type = rhinoceros;
	if( plateau_modification_changer_orientation_piece_etre_possible(&plateau, 0, 0, haut) != 1 )
		puts("orientation haut rhinoceros KO");

	//la case (2,2) contient un rocher
	if( plateau_modification_changer_orientation_piece_etre_possible(&plateau, 2, 2, haut) != 0 ) 
		puts("orientation haut Rocher KO");

	if( plateau_modification_changer_orientation_piece_etre_possible(&plateau, 0, 0, droite) != 0 )
		puts("meme orientation rhinoceros KO");
}


void test_plateau_modification_changer_orientation_piece()
{
	puts("Test plateau_modification_changer_orientation_piece");

	plateau_siam plateau;
	plateau_initialiser(&plateau);
	
	piece_siam *piece = plateau_obtenir_piece(&plateau, 0, 0);
	piece->type = elephant;
	piece->orientation = droite;

	plateau_modification_changer_orientation_piece(&plateau, 0, 0, gauche);
	if( piece->orientation != gauche)
		puts("elephant gauche KO");

	plateau_modification_changer_orientation_piece(&plateau, 0, 0, haut);
	if( piece->orientation != haut)
		puts("elephant haut KO");

	plateau_modification_changer_orientation_piece(&plateau, 0, 0, bas);
	if( piece->orientation != bas)
		puts("elephant bas KO");

	plateau_modification_changer_orientation_piece(&plateau, 0, 0, droite);
	if( piece->orientation != droite)
		puts("elephant droite KO");

	piece->type = rhinoceros;
	plateau_modification_changer_orientation_piece(&plateau, 0, 0, gauche);
	if( piece->orientation != gauche)
		puts("rhinoceros gauche KO");

	plateau_modification_changer_orientation_piece(&plateau, 0, 0, haut);
	if( piece->orientation != haut)
		puts("rhinoceros haut KO");

	plateau_modification_changer_orientation_piece(&plateau, 0, 0, bas);
	if( piece->orientation != bas)
		puts("rhinoceros bas KO");

	plateau_modification_changer_orientation_piece(&plateau, 0, 0, droite);
	if( piece->orientation != droite)
		puts("rhinoceros droite KO");

}

void test_plateau_modification_introduire_piece_etre_possible()
{
	puts("Test plateau_modification_introduire_piece_etre_possible");

	plateau_siam plateau;
	plateau_initialiser(&plateau);

        if(plateau_modification_introduire_piece_etre_possible(&plateau, 1, 3, elephant, bas) !=0)
    	puts(" introduction case non au bord KO");

	if(plateau_modification_introduire_piece_etre_possible(&plateau, 6, 5, elephant, bas) !=0)
    	puts(" introduction coordonnees non au bord KO");

	if(plateau_modification_introduire_piece_etre_possible(&plateau, 0, 1, elephant, bas) !=1)
		puts("elephant introduction case vide KO");

	piece_siam *piece = plateau_obtenir_piece(&plateau, 0, 1);
	piece->type = elephant;
	piece->orientation = droite;

	if(plateau_modification_introduire_piece_etre_possible(&plateau, 0, 1, elephant, bas) !=0)
		puts("elephant introduction case occupe avec mauvaise orientation KO");
	
	if(plateau_modification_introduire_piece_etre_possible(&plateau, 0, 1, elephant, droite) !=1)
		puts("elephant introduction case occupe avec bonne orientation orientation KO");
}

void test_plateau_modification_introduire_piece()
{
	puts("Test plateau_modification_introduire_piece");

	plateau_siam plateau;
	plateau_initialiser(&plateau);
	condition_victoire_partie victoire;
	condition_victoire_initialiser(&victoire);

	plateau_modification_introduire_piece(&plateau, 0, 1, elephant, bas, &victoire);
	const piece_siam *piece = plateau_obtenir_piece_info(&plateau, 0, 1);
	
	if(piece->type != elephant || piece->orientation != bas)
		puts("elephant introduction KO");
}

void test_plateau_modification_deplacer_piece_etre_possible()
{
	puts("Test plateau_modification_deplacer_piece_etre_possible");

	plateau_siam plateau;
	plateau_initialiser(&plateau);

	piece_siam *piece = plateau_obtenir_piece(&plateau, 1, 1);
	piece->type = elephant;
	piece->orientation = bas;

	if(plateau_modification_deplacer_piece_etre_possible(&plateau, 6, 5, gauche, bas) !=0)
    		puts("deplacement coordonnees non au bord KO");
	if(plateau_modification_deplacer_piece_etre_possible(&plateau, 1, 1, bas, haut) !=1)
		puts("deplacer elephant KO");
    	if(plateau_modification_deplacer_piece_etre_possible(&plateau, 2, 2, haut, haut) !=1)
		puts("deplacer rocher KO");
   	if(plateau_modification_deplacer_piece_etre_possible(&plateau, 0, 1, haut, haut) !=0)
		puts("deplacer case_vide KO");

}

void test_plateau_modification_deplacer_piece()
{
	puts("Test plateau_modification_deplacer_piece");

	plateau_siam plateau;
	plateau_initialiser(&plateau);

	piece_siam *piece = plateau_obtenir_piece(&plateau, 1, 1);
	piece->type = elephant;
	piece->orientation = bas;

	condition_victoire_partie victoire;
	condition_victoire_initialiser(&victoire);
	
    	plateau_modification_deplacer_piece(&plateau, 1, 1, bas, haut, &victoire);

	//on test si l'ancienne case après deplacement est bien une case_vide
	const piece_siam *piece_ancienne_case = plateau_obtenir_piece_info(&plateau, 1, 1);
	if(piece_ancienne_case->type != case_vide || piece_ancienne_case->orientation != aucune_orientation)
		puts("Ancienne case KO");

	//on test si la piece est bien déplacée
	const piece_siam *piece_new_case = plateau_obtenir_piece_info(&plateau, 1, 0);
	if(piece_new_case->type != elephant || piece_new_case->orientation != haut)
		puts("Nouvelle case KO");

	//on test maintenant si on déplace une piece hors du plateau, elle est bien enlevée
	plateau_modification_deplacer_piece(&plateau, 1, 0, bas, haut, &victoire);
	if(piece_new_case->type != case_vide || piece_new_case->orientation != aucune_orientation)
		puts("deplacement en dehros du plateau KO KO");

}



