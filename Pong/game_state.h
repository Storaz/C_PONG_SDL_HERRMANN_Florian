#ifndef GAME_STATE_H_INCLUDED
#define GAME_STATE_H_INCLUDED
#pragma once

#include "coordonnees.h"

#include <SDL2/SDL.h>

typedef struct game{

    SDL_Window *g_pWindow;
    SDL_Renderer *g_pRenderer;
    SDL_Texture *g_pTexture;

}game;

typedef struct gameState{

    int g_bRunning;

}gameState;

//Prototypes
extern int init(char *title,int xpos,int ypos,int width,int height,int flags,game *myGame);
extern void handleEvents(gameState *state,coordonnees *raquetteGauche, coordonnees *raquetteDroite);
extern void delay(unsigned int frameLimit);
extern void destroy(game *myGame);

#endif // GAME_STATE_H_INCLUDED
