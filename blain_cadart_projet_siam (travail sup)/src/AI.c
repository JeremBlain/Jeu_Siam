
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h> //besoin pour les nombres aleatoires


#include "AI.h"



/*Algorithme de l'IA (joue des coups aléatoires)
On écrira les instructions jouées par l'AI dans un fichier et on considère qu'elle joue les rhino
	on dénombre les pieces appartant à l'IA
	Si pas de piece => on introduit une piece au hasard au bord  
	Si piece :
		on choisit au hasard une action (intro, deplacer, orienter)
		Si c'est une introduction on choisit deux nombres nombres au hasard pour mettre la piece sur la plateau
		Sinon (déplacement ou orientation) :
			on parcourt le tableau, et à chaque piece trouvee, 
			on tire un nombre aléatoire pour savoir si on joue cette piece
				si on tombe sur le bon chiffre => on tire aléatoirement une orientation
				sinon on continue le parcourt jusqu'à tomber sur le bon chiffre sur une piece
*/
void ai_joue_tour(jeu_siam *jeu)
{
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));

    
    int nbr_piece_ai = plateau_denombrer_type( &(jeu->plateau), rhinoceros);

    const char *filename="AI_instructions.txt";

    if(nbr_piece_ai == 0)
    {
	ai_introduction_piece(filename);  
	return; 
    }

   ai_tirage_action(&(jeu->plateau), nbr_piece_ai, filename);

}

void ai_introduction_piece(const char* filename)
{
	srand(time(NULL)); //pour générer des nombres aleatoires

	int x=0, y=0;
	//on génère la position x et y ainsi que l'orientation aléatoirement
	do
	{
		x = rand()%NBR_CASES;
		y = rand()%NBR_CASES;
	}while(coordonnees_etre_bordure_plateau(x,y) != 1); //saisie protégée pour que les coordonnees soient au bord

	orientation_deplacement orientation = rand()%4;

	FILE *fid=fopen(filename,"w");
	const char* char_orien =orientation_nommer_nom_cours(orientation);
	fprintf(fid, "n %d %d %c", x, y, *char_orien);

	int c=fclose(fid);
   	if(c!=0)
   	{
    		printf("Erreur fermeture fichier %s\n", "AI_instructions.txt"); exit(1);
   	}
	return;
}

void ai_deplacement_piece(plateau_siam *plateau, int ai_nbr_piece, const char* filename)
{
	srand(time(NULL));

	int ky=0;
	for(ky=0; ky<NBR_CASES; ++ky)
	{
		int kx=0;
		for(kx=0; kx<NBR_CASES; ++kx)
		{
			const piece_siam *piece = plateau_obtenir_piece_info(plateau, kx, ky);
			//si la piece appartient à l'AI (rhino)
			if(piece->type == rhinoceros)
			{
				 //alors on choisit un nbr aléatoire entre 0 et le nbr de piece que possède l'AI
				int piece_choisie = rand()%ai_nbr_piece; 
				if(piece_choisie==0) //si ce nombre est 0, alors on deplace cette piece 
				{
					orientation_deplacement orientation = rand()%4;	
					FILE *fid=fopen(filename,"w");
					const char* char_orien = orientation_nommer_nom_cours(orientation);
					fprintf(fid, "d %d %d %d %c", kx, ky, orientation, *char_orien);

					int c=fclose(fid);
   					if(c!=0)
   					{
    						printf("Erreur fermeture fichier %s\n", "AI_instructions.txt"); exit(1);
   					}
				}		
			}
		}
	}
}

void ai_orientation_piece(plateau_siam *plateau, int ai_nbr_piece, const char* filename)
{
	srand(time(NULL));

	int ky=0;
	for(ky=0; ky<NBR_CASES; ++ky)
	{
		int kx=0;
		for(kx=0; kx<NBR_CASES; ++kx)
		{
			const piece_siam *piece = plateau_obtenir_piece_info(plateau, kx, ky);
			//si la piece appartient à l'AI (rhino)
			if(piece->type == rhinoceros)
			{
				 //alors on choisit un nbr aléatoire entre 0 et le nbr de piece que possède l'AI
				int piece_choisie = rand()%ai_nbr_piece; 
				if(piece_choisie==0) //si ce nombre est 0, alors on deplace cette piece 
				{
					orientation_deplacement orientation = rand()%4;	
					FILE *fid=fopen(filename,"w");
					const char* char_orien = orientation_nommer_nom_cours(orientation);
					fprintf(fid, "o %d %d %c", kx, ky, *char_orien);

					int c=fclose(fid);
   					if(c!=0)
   					{
    						printf("Erreur fermeture fichier %s\n", "AI_instructions.txt"); exit(1);
   					}
				}		
			}
		}
	}
}

void ai_tirage_action(plateau_siam *plateau, int ai_nbr_piece, const char* filename)
{
	srand(time(NULL));

	int action_realiser = rand()%3;

	if(action_realiser == introduire)
     	{
		ai_introduction_piece(filename);
	}

	if(action_realiser == deplacer)
     	{
		ai_deplacement_piece(plateau, ai_nbr_piece, filename);
	}

	if(action_realiser == orienter)
     	{
		ai_orientation_piece(plateau, ai_nbr_piece, filename);
	}
}



