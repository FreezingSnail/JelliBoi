#ifndef gameEngine_h
#define gameEngine_h

#include "worldMap.h"
#include "Globals.h"
#include "larva.h";
#include "polyp.h"
#include "pellets.h"
#include "strobilates.h"
#include "fish.h"
#include "medusa.h"

void  larvaStage();
void  PolypStage();
void  StrobilateStage();
void  MedusaStage();
void gameOver();
void  worldDemo();
void getDirection();
void intro();
void beeper();
bool collision();
#endif
