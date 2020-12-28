#include "keyboard_event.h"

void handle_events(jeu_t* jeu, SDL_Event* event){

    while( SDL_PollEvent( event ) ) 
    {
        if( event->type == SDL_QUIT ) 
        {
            jeu->gameover = true;
        }

    }

}
