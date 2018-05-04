#include "game_state.h"
#include "gestion_jeu.h"

int init(char *title,int xpos,int ypos,int width,int height,int flags,game *myGame){

    myGame->g_pRenderer=NULL;
    myGame->g_pTexture=NULL;
    myGame->g_pWindow=NULL;

    //init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
        //creation fenêtre
        myGame->g_pWindow=SDL_CreateWindow(title,xpos,ypos,width,height,flags);

        //ai fenêtre
        if(myGame->g_pWindow!=NULL){
            myGame->g_pRenderer=SDL_CreateRenderer(myGame->g_pWindow,-1,SDL_RENDERER_ACCELERATED);//création rendu
        }
        SDL_SetRenderDrawColor(myGame->g_pRenderer,0,0,0,0);
        }else{
            return 0;
        }

        SDL_RenderClear(myGame->g_pRenderer);
        SDL_RenderPresent(myGame->g_pRenderer);
        return 1;

}

void destroy(game *myGame){

    //Destruction texture
    if(myGame->g_pTexture!=NULL)
        SDL_DestroyTexture(myGame->g_pTexture);
    if(myGame->g_pRenderer!=NULL)
        SDL_DestroyRenderer(myGame->g_pRenderer);
    if(myGame->g_pWindow!=NULL)
        SDL_DestroyWindow(myGame->g_pWindow);

}

void handleEvents(gameState *state,coordonnees *raquetteGauche,coordonnees *raquetteDroite){

    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT://ex clique croix
            state->g_bRunning=0;break;
        case SDL_KEYDOWN://pression touche clavier
            switch (event.key.keysym.sym)
                {
                    case SDLK_z:
                        raquetteGauche->y-=15;break;
                    case SDLK_s:
                        raquetteGauche->y+=15;break;
                    case SDLK_UP:
                        raquetteDroite->y-=15;break;
                    case SDLK_DOWN:
                        raquetteDroite->y+=15;break;
                    case SDLK_ESCAPE:state->g_bRunning=0;break;
                }
                break;

                    case SDL_KEYUP:

                            break;
        }
    }

}

void delay(unsigned int frameLimit){

    unsigned int ticks = SDL_GetTicks();

    if(frameLimit<ticks)
    {
        return;
    }

    if(frameLimit>ticks + 16)
    {
        SDL_Delay(16);
    }
    else
    {
        SDL_Delay(frameLimit-ticks);
    }
}

