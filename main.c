
#ifndef MAIN_C
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "constante.h"
#include "fonctions_SDL.h"
#include "sprite.h"
#include "ressources.h"
#include "jeu.h"
#include "renderer.h"
#endif


void main()
{
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Event event;
	jeu_t jeu1;
	ressources_t ressources;

	init(&window, &renderer, &ressources, &jeu1); 

	do 
	{
		Evenements(&event, &jeu1);
		Affichage(renderer, &jeu1, &ressources);
	} while (fin_jeu(&jeu1)  == 0) ;

	clean(window, renderer, &ressources, &jeu1);

	
}


