#include "polyp.h"





polyp::polyp(int16_t xStart, int16_t yStart, uint8_t direct){
  x = xStart;
  y = yStart;
  spriteDirection = direct;

  growCounter = 0;
  if(spriteDirection == 1){
    tentX = x- 2;
    tentY = y- 4;
    }
  else if (spriteDirection == 0){
    tentX = x+10;
    tentY = y -4;
  }
}

void polyp::setDirection(){
  if (playerDirection == left){
    spriteDirection = 1;
    tentX = x- 2;
    tentY = y- 4;

  }
  else  if (playerDirection == right){
    spriteDirection = 0;
    tentX = x+10;
    tentY = y -4;

  }
}

void polyp::drawPolyp(){
  sprite.drawExternalMask(x, y, polypBMP, polupMask, spriteDirection, spriteDirection);
  if(spriteDirection == 1){
    sprite.drawSelfMasked(tentX, tentY, polupTentacles, spriteDirection);}
  else if (spriteDirection == 0){
    sprite.drawSelfMasked(tentX, tentY, polupTentacles, spriteDirection);}
  }


void polyp::updatePolyp(){
  setDirection();
  
    if(frameCounter % 15 == 0 ){
      growCounter++;
 }

    if (growCounter > 30){
    frameCounter = 0;
    enteringStage = true;
    GameStage = Strobilate;
   
  }
  
}
