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

const uint8_t PROGMEM bigFishArray[] =
{
// width, height,
8, 8,
// TILE 00
0x7c, 0x48, 0x78, 0x68, 0x30, 0x20, 0x20, 0x20, 
// TILE 01
0x7c, 0x24, 0x5e, 0x76, 0x6c, 0x2c, 0x08, 0x00, 
// TILE 02
0x44, 0x38, 0x10, 0x30, 0x38, 0x78, 0x6a, 0x4e, 
// TILE 03
0x33, 0x1e, 0x0c, 0x0c, 0x1e, 0x56, 0x63, 0x6b, 
// TILE 04
0x20, 0x20, 0x20, 0x30, 0x68, 0x78, 0x48, 0x7c, 
// TILE 05
0x00, 0x08, 0x2c, 0x6c, 0x76, 0x5e, 0x24, 0x7c, 
// TILE 06
0x4e, 0x6a, 0x78, 0x38, 0x30, 0x10, 0x38, 0x44, 
// TILE 07
0x6b, 0x63, 0x56, 0x1e, 0x0c, 0x0c, 0x1e, 0x33, 
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
       if( moveDirection > 0 && xLoc >176 ||  moveDirection < 0 && xLoc < -50){
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
                             
      Rect fishRect =  {xLoc+1, yLoc+1, 6, 6 };
  
                             
      
        if(arduboy.collide(playerRect, fishRect)){

         return true;
          
        }
  
      
  return false;
}


bigFish::bigFish(){
  byte fishType = rand() % 2;
  resetBigFish();
  
}

void bigFish::drawBigFish(){
  sprite.drawSelfMasked( xLoc,  yLoc, bigFishArray, (fishType+(pelDirect*4)));
  if(pelDirect == 0){
  sprite.drawSelfMasked( xLoc-8,  yLoc, bigFishArray, fishType+2+(pelDirect*4));
  }else{
    sprite.drawSelfMasked( xLoc+8,  yLoc, bigFishArray, fishType+2+(pelDirect*4));
  }
  
}

bool bigFish::fishBigCollision(int plyrX, int plyrY, int spriteDimX, int spriteDimY){
    
      
      Rect playerRect = {plyrX, 
                              plyrY,
                              spriteDimX,
                             spriteDimY };
                             
      Rect fishRect;
      if (pelDirect == 0){
        fishRect =  {xLoc-8, yLoc+1, 16, 6 };
      }else{
        fishRect =  {xLoc, yLoc+1, 16, 6 };
      }
  
                             
      
        if(arduboy.collide(playerRect, fishRect)){

         return true;
          
        }
  
      
  return false;
}

void bigFish::resetBigFish(){

           fishType = rand() % 2;
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
 void bigFish::updateBigFish(){
      xLoc += moveDirection;
       if( moveDirection > 0 && xLoc >200 ||  moveDirection < 0 && xLoc < -100){
       resetBigFish();
       }
  }

