#include "piece_siam.h"
#include "type_piece.h"
#include "orientation_deplacement.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int piece_etre_integre(const piece_siam* piece)
{

    assert(piece!=NULL);
    int est_animal = type_etre_animal(piece->type);
    int deplacement = orientation_etre_integre_deplacement(piece->orientation);
    if(est_animal==1 && deplacement==1)
        return 1;

    int type_integre = type_etre_integre(piece->type);
    int orientation_integre = orientation_etre_integre(piece->orientation);
    if(est_animal==0 && type_integre==1 && deplacement==0 && orientation_integre == 1)
        return 1;

    return 0;
}

void piece_initialiser(piece_siam* piece)
{
    assert(piece!=NULL);

    piece_definir(piece,case_vide,aucune_orientation);

    assert(piece_etre_integre(piece));
}


int piece_etre_animal(const piece_siam* piece)
{


    assert(piece_etre_integre(piece));
    int est_animal = type_etre_animal(piece->type);
    if(est_animal==1)
        return 1;
    return 0;

}


int piece_etre_rocher(const piece_siam* piece)
{

     assert(piece_etre_integre(piece));
     if(piece->type==2)
        return 1;
     return 0;
}


int piece_etre_case_vide(const piece_siam* piece)
{

    assert(piece_etre_integre(piece));
    if(piece->type==3)
       return 1;
    return 0;
}



void piece_definir(piece_siam* piece,type_piece type,orientation_deplacement orientation)
{
    assert(piece!=NULL);
    piece->type=type;
    piece->orientation=orientation;

    assert(piece_etre_integre(piece));

}


void piece_definir_rocher(piece_siam* piece)
{
    assert(piece!=NULL);
    piece_definir(piece,rocher,aucune_orientation);
    assert(piece_etre_integre(piece));
}

void piece_definir_case_vide(piece_siam* piece)
{
    assert(piece!=NULL);
    piece_definir(piece,case_vide,aucune_orientation);
    assert(piece_etre_integre(piece));
}





orientation_deplacement piece_recuperer_orientation_animal(const piece_siam* piece)
{
    assert(piece!=NULL);
    assert(piece_etre_integre(piece));
    assert(piece_etre_animal(piece));

    return piece->orientation;
}


void piece_afficher(const piece_siam* piece)
{
    assert(piece!=NULL);

    printf("%s,%s",type_nommer(piece->type),orientation_nommer(piece->orientation));
}

void piece_afficher_nom_cours(const piece_siam* piece)
{
    assert(piece!=NULL);

    printf("%s",type_nommer_nom_cours(piece->type));
    if(piece_etre_animal(piece))
        printf("-%s",orientation_nommer_nom_cours(piece->orientation));
}


piece_siam piece_correspondre_nom_cours(const char* nom_cours)
{
    assert(nom_cours!=NULL);
    assert(strlen(nom_cours)==3);

    //Possibilites:
    //
    // - nom vaut "***" -> case vide
    // - nom vaut "RRR" -> rocher
    // - nom commence par "e-" ou "r-"
    //     Alors il s'agit d'un animal.
    //     -> Recuperer le 3eme caractere
    //     -> Le convertir dans l'orientation de l'animal.
    //  - Si aucun des cas precedent, alors affiche erreur.

    piece_siam piece;
    piece_initialiser(&piece);


    if(strncmp(nom_cours,"***",3)==0)
    {
        piece_definir_case_vide(&piece);
    }
    else if(strncmp(nom_cours,"RRR",3)==0)
    {
        piece_definir_rocher(&piece);
    }
    else if((nom_cours[0]=='e' || nom_cours[0]=='r') && nom_cours[1]=='-')
    {
        const type_piece type=type_correspondre_caractere_animal(nom_cours[0]);
        const orientation_deplacement orientation=orientation_correspondre_caractere(nom_cours[2]);

        piece_definir(&piece,type,orientation);
    }
    else
    {
        printf("Erreur fonction %s\n",__FUNCTION__);
        abort();
    }

    return piece;

}

