#include "init_jeu.h"
#include "jeu.h"
#include "keyboard_event.h"
#include "screen.h"

int main(int argc, char* argv[])
{
    SDL_Renderer *renderer;
    SDL_Event event;
    jeu_t jeu;
    renderer = init_sdl();
    init_jeu(&jeu, renderer);
    
  while(!jeu.endgame){

        handle_events(&jeu, &event);
    }
    
    screen_end(&jeu, renderer);
    SDL_Quit(); 

}

