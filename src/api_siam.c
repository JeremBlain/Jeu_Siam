#include "api_siam.h"
#include "plateau_modification.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

coup_jeu api_siam_tenter_introduire_nouvelle_piece_si_possible(jeu_siam* jeu,
                                                               int x,int y,
                                                               orientation_deplacement orientation)
{
    assert(jeu_etre_integre(jeu));
    coup_jeu coup;
    coup_jeu_initialiser(&coup);

 
    type_piece type = joueur_obtenir_animal(jeu->joueur);
    if(plateau_modification_introduire_piece_etre_possible(&(jeu->plateau),x,y,type,orientation)==0)
        return coup;

    const piece_siam *piece = plateau_obtenir_piece_info(&(jeu->plateau), x, y);

    if(piece->type != case_vide)
    {
       if(poussee_etre_valide(&(jeu->plateau), x, y, orientation, orientation) == 1)
       {
		//ici il faut vérifier la condition de victoire avant la poussée
		//car si jamais un rocher est au bord, il faut pouvoir le voir avant que la poussé ne soit effectuée !
            coup.condition_victoire=verification_condition_victoire_valide(jeu,x,y,orientation);
            poussee_realiser(&(jeu->plateau), x, y, orientation, orientation, &(coup.condition_victoire));
       }
    }

    plateau_modification_introduire_piece(&(jeu->plateau),x,y,type,orientation,&(coup.condition_victoire));
    coup.valide=1;   

	//on change de joueur
    joueur_changer(&(jeu->joueur));
    return coup;


}



coup_jeu api_siam_tenter_deplacer_piece_si_possible(jeu_siam* jeu,
                                                    int x,int y,
                                                    orientation_deplacement deplacement,
                                                    orientation_deplacement orientation)
{
    assert(jeu_etre_integre(jeu));
    coup_jeu coup;
    coup_jeu_initialiser(&coup);

  
    if(plateau_modification_deplacer_piece_etre_possible(&(jeu->plateau),x,y, deplacement, orientation)==0)
    {
        puts("  deplacement impossible");
        return coup;
    }

    const piece_siam *piece = plateau_obtenir_piece_info(&(jeu->plateau), x, y);

    // On vérifie que la pièce au coordonnées indiquées appartienne bien au joueur actuel.

    if(piece->type==rocher || piece->type==case_vide)
    {
        puts("  Vous ne pouvez pas bouger cette pièce (rocher ou case vide) !");
        return coup;
    }

    if(joueur_etre_type_animal(jeu->joueur,piece->type)==0 )
    {
        puts("  La piece choisie n'est pas la votre !");
        return coup;
    }

	

    	//on copie les valeurs de x et y pour regarder ensuite à la case après deplacement, pour voir si la poussee
	//est réalisable
    int x_deplacement = x, y_deplacement=y;
    coordonnees_appliquer_deplacement(&x_deplacement, &y_deplacement, deplacement);

	//si la piece est au bord et qu'on veut l'enlever (deplacement hors plateau), 
	//on l'enleve directement et on fini le tour
    if(coordonnees_etre_dans_plateau(x_deplacement,y_deplacement) != 1)
    {
	plateau_modification_deplacer_piece(&(jeu->plateau), x, y , deplacement, orientation, &(coup.condition_victoire));
    	coup.valide=1;
 	joueur_changer(&(jeu->joueur));

	return coup;
    }

    piece = plateau_obtenir_piece_info(&(jeu->plateau), x_deplacement, y_deplacement);

    if(piece->type != case_vide)
    {
       if(poussee_etre_valide(&(jeu->plateau), x_deplacement, y_deplacement, deplacement, orientation) == 1)
       {
        coup.condition_victoire=verification_condition_victoire_valide(jeu,x,y,orientation);
        poussee_realiser(&(jeu->plateau), x_deplacement, y_deplacement, deplacement, orientation, &(coup.condition_victoire));
       }

       else
       {
           puts("  La poussee n'est pas valide");
           return coup;
       }
    }


    plateau_modification_deplacer_piece(&(jeu->plateau), x, y , deplacement, orientation, &(coup.condition_victoire));
    coup.valide=1;

	//on change de joueur
    joueur_changer(&(jeu->joueur));
    return coup;
}



