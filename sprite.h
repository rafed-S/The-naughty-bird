
#ifndef SPRITE_H
#define SPRITE_H
#include "constante.h"


typedef struct sprite_s
{
    int x;            
    int y;             
    int h;          
    int w;           
    int vitesse;            

} sprite_t;


void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int vitesse);


#endif
