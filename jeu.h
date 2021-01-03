/*
 * 
Safour Rafed & Boujamaoui Abdessamad
*
*/
#ifndef JEU
#define JEU
#include "constante.h"


void jeu_update(jeu_t* jeu);

void update_bird(jeu_t* jeu);

void update_speeds(sprite_t* bird);

int moving_bird(jeu_t* jeu);

void mur_bird_collision(jeu_t* jeu);

int deplacement_bird(jeu_t* jeu, double vx, double vy);

int Collision(jeu_t* jeu, SDL_Rect bird);

void scroll(jeu_t* jeu);

void free_jeu(jeu_t* jeu, SDL_Renderer* renderer);

#endif
