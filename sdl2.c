#include "sdl2.h"

int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        fprintf("Erreur initialisation SDL : %s", SDL_GetError());
        return -1;
    }
    if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, window, renderer) != 0)
    {
        fprintf("Erreur dans la creation de l'image ou du renderer : %s", SDL_GetError());
        return -1;
    }
    return 0;
}
