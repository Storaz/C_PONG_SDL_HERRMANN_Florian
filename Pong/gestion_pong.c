#include "gestion_jeu.h"


void InitGame(game *myGame,coordonnees *posRaquetteGauche,coordonnees *posRaquetteDroite,coordonnees *posBalle,Bool DeplacementGauche,Bool DeplacementDroite,Bool DeplacementHaut,Bool DeplacementBas){

    //On initialise le déplacement de base de la balle
    DeplacementHaut=TRUE;
    DeplacementBas=FALSE;
    DeplacementDroite=FALSE;
    DeplacementGauche=FALSE;

    //On dessine la raquette de gauche
    SDL_Rect RaquetteGauche;
    RaquetteGauche.x=0;//debut x
    if(posRaquetteGauche->y<0){ //On limite les déplacements de la raquette afin d'éviter qu'elle ne sorte de l'écran
        posRaquetteGauche->y=0;
    }else if(posRaquetteGauche->y+TailleRaquette>SCREEN_HEIGHT){
        posRaquetteGauche->y=SCREEN_HEIGHT-TailleRaquette;
    }
    RaquetteGauche.y=posRaquetteGauche->y;
    RaquetteGauche.w=10; //Largeur
    RaquetteGauche.h=TailleRaquette;//Hauteur

    //On dessine la raquette de droite
    SDL_Rect RaquetteDroite;
    RaquetteDroite.x=SCREEN_WIDTH-10;//debut x
    if(posRaquetteDroite->y<0){ //On limite les déplacements de la raquette afin d'éviter qu'elle ne sorte de l'écran
        posRaquetteDroite->y=0;
    }else if(posRaquetteDroite->y+TailleRaquette>SCREEN_HEIGHT){
        posRaquetteDroite->y=SCREEN_HEIGHT-TailleRaquette;
    }
    RaquetteDroite.y=posRaquetteDroite->y;
    RaquetteDroite.w=10; //Largeur
    RaquetteDroite.h=TailleRaquette; //Hauteur

    //On dessine la balle
    SDL_Rect Balle;
    Balle.x=posBalle->x;
    Balle.y=posBalle->y;
    Balle.w=TailleBalle;
    Balle.h=TailleBalle;

    //Draw in Render
    SDL_SetRenderDrawColor(myGame->g_pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(myGame->g_pRenderer);

    SDL_SetRenderDrawColor(myGame->g_pRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderDrawRect(myGame->g_pRenderer,&RaquetteGauche);
    SDL_RenderDrawRect(myGame->g_pRenderer,&RaquetteDroite);
    SDL_RenderDrawRect(myGame->g_pRenderer,&Balle);


    SDL_RenderFillRect(myGame->g_pRenderer, &RaquetteGauche);
    SDL_RenderFillRect(myGame->g_pRenderer, &RaquetteDroite);
    SDL_RenderFillRect(myGame->g_pRenderer, &Balle);

    SDL_RenderPresent(myGame->g_pRenderer);

}

void DeplacementBalle(coordonnees *posBalle,Bool DeplacementGauche,Bool DeplacementDroite,Bool DeplacementHaut,Bool DeplacementBas,int vitesse){

    //float scale=1.1;

    //if(DeplacementHaut==TRUE){
        posBalle->y-=vitesse;//On déplace la balle en modifiant sa position
    //}
}
