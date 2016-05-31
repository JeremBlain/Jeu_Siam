


#include <stdio.h>
#include "type_piece.h"
#include "orientation_deplacement.h"
#include "piece_siam.h"
#include "plateau_siam.h"
#include "coordonnees_plateau.h"
#include "plateau_modification.h"
#include "mode_interactif.h"
#include "api_siam.h"
#include "poussee.h"
#include "entree_sortie.h"

void test_lancer()
{

   	test_type_etre_integre();
   	test_type_nommer();
   	test_type_nommer_nom_cours();
    	test_type_correspondre_caractere_animal();
  	test_orientation_nommer();
   	test_orientation_nommer_nom_cours();
   	test_orientation_inverser();
   	test_orientation_correspondre_caractere();
   	test_piece_etre_integre();
   	test_piece_definir();
    	test_piece_etre_case_vide();
   	test_piece_etre_rocher();
   	test_piece_etre_animal();
   	test_piece_correspondre_nom_cours();
    	test_plateau_etre_integre();
	test_plateau_exister_piece();
	test_coordonnees_etre_bordure_plateau();
	test_coordonnees_appliquer_deplacement();
	test_plateau_modification_changer_orientation_piece_etre_possible();
	test_plateau_modification_changer_orientation_piece();
	test_plateau_modification_introduire_piece_etre_possible();
	test_plateau_modification_introduire_piece();
	test_plateau_modification_deplacer_piece_etre_possible();
	test_plateau_modification_deplacer_piece();
        test_api_siam_tenter_changer_orientation_piece_si_possible();
        test_api_siam_tenter_introduire_nouvelle_piece_si_possible();
	test_api_siam_tenter_deplacer_piece_si_possible();
	test_poussee_etre_valide();
	test_poussee_realiser();
	test_piece_etre_derniere_poussee();
	
	
	return;
}



int main()
{


test_lancer();
mode_interactif_lancer();

plateau_siam plateau;
plateau_initialiser(&plateau);

plateau.piece[0][0].type = elephant;
plateau.piece[0][0].orientation = haut;

FILE *fid = fopen("etat_test", "w");
entree_sortie_ecrire_plateau_pointeur_fichier(fid, &plateau);

return 0;
}
