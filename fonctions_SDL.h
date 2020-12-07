#ifndef __fonctions_SDL__H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "constante.h"
#include "jeu.h"


int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height);
SDL_Texture *charger_image(const char* nomFichier, SDL_Renderer *renderer);
void clean_texture(SDL_Texture *texture);
void clean_sdl(SDL_Renderer *renderer, SDL_Window *window);
void Evenements(SDL_Event *event, jeu_t *jeu);
void apply_texture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y);


#endif
