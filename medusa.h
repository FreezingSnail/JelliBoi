#pragma once
#include "Globals.h"

class medusa{
  public: 
    int xLoc;
    int yLoc;
    int tentX;
    int tentY;
    int xSpeed;
    int ySpeed;
    int direct = 0;
    int growCounter = 0;
    uint8_t counter = 0;
    bool growing = true;
    medusa(int x, int y);
    
   
    void drawMedusa();
    void updateMedusa();
    void setDirection();
};
