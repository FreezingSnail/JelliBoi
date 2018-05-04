#pragma once
#include "Globals.h"

class larva{
  private:
    const int8_t downSpeed = 1;

  public: 
    uint8_t spriteDirection;
    int x;
    int y;
    int horizontalSpeed;
    int growCounter;

    larva(int x, int y);
    void setDirection();
    void drawLarva();
    void updateLarva();
};


//Float downward stage.
