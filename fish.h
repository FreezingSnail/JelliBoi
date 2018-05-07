#pragma once
#include "Globals.h"
#include "pellets.h"

class fish: public pellets {
  public:
  byte fishType; // 

 fish();
 virtual void drawFish();
 virtual void updateFish();
 void resetFish();
 virtual bool fishCollision(int plyrX, int plyrY, int spriteDim, int caseType);
};


class bigFish: public fish{
  public:
  bigFish();
  virtual void drawBigFish();
  virtual void updateBigFish();
  virtual bool fishBigCollision(int plyrX, int plyrY, int spriteDim, int caseType);
  void resetBigFish();
};

