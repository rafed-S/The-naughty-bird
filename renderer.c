
#include "renderer.h"
#include "constante.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h> 

void Affichage(SDL_Renderer *renderer, jeu_t *jeu, ressources_t *ressources)
{
    SDL_RenderClear(renderer);

if (ressources->screen != NULL)
    {
        apply_texture(ressources->screen, renderer, 0, 0);
        apply_texture(ressources->mur1, renderer, 400, 500);
        apply_texture(ressources->mur1, renderer, 650, 0);
        //apply_texture(ressources->mur2, renderer, 550, 0);
        apply_texture(ressources->man, renderer, 700, 700);
    }
    
    if (jeu->niveau == 2)
    {
        apply_texture(ressources->screen, renderer, 0, 0);
        apply_texture(ressources->mur1, renderer, 700, 500);
        apply_texture(ressources->mur1, renderer, 1200, 0);
        //apply_texture(ressources->mur2, renderer, 550, 0);
        apply_texture(ressources->man, renderer, 1500, 700);
    }

    apply_sprite(renderer, ressources->bird, jeu->bird);
    refresh_sprite_shit(renderer, ressources->shit, jeu->shit, NB_SHITS);
    SDL_RenderPresent(renderer);
    SDL_Delay(10);

}

void clean(SDL_Window *window, SDL_Renderer *renderer, ressources_t *ressources, jeu_t *jeu)
{
    clean_jeu(jeu);
    clean_ressources(ressources);
    clean_sdl(renderer, window);
}

void init(SDL_Window **window, SDL_Renderer **renderer, ressources_t *ressources, jeu_t *jeu)
{
    TTF_Init();
    init_sdl(window, renderer, WIDTH, HEIGHT);
    init_jeu(jeu);
    init_ressources(*renderer, ressources);
}

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite)
{
    apply_texture(texture, renderer, sprite->x - (BIRD_SIZE / 2), sprite->y -  (BIRD_SIZE / 2)); 
}

void refresh_sprite_shit(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *tab[], int total)
{
    for (int i = 0; i < total; i++)
    {
        apply_sprite_shit(renderer, texture, tab[i]);
    }
}

void apply_sprite_shit(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite)
{
    if (sprite->exist == 1)
    {
        apply_texture(texture, renderer, sprite->x - (SHIT_SIZE / 2), sprite->y - (SHIT_SIZE / 2));
    }
}




