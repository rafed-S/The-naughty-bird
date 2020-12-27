#include "animation.h"
#include "constante.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h> 

void Animation(SDL_Renderer *renderer, jeu_t *jeu, ressources_t *ressources){
    
    if(ressources->com >=0 && ressources->com<5){
        apply_sprite(renderer, ressources->bird[ressources->af], jeu->bird);
        ressources->com = ressources->com +1;
        if(ressources->com >=5){
            ressources->af =1; 
        }
    }else if(ressources->com >=5 && ressources->com<10){
        apply_sprite(renderer, ressources->bird[ressources->af], jeu->bird);
        ressources->com = ressources->com +1;
        if(ressources->com >=10){
            ressources->af =2; 
        }
    }else if(ressources->com >=10 && ressources->com<15){
        apply_sprite(renderer, ressources->bird[ressources->af], jeu->bird);
        ressources->com = ressources->com +1;
        if(ressources->com >=15){
            ressources->af =3; 
        }
    }else if(ressources->com >=15 && ressources->com<20){
        apply_sprite(renderer, ressources->bird[ressources->af], jeu->bird);
        ressources->com = ressources->com +1;
        if(ressources->com >=20){
            ressources->af =4; 
        }
    }else if(ressources->com >=20 && ressources->com<25){
        apply_sprite(renderer, ressources->bird[ressources->af], jeu->bird);
        ressources->com = ressources->com +1;
        if(ressources->com >=25){
            ressources->af =4; 
        }
    }else if(ressources->com >=25 && ressources->com<30){
        apply_sprite(renderer, ressources->bird[ressources->af], jeu->bird);
        ressources->com = ressources->com +1;
        if(ressources->com >=30){
            ressources->af =3; 
        }
    }else if(ressources->com >=30 && ressources->com<35){
        apply_sprite(renderer, ressources->bird[ressources->af], jeu->bird);
        ressources->com = ressources->com +1;
        if(ressources->com >=35){
            ressources->af =2; 
        }
    }else if(ressources->com >=35 && ressources->com<40){
        apply_sprite(renderer, ressources->bird[ressources->af], jeu->bird);
        ressources->com = ressources->com +1;
        if(ressources->com >=40){
            ressources->af =1; 
        }
    }else if(ressources->com >=40 && ressources->com<45){
        apply_sprite(renderer, ressources->bird[ressources->af], jeu->bird);
        ressources->com = ressources->com +1;
        if(ressources->com >=45){
            ressources->com =0; 
            ressources->af =0; 
        }
    }
}
