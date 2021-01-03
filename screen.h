/*
 * 
Safour Rafed & Boujamaoui Abdessamad
*
*/

#ifndef SCREEN 
#define SCREEN
#include "constante.h"


void refresh_screen(jeu_t* jeu, SDL_Renderer* renderer);

void afficher_screen(map_t* m, SDL_Renderer* renderer);
 
void screen_end(jeu_t* jeu, SDL_Renderer* renderer);

#endif
