

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
 *
 * Implementation des fonction de entree_sortie.
 *
 */



#include "entree_sortie.h"


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_MAX 512


int entree_sortie_fichier_etre_accessible(const char* filename)
{
    assert(filename!=NULL);

    //tente d'ouvir le fichier en ecriture/ajout
    // si le pointeur n'est pas nulle
    //  alors le fichier est accessible
    // sinon le fichier n'est pas accessible
    FILE *fid=NULL;
    fid=fopen(filename,"a+");

    if(fid==NULL)
        return 0;

    fclose(fid);
    return 1;
}

int entree_sortie_fichier_exister(const char* filename)
{

    assert(filename!=NULL);

    //tente d'ouvir le fichier en lecture seule
    // si le pointeur n'est pas nulle
    //  alors le fichier est accessible
    // sinon le fichier n'est pas accessible

    FILE *fid=NULL;
    fid=fopen(filename,"r");

    if(fid==NULL)
        return 0;

    fclose(fid);
    return 1;
}


void entree_sortie_ecrire_jeu_fichier(const char* filename,const jeu_siam* jeu)
{
    assert(filename!=NULL);
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));
    assert(entree_sortie_fichier_etre_accessible(filename)==1);

    // Ouvre fichier
    FILE *fid=NULL;
    fid=fopen(filename,"w");
    assert(fid!=NULL);
    if(fid==NULL) //double protection en mode release
    {
        printf("Erreur ouverture fichier %s\n",filename);
        abort();
    }

    entree_sortie_ecrire_jeu_pointeur_fichier(fid,jeu);

    // Ferme fichier
    int c=fclose(fid);
    if(c!=0) //double protection
    {
        printf("Erreur fermeture fichier %s\n",filename);
        abort();
    }
}



void entree_sortie_lire_jeu_fichier(const char* filename,jeu_siam* jeu)
{
    /*const char* _0x10="joueur 0 (elephant)",*_0x01="joueur 1 (rhinoceros)";
    const char* ___="[%d] %s | %s | %s | %s | %s |",*_0x00=filename;
    jeu_siam* __=jeu,_;int *_00x0=&_.joueur;
    piece_siam (*_0_)(const char*)=piece_correspondre_nom_cours;
    size_t (*_0x50)(const char*)=strlen;piece_siam* _00x02=*_.plateau.piece,*_0x02,_0x03;
    int _00x00_,_10x01_=0x00;char _0x100[0x100],_01x10_[0x05][0x100];
    const char* _for="Erreur ouverture fichier %s\n",*_jeu="Erreur lecture numero de ligne",*_while="Jeu invalide lecture fichier %s\n";
    jeu_initialiser(&_);FILE *_0x100_=fopen(_0x00,"r");assert(_0x100_!=0x00);if(_0x100_==0x00)
    {printf(_for,_0x00);exit(1);}while(fgets(_0x100,0x100,_0x100_)!=0){_00x00_=0x00;
    if(_0x50(_0x100)>=011&&strncmp(_0x100,_0x10,0x13)==0x00){*_00x0=0x00;
    }else if(_0x50(_0x100)>=011&&strncmp(_0x100,_0x01,0x13)
    ==0x00){*_00x0=0x01;}else if(sscanf(_0x100,___,&_00x00_,
    0x00[_01x10_],0x01 [_01x10_],0x02[_01x10_],0x03[_01x10_],0x04[_01x10_])
    ==0x06&&0x08>0x02){if(_00x00_<0x00||_00x00_>0x04){puts(_jeu);abort();}for(_10x01_=0x00;
    _10x01_<0x05;_10x01_+=0x01){_0x02=&(0x05*_10x01_+_00x00_)[_00x02];_0x03=_0_(_10x01_[_01x10_]);
    *_0x02=_0x03;}}}if(jeu_etre_integre(&_))*__=_;else printf(_while,_0x00);*/

    assert(filename!=NULL);
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));
    FILE *fid=NULL;//struct contenant un descripteur de fichier
    fid=fopen(filename,"r");

    //Précaution, mais inutile car on verifie deja avec l'assert que filename different de NULL
    if(fid==NULL)
    {
        printf("Erreur ouverture du fichier %s\n",filename); exit(1);
    }

    char buffer[BUFFER_MAX];
    fscanf(fid, "joueur %d %s\n", &(jeu->joueur),buffer);
    printf("%d\n",jeu->joueur);

    int ky=0, ligne=0;
    char case_0_ky[4]="***", case_1_ky[4]="***", case_2_ky[4]="***", case_3_ky[4]="***", case_4_ky[4]="***";
    plateau_siam plateau;
    plateau_initialiser(&plateau);

	//on va ici lire le fichier ligne par ligne.
    for(ky=4;ky>=0;ky--)
    {
       fscanf(fid,"[%d] %s | %s | %s | %s | %s |\n", &ligne,case_0_ky, case_1_ky, case_2_ky, case_3_ky, case_4_ky);


       printf("%d\n",ligne);

       piece_siam *piece_0_ky = plateau_obtenir_piece(&plateau, 0, ky);
       *piece_0_ky = piece_correspondre_nom_cours(case_0_ky);
       piece_siam *piece_1_ky = plateau_obtenir_piece(&plateau, 1, ky);
       *piece_1_ky = piece_correspondre_nom_cours(case_1_ky);
       piece_siam *piece_2_ky = plateau_obtenir_piece(&plateau, 2, ky);
       *piece_2_ky = piece_correspondre_nom_cours(case_2_ky);
       piece_siam *piece_3_ky = plateau_obtenir_piece(&plateau, 3, ky);
       *piece_3_ky = piece_correspondre_nom_cours(case_3_ky);
       piece_siam *piece_4_ky = plateau_obtenir_piece(&plateau, 4, ky);
       *piece_4_ky = piece_correspondre_nom_cours(case_4_ky);

      }

    jeu->plateau = plateau;
    plateau_afficher(&plateau);

    int c=fclose(fid);
    if(c!=0)
    {
    printf("Erreur fermeture fichier %s\n",filename); exit(1);
    }

}


