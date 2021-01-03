/*
 * 
Safour Rafed & Boujamaoui Abdessamad
*
*/
#include "keyboard_event.h"

void handle_events(jeu_t* jeu, SDL_Event* event)
{
    //La fonction gèrer les événements
    while( SDL_PollEvent( event ) ) 
    {
        if( event->type == SDL_QUIT ) 
        {
            jeu->endgame = true;
        }
    }
    move_bird(jeu);
}

void move_bird(jeu_t* jeu)
{
    //La fonction gère les interactions de l'utilisateur
    const Uint8* keystates;
    SDL_PumpEvents();
    keystates = SDL_GetKeyboardState(NULL);
    if(keystates[SDL_SCANCODE_DOWN])
    {
        jeu->bird->vy += 0.2;
    }
    if(keystates[SDL_SCANCODE_UP])
    {
        jeu->bird->vy -= 0.2;
    }
    if(keystates[SDL_SCANCODE_ESCAPE])
    {
        jeu->endgame = true;
    }
}
