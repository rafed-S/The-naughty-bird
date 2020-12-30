#ifndef CONSTANTE
#define CONSTANTE

#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#define fenetHauteur 800
#define fenetLargeur 1100
#define BirdHauteur 100
#define BirdLargeur 100
#define BlocJeu_Hauteur 100
#define BlocJeu_Largeur 100


struct sprite_s
{
    double vx, vy; 
    int w, h; 
    SDL_Rect dest; 
};
typedef struct sprite_s sprite_t;


struct bloc_s
{
    SDL_Rect rect;
    int type
};
typedef struct bloc_s bloc_t;

struct map_s
{
    
    int x, y;
    int x_jeu, y_jeu; 
    tile_t* tabMap;
    int** numT; 
    SDL_Texture* sprite; 
    int xGlobal, yGlobal;
};
typedef struct map_s map_t;



#endif
