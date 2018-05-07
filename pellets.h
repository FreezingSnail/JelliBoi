#pragma once
#include <stdlib.h>
#include "Globals.h"


class pellets{

  public:
  int xLoc =- -30;
  int yLoc =rand() %48 + 10;
  int moveDirection;
  bool inuse;
  int pelDirect;
  Directions pelDirection;

  explicit pellets();
  
  void updatePellet();
  void drawPellet();
  void resetPellet();
  bool pelletCollision(int plyrX, int plyrY, int spriteDim, int collisionCase);
  
};

void spawnPellets(pellets pelletArray[]);
void updatePellets(pellets pelletArray[]);
void drawPellets(pellets pelletArray[]);
