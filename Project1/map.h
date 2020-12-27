#ifndef MAP_H
#define MAP_H
#include "jeu.h"
#include "constante.h"


void init_map_niveau_1(jeu_t *jeu);
void init_map_niveau_2(jeu_t *jeu);
void sprite_map_niveau_1(jeu_t *jeu);

int crash_condition(jeu_t *jeu, sprite_t *bir);

#endif
