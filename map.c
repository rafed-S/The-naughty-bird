#include "map.h"
#include <math.h>

/*
void init_mur_1(jeu_t *jeu)
{
    init_sprite(jeu->mur1, 400, 415, MUR_1_LARGEUR, MUR_1_HAUTEUR, 0 ,1);
}
*/

void init_map_niveau_1(jeu_t *jeu)
{
    jeu->tab_mur1_x[0] = 400;
    jeu->tab_mur1_y[0] = 500;
    jeu->tab_mur1_x[1] = 650;
    jeu->tab_mur1_y[1] = 0;
}

void init_map_niveau_2(jeu_t *jeu)
{
    jeu->tab_mur1_x[0] = 700;
    jeu->tab_mur1_y[0] = 500;
    jeu->tab_mur1_x[1] = 1200;
    jeu->tab_mur1_y[1] = 0;
}

void sprite_map_niveau_1(jeu_t *jeu)
{   
    for(int i=0; i<NB_MUR_1; i++)
    {
        init_sprite(jeu->mur1[i], jeu->tab_mur1_x[i], jeu->tab_mur1_y[i], MUR_1_LARGEUR, MUR_1_HAUTEUR, 0 ,1);
    }
}


int crash_condition(jeu_t *jeu, sprite_t *bir)
{
    for(int i=0; i<NB_MUR_1; i++)
    {
       if(bir->x+BIRD_SIZE/2 >= jeu->tab_mur1_x[i] && bir->x-BIRD_SIZE/2 <= jeu->tab_mur1_x[i] +MUR_1_LARGEUR)
        {
            if(bir->y+BIRD_SIZE/2 >= jeu->tab_mur1_y[i] && bir->y-BIRD_SIZE/2 <= jeu->tab_mur1_y[i] + MUR_1_HAUTEUR)
            {
                return 1;
            }
        } 
    }
    if(jeu->bird->x+BIRD_SIZE/2 == WIDTH)
    {
        jeu->niveau = 2;
        return 2; 
    }
    return 0;
}
