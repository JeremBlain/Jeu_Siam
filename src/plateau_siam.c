#include "plateau_siam.h"
#include "entree_sortie.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>



void plateau_initialiser(plateau_siam* plateau)
{
    // Initialise l'ensemble des cases du plateau a piece_vide
    // sauf les 3 cases du milieu avec un rocher (2,1), (2,2) et (2,3)
    //
    // L'etat de l'echiquier initial est le suivant:
    //
    // [4] *** | *** | *** | *** | *** |
    // [3] *** | *** | *** | *** | *** |
    // [2] *** | RRR | RRR | RRR | *** |
    // [1] *** | *** | *** | *** | *** |
    // [0] *** | *** | *** | *** | *** |
    //     [0]   [1]   [2]   [3]   [4]
    //


    int kx=0;
    for(kx=0;kx<NBR_CASES;++kx)
    {
        int ky=0;
        for(ky=0;ky<NBR_CASES;++ky)
        {
            piece_siam* piece=plateau_obtenir_piece(plateau,kx,ky);
            assert(piece!=NULL);

            if(ky==2 && (kx>=1 && kx<=3) )
                piece_definir_rocher(piece);
            else
                piece_definir_case_vide(piece);
        }
    }

    assert(plateau_etre_integre);
}



piece_siam* plateau_obtenir_piece(plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(coordonnees_etre_dans_plateau(x,y));


    piece_siam* piece=&(plateau->piece[x][y]);

    return piece;
}

const piece_siam* plateau_obtenir_piece_info(const plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);

    assert(coordonnees_etre_dans_plateau(x,y));

    const piece_siam* piece=&(plateau->piece[x][y]);

    return piece;
}


int plateau_denombrer_type(const plateau_siam* plateau,type_piece type)
{
    assert(plateau!=NULL);
    //Algorithme :

    //Initialiser compteur à 0
    // Pour toutes les cases du tableau
    // SI case courante est du type souhaite
    //          Increment du compteur
    //renvoie compteur
    int compteur=0;
    int kx=0;

    for(kx=0;kx<NBR_CASES;++kx)
    {
        int ky=0;
        for(ky=0;ky<NBR_CASES;++ky)
        {
             const piece_siam* piece=plateau_obtenir_piece_info(plateau,kx,ky);
             assert(piece!=NULL);

             if(piece->type==type)
                 compteur++;
        }
    }
    return compteur;
}
int plateau_etre_integre(const plateau_siam* plateau)
{
    //Verifie si chaque pieces (y compris les cases vides) du plateau est integre.
    // Si elles le sont, elle verifie que le nombre de rhinoceros et d'elephants est compris entre 0
    // et 5 (inclu), et que le nombre de rochers est compris entre 0 et 3 (inclu).
    //
    // Comme le compteur est initialise a 0 dans la fonction plateau_denombrer_type, on verifie juste
    // que le nombre de pieces est bien inferieur a 3 ou 5.
    assert(plateau!=NULL);
    int kx=0;
    for(kx=0;kx<NBR_CASES;++kx)
    {
        int ky=0;
        for(ky=0;ky<NBR_CASES;++ky)
        {
             const piece_siam* piece=plateau_obtenir_piece_info(plateau,kx,ky);
             assert(piece!=NULL);

             if(piece_etre_integre(piece)==0)
                 return 0;

        }
    }

    if(plateau_denombrer_type(plateau, elephant)>5)
        return 0;

    if(plateau_denombrer_type(plateau, rhinoceros)>5)
        return 0;
    if(plateau_denombrer_type(plateau, rocher)>3)
       	return 0;

    return 1;

}

int plateau_exister_piece(const plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(coordonnees_etre_dans_plateau(x,y));


    if(piece_etre_animal(&(plateau->piece[x][y]))==1 || piece_etre_rocher(&(plateau->piece[x][y]))==1)
        return 1;

    return 0;
}

void plateau_afficher(const plateau_siam* plateau)
{
    assert(plateau!=NULL);

    //utilisation d'une fonction generique d'affichage
    // le parametre stdout permet d'indiquer que l'affichage
    // est realise sur la ligne de commande par defaut.
    entree_sortie_ecrire_plateau_pointeur_fichier(stdout,plateau);

}


//Fonctions de test
void test_plateau_etre_integre()
{

    puts("Test plateau etre integre");

    plateau_siam plateau;
    plateau_initialiser(&plateau);

    piece_siam Elephant;
    Elephant.type = elephant;
    Elephant.orientation=gauche;

    plateau.piece[1][1] = Elephant;
    plateau.piece[4][1] = Elephant;
    plateau.piece[3][4] = Elephant;
    plateau.piece[2][1] = Elephant;
    plateau.piece[0][3] = Elephant;

    piece_siam Rhino;
    Rhino.type = rhinoceros;
    Rhino.orientation=gauche;
    plateau.piece[1][2] = Rhino;
    plateau.piece[4][2] = Rhino;
    plateau.piece[3][1] = Rhino;
    plateau.piece[2][2] = Rhino;
    plateau.piece[1][3] = Rhino;

    if(plateau_etre_integre(&plateau) != 1)
        puts("Plateau KO");
}

void test_plateau_exister_piece()
{
	puts("Test plateau exister piece");

	plateau_siam plateau;
	plateau_initialiser(&plateau);
		
	plateau.piece[1][1].type = elephant;
	plateau.piece[1][1].orientation = gauche;

	plateau.piece[1][2].type = rhinoceros;
	plateau.piece[1][2].orientation = gauche;

	if( plateau_exister_piece(&plateau, 1 , 1) !=1 )
		puts("elephant KO");

	if( plateau_exister_piece(&plateau, 1 , 2) !=1 )
		puts("Rhinoceros KO");

	if( plateau_exister_piece(&plateau, 2, 2) !=1 )
		puts("Rocher KO");

	if( plateau_exister_piece(&plateau, 0 , 0) !=0 )
		puts("case_vide KO");
}



