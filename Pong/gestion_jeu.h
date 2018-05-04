#ifndef GESTION_JEU_H_INCLUDED
#define GESTION_JEU_H_INCLUDED
#pragma once

#include "coordonnees.h"
#include "bool.h"
#include "define.h"
#include "game_state.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>




//Prototypes
extern void InitGame(game *myGame,coordonnees *posRaquetteGauche,coordonnees *posRaquetteDroite,coordonnees *posBalle,Bool DeplacementGauche,Bool DeplacementDroite,Bool DeplacementHaut,Bool DeplacementBas);
extern void DeplacementBalle(coordonnees *posBalle,Bool DeplacementGauche,Bool DeplacementDroite,Bool DeplacementHaut,Bool DeplacementBas,int vitesse);


#endif // GESTION_JEU_H_INCLUDED
