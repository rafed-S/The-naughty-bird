#include "init_jeu.h"


void init_jeu(jeu_t* jeu, SDL_Renderer* renderer){
    jeu->gameover = false;
    jeu->bird = init_bird();
    SDL_Surface* image_bird = SDL_LoadBMP("ressources/bird.bmp");
    jeu->texture_bird = SDL_CreateTextureFromSurface(renderer, image_bird);
  SDL_FreeSurface(image_bird);
  jeu->map = charger_map(jeu, renderer);
}


sprite_t* init_bird(){
    sprite_t* bird = calloc(1,sizeof(sprite_t));
    bird->h = BirdHauteur;
  bird->w = BirdLargeur;
  SDL_Rect dest = {fenetLargeur/2 - bird->w/2, fenetHauteur - (BirdHauteur +1)*2, bird->w, bird->h};
  bird->dest = dest;
  bird->vx = 2.0;
  bird->vy = 2.0;
  return bird;
}

SDL_Renderer* init_sdl(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Probleme au niveau d'initia du SDL(%s)\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

  SDL_Window *window = SDL_CreateWindow("The Naughty Bird",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,fenetLargeur,fenetHauteur,SDL_WINDOW_SHOWN);
  SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

    return rend;
}

map_t* charger_map(jeu_t* jeu, SDL_Renderer* renderer){

  FILE* F = fopen("map.txt", "r");
  map_t* map = malloc(sizeof(map_t));

  if(!F){
    printf("impossible de trouver le fichier");
    SDL_Quit();
  }
    charger_blocs(F, map, renderer);
    charger_niveau(F, map);
    fclose(F);
    map->xGlobal =0;
    map->yGlobal = map->yGlobal*BlocJeu_Hauteur - fenetHauteur ;
  return map;

}


void charger_blocs(FILE* F, map_t* m, SDL_Renderer* renderer){

    int N,i,j;
    char NomFichier[1000], blocs[1000];
    fscanf(F,"%s",NomFichier);
    SDL_Surface* tmp = SDL_LoadBMP("ressources/jeu.bmp");
    if (tmp==NULL)
    {
        printf("Image introuvable !! \n");
        SDL_Quit();
        exit(-1);
    }
    m->tileset = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    
    fscanf(F,"%d %d",&m->x,&m->y);

    m->tabMap = malloc(m->x*m->y*sizeof(tile_t));
    for(j=0,N=0;j<m->y;j++)
    {
        for(i=0;i<m->x;i++,N++)
        {
            m->tabMap[N].rect.w = BlocJeu_Largeur;
            m->tabMap[N].rect.h = BlocJeu_Hauteur;
            m->tabMap[N].rect.x = i*BlocJeu_Largeur;
            m->tabMap[N].rect.y = j*BlocJeu_Hauteur;
            fscanf(F,"%s",blocs);
      
            m->tabMap[N].typeT = 1;
            if (strcmp(blocs,"plein")==0){
                m->tabMap[N].typeT = 0;
            }
            if (strcmp(blocs,"victory") == 0){
                m->tabMap[N].typeT = 2;
            }
        }
    }
}



void charger_niveau(FILE* F,map_t* m){

  int i,j;  
    fscanf(F,"%d %d",&m->x_jeu,&m->y_jeu);
    m->numT = malloc(m->x_jeu*sizeof(int*));

    for(i=0;i<m->x_jeu;i++){
        m->numT[i] = malloc(m->y_jeu*sizeof(int));
    }

    for(j=0;j<m->y_jeu;j++)
    {
        for(i=0;i<m->x_jeu;i++)
        {
            int tmp;
            fscanf(F,"%d",&tmp);
            if (tmp>=m->x*m->y)
            {
                printf("level hors limite\n");
                SDL_Quit();
                exit(-1);
            }
            m->numT[i][j] = tmp;
        }
    }
}
