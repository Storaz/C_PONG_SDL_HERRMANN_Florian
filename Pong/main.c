#include "main.h"

int main(int argc, char *argv[])
{
    game myGame;
    gameState state;
    coordonnees raqGauche;
    coordonnees raqDroite;
    coordonnees Balle;
    //On initie les déplacement à FAUX
    Bool DeplacementGauche=FALSE;
    Bool DeplacementDroite=FALSE;
    Bool DeplacementHaut=FALSE;
    Bool DeplacementBas=FALSE;
    int vitesse=1;
    unsigned int frameLimit = SDL_GetTicks() + 16;
    raqGauche.x=0,raqGauche.y=(SCREEN_HEIGHT/2)-(TailleRaquette/2);
    raqDroite.x=0,raqDroite.y=(SCREEN_HEIGHT/2)-(TailleRaquette/2);
    Balle.x=(SCREEN_WIDTH/2)-(TailleBalle/2);
    Balle.y=(SCREEN_HEIGHT/2)-(TailleBalle/2);
    int choix=0;

     state.g_bRunning=1;

        while(state.g_bRunning){

                if(choix==0){

                    printf("1:Jouer au jeu\n");
                    scanf("%i",&choix);
                }
                switch (choix){
                        case 1:
                                init("Pong",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&myGame);
                                while(state.g_bRunning){
                                    InitGame(&myGame,&raqGauche,&raqDroite,&Balle,DeplacementGauche,DeplacementDroite,DeplacementHaut,DeplacementBas);
                                    DeplacementBalle(&Balle,DeplacementGauche,DeplacementDroite,DeplacementHaut,DeplacementBas,vitesse);
                                    handleEvents(&state,&raqGauche,&raqDroite);
                                }
                                break;

                        default:state.g_bRunning=0;
                                break;

                }
                 system ("cls");


        }
        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
        destroy(&myGame);
        SDL_Quit();

    return 0;
}

