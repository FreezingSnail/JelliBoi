#pragma once
#include "Globals.h"

class polyp{
  public: 
    uint8_t spriteDirection;
    int x;
    int y;
    int tentX;
    int tentY;
    int growCounter;

    polyp(int x, int y, int direct);
    
    void setDirection();
    void drawPolyp();
    void updatePolyp();
};

//Float downward stage.
