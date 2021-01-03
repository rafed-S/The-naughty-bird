/*
 * 
Safour Rafed & Boujamaoui Abdessamad
*
*/
#include "init_jeu.h"

void init_jeu(jeu_t* jeu, SDL_Renderer* renderer)
{
    //On initialise les données du monde :
    jeu->endgame = false;
    jeu->victory = false;
    jeu->bird = init_bird();
    SDL_Surface* image_bird = SDL_LoadBMP("ressources/bird.bmp");
    jeu->texture_bird = SDL_CreateTextureFromSurface(renderer, image_bird);
    SDL_FreeSurface(image_bird);
    jeu->map = charger_map(jeu, renderer);
}

sprite_t* init_bird()
{
    //initialisation de bird
    sprite_t* bird = calloc(1,sizeof(sprite_t));
    bird->h = BirdHauteur;
    bird->w = BirdLargeur;
    SDL_Rect dest = {fenetLargeur/6 - bird->w/6, fenetHauteur - BirdHauteur*4, bird->w, bird->h};
    bird->dest = dest;
    bird->vx = 0.0;
    bird->vy = 0.0;
    return bird;
}

SDL_Renderer* init_sdl()
{   
    //initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'init_jeu de la SDL (%s)\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Window *window = SDL_CreateWindow("The Naughty Bird",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,fenetLargeur, fenetHauteur,SDL_WINDOW_SHOWN);
    SDL_Renderer *pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return pRenderer;
}

map_t* charger_map(jeu_t* jeu, SDL_Renderer* renderer)
{   
    //lire le fichier de map
    FILE* F = fopen("map.txt", "r");
    map_t* map = calloc(1, sizeof(map_t));
    if(!F)
    {
        printf("fichier introuvable");
        SDL_Quit();
        exit(-1);
    }
    charger_tileset(F, map, renderer);
    charger_level(F, map);
    fclose(F);
    map->xCamera =0;
    map->yCamera = map->Y_jeu*TileJeu_Hauteur - fenetHauteur ;
    return map;
}

void charger_tileset(FILE* F, map_t* m, SDL_Renderer* renderer)
{   
    //On initialise et charger les données de map (tile mapping)
    int N,i,j;
    char info[1000];
    char info2[1000]; 
    if(fscanf(F,"%s",info) != 1)
    {
        printf("erreur fscanf");
    }
    SDL_Surface* tmp = SDL_LoadBMP("ressources/jeu.bmp");
    if (tmp==NULL)
    {
        printf("Image introuvable !! \n");
        SDL_Quit();
        exit(-1);
    }
    m->tileset = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if(fscanf(F,"%d %d",&m->xt,&m->yt) != 1)
    {
        printf("erreur fscanf");
    }
    m->tabT = malloc(m->xt*m->yt*sizeof(tile_t));
    for(j=0,N=0;j<m->yt;j++)
    {
        for(i=0;i<m->xt;i++,N++)
        {
            m->tabT[N].rect.w = TileJeu_Largeur;
            m->tabT[N].rect.h = TileJeu_Hauteur;
            m->tabT[N].rect.x = i*TileJeu_Largeur;
            m->tabT[N].rect.y = j*TileJeu_Hauteur;
            if(fscanf(F,"%s %s",info,info2) != 1)
            {
                printf("erreur fscanf");
            }
            m->tabT[N].typeTile = 1;
            if (strcmp(info2,"plein")==0)
            {
                m->tabT[N].typeTile = 0;
            }
            if (strcmp(info2,"victory") == 0)
            {
                m->tabT[N].typeTile = 2;
            }
        }
    }
}

void charger_level(FILE* F,map_t* m)
{
    //On initialise les Types de données pour le map
    int i,j;
    char info[1000];    
    if(fscanf(F,"%d %d",&m->X_jeu,&m->Y_jeu) != 1)
    {
        printf("erreur fscanf");
    }
    m->numT = malloc(m->X_jeu*sizeof(int*));
    for(i=0;i<m->X_jeu;i++)
    {
        m->numT[i] = malloc(m->Y_jeu*sizeof(int));
    }
    for(j=0;j<m->Y_jeu;j++)
    {
        for(i=0;i<m->X_jeu;i++)
        {
        int tmp;
        if(fscanf(F,"%d",&tmp) !=1)
        {
            printf(" ");
        }
            if (tmp>=m->xt*m->yt)
            {
                printf("errore leve\n");
                SDL_Quit();
                exit(-1);
            }
            m->numT[i][j] = tmp;
        }
    }
}
