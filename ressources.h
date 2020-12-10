
#ifndef RESSOURCES_H
#define RESSOURCES_H
#include "constante.h"
#include "fonctions_SDL.h"

typedef struct ressources_s
{
    SDL_Texture *screen;  
    SDL_Texture *bird;       
    SDL_Texture *mur1;         
    SDL_Texture *mur2;         
    SDL_Texture *man;
    SDL_Texture *shit;          
} ressources_t;


void init_ressources(SDL_Renderer *renderer, ressources_t *ressources);
void clean_ressources(ressources_t *ressources);


#endif
