#include "larva.h"



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
  if(CycleCount>1 && counter <=24){
    sprite.drawSelfMasked(x-4, y-4, jelli2Larva, counter/2);
  }
  else{sprite.drawSelfMasked(x, y, larvaBMP, spriteDirection);}
}

void larva::updateLarva(){
  setDirection();
  if(counter >24){
  if( y < 64-8){
  x += horizontalSpeed;
  if(frameCounter % 4 == 0){
   y += downSpeed;
  }
 
    if(x < 0){ 
      horizontalSpeed = 1; 
      spriteDirection = 1;
      }
    if(x > 120){ 
      horizontalSpeed = -1; 
      spriteDirection = 0;
      }
      if(x > 120){
    x = 120;
  }
  else if( x < 0 ){
    x = 0; 
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
  else{counter++;}
  
}



