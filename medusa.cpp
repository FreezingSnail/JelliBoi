#include "medusa.h"


uint8_t swimJelliPattern[] = { 4, 5,6,7,7,6,5,4};
int swimJelliframe = 0;
bool swimmingJelli = false;


const uint8_t PROGMEM jelli[] =
{
// width, height,
8, 8,
// TILE 00
0xe0, 0xb0, 0xd0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 
// TILE 01
0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xd0, 0xb0, 0xe0, 
// TILE 02
0x1f, 0x60, 0x8f, 0x70, 0x87, 0x38, 0x43, 0x5c, 
// TILE 03
0x5c, 0x43, 0x38, 0x87, 0x70, 0x8f, 0x60, 0x1f, 
// TILE 04
0xe0, 0xb0, 0xd0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 
// TILE 05
0xc0, 0xb0, 0xd8, 0xf8, 0xf8, 0xf8, 0xf0, 0xc0, 
// TILE 06
0x00, 0xf0, 0xcc, 0xfc, 0xfc, 0xfc, 0xf0, 0x00, 
// TILE 07
0x00, 0x30, 0xcc, 0xfe, 0xfe, 0xfc, 0x30, 0x00, 
// TILE 08
0x1f, 0x60, 0x3f, 0xc0, 0xc0, 0x3f, 0x60, 0x1f, 
// TILE 09
0x03, 0x3c, 0x47, 0xf8, 0xf8, 0x47, 0x3c, 0x03, 
// TILE 10
0x00, 0x07, 0x7f, 0xf8, 0xf8, 0x7f, 0x07, 0x00, 
// TILE 11
0x00, 0x00, 0x0f, 0xfe, 0xfe, 0x0f, 0x00, 0x00, 
};

medusa::medusa(int startX, int startY){
  xLoc = startX;
  yLoc= startY;
  tentX= xLoc;
  tentY=yLoc+8;
}

void medusa::drawMedusa(){
  if (swimmingJelli ==true){
    sprite.drawSelfMasked(xLoc, yLoc, jelli, swimJelliPattern[swimJelliframe]+ direct);
    sprite.drawSelfMasked(xLoc, yLoc, jelli, swimJelliPattern[swimJelliframe]+ 4);
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
  
  }
  else  if (playerDirection == right){
    direct = 1;

  }
}

void medusa::updateMedusa(){
  
 if (swimmingJelli == false){ setDirection(); }
 
 
 if(frameCounter % 4 == 0){
      xLoc--;
      yLoc += 2;
      tentX--;
      tentY += 2;
 }
    
 if( arduboy.justPressed(B_BUTTON)){
    swimmingJelli = true;
    
    switch (direct){
    case 0:
    ySpeed =-4;
    xSpeed-=3;
    break;
    case 1:
    ySpeed = -4;
    xSpeed = 3;
    break;

    }
  }

  xLoc+= xSpeed;
  yLoc+= ySpeed;
  tentX += xSpeed;
  tentY += ySpeed;
  
  if (xSpeed > 0){ xSpeed--;}
  else if (xSpeed < 0){ xSpeed++;}
  else if (ySpeed < 0){ ySpeed++;}
  

  if(xLoc > 120){
    xLoc = 120;
    tentX = 120;
  }
  else if( xLoc < 0 ){
    xLoc = 0; 
    tentX = 0;
  }
  else if(yLoc > 30){
    yLoc = 30;
    tentY=yLoc + 8;
  }
  else if( yLoc < 13){
    yLoc = 13;
    tentY= 13+ 8;
  }

}
