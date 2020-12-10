#include "ressources.h"


void init_ressources(SDL_Renderer *renderer, ressources_t *ressources)
{
    ressources->screen = charger_image("ressources/background.bmp", renderer);
    ressources->bird = charger_image("ressources/bird-1.bmp", renderer);
    ressources->mur1= charger_image("ressources/obstacleG1.bmp", renderer);
    ressources->mur2= charger_image("ressources/obstacleP2.bmp", renderer);
    ressources->man= charger_image("ressources/man.bmp", renderer);
    ressources->shit= charger_image("ressources/shit.bmp", renderer);
}

void clean_ressources(ressources_t *ressources)
{
    clean_texture(ressources->screen);
    clean_texture(ressources->bird);
    clean_texture(ressources->mur1);
    clean_texture(ressources->mur2);
    clean_texture(ressources->man);
}

