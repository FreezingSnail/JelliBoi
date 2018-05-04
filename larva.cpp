#include "larva.h"

const uint8_t PROGMEM larvaBMP[] =
{
// width, height,
8, 8,
// TILE 00 left
0x80, 0xf0, 0x7c, 0x56, 0x6b, 0x35, 0x1d, 0x0e, 
// TILE 01 right
0x0e, 0x1d, 0x35, 0x6b, 0x56, 0x7c, 0xf0, 0x80, 
};


larva::larva(int xStart, int yStart){
  x = xStart;
  y = yStart;
  spriteDirection = 1;
  horizontalSpeed = 0;
  growCounter = 0;
}

void larva::setDirection(){
  if (playerDirection == left){
    spriteDirection = 0;
    horizontalSpeed = -1;
  }
  else  if (playerDirection == right){
    spriteDirection = 1;
    horizontalSpeed = 1;
  }
}

void larva::drawLarva(){
  sprite.drawSelfMasked(x, y, larvaBMP, spriteDirection);
}

void larva::updateLarva(){
  setDirection();
  if( y < 64-8){
  x += horizontalSpeed;
  if(frameCounter % 4 == 0){
   y += downSpeed;
  }
 
    if(x < 0){ 
      horizontalSpeed = 1; 
      spriteDirection = 1;
      }
    if(x > 121){ 
      horizontalSpeed = -1; 
      spriteDirection = 0;
      }
  }
   else {
    growCounter++;
  }
    if (growCounter > 30){
    frameCounter = 0;
    enteringStage = true;
    GameStage = Polyp;
   
  }
  
}



