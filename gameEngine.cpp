#include "gameEngine.h"


const uint8_t PROGMEM titleScreen[] =
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xfe, 0xff, 0xff, 0xff, 0x7, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0x70, 0xf0, 0x70, 0xf0, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xe0, 0xf3, 0xff, 0xff, 0x13, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x83, 0xb3, 0x9f, 0x83, 0xc7, 0xff, 0xff, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0x70, 0x70, 0x70, 0xf0, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf3, 0xff, 0xff, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xf0, 0xf0, 0xf0, 0xe0, 0x80, 0x80, 0x80, 0xe0, 0xff, 0xff, 0xff, 0x3f, 0x1, 0x00, 0x18, 0xff, 0xff, 0xff, 0xff, 0xce, 0x8e, 0xae, 0x9e, 0xcf, 0xef, 0xcf, 0x1f, 0x66, 0x80, 0xfc, 0xff, 0xff, 0xff, 0x7, 0x00, 0x80, 0xfc, 0xff, 0xff, 0xff, 0xf, 0x00, 0xc0, 0xfe, 0xff, 0xff, 0x7f, 0x7, 0x00, 0x80, 0xfe, 0xff, 0xff, 0xff, 0x9f, 0x83, 0x83, 0xb3, 0x8b, 0xc7, 0xff, 0xfe, 0xfe, 0x7c, 0x00, 0x00, 0x00, 0x3e, 0xff, 0xff, 0xff, 0x81, 0x90, 0x8e, 0xc1, 0xf0, 0xff, 0xff, 0x7f, 0x1f, 0x00, 0xc0, 0xfe, 0xff, 0xff, 0xff, 0x3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x8, 0xf, 0x1, 0x3, 0xbf, 0xc7, 0x33, 0x3, 0xf, 0x9, 0x79, 0x1, 0x3e, 0x00, 0x00, 0xc2, 0x42, 0x47, 0x39, 0x3, 0x1f, 0xd3, 0x73, 0x3, 0x1f, 0x11, 0x71, 0x00, 0x00, 0x5f, 0x7, 0x3, 0x7b, 0x7, 0x00, 0x78, 0x7, 0x3, 0x3f, 0xe3, 0x3, 0x00, 0x00, 0x3, 0x7f, 0x3, 0x3, 0x00, 0x00, 0xcc, 0x77, 0x3, 0x3, 0x83, 0xdf, 0x73, 0x3f, 0x23, 0x3, 0x1f, 0x13, 0xf1, 0xf, 0x8, 0x18, 0x00, 0x20, 0x18, 0xf, 0x1, 0x1, 0xfb, 0x7, 0x3, 0x33, 0xf, 0x1, 0x1, 0x3e, 0x00, 0x00, 0xfc, 0x7, 0x73, 0x13, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


  larva plyrLarva(62, 16);
  polyp plyrPolyp = polyp(0, 0, 0);
  strob plyrStrob = strob(10,30);
  medusa plyrMedusa = medusa(60,16);

pellets pellet[5];
fish lilfish[3];
bigFish bigFishes[2];

pellets pelletI[5];
fish lilfishI[3];
bigFish bigFishesI[2];


  
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

  if (enteringStage == true && CycleCount>1){
  plyrLarva.x = plyrMedusa.xLoc;
  plyrLarva.y = plyrMedusa.yLoc;
  plyrLarva.growCounter = 0;
   frameCounter = 0;
   enteringStage = false;
  }else if (enteringStage == true){
    plyrLarva.x = 60;
  plyrLarva.y = 14;
  plyrLarva.growCounter = 0;
   frameCounter = 0;
   enteringStage = false;
  }
  plyrLarva.updateLarva();
  plyrLarva.drawLarva();

  if(CycleCount > 1){
    for(int x = 0; x < 5; x++){
     pellet[x].updatePellet();
     pellet[x].drawPellet();
    }
    for(int x = 0; x < 2; x++){
     lilfish[x].updateFish();
     lilfish[x].drawFish();
      if( lilfish[x].fishCollision(plyrLarva.x, plyrLarva.y, 8, 8)){
      enteringStage = true;
      GameStage = GameOver;
      }
     }
     for(int x = 0; x < 1; x++){
     bigFishes[x].updateBigFish();
     bigFishes[x].drawBigFish();
      if( bigFishes[x].fishBigCollision(plyrLarva.x, plyrLarva.y, 8, 8)){
        enteringStage = true;
        GameStage = GameOver;
      }
    }
    
  }
  
}