void test_piece_etre_integre()
{

    puts("Test_piece_etre_integre");
    piece_siam piece;
    piece.type=elephant;
    piece.orientation=gauche;
    if(piece_etre_integre(&piece)==0)
        puts("elephant gauche KO");
    piece.orientation=haut;
    if(piece_etre_integre(&piece)==0)
        puts("elephant haut KO");
    piece.orientation=bas;
    if(piece_etre_integre(&piece)==0)
        puts("elephant bas KO");
    piece.orientation=droite;
    if(piece_etre_integre(&piece)==0)
        puts("elephant droite KO");
    piece.orientation=aucune_orientation;
    if(piece_etre_integre(&piece)==1)
        puts("elephant aucune_orientation KO");


    piece.type=rhinoceros;
    piece.orientation=gauche;
    if(piece_etre_integre(&piece)==0)
        puts("rhinoceros gauche KO");
    piece.orientation=haut;
    if(piece_etre_integre(&piece)==0)
        puts("rhino haut KO");
    piece.orientation=bas;
    if(piece_etre_integre(&piece)==0)
        puts("rhino bas KO");
    piece.orientation=droite;
    if(piece_etre_integre(&piece)==0)
        puts("rhino droite KO");
    piece.orientation=aucune_orientation;
    if(piece_etre_integre(&piece)==1)
        puts("rhino aucune_orientation KO");

    piece.type=rocher;
    piece.orientation=aucune_orientation;
    if(piece_etre_integre(&piece)==0)
        puts("rocher aucune orientation KO");
    piece.orientation=gauche;
    if(piece_etre_integre(&piece)==1)
        puts("rocher gauche KO");

    piece.type=case_vide;
    piece.orientation=aucune_orientation;
    if(piece_etre_integre(&piece)==0)
        puts("case vide aucune orientation KO");
    piece.orientation=gauche;
    if(piece_etre_integre(&piece)==1)
        puts("case vide gauche KO");

}

void test_piece_etre_animal()
{

    puts("Test piece etre animal");

    piece_siam piece;
    piece.orientation = gauche;
    piece.type = elephant;
    if(piece_etre_animal(&piece) == 0)
        puts("elephant KO");

    piece.type = rhinoceros;
    if(piece_etre_animal(&piece) == 0)
        puts("rhinoceros KO");

    piece.type = rocher;
    piece.orientation = aucune_orientation;
    if(piece_etre_animal(&piece) == 1)
        puts("rocher KO");

    piece.type = case_vide;
    if(piece_etre_animal(&piece) == 1)
        puts("case vide KO");

}

void test_piece_etre_rocher()
{
    puts("Test piece etre rocher");
    piece_siam piece;
    piece.type = elephant;
    piece.orientation = gauche;
    if(piece_etre_rocher(&piece) == 1)
        puts("elephant KO");

    piece.type = rhinoceros;
    if(piece_etre_rocher(&piece) == 1)
        puts("rhinoceros KO");

    piece.type = rocher;
    piece.orientation = aucune_orientation;
    if(piece_etre_rocher(&piece) == 0)
        puts("rocher KO");

    piece.type = case_vide;
    if(piece_etre_rocher(&piece) == 1)
        puts("case vide KO");
}

void test_piece_etre_case_vide()
{
    puts("Test piece etre case vide");
    piece_siam piece;
    piece.type = elephant;
    piece.orientation = gauche;
    if(piece_etre_case_vide(&piece) == 1)
        puts("elephant KO");

    piece.type = rhinoceros;
    if(piece_etre_case_vide(&piece) == 1)
        puts("rhinoceros KO");

    piece.type = rocher;
    piece.orientation = aucune_orientation;
    if(piece_etre_case_vide(&piece) == 1)
        puts("rocher KO");

    piece.type = case_vide;
    if(piece_etre_case_vide(&piece) == 0)
        puts("case vide KO");
}


