/*
 * 
Safour Rafed & Boujamaoui Abdessamad
*
*/
#include "init_jeu.h"
#include "jeu.h"
#include "keyboard_event.h"
#include "screen.h"

int main(int argc, char* argv[])
{
    SDL_Renderer *renderer = init_sdl();
    SDL_Event event;
    jeu_t jeu;
    
    //Initialisation du jeu 
    init_jeu(&jeu, renderer);
    
    //Boucle du jeu
    while(!jeu.endgame){

        handle_events(&jeu, &event);
        jeu_update(&jeu);
        refresh_screen(&jeu, renderer);
        SDL_Delay(10);
        
    }
    //Nettoyage final
    screen_end(&jeu, renderer);
    free_jeu(&jeu, renderer);
    SDL_Quit();
}