void entree_sortie_ecrire_jeu_pointeur_fichier(FILE* identifiant,const jeu_siam* jeu)
{
    assert(identifiant!=NULL);
    assert(jeu!=NULL);


    const plateau_siam* plateau=&jeu->plateau;
    assert(plateau!=NULL);

    fprintf(identifiant,"joueur %d (%s)\n",jeu->joueur,type_nommer(jeu_obtenir_type_animal_courant(jeu)));

    entree_sortie_ecrire_plateau_pointeur_fichier(identifiant,plateau);

}





void entree_sortie_ecrire_plateau_pointeur_fichier(FILE* identifiant,const plateau_siam* plateau)
{
    /*const char* (*_00x00_)(type_piece)=type_nommer_nom_cours,*(*_01)(orientation_deplacement)=orientation_nommer_nom_cours;
    FILE* _=identifiant;int _0x00,(*__)(FILE*,const char*,...)=fprintf,_0x01,_0x20,_0x11;
    const piece_siam* _0x10,*_0x02=*plateau->piece;
    for(_0x20  =0x00;_0x20<0x10-0x05;_0x20+=0x01)
    {if(_0x20==0x02){for(_0x00=0x04;_0x00>=0x00;--_0x00)
    {__(_,"[%d] ",_0x00);for(_0x01=0x00;_0x01<010-03&&05<0x080;++_0x01)
    {_0x10=&(0x05*_0x01+_0x00)[_0x02];for(_0x11=0;_0x11<0x04+0x04;++_0x11)
    {if(_0x11==0x05){__(_,"%s",_00x00_(_0x10->type));
    if(_0x10->type==0x00 || _0x10->type==0x01)__(_,"-%s",_01(_0x10->orientation));
    }}__(_," | ");}__(_,"\n");}}}__(_,"    ");for(_0x01=0;_0x01<0x05;++_0x01){
    __(_,"[%d]   ",_0x01);}__(_,"\n");*/

    assert(identifiant!=NULL);
    assert(plateau!=NULL);
    assert(plateau_etre_integre(plateau));


    char buffer[BUFFER_MAX];
    fscanf(identifiant, "%s\n", buffer);
    int kx=0, ky=0;

	//on écrit ici dans la fichier, mais case par case.
	//Ici dans l'affichage, on commence la première ligne à 4 pour aller jusqu'à la 5e ligne 0
	//il faut donc créer une boucle qui part de ky=4 jusqu'à 0
    for(ky=4; ky>=0; ky--)
    {
        fprintf(identifiant,"[%d]", ky); //en début de chaque ligne, on a le numéro de la ligne

        for(kx=0; kx<5; kx++)
        {

           const piece_siam* piece = plateau_obtenir_piece_info(plateau, kx, ky);

		//il faut faire attention, un animal s'écrit sous la forme X-Y alors qu'un Rocher ou une case vid ZZZ
		//on va alors récupérer le X et le Y si c'est un animal et la chaine ZZZ si c'en est pas un
           if(type_etre_animal(piece->type) == 1)
           {
            const char *type = type_nommer_nom_cours(piece->type);
            fprintf(identifiant," %s-%s |",type, orientation_nommer_nom_cours(piece->orientation));
           }
           else
           {
            const char *type = type_nommer_nom_cours(piece->type);
            fprintf(identifiant, " %s |", type);

           }
        }
        fprintf(identifiant, "\n");
    }

fprintf(identifiant, "    [0]   [1]   [2]   [3]   [4]\n"); //on écrit le numéro des colonnes en dessous du tableau
}



