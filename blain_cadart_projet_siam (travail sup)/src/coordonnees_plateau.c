#include "coordonnees_plateau.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int coordonnees_etre_dans_plateau(int x,int y)
{
    if((x>=0 && x<NBR_CASES) && (y>=0 && y<NBR_CASES))
        return 1;
    return 0;
}

int coordonnees_etre_bordure_plateau(int x,int y)
{
    //Verifie que les coordonnees passees en parametres sont bien dans le plateau.
    //Verifie que les coordonnees correspondent a un bord du plateau, cad si x, ou y valent
    // soit 0 soit NBR_CASES-1.
    assert(coordonnees_etre_dans_plateau(x,y));
    if(x==0 || y==0 || y==NBR_CASES-1 || x==NBR_CASES-1 )
        return 1;
    return 0;
}

void coordonnees_appliquer_deplacement(int* x,int* y,orientation_deplacement orientation)
{
    assert(x!=NULL);
    assert(y!=NULL);
    assert(orientation_etre_integre_deplacement(orientation));

    // Table de correspondance:
    //  haut   -> (x,y+1)
    //  bas    -> (x,y-1)
    //  gauche -> (x-1,y)
    //  droite -> (x+1,y)

    switch(orientation)
    {
    case haut:
        *y+=1;
        break;
    case bas:
        *y-=1;
        break;
    case gauche:
        *x-=1;
        break;
    case droite:
        *x+=1;
        break;
    default:
        printf("Probleme fonction %s\n",__FUNCTION__);
    }
}


//Fonctions de Test

void test_coordonnees_etre_bordure_plateau()
{
	puts("Test coordonnes etre bordure plateau");

	int kx=0;
	for(kx=0; kx<NBR_CASES; kx++)
	{	
		if ( coordonnees_etre_bordure_plateau(kx, 0) !=1 )	//on test si les cases du bord haut sont bien au bord
			printf("Case ( kx = %d, ky = 0) KO \n", kx);
		if ( coordonnees_etre_bordure_plateau(kx, NBR_CASES-1) !=1 )	//idem pour les cases du bas
			printf("Case ( kx = %d, ky = %d) KO \n", kx, NBR_CASES-1);
	}

	int ky=0;
//pour les cases à gauche et à droite, on commence à partir de y = 1 et on finit à NBR_CASES-2 car les cases 0 et NBR_CASES-1 ont
//déjà été faites dans la première boucle 
	for(ky=1; ky<NBR_CASES-1; ky++)
	{
		if ( coordonnees_etre_bordure_plateau(0, ky) !=1 )	//on test si les cases du bord haut sont bien au bord
			printf("Case ( kx = 0, ky = %d) KO \n", ky);
		if ( coordonnees_etre_bordure_plateau(NBR_CASES-1, ky) !=1 )	//idem pour les cases du bas
			printf("Case ( kx = %d, ky = %d) KO \n", NBR_CASES-1, ky);
	}

	for(kx=1; kx<NBR_CASES-1; kx++)
	{
		for(ky=1; ky<NBR_CASES-1; ky++)
		{
			if ( coordonnees_etre_bordure_plateau(kx, ky) !=0 )	//on test si les cases du milieu ne sont
			printf("Case ( kx = %d, ky = %d) KO \n", kx, ky);	//pas au bord
		}
	}
}

void test_coordonnees_appliquer_deplacement()
{
	puts("Test coordonnees appliquer deplacement");
	
	int *x=NULL, *y=NULL;
	int a=1, b=1;
	x=&a; y=&b;

 	coordonnees_appliquer_deplacement(x, y, gauche); // x vaut 0 après appel de la fonction
	if( *x !=0 || *y != 1)	
		puts("deplacement gauche KO");

	coordonnees_appliquer_deplacement(x, y, droite); // x vaut 1 après appel de la fonction
	if( *x !=1 || *y != 1)
		puts("deplacement droite KO");

	coordonnees_appliquer_deplacement(x, y, bas); // y vaut 0 après appel de la fonction
	if( *x !=1 || *y != 0)
		puts("deplacement bas KO");

	coordonnees_appliquer_deplacement(x, y, haut); // y vaut 1 après appel de la fonction
	if( *x !=1 || *y != 1)
		puts("deplacement haut KO");
}




