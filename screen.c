/*
 * 
Safour Rafed & Boujamaoui Abdessamad
*
*/
#include "screen.h"

void refresh_screen(jeu_t* jeu, SDL_Renderer* renderer)
{   
    //Application du jeu dans le renderer
    SDL_RenderClear(renderer);
    afficher_screen(jeu->map, renderer);
    SDL_RenderCopy(renderer, jeu->texture_bird, NULL, &jeu->bird->dest);
    SDL_RenderPresent(renderer);
}

void afficher_screen(map_t* m, SDL_Renderer* renderer)
{   
    //La fonction permet d'appliquer une texture sur le renderer
    int i,j;
    SDL_Rect Rect_dest = {0,0,TileJeu_Largeur,TileJeu_Hauteur};
    int N;
    int miniX, maxiX, miniY, maxiY;
    miniX = m->xCamera / TileJeu_Largeur;
    miniY = m->yCamera / TileJeu_Hauteur;
    maxiX = (m->xCamera + fenetLargeur)/TileJeu_Largeur;
    maxiY = (m->yCamera + fenetHauteur)/TileJeu_Hauteur;
    for(i=miniX;i<=maxiX;i++)
    {
        for(j=miniY;j<=maxiY;j++)
        {
            Rect_dest.x = i*TileJeu_Largeur - m->xCamera;
            Rect_dest.y = j*TileJeu_Hauteur - m->yCamera;
            if (i<0 || i>=m->X_jeu || j<0 || j>=m->Y_jeu)
                N = 1;
            else
                N = m->numT[i][j];
            SDL_RenderCopy(renderer,m->tileset,&(m->tabT[N].rect),&Rect_dest);
        }
    }
}

void screen_end(jeu_t* jeu, SDL_Renderer* renderer)
{
    //La fonction nettoie une texture en mémoire et vide le contenu graphique
    SDL_Surface* t;
    if(jeu->victory == true)
    {
        t = SDL_LoadBMP("ressources/victory.bmp");
    }else if(jeu->endgame == true)
    {
        t = SDL_LoadBMP("ressources/endgame.bmp");
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, t);
    SDL_FreeSurface(t);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, tex, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(tex);
    SDL_Delay(3000);
}
