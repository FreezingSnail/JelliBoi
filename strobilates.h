#pragma once
#include "Globals.h"

class strob{
  public: 
    int x;
    int y;
    int xSpeed;
    int ySpeed;
    int direct = 0;
    int growCounter = 0;
    uint8_t counter = 0;
    bool growing = true;
    strob(int x, int y);
    
   
    void drawStrob();
    void updateStrob();
    void setDirection();
};
