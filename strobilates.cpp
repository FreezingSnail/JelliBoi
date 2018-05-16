#include "strobilates.h"
#include <stdint.h>

uint8_t swimframe = 0;
bool swimming = false;

const int growthModifier = 2;

strob::strob(int16_t xStart, int16_t yStart){
  x = xStart;
  y = yStart;
}

void strob::drawStrob(){
  if (counter <= 14*growthModifier){
  sprite.drawSelfMasked(x, y, strobolateAnimation, counter/growthModifier);
  }
  else if (counter > 14*growthModifier && swimming ==true){
    sprite.drawSelfMasked(x, y, strobSwim, swimStrobPattern[swimframe]+ direct);
    swimframe++;
  }
  else {
    sprite.drawSelfMasked(x, y, strobSwim, direct);
   
  }
  if(swimframe > 8){
    swimming = false;
    swimframe = 0;
    } 
}

void strob::updateStrob(){
  
 if (swimming == false){ setDirection(); }
 
 
 if(frameCounter % 4 == 0 && counter > 14*growthModifier){
      x--;
 }
    if (counter < 30){
    counter++;}
    else{
      growing = false;
    }
    
 if( arduboy.justPressed(B_BUTTON) && growing == false){
    swimming = true;
    
    switch (direct){
    case 0:
    ySpeed =-4;
    break;
    case 1:
    xSpeed = -4;
    break;
    case 2:
    ySpeed = 4;
    break;
    case 3:
    xSpeed = 4;
    break;
    }
  }

  x+= xSpeed;
  y+= ySpeed;
  
  if (xSpeed > 0){ xSpeed--;}
  else if (xSpeed < 0){ xSpeed++;}
  if (ySpeed > 0){ ySpeed--;}
  else if (ySpeed < 0){ ySpeed++;}
  

  if(x > 120){
    x = 120;
  }
  else if( x < 0 ){
    x = 0; 
  }
  else if(y > 50){
    y = 50; 
  }
  else if( y < 13-6){
    y = 13-6;
  }

 if(frameCounter % 15 == 0 ){
      growCounter++;
 }
if (growCounter > 30){
    frameCounter = 0;
    enteringStage = true;
    GameStage = Medusa;
   
  }
}
 


void strob::setDirection(){
  
  if (playerDirection == up){
    direct = 0;   
  }
  else  if (playerDirection == left){
    direct = 1;
  }
  else  if (playerDirection == down){
    direct = 2;
  }
  else  if (playerDirection == right){
    direct = 3;
  }
}

