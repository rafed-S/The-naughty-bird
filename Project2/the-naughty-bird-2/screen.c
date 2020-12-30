#include"screen.h"

void refresh_screen(jeu_t* jeu, SDL_Renderer* renderer){
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, jeu->texture_bird, NULL, &jeu->bird->dest);
    SDL_RenderPresent(renderer);

}

void screen_end(jeu_t* jeu, SDL_Renderer* renderer){	
    SDL_Surface* end;
    if(jeu->victory == true){
        end = SDL_LoadBMP("ressources/bitmaps/victory.bmp");
    }else if(jeu->endgame == true){
        end = SDL_LoadBMP("ressources/bitmaps/endscreen.bmp");
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, end);
    SDL_FreeSurface(end);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, tex, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(tex);
    SDL_Delay(3000);
}