coup_jeu api_siam_tenter_changer_orientation_piece_si_possible(jeu_siam* jeu,int x,int y,orientation_deplacement orientation)
{
    assert(jeu_etre_integre(jeu)); 
    coup_jeu coup;
    coup_jeu_initialiser(&coup);


    if(plateau_modification_changer_orientation_piece_etre_possible(&(jeu->plateau),x,y,orientation)==0)
    {
        puts("  orientation pas bonne");
        return coup;
    }

    const piece_siam *piece = plateau_obtenir_piece_info(&(jeu->plateau), x, y);
	// On vérifie que la pièce au coordonnées indiquées appartienne bien au joueur actuel.
    if(piece->type==rocher || piece->type==case_vide)
    {
        puts("  Vous ne pouvez pas bouger cette pièce (rocher ou case vide) !");
        return coup;
    }

    if(joueur_etre_type_animal(jeu->joueur,piece->type)==0)
    {
        puts("  La piece choisie n'est pas la votre !");
        return coup;
    }


    plateau_modification_changer_orientation_piece(&(jeu->plateau),x,y,orientation);
    coup.valide=1;

	//on change de joueur
    joueur_changer(&(jeu->joueur));
    return coup;

    // Cette fonction permet de changer l'orientation d'une pièce, dans tous les cas elle ne permettra pas
    // de désigner un vainqueur : on ne changera pas la valeur de coup.victoire (initialisée à 0).
}


//fonctions de tests
void test_api_siam_tenter_changer_orientation_piece_si_possible()
{
    puts("Test api_siam_tenter_changer_orientation_piece_si_possible");   

    jeu_siam jeu;
    jeu_initialiser(&jeu);

    piece_siam *piece = plateau_obtenir_piece(&(jeu.plateau),1,1);
    piece->type=elephant;
    piece->orientation=bas;
    
    coup_jeu coup;
    coup_jeu_initialiser(&coup);

	//on test si le coup est valide en changeant l'orientation de l'éléphant avec le bon joueur
    coup = api_siam_tenter_changer_orientation_piece_si_possible(&jeu,1,1,haut);
    if(coup.valide!=1 || piece->orientation!=haut || jeu.joueur!=1)
        puts("joueur 0/elephant haut KO");

	//on test si le coup est non valide en changeant l'orientation d'une piece avec le mauvais joueur
    coup = api_siam_tenter_changer_orientation_piece_si_possible(&jeu,1,1,bas);
    if(coup.valide!=0 || jeu.joueur!=1)
        puts("joueur 1/elephant haut KO");

    jeu.joueur=0; //on revient au premier joueur (des elephants)

	//on test si le coup est non valide en envoyant la meme orientation
    coup = api_siam_tenter_changer_orientation_piece_si_possible(&jeu,1,1,haut);
    if(coup.valide!=0 || jeu.joueur!=0)
        puts("joueur 0/meme orientation KO");
}

