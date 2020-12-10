#include "jeu.h"

void init_jeu(jeu_t *jeu)
{
    jeu->fin = 0;
    jeu->score = 0;
    jeu->bird = malloc(sizeof(sprite_t));
    jeu->mur1 = malloc(sizeof(sprite_t));
    jeu->mur2 = malloc(sizeof(sprite_t));
    init_sprite(jeu->bird, WIDTH/9, HEIGHT/2, BIRD_SIZE, BIRD_SIZE, BIRD_SPEED,1);
    init_data(jeu->shit, NB_SHITS);
    init_shit(jeu);

}

void init_data(sprite_t *tab[], int total)
{
    for (int i = 0; i < total; i++)
    {
        tab[i] = malloc(sizeof(sprite_t));
    }
}

void init_shit(jeu_t *jeu)
{
    for (int i = 0; i < NB_SHITS; i++)
    {
        init_sprite(jeu->shit[i], jeu->bird->x, jeu->bird->y, SHIT_SIZE, SHIT_SIZE, 0 ,0);
    }
}

void refresh_shit(jeu_t *jeu)
{
    for (int i = 0; i < NB_SHITS; i++)
    {
        if (jeu->shit[i]->exist == 0)
        {
            jeu->shit[i]->y = jeu->bird->y;
            jeu->shit[i]->x = jeu->bird->x;
        }
        else
        {
            jeu->shit[i]->y += jeu->shit[i]->vitesse;
        }
    }
}

void refresh_game(jeu_t *jeu)
{
    refresh_shit(jeu);
}

void clean_jeu(jeu_t *jeu)
{ 
    free(jeu->bird); 
    
}

int fin_jeu(jeu_t *jeu)
{
	return jeu->fin;
}




