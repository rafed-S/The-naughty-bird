#include "keyboard_event.h"

void Evenements(SDL_Event *event, jeu_t *jeu)
{
    while (SDL_PollEvent(event))
    {
        if (event->type == SDL_QUIT)
        {
            jeu->fin = 1;
        }
        if (event->key.keysym.sym == SDLK_ESCAPE)
            {
                jeu->fin = 1;
            }
        if (event->type == SDL_KEYDOWN)
        {
            if (event->key.keysym.sym == SDLK_UP)
            {
                for (int i = 0; i < 10 ; ++i)
                {
                    if (jeu->bird->y - (jeu->bird->h / 2) < 900)
                    {
                        jeu->bird->y = jeu->bird->y - 1;
                    }
                }
            }
            if (event->key.keysym.sym == SDLK_DOWN)
            {
                for (int i = 0; i < 10; ++i)
                {
                    if (jeu->bird->y - (jeu->bird->h / 2) > 0)
                    {
                        jeu->bird->y = jeu->bird->y + 1;
                    }
                }
            }
            
            if (event->key.keysym.sym == SDLK_RIGHT)
            {
                for (int i = 0; i < 10; ++i)
                {
                    if (jeu->bird->x + (jeu->bird->w / 2) < 1800)
                    {
                        jeu->bird->x = jeu->bird->x + 1;
                    }
                }
            }
            if (event->key.keysym.sym == SDLK_LEFT)
            {
                for (int i = 0; i < 10; ++i)
                {
                    if (jeu->bird->x - (jeu->bird->w / 2) > 0)
                    {
                        jeu->bird->x = jeu->bird->x - 1;
                    }
                }
            }
            if (event->key.keysym.sym == SDLK_SPACE)
            {
                for (int i = 0; i < NB_SHITS - 1; i++)
                {
                    if (jeu->shit[0]->exist == 0)
                    {
                        jeu->shit[i]->exist = 1;
                        jeu->shit[i]->vitesse = SHIT_SPEED;
                        i = NB_SHITS - 1;
                    }
                    else if (jeu->shit[i]->exist == 1 && jeu->shit[i + 1]->exist == 0)
                    {
                        jeu->shit[i + 1]->exist = 1;
                        jeu->shit[i + 1]->vitesse = SHIT_SPEED;
                        i = SHIT_SPEED - 1;
                    }
                }
            }
        }
    }
}

