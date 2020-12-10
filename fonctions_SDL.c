#include "fonctions_SDL.h"

int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height)
{
if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
{
printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
SDL_Quit();
return EXIT_FAILURE;
}
if(SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, window, renderer)< 0) 
{
printf("Erreur d’initialisation de  la fenetre et le renderer: %s",SDL_GetError());
SDL_Quit();
return EXIT_FAILURE;
}

    return 0;
}

SDL_Texture *charger_image(const char* nomFichier, SDL_Renderer *renderer)
{

    SDL_Texture *texture = NULL;
    SDL_Surface *image = SDL_LoadBMP(nomFichier);
    if (image == NULL )
    {
printf("Erreur dans le chargement de l'image %s",SDL_GetError());
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(renderer, image);
    if (texture == NULL)
    {
printf("Erreur dans la creation de la texture %s",SDL_GetError());
        return NULL;
    }
        SDL_FreeSurface(image);

    return texture;
}

void apply_texture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y)
{
    SDL_Rect rect = {0, 0, 0, 0};

    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    rect.x = x;
    rect.y = y;

    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void clean_texture(SDL_Texture *texture)
{
    if ( texture != NULL)
    {
        SDL_DestroyTexture(texture);
    }
}
 
void clean_sdl(SDL_Renderer *renderer, SDL_Window *window)
{
    if (renderer != NULL && window != NULL ) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);}
        SDL_Quit();
}


// Les evenements du Jeu

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


