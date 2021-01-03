/*
 * 
Safour Rafed & Boujamaoui Abdessamad
*
*/
#ifndef CONSTANTE
#define CONSTANTE
#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#define fenetHauteur 800
#define fenetLargeur 1100
#define BirdHauteur 100
#define BirdLargeur 100
#define TileJeu_Hauteur 100
#define TileJeu_Largeur 100


struct sprite_s         /* Représentation d'un sprite */
{
    double vx, vy;
    int w, h;
    SDL_Rect dest;
};
typedef struct sprite_s sprite_t;


struct tile_s           /* til mapping */
{
    SDL_Rect rect;
    int typeTile;
};
typedef struct tile_s tile_t;


struct map_s            /* map du jeu */
{
    int xt, yt;
    int X_jeu, Y_jeu;
    tile_t* tabT;
    SDL_Texture* tileset;
    int** numT;
    int xCamera, yCamera;
};
typedef struct map_s map_t;


struct jeu_s            /* Représentation du monde du jeu */
{
    bool endgame;
    bool victory;
    sprite_t* bird;
    map_t* map;
    SDL_Texture* texture_bird;
};
typedef struct jeu_s jeu_t;

#endif
