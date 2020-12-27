
#ifndef SPRITE_H
#define SPRITE_H
#include "constante.h"


typedef struct sprite_s
{
    int x;              // Abscisses par rapport au centre de l'image
    int y;              // Ordionnée par rapport au centre de l'image         
    int h;              // Hauteur du sprite
    int w;              // Largeur du sprite         
    int vitesse;        //(speed) Vitesse de déplacement
    int exist;          //si il est existe dans la jeu

} sprite_t;


void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int vitesse, int exist);


#endif
