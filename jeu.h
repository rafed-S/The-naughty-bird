
#ifndef jeu_H
#define jeu_H
#include "constante.h"
#include "sprite.h"


typedef struct jeu_s
{
    sprite_t *bird;                
    sprite_t *mur1;                
    sprite_t *mur2;              
    int fin;                 
    int score;                     
} jeu_t;

void init_jeu(jeu_t *jeu);
void clean_jeu(jeu_t *jeu);
int fin_jeu(jeu_t *jeu);


#endif