//cette fonction de test sert ausi pour les fonctions piece_definir_rocher et piece_definir_case_vide
void test_piece_definir()
{
    puts("Test_piece_definir");
    piece_siam piece;
    piece.type=elephant;
    piece.orientation=gauche;

    piece_definir(&piece,elephant,gauche);
    if(piece.type != elephant && piece.orientation != gauche)
        puts("elephant et gauche KO");
    piece_definir(&piece,elephant,droite);
    if(piece.type != elephant && piece.orientation != droite)
        puts("elephant et droite KO");
    piece_definir(&piece,elephant,haut);
    if(piece.type != elephant && piece.orientation != haut)
        puts("elephant et haut KO");
    piece_definir(&piece,elephant,bas);
    if(piece.type != elephant && piece.orientation != bas)
        puts("elephant et bas KO");

    piece_definir(&piece,rhinoceros,gauche);
    if(piece.type != rhinoceros && piece.orientation != gauche)
        puts("rhinceros et gauche KO");
    piece_definir(&piece,rhinoceros,droite);
    if(piece.type != rhinoceros && piece.orientation != droite)
        puts("rhinoceros et droite KO");
    piece_definir(&piece,rhinoceros,haut);
    if(piece.type != rhinoceros && piece.orientation != haut)
        puts("rhinoceros et haut KO");
    piece_definir(&piece,rhinoceros,bas);
    if(piece.type != rhinoceros && piece.orientation != bas)
        puts("rhinoceros et bas KO");

    piece_definir(&piece,rocher,aucune_orientation);
    if(piece.type != rocher && piece.orientation != aucune_orientation)
        puts("rocher et aucune orientation KO");

    piece_definir(&piece,case_vide,aucune_orientation);
    if(piece.type != case_vide && piece.orientation != aucune_orientation)
        puts("case_vide et aucuneorientation KO");

}

void test_piece_correspondre_nom_cours()
{

    puts("Test piece correspondre nom cours");
    piece_siam piece;
    piece.orientation = aucune_orientation;

    piece.type = case_vide;
    piece_siam test_piece = piece_correspondre_nom_cours("***");
    if(test_piece.type != piece.type || test_piece.orientation != piece.orientation)
        puts("Case vide KO");

    piece.type = rocher;
    test_piece = piece_correspondre_nom_cours("RRR");
    if(test_piece.type != piece.type || test_piece.orientation != piece.orientation)
        puts("rocher KO");

    piece.type = elephant;
    piece.orientation = gauche;
    test_piece = piece_correspondre_nom_cours("e-<");
    if(test_piece.type != piece.type || test_piece.orientation != piece.orientation)
        puts("elephant gauche KO");

    piece.orientation = droite;
    test_piece = piece_correspondre_nom_cours("e->");
    if(test_piece.type != piece.type || test_piece.orientation != piece.orientation)
        puts("elephant droite KO");

    piece.orientation = haut;
    test_piece = piece_correspondre_nom_cours("e-^");
    if(test_piece.type != piece.type || test_piece.orientation != piece.orientation)
        puts("elephant haut KO");

    piece.orientation = bas;
    test_piece = piece_correspondre_nom_cours("e-v");
    if(test_piece.type != piece.type || test_piece.orientation != piece.orientation)
        puts("elephant bas KO");

    piece.type = rhinoceros;
    test_piece = piece_correspondre_nom_cours("r-v");
    if(test_piece.type != piece.type || test_piece.orientation != piece.orientation)
        puts("rhinoceros bas KO");

    piece.orientation = droite;
    test_piece = piece_correspondre_nom_cours("r->");
    if(test_piece.type != piece.type || test_piece.orientation != piece.orientation)
        puts("rhinceros droite KO");

    piece.orientation = haut;
    test_piece = piece_correspondre_nom_cours("r-^");
    if(test_piece.type != piece.type || test_piece.orientation != piece.orientation)
        puts("rhinoceros haut KO");

    piece.orientation = gauche;
    test_piece = piece_correspondre_nom_cours("r-<");
    if(test_piece.type != piece.type || test_piece.orientation != piece.orientation)
        puts("rhinoceros gauche KO");
}
