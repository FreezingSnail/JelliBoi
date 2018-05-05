#include "fish.h"

const uint8_t PROGMEM lilFish[] =
{
// width, height,
8, 8,
// TILE 00
0x3c, 0x18, 0x7d, 0x67, 0x3f, 0x36, 0x6c, 0x48, 
// TILE 01
0x3c, 0x18, 0x1d, 0x3f, 0x36, 0x3c, 0x66, 0x42, 
// TILE 02
0x38, 0x10, 0x3a, 0x7c, 0x68, 0x30, 0x20, 0x20, 
// TILE 03
0x48, 0x6c, 0x36, 0x3f, 0x67, 0x7d, 0x18, 0x3c, 
// TILE 04
0x42, 0x66, 0x3c, 0x36, 0x3f, 0x1d, 0x18, 0x3c, 
// TILE 05
0x20, 0x20, 0x30, 0x68, 0x7c, 0x3a, 0x10, 0x38,  
};

fish::fish(): pellets(){
  byte fishType = rand() % 3;
  resetFish();
}

void fish::drawFish(){
  
    sprite.drawSelfMasked( xLoc,  yLoc, lilFish, fishType+(pelDirect*3));
  
}

void fish::updateFish(){

      
       xLoc += moveDirection;
       if( moveDirection > 0 && xLoc >156 ||  moveDirection < 0 && xLoc < -20){
       resetFish();
       }
    
}

void fish::resetFish(){

           fishType = rand() % 3;
           pelDirect = rand() % 2;
           yLoc =rand() %36 + 13;

        if(pelDirect==0){
             xLoc =-1;
             pelDirection = right;
            moveDirection = rand() %2 + 1;
        }
        else if(pelDirect==1){
             xLoc =129;
             pelDirection = left;
            moveDirection = rand() %2 + -2;
        }
      
}

bool fish::fishCollision(int plyrX, int plyrY, int spriteDimX, int spriteDimY){
    
      
      Rect playerRect = {plyrX, 
                              plyrY,
                              spriteDimX,
                             spriteDimY };
                             
      Rect fishRect =  {xLoc, yLoc, 8, 8 };
  
                             
      
        if(arduboy.collide(playerRect, fishRect)){

         return true;
          
        }
  
      
  return false;
}
