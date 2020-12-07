
#include "jeu.h"

void init_jeu(jeu_t *jeu)
{
	jeu->fin = 0;
	jeu->score = 0;
	jeu->bird = malloc(sizeof(sprite_t));
	jeu->mur1 = malloc(sizeof(sprite_t));
    jeu->mur2 = malloc(sizeof(sprite_t));
	init_sprite(jeu->bird, WIDTH/9, HEIGHT/2, BIRD_SIZE, BIRD_SIZE, BIRD_SPEED);

}

void clean_jeu(jeu_t *jeu) { free(jeu->bird); }

int fin_jeu(jeu_t *jeu)
{
	return jeu->fin;
}




