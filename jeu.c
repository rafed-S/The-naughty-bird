/*
 * 
Safour Rafed & Boujamaoui Abdessamad
*
*/
#define SIGNE(X) (((X)==0)?(0):(((X)<0)?(-1):(1)))
#include "jeu.h"

void jeu_update(jeu_t* jeu)
{
        update_bird(jeu);
        scroll(jeu);
}

void update_bird(jeu_t* jeu)
{    
    if(moving_bird(jeu) == 1)
    {
        mur_bird_collision(jeu);
    }
    update_speeds(jeu->bird);
}

void update_speeds(sprite_t* bird)
{
    bird->vx = 2;
}

int moving_bird(jeu_t* jeu)
{
    //La fonction gère le movement de bird
    SDL_Rect next;
    SDL_Rect prev;
    next = jeu->bird->dest;
    next.x += jeu->bird->vx;
    next.y += jeu->bird->vy;
    if(Collision(jeu, next) == 1)
    {
        prev = jeu->bird->dest;
        jeu->bird->dest = next;
        return 0;
    }
    return 1;
}

void mur_bird_collision(jeu_t* jeu)
{
    //La fonction gère la colision entre le bird et les murs
    int i;  
    for(i=0;i<abs(jeu->bird->vx);i++)
    {
        if(deplacement_bird(jeu, SIGNE(jeu->bird->vx), 0) == 1)
        {
            break;
        }
    }
    for(i=0;i<abs(jeu->bird->vy);i++)
    {
        if(deplacement_bird(jeu, 0, SIGNE(jeu->bird->vy)) == 1)
        {
            break;
        }          
    }
}

int deplacement_bird(jeu_t* jeu, double vx, double vy)
{
    SDL_Rect next;
    SDL_Rect prev;
    next = jeu->bird->dest;
    next.x += vx;
    next.y += vy;
    SDL_Rect test = {0,0,0,0};
    int resTest = Collision(jeu, next);
    if(resTest == 1)
    {
        prev = jeu->bird->dest;
        jeu->bird->dest = next;
        return 0;
    }
    return 1;
}

int Collision(jeu_t* jeu, SDL_Rect bird)
{
    int miniX,maxiX,miniY,maxiY;
    int i,j,indiceT;
    miniX = (bird.x + jeu->map->xCamera) / TileJeu_Largeur;
    miniY = (bird.y + jeu->map->yCamera) / TileJeu_Hauteur;
    maxiX = ((bird.x + bird.w -1) + jeu->map->xCamera) / TileJeu_Largeur;
    maxiY = ((bird.y + bird.h -1) + jeu->map->yCamera) / TileJeu_Hauteur; 
    if (miniX<0 || miniY<0 || maxiX>=jeu->map->X_jeu || maxiY>=jeu->map->Y_jeu)
        return 0;
    for(i=miniX;i<=maxiX;i++)
    {
        for(j=miniY;j<=maxiY;j++)
        {
            indiceT = jeu->map->numT[i][j];
            if (jeu->map->tabT[indiceT].typeTile == 0)
            {
               return 0;
            }
            if(jeu->map->tabT[indiceT].typeTile == 2)
            {
                jeu->endgame = true;
                jeu->victory = true;
            }
        }
    }
    return 1;
}

void scroll(jeu_t* jeu)
{    
    int yp;
    yp = jeu->bird->dest.y + TileJeu_Hauteur/2 + jeu->map->yCamera;
    jeu->map->yCamera = yp - (fenetHauteur/2);
    jeu->bird->dest.y = fenetHauteur/2 - TileJeu_Hauteur/2;
    
    int xp;
    xp = jeu->bird->dest.x + TileJeu_Largeur/2 + jeu->map->xCamera;
    jeu->map->xCamera = xp - (fenetLargeur/2);
    jeu->bird->dest.x = fenetLargeur/2 - TileJeu_Largeur/2;
}


void free_jeu(jeu_t* jeu, SDL_Renderer* renderer)
{
    int i;
    free(jeu->bird);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(jeu->texture_bird);
    SDL_DestroyTexture(jeu->map->tileset);
    free(jeu->map->tabT);
    for(i = 0; i < jeu->map->X_jeu; i++)
    {
        free(jeu->map->numT[i]);
    }
    free(jeu->map->numT);
    free(jeu->map);
}
