#pragma once
#include "Globals.h"
#include "pellets.h"

class fish: public pellets {
  public:
  byte fishType; // 

 fish();
 void drawFish();
 void updateFish();
 void resetFish();
 bool fishCollision(int plyrX, int plyrY, int spriteDim);
};

