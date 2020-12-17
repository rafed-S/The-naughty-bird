#include "jeu.h"

void init_jeu(jeu_t *jeu)
{
    jeu->fin = 0;
    jeu->score = 0;
    jeu->niveau = 0;
    
    jeu->bird = malloc(sizeof(sprite_t));
    
    //jeu->mur1 = malloc(sizeof(sprite_t));
    jeu->mur2 = malloc(sizeof(sprite_t));
    
    init_sprite(jeu->bird, BIRD_SIZE/2 , HEIGHT/2, BIRD_SIZE, BIRD_SIZE, BIRD_SPEED,1);
    
    //init_sprite(jeu->mur1, 400, 500, MUR_1_LARGEUR, MUR_1_HAUTEUR, 0 ,1);
    init_data(jeu->mur1, NB_MUR_1);
    init_map_niveau_1(jeu);
    sprite_map_niveau_1(jeu);

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
    for (int i = 0; i < NB_MUR_1; i++)
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
            jeu->shit[i]->y = jeu->bird->y+SHIT_SIZE;
            jeu->shit[i]->x = jeu->bird->x;
        }
        else
        {
            jeu->shit[i]->y += jeu->shit[i]->vitesse;
        }
    }
}

void refresh_bird_horizontal(jeu_t *jeu, sprite_t *b)
{
    b->x += b->vitesse ;
}

void clean_jeu(jeu_t *jeu)
{ 
    free(jeu->bird); 
    
}

int fin_jeu(jeu_t *jeu)
{
    return jeu->fin;
}

void next_niveau(jeu_t *jeu)
{
    init_data(jeu->mur1, NB_MUR_1);
    init_map_niveau_2(jeu);
    sprite_map_niveau_1(jeu);
    init_sprite(jeu->bird, BIRD_SIZE/2 , HEIGHT/2, BIRD_SIZE, BIRD_SIZE, BIRD_SPEED,1);
}



void refresh_game(jeu_t *jeu)
{
    ++jeu->timer;
    //refresh_bird_horizontal(jeu, jeu->bird);
    refresh_shit(jeu);
    
    if(crash_condition(jeu ,jeu->bird) == 1)
    {
        jeu->fin = 1;
    }else if(crash_condition(jeu ,jeu->bird) == 2)
    {
        next_niveau(jeu);
    }
}



