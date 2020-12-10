
#ifndef jeu_H
#define jeu_H
#include "constante.h"
#include "sprite.h"


typedef struct jeu_s
{
    sprite_t *bird;             // Sprite du bird            
    sprite_t *mur1;             // Sprite du Obstacle 1       
    sprite_t *mur2;             // Sprite du Obstacle 2
    int fin;                    // Champ indiquant si on est à la fin du jeu
    int score;                  // score de bird    
    sprite_t *shit[NB_SHITS];   // Sprites des shits
} jeu_t;

void init_data(sprite_t *tab[], int total);
void init_shit(jeu_t *jeu);
void refresh_shit(jeu_t *jeu);
void refresh_game(jeu_t *jeu);
void init_jeu(jeu_t *jeu);
void clean_jeu(jeu_t *jeu);
int fin_jeu(jeu_t *jeu);


#endif