#include"screen.h"

void refresh_screen(jeu_t* jeu, SDL_Renderer* renderer){
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, jeu->texture_bird, NULL, &jeu->bird->dest);
    SDL_RenderPresent(renderer);

}

