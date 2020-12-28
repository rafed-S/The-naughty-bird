#include "init_jeu.h"


void init_jeu(jeu_t* jeu, SDL_Renderer* renderer){
    jeu->gameover = false;
    jeu->bird = init_bird();
    SDL_Surface* image_bird = SDL_LoadBMP("ressources/bird.bmp");
    jeu->texture_bird = SDL_CreateTextureFromSurface(renderer, image_bird);
  SDL_FreeSurface(image_bird);
  jeu->map = charger_map(jeu, renderer);
}


sprite_t* init_bird(){
    sprite_t* bird = calloc(1,sizeof(sprite_t));
    bird->h = BirdHauteur;
  bird->w = BirdLargeur;
  SDL_Rect dest = {fenetLargeur/2 - bird->w/2, fenetHauteur - (BirdHauteur +1)*2, bird->w, bird->h};
  bird->dest = dest;
  bird->vx = 2.0;
  bird->vy = 2.0;
  return bird;
}

SDL_Renderer* init_sdl(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Probleme au niveau d'initia du SDL(%s)\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

  SDL_Window *window = SDL_CreateWindow("The Naughty Bird",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,fenetLargeur,fenetHauteur,SDL_WINDOW_SHOWN);
  SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

    return rend;
}

map_t* charger_map(jeu_t* jeu, SDL_Renderer* renderer){

  FILE* F = fopen("map.txt", "r");
  map_t* map = malloc(sizeof(map_t));

  if(!F){
    printf("impossible de trouver le fichier");
    SDL_Quit();
  }

  return map;
}


void charger_niveau(FILE* F,map_t* m){


}
