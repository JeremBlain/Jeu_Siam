

#ifndef AI_H
#define AI_H

#include "jeu_siam.h"

typedef enum{introduire, deplacer, orienter} instruction;

void ai_joue_tour(jeu_siam *jeu);


void ai_introduction_piece(const char* filename);

void ai_deplacement_piece(plateau_siam *plateau, int ai_nbr_piece, const char* filename);

void ai_orientation_piece(plateau_siam *plateau, int ai_nbr_piece, const char* filename);

void ai_tirage_action(plateau_siam *plateau, int ai_nbr_piece, const char* filename);

#endif
