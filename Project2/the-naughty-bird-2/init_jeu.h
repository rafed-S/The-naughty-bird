#ifndef INIT_JEU
#define INIT_JEU

#include "constante.h"

struct jeu_s
{
    bool gameover;
    SDL_Texture* texture_bird; 
    sprite_t* bird;
    map_t* map; 

};
typedef struct jeu_s jeu_t;


void init_jeu(jeu_t* jeu, SDL_Renderer* renderer);
sprite_t* init_bird();
SDL_Renderer* init_sdl();
map_t* charger_map(jeu_t* jeu, SDL_Renderer* renderer);
void charger_niveau(FILE* F, map_t* m);


#endif
