#include "pellets.h"


pellets::pellets(){
   pelDirect = rand() %2;

  if(pelDirect==0){
     xLoc =-1;
     pelDirection = right;
    moveDirection = rand() %2  +1;
  }
  else if(pelDirect==1){
     xLoc =128;
     pelDirection = left;
    moveDirection = rand() %2 -2;
  }
  
   yLoc;
  
  bool inuse = true;

  
}


void pellets::updatePellet(){

      
       xLoc += moveDirection;
       if( moveDirection > 0 && xLoc >130 ||  moveDirection < 0 && xLoc < -2){
       resetPellet();
       }
    
}

void pellets::resetPellet(){
    
           pelDirect = rand() % 2;
           yLoc =rand() %40 + 17;

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

void pellets::drawPellet(){
  
    arduboy.drawPixel( xLoc,  yLoc, WHITE);
  
}

bool pellets::pelletCollision(int plyrX, int plyrY, int spriteDim, int collisionCase){
    
 

      Rect playerRect;
      if(playerDirection == up || playerDirection == down){
          Rect playerRect = { plyrX, 
                              plyrY +2,
                              spriteDim,
                              spriteDim-4 };

      }
      else if(playerDirection == left || playerDirection == right){
          Rect playerRect = { plyrX+2, 
                              plyrY,
                              spriteDim - 4,
                              spriteDim };

      }
      else{
        Rect playerRect = { plyrX, 
                              plyrY,
                              spriteDim,
                              spriteDim };
      }
                             
      Rect pelletRect =  {xLoc, yLoc, 1, 1 };
                             
      if(collisionCase == 0){ // same
        if(arduboy.collide(playerRect, pelletRect) && pelDirection == playerDirection ) {

          return true;
          
        }
      }
      else if(collisionCase == 1){ //aything but the same
        if(arduboy.collide(playerRect, pelletRect) && pelDirection != playerDirection ) {

          return true;
          
        }
      }
      
    
    
  

  return false;
}


void spawnPellets(pellets pelletArray[]){
  for(int counter = 0; counter < 10; counter++){
//    pelletArray[counter].spawnPellet();
  }
}

void updatePellets(pellets pelletArray[]){
  for(int counter = 0; counter < 10; counter++){
    pelletArray[counter].updatePellet();
  }
}

void drawPellets(pellets pelletArray[]){
  for(int counter = 0; counter < 10; counter++){
    pelletArray[counter].drawPellet();
  }
}



