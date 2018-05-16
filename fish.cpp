#include "fish.h"



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

