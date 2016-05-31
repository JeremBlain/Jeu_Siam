#include "type_piece.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


int type_etre_integre(type_piece type)
{
    // L'enumeration designe un type integre si elle est comprise
    //  entre 0 et 4.
    // Une enumeration etant un type non signee, il est forcement positif.
    // Il suffit donc que type soit < 4 pour designer un type valide.
    if(type<4)
        return 1;
    return 0;
}


int type_etre_animal(type_piece type)
{
    if (type<2) //Un éléphant et un rhinocéros correspondent à un entier (soit 0, soit 1).
        // Comme une énumération est un type forcément positif,
        //il suffit que le type soit <2 pour qu'il soit un animal.
        return 1;
 return 0;
}


const char* type_nommer(type_piece type)
{
    // "Look up table" (LUT) convertissant un type de piece vers
    //    la chaine de caractere correspondante.

    switch(type)
    {
    case elephant:
        return "elephant";
    case rhinoceros:
        return "rhinoceros";
    case rocher:
        return "rocher";
    case case_vide:
        return "vide";
    default:
        printf("Erreur, type piece %d non reconnue",type);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}


const char* type_nommer_nom_cours(type_piece type)
{
    // "Look up table" (LUT) convertissant un type de piece vers
    //    la chaine de caractere courte correspondante.

    switch(type)
    {
    case elephant:
        return "e";
    case rhinoceros:
        return "r";
    case rocher:
        return "RRR";
    case case_vide:
        return "***";
    default:
        printf("Erreur, type piece %d non reconnue",type);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

int type_caractere_animal_etre_integre(char type)
{
    // Verifie que le caractere correspond a elephant (e) ou rhinoceros (r).
    if(type=='e' || type=='r')
        return 1;
    return 0;
}

type_piece type_correspondre_caractere_animal(char type)
{
    assert(type_caractere_animal_etre_integre(type));

    type_piece type_enum=elephant;
    if (type=='e')
        type_enum=elephant;

    else
        type_enum=rhinoceros;


    return type_enum;

}

void test_type_etre_integre()
{
    puts("Test type_etre_integre");

    if(type_etre_animal(elephant)!=1)
        puts("elephant KO");

    if(type_etre_animal(rhinoceros)!=1)
        puts("rhinoceros KO");

    if(type_etre_animal(rocher)!=0)
        puts("rocher KO");

   if(type_etre_animal(case_vide)!=0)
        puts("case vide KO");
   int k=0;
   for(k=4;k<20;k++)
       if(type_etre_animal(k)!=0)
           printf("valeur %d KO\n",k);

}

void test_type_nommer()
{
    puts("Test type_nommer");

    if(strcmp(type_nommer(elephant),"elephant")!=0)
        puts("elephant KO");
    if(strcmp(type_nommer(rhinoceros),"rhinoceros")!=0)
        puts("rhinoceros KO");
    if(strcmp(type_nommer(rocher),"rocher")!=0)
        puts("rocher KO");
    if(strcmp(type_nommer(case_vide),"vide")!=0)
        puts("case vide KO");

}

void test_type_nommer_nom_cours()
{
     puts("Test type_nommer_nom_cours");
    if(strcmp(type_nommer_nom_cours(elephant),"e")!=0)
        puts("elephant KO");
    if(strcmp(type_nommer_nom_cours(rhinoceros),"r")!=0)
        puts("rhinoceros KO");
    if(strcmp(type_nommer_nom_cours(rocher),"RRR")!=0)
        puts("rocher KO");
    if(strcmp(type_nommer_nom_cours(case_vide),"***")!=0)
        puts("case vide KO");

}

void test_type_correspondre_caractere_animal()
{
     puts("Test type_correspondre_caractere_animal");
    if(type_correspondre_caractere_animal('e')!=elephant)
        puts("elephant KO");
    if(type_correspondre_caractere_animal('r')!=rhinoceros)
        puts("rhinoceros KO");

}