void test_api_siam_tenter_introduire_nouvelle_piece_si_possible()
{
    puts("Test api_siam_tenter_introduire_nouvelle_piece_si_possible");

    jeu_siam jeu;
    jeu_initialiser(&jeu);

    coup_jeu coup;
    coup_jeu_initialiser(&coup);

    const piece_siam *piece = plateau_obtenir_piece_info(&(jeu.plateau),0,0);

	//on test si le coup est valide si on envoie des coordonnees au bord
    coup = api_siam_tenter_introduire_nouvelle_piece_si_possible(&jeu, 0, 0, haut);	
    if(coup.valide!=1 || piece->orientation!=haut || jeu.joueur!=1)
    	puts(" introduction case vide KO");

	//on test si le coup n'est pas valide si on envoie des coordonnees pas au bord
    coup = api_siam_tenter_introduire_nouvelle_piece_si_possible(&jeu, 1, 1, haut);	
    if(coup.valide!=0 || jeu.joueur!=1)
	puts(" introduction pas au bord KO");

	//on test si le coup est valide si on introduit sur une case deja occupee avec une bonne orientation
    coup = api_siam_tenter_introduire_nouvelle_piece_si_possible(&jeu, 0, 0, haut);	
    if(coup.valide!=1 || jeu.joueur!=0)
	puts(" introduction sur une piece deja existante bonne orientation KO");

	//on test si le coup est non valide si on introduit sur une case deja occupee avec une mauvaise orientation
    coup = api_siam_tenter_introduire_nouvelle_piece_si_possible(&jeu, 0, 0, bas);	
    if(coup.valide!=0 || jeu.joueur!=0)
	puts(" introduction sur une piece deja existante mauvaise orientation KO");

	//on test si on essaye d'introduire trop de piece (plus de 5)

	//il y a déjà un éléphant, il faut en rajouter 4
    piece_siam *piece_4_4 = plateau_obtenir_piece(&(jeu.plateau), NBR_CASES-1, NBR_CASES-1);
    piece_4_4->type = elephant;
    piece_4_4->orientation = gauche;

    piece_siam *piece_3_4 = plateau_obtenir_piece(&(jeu.plateau), 3, NBR_CASES-1);
    piece_3_4->type = elephant;
    piece_3_4->orientation = gauche;

    piece_siam *piece_2_4 = plateau_obtenir_piece(&(jeu.plateau), 2, NBR_CASES-1);
    piece_2_4->type = elephant;
    piece_2_4->orientation = gauche;

    piece_siam *piece_1_4 = plateau_obtenir_piece(&(jeu.plateau), 1, NBR_CASES-1);
    piece_1_4->type = elephant;
    piece_1_4->orientation = gauche;

    coup = api_siam_tenter_introduire_nouvelle_piece_si_possible(&jeu, NBR_CASES-1, 0, haut);
    if(coup.valide!=0 || jeu.joueur!=0)
	puts(" introduction de plus de 5 pieces KO");
}

void test_api_siam_tenter_deplacer_piece_si_possible()
{
    puts("Test api_siam_tenter_deplacer_piece_si_possible");

    jeu_siam jeu;
    jeu_initialiser(&jeu);


    int x=0, y=0;
    piece_siam *piece = plateau_obtenir_piece(&(jeu.plateau),x,y);
    piece->type=elephant;
    piece->orientation=bas;

    coup_jeu coup;
    coup_jeu_initialiser(&coup);    
	
	//on test si le coup est valide en bougeant la bonne piece et avec des coordonnees dans le plateau
    coup = api_siam_tenter_deplacer_piece_si_possible(&jeu, x, y, haut, bas);
    coordonnees_appliquer_deplacement(&x, &y, haut);
    piece_siam *piece_apres_deplacement = plateau_obtenir_piece(&(jeu.plateau),x,y);

    if(coup.valide!=1 || piece_apres_deplacement->orientation!= bas || jeu.joueur!=1)
    {printf("orientation = %d",piece_apres_deplacement->orientation); puts(" joueur 0/elephant orientation KO");}

	//on test si le coup n'est pas valide si on envoie des coordonnees pas dans le plateau
    coup = api_siam_tenter_deplacer_piece_si_possible(&jeu, 6, 2, haut, bas);	
    if(coup.valide!=0 || jeu.joueur!=1)
	puts(" joueur 1/coordonnees pas au bord KO");

    //on test si le coup est non valide si on essaye de deplacer sur une case avec un animal d'orientation non opposée
    int copy_x=x, copy_y=y; //on copie les valeurs de x et y pour introduire une nouvelle piece
    coordonnees_appliquer_deplacement(&copy_x, &copy_y, droite); //on change les coordonnes pour introduire la nouvelle piece
								//à l'endroit desire
    piece_siam *nouvelle_piece = plateau_obtenir_piece(&(jeu.plateau), copy_x, copy_y);
    piece_apres_deplacement->type = rhinoceros; //on est au joueur 1 qui joue les rhino, or à la position x et y a il y a un elephant !
    nouvelle_piece->type = rhinoceros;
    nouvelle_piece->orientation = gauche;


    coup = api_siam_tenter_deplacer_piece_si_possible(&jeu, x, y, droite, droite);	
    if(coup.valide!=0 || jeu.joueur!=1)
	puts(" joueur 1/deplacement sur une case avec un animal non oppose KO");                                         
	


	//on test si le coup est valide si on essaye de deplacer sur une case avec un animal d'orientation non opposée
    nouvelle_piece->orientation = bas;

    coup = api_siam_tenter_deplacer_piece_si_possible(&jeu, x, y, droite, droite);
    if(coup.valide!=0 || jeu.joueur!=1)
        puts(" joueur 0/deplacement sur une case avec un animal non oppose KO");
	
}




