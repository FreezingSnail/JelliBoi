#include "medusa.h"



uint8_t swimJelliframe = 0;
bool swimmingJelli = false;



medusa::medusa(int startX, int startY){
  xLoc = startX;
  yLoc= startY;
  tentX= xLoc;
  tentY=yLoc+8;
}

void medusa::drawMedusa(){

  if (counter <= 12){
  sprite.drawSelfMasked(xLoc, yLoc, strob2Jelli, counter/2);
  }
  else if (swimmingJelli ==true && counter > 18){
    sprite.drawSelfMasked(xLoc, yLoc, jelli, swimJelliPattern[swimJelliframe]);
    sprite.drawSelfMasked(tentX, tentY, jelli, swimJelliPattern[swimJelliframe]+ 4);
    swimJelliframe++;
  }
  else {
    sprite.drawSelfMasked(xLoc, yLoc, jelli, direct);
    sprite.drawSelfMasked(tentX, tentY, jelli, direct+2);
   
  }
  if(swimJelliframe > 7){
    swimmingJelli = false;
    swimJelliframe = 0;
    } 
}

void medusa::setDirection(){
  if (playerDirection == left){
    direct = 0;
    xSpeed = -1;
  
  }
  else  if (playerDirection == right){
    direct = 1;
    xSpeed = 1;

  }
}

void medusa::updateMedusa(){

  if (counter < 20){
    counter++;}
  
 if (swimmingJelli == false){ setDirection(); }
 
 
 if(frameCounter % 9 == 0){
      yLoc++;   
      tentY =yLoc+8;
 }
    
 if( arduboy.justPressed(B_BUTTON) && swimmingJelli == false){
    swimmingJelli = true;
    
    switch (direct){
    case 0:
    ySpeed =-2;
    xSpeed-=3;
    break;
    case 1:
    ySpeed = -2;
    xSpeed = 3;
    break;

    }
  }
  if ( arduboy.pressed(A_BUTTON) && swimmingJelli == false){
    ySpeed = 2;
  }
  if(swimmingJelli){
  tentX += xSpeed;
  xLoc+= xSpeed;
  }
  else{
    if(frameCounter % 4 == 0){
      tentX += xSpeed;
      xLoc+= xSpeed;
   }
  }
  yLoc+= ySpeed;
  tentY += ySpeed;
  
  if (xSpeed > 1){ xSpeed--;}
  else if (xSpeed < -1){ xSpeed++;}
  else if (ySpeed < 0){ ySpeed++;}
  

  if(xLoc > 120){
    xLoc = 120;
    tentX = 120;
  }
  else if( xLoc < 0 ){
    xLoc = 0; 
    tentX = 0;
  }
  else if(yLoc > 41){
    yLoc = 41;
    tentY=yLoc + 8;
  }
  else if( yLoc < 4){
    yLoc = 4;
    tentY= yLoc+ 8;
  }

  if(frameCounter % 15 == 0 ){
      growCounter++;
  }
  if (growCounter > 30){
    frameCounter = 0;
    enteringStage = true;
    CycleCount++;
    GameStage = Larva;
   
  }

}
