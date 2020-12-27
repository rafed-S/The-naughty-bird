
#ifndef RENDERER_H
#define RENDERER_H
#include "constante.h"
#include "jeu.h"
#include "ressources.h"


void clean(SDL_Window *window, SDL_Renderer *renderer, ressources_t *ressources, jeu_t *jeu);
void Affichage(SDL_Renderer *renderer, jeu_t *jeu, ressources_t *ressources);
void init(SDL_Window **window, SDL_Renderer **renderer, ressources_t *ressources, jeu_t *jeu);
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);
void refresh_sprite_shit(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *tab[], int total);
void apply_sprite_shit(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);
#endif
