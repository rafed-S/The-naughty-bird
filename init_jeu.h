/*
 * 
Safour Rafed & Boujamaoui Abdessamad
*
*/
#ifndef INIT_JEU 
#define INIT_JEU
#include "constante.h"


void init_jeu(jeu_t* jeu, SDL_Renderer* renderer);

sprite_t* init_bird();

SDL_Renderer* init_sdl();

map_t* charger_map(jeu_t* jeu, SDL_Renderer* renderer);

void charger_tileset(FILE* F, map_t* m, SDL_Renderer* renderer);

void charger_level(FILE* F, map_t* m);

#endif
