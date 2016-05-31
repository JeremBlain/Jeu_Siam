#include "orientation_deplacement.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int orientation_etre_integre(orientation_deplacement orientation)
{
    // L'enumeration designe une orientation integre si elle est compris
    //  entre 0 et 5.
    // Une enumeration etant un type non signee, il est forcement positif.
    // Il suffit donc que type soit < 5 pour designer un type valide.

    if(orientation<5)
        return 1;
    return 0;
}

int orientation_etre_integre_deplacement(orientation_deplacement direction_deplacement)
{
    // Verifie si l'orientation permet le déplacement (haut, bas, gauche, droite)
    // Une enumeration etant un type non signe, il est forcement positif.
    //Il suffit que le type soit inferieur a 4 pour que l'orientation corresponde
    //a un deplacement valide.

    if(direction_deplacement<4)
        return 1;

    return 0;
}

const char* orientation_nommer(orientation_deplacement orientation)
{
    // "Look up table" (LUT) convertissant une orientation vers
    //    la chaine de caractere correspondante.

    switch(orientation)
    {
    case haut:
        return "haut";
    case bas:
        return "bas";
    case gauche:
        return "gauche";
    case droite:
        return "droite";
    case aucune_orientation:
        return "aucune";
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}



const char* orientation_nommer_nom_cours(orientation_deplacement orientation)
{
    // "Look up table" (LUT) convertissant une orientation vers
    //    la chaine de caractere courte correspondante.

    switch(orientation)
    {
    case haut:
        return "^";
    case bas:
        return "v";
    case gauche:
        return "<";
    case droite:
        return ">";
    case aucune_orientation:
        return "????";
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

orientation_deplacement orientation_inverser(orientation_deplacement orientation)
{
    assert(orientation_etre_integre_deplacement(orientation));

    // "Look up table" (LUT) convertissant une orientation vers
    //    son oppose
    // haut   <-> bas
    // droite <-> gauche


    switch(orientation)
    {
    case haut:
        return bas;
    case bas:
        return haut;
    case gauche:
        return droite;
    case droite:
        return gauche;
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}



int orientation_caractere_etre_integre(char orientation)
{
    if(orientation=='<' || orientation=='>' || orientation=='^' || orientation=='v')
        return 1;
    return 0;
}


orientation_deplacement orientation_correspondre_caractere(char orientation)
{
    switch(orientation)
    {
    case '<':
        return gauche;
    case '>' :
        return droite;
    case 'v':
        return bas;
    case '^':
        return haut;
    default :
        printf("Impossible, le caractere %c n'est pas valide (caracteres valides : <, >, ^, v)", orientation);
        abort();
    }

   return 0;
}


void test_orientation_nommer()
{
    puts("Test type_orientation_nommer");

   if(strcmp(orientation_nommer(haut),"haut")!=0)
       puts("haut KO");
   if(strcmp(orientation_nommer(bas),"bas")!=0)
       puts("bas KO");
   if(strcmp(orientation_nommer(gauche),"gauche")!=0)
       puts("gauche KO");
   if(strcmp(orientation_nommer(droite),"droite")!=0)
       puts("droite KO");
   if(strcmp(orientation_nommer(aucune_orientation),"aucune")!=0)
       puts("aucune orientation KO");
}

void test_orientation_nommer_nom_cours()
{
     puts("Test type_orientation_nom_cours");

    if(strcmp(orientation_nommer_nom_cours(haut),"^")!=0)
      puts("haut KO");
    if(strcmp(orientation_nommer_nom_cours(bas),"v")!=0)
      puts("bas KO");
    if(strcmp(orientation_nommer_nom_cours(gauche),"<")!=0)
     puts("gauche KO");
    if (strcmp(orientation_nommer_nom_cours(droite),">")!=0)
      puts("droite KO");
    if (strcmp(orientation_nommer_nom_cours(aucune_orientation),"????")!=0)
      puts("aucune orientation KO");
}

void test_orientation_inverser()
{
    puts("Test type_orientation_inverser");

    if(orientation_inverser(haut)!=bas)
      puts("haut KO");
    if(orientation_inverser(bas)!=haut)
      puts("bas KO");
    if(orientation_inverser(gauche)!=droite)
     puts("gauche KO");
    if (orientation_inverser(droite) != gauche)
      puts("droite KO");
}

void test_orientation_correspondre_caractere()
{
    puts("Test type_orientation_correspondre_caractere");

    if(orientation_correspondre_caractere('v')!=bas)
      puts("haut KO");
    if(orientation_correspondre_caractere('^')!=haut)
      puts("bas KO");
    if(orientation_correspondre_caractere('>')!=droite)
     puts("gauche KO");
    if (orientation_correspondre_caractere('<') != gauche)
      puts("droite KO");
}

void test_orientation_etre_integre()
{
    puts("Test type_orientation_integre");

    if(orientation_etre_integre_deplacement(haut)!=1)
        puts("haut KO");

    if(orientation_etre_integre_deplacement(bas)!=1)
        puts("bas KO");

    if(orientation_etre_integre_deplacement(gauche)!=1)
        puts("gauche KO");

   if(orientation_etre_integre_deplacement(droite)!=1)
        puts("droite KO");
   if(orientation_etre_integre_deplacement(aucune_orientation) != 0)
       puts("aucune orientation KO");

   int k=0;
   for(k=5;k<50;k++)
       if(orientation_etre_integre_deplacement(k)!=0)
           printf("valeur %d KO\n",k);

}
