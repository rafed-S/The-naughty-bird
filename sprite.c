
#include "sprite.h"

void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int vitesse)
{
	sprite->x = x;
	sprite->y = y;
	sprite->w = w;
	sprite->h = h;
	sprite->vitesse = vitesse;
}

