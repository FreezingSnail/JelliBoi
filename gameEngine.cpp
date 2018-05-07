#include "gameEngine.h"
  larva plyrLarva(62, 16);
  polyp plyrPolyp = polyp(0, 0, 0);
  strob plyrStrob = strob(10,30);
  medusa plyrMedusa = medusa(40,30);

pellets pellet[5];
fish lilfish[3];
bigFish bigFishes[2];
  
void getDirection(){
 
  if(arduboy.justPressed(UP_BUTTON) && !arduboy.justPressed(LEFT_BUTTON) && !arduboy.justPressed(RIGHT_BUTTON)){
    playerDirection = up;
  }
  else if(arduboy.justPressed(DOWN_BUTTON) && !arduboy.justPressed(LEFT_BUTTON) && !arduboy.justPressed(RIGHT_BUTTON)){
    playerDirection = down;
  }
  else if(arduboy.justPressed(RIGHT_BUTTON) && !arduboy.justPressed(UP_BUTTON) && !arduboy.justPressed(DOWN_BUTTON)){
    playerDirection = right;
  }
  else if(arduboy.justPressed(LEFT_BUTTON) && !arduboy.justPressed(UP_BUTTON) && !arduboy.justPressed(DOWN_BUTTON)){
    playerDirection = left;
  }
  
}


void larvaStage(){

  if (enteringStage == true){
  larva  plyrLarva = larva(62, 16);
   frameCounter = 0;
   enteringStage = false;
  }
  plyrLarva.updateLarva();
  plyrLarva.drawLarva();
  
}

void  PolypStage(){
    if (enteringStage == true){
   plyrPolyp.x = plyrLarva.x -8;
   plyrPolyp.y = plyrLarva.y -8;
   plyrPolyp.spriteDirection = plyrLarva.spriteDirection;
   frameCounter = 0;
   enteringStage = false;
  }
  plyrPolyp.updatePolyp();
  plyrPolyp.drawPolyp();
  

 // spawnPellets(pelletList);

   // pellet.spawnPellet();
   for(int x = 0; x < 5; x++){
     pellet[x].updatePellet();
     pellet[x].drawPellet();
     if(pellet[x].pelletCollision(plyrPolyp.tentX, plyrPolyp.tentY, 8, 1) == true){
     pellet[x].resetPellet();
     score++;
     }
   }

  //drawPellets(pelletList);

  
}


void StrobilateStage(){
  if (enteringStage == true){
   plyrStrob.x = plyrPolyp.x;
   plyrStrob.y = plyrPolyp.y;
   enteringStage = false;
  }
  
  plyrStrob.drawStrob();
  plyrStrob.updateStrob();


  for(int x = 0; x < 5; x++){
     pellet[x].updatePellet();
     pellet[x].drawPellet();
     
     if(pellet[x].pelletCollision(plyrStrob.x, plyrStrob.y, 8,  0) == true){
     pellet[x].resetPellet();
     score++;
     }
     
     
   }
    for(int x = 0; x < 3; x++){
     lilfish[x].updateFish();
     lilfish[x].drawFish();
     if( lilfish[x].fishCollision(plyrStrob.x, plyrStrob.y, 8, 8) && plyrStrob.growing == false){
      enteringStage = true;
      GameStage = GameOver;
     }
  
   }

}

void MedusaStage(){
  if (enteringStage == true){
   plyrMedusa.xLoc= plyrStrob.x;
   plyrMedusa.yLoc = plyrStrob.y;
   plyrMedusa.tentX = plyrMedusa.xLoc; 
   plyrMedusa.tentY = plyrMedusa.yLoc+8;
   enteringStage = false;
  }
  
  plyrMedusa.drawMedusa();
  plyrMedusa.updateMedusa();

   for(int x = 0; x < 5; x++){
     pellet[x].updatePellet();
     pellet[x].drawPellet();
     
     if(pellet[x].pelletCollision(plyrMedusa.tentX, plyrMedusa.tentY, 8, 2 )){
     pellet[x].resetPellet();
     score++;
     }
     
     
   }
    for(int x = 0; x < 2; x++){
     lilfish[x].updateFish();
     lilfish[x].drawFish();
     if( lilfish[x].fishCollision(plyrMedusa.xLoc, plyrMedusa.yLoc+4, 8, 4)){
      enteringStage = true;
      GameStage = GameOver;
     }
      if( (lilfish[x].fishCollision(plyrMedusa.tentX, plyrMedusa.tentY, 8, 8)) && (lilfish[x].fishCollision(plyrMedusa.xLoc, plyrMedusa.yLoc+4, 8, 4)) == false){
      lilfish[x].resetFish();
      score +=3;
     }
  }
   for(int x = 0; x < 2; x++){
     bigFishes[x].updateBigFish();
     bigFishes[x].drawBigFish();
     if( bigFishes[x].fishCollision(plyrMedusa.xLoc, plyrMedusa.yLoc+4, 8, 12)){
      enteringStage = true;
      GameStage = GameOver;
     }
  }
}


void gameOver(){
  arduboy.print("GAMEOVER");
  arduboy.setCursor(60,30);
  arduboy.print(score);

}

void intro(){
  arduboy.setCursor(45,30);
  arduboy.print("B TO Start");
  if(arduboy.justPressed(B_BUTTON)){
    arduboy.initRandomSeed();
    GameStage = Larva;
  }
     for(int x = 0; x < 5; x++){
      pellet[x].updatePellet();
      pellet[x].drawPellet();
     }
       
    for(int x = 0; x < 3; x++){
     lilfish[x].updateFish();
     lilfish[x].drawFish();
     
     }

     for(int x = 0; x < 2; x++){
     bigFishes[x].updateBigFish();
     bigFishes[x].drawBigFish();
     }
  
}