void  PolypStage(){
    if (enteringStage == true){
   plyrPolyp.x = plyrLarva.x -8;
   plyrPolyp.y = plyrLarva.y -8;
   plyrPolyp.growCounter =0;
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
     score += (1*CycleCount);
     beeper();
     }
   }

  //drawPellets(pelletList);

  if(CycleCount > 1){
    for(int x = 0; x < 5; x++){
     pellet[x].updatePellet();
     pellet[x].drawPellet();
    }
    for(int x = 0; x < 2; x++){
     lilfish[x].updateFish();
     lilfish[x].drawFish();
     bigFishes[x].updateBigFish();
     bigFishes[x].drawBigFish();
    }
    
  }
}


void StrobilateStage(){
  if (enteringStage == true){
   plyrStrob.x = plyrPolyp.x;
   plyrStrob.y = plyrPolyp.y;
   enteringStage = false;
   plyrStrob.growCounter =0;
   plyrStrob.counter =0;
  }
  
  plyrStrob.drawStrob();
  plyrStrob.updateStrob();


  for(int x = 0; x < 5; x++){
     pellet[x].updatePellet();
     pellet[x].drawPellet();
     
     if(pellet[x].pelletCollision(plyrStrob.x, plyrStrob.y, 8,  0) == true){
     pellet[x].resetPellet();
     score += (1*CycleCount);
     beeper();
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
   plyrLarva.counter=0;
   plyrMedusa.xLoc= plyrStrob.x;
   plyrMedusa.yLoc = plyrStrob.y;
   plyrMedusa.tentX = plyrMedusa.xLoc; 
   plyrMedusa.tentY = plyrMedusa.yLoc+8;
   plyrMedusa.growCounter =0;
   plyrMedusa.counter = 0;
   enteringStage = false;
  }
  
  plyrMedusa.drawMedusa();
  plyrMedusa.updateMedusa();

   for(int x = 0; x < 5; x++){
     pellet[x].updatePellet();
     pellet[x].drawPellet();
     
     if(pellet[x].pelletCollision(plyrMedusa.tentX, plyrMedusa.tentY, 8, 2 )){
     pellet[x].resetPellet();
     score += (1*CycleCount);
     beeper();
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
      beeper();
      score += (3*CycleCount);
     }
  }
   for(int x = 0; x < 1; x++){
     bigFishes[x].updateBigFish();
     bigFishes[x].drawBigFish();
     if( bigFishes[x].fishBigCollision(plyrMedusa.xLoc, plyrMedusa.yLoc+4, 8, 12)){
      enteringStage = true;
      GameStage = GameOver;
     }
  }
}


void gameOver(){
  
  if (score < Hscore){
  arduboy.setCursor(30,10);
  arduboy.print("GAMEOVER");
  arduboy.setCursor(30,30);
  arduboy.print(F("You Scored:"));
  arduboy.setCursor(60,40);
  arduboy.print(score);
  }
  else{
  if(score > Hscore)
  arduboy.clear();
  arduboy.setCursor(30,10);
  arduboy.print(F("New HighScore!"));
  arduboy.setCursor(30,30);
  arduboy.print(F("You Scored:"));
  arduboy.setCursor(60,40);
  arduboy.print(score);
  
  }
  
  CycleCount = 1;
  if(arduboy.justPressed(B_BUTTON)){
    enteringStage = true;
    
    if (score > Hscore) {
      Hscore = score;
      EEPROM.put(EEPROM_SCORE, Hscore);
    }\score = 0;
    GameStage = Intro;
  }
 

}

void intro(){
  arduboy.drawBitmap(16,10, titleScreen, 96, 32, WHITE);
  arduboy.setCursor(34,45);
  arduboy.print("B To Start");
  arduboy.setCursor(34,55);
  arduboy.print("A for help");
  if(arduboy.justPressed(B_BUTTON)){
    arduboy.initRandomSeed();
    GameStage = Larva;
  }
     for(int x = 0; x < 5; x++){
      pelletI[x].updatePellet();
      pelletI[x].drawPellet();
     }
       
    for(int x = 0; x < 3; x++){
     lilfishI[x].updateFish();
     lilfishI[x].drawFish();
     
     }

     for(int x = 0; x < 2; x++){
     bigFishesI[x].updateBigFish();
     bigFishesI[x].drawBigFish();
     }
     if (arduboy.justPressed(A_BUTTON)){
       GameStage = help;
       menuCounter = 0;
    }
  
}
void beeper(){
  beep.tone(beep.freq(440), 5);
}

