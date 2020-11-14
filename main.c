#include"renderer.h"
#include"characters.h"
#include"map.h"

int main(int argc, char *args[]){
    
    characters_c characters;
    map_m map;
    SDL_Renderer *renderer;
    SDL_Window *window;
    
    init(&window, &renderer, &characters, &map);
    
    return EXIT_SUCCESS;
}
