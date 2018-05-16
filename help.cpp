#include "help.h"
#include "fish.h"


uint8_t swimframeH =0;


void helpmenu(){

    if(arduboy.justPressed(UP_BUTTON)){
    menuCounter--;
  }
  else if(arduboy.justPressed(DOWN_BUTTON)){
    menuCounter++;
  }
  if(arduboy.justPressed(A_BUTTON)){menuCounter++;}

switch(menuCounter){

  case 0:
  sprite.drawSelfMasked(1,20, larvaBMP, 0);
  arduboy.setCursor(13, 20);
  arduboy.println(F("Larva, coast to  "));
  arduboy.setCursor(13, 30);
  arduboy.println(F("the seafloor. "));
  arduboy.setCursor(13, 40);
  arduboy.print(F("< > to move"));
  break;

  case 1:
  sprite.drawSelfMasked(-4, 24, polypBMP, 0);
  sprite.drawSelfMasked(4, 20, polupTentacles, 0);
   arduboy.setCursor(13, 20);
  arduboy.println(F("Polyp, catch food"));
  arduboy.setCursor(13, 30);
  arduboy.println(F("with the tentacles. "));
  arduboy.setCursor(13, 40);
  arduboy.print(F("< > to move"));
  break;
  
  case 2:
  sprite.drawSelfMasked(1, 20, strobSwim, swimStrobPattern[swimframeH]);
   swimframeH++;
    if(swimframeH > 8){
     swimframeH = 0;
      } 
  arduboy.setCursor(13, 20);
  arduboy.println(F("Young Medusa, swim "));
  arduboy.setCursor(13, 30);
  arduboy.println(F("to avoid fish. B "));
  arduboy.setCursor(13, 40);
  arduboy.print(F("swims.<^>v to move. "));
  break;

  case 3:
   sprite.drawSelfMasked(2, 10, jelli, swimJelliPattern[swimframeH]);
   sprite.drawSelfMasked(2, 18, jelli, swimJelliPattern[swimframeH]+ 4);
   sprite.drawSelfMasked(2, 30, jelli, 0);
   sprite.drawSelfMasked(2, 38, jelli, 2);
   swimframeH++;
   if(swimframeH > 7){
     swimframeH = 0;
      } 
  arduboy.setCursor(13, 20);
  arduboy.println(F("Adult Jelli, catch "));
  arduboy.setCursor(13, 30);
  arduboy.println(F("food with Tentacles. B "));
  arduboy.setCursor(13, 40);
  arduboy.print(F("B swims <> to move. "));
  break;

  case 4:
  sprite.drawSelfMasked( 2,  13, lilFish, 0);
  sprite.drawSelfMasked( 14,  13, lilFish, 1);
  sprite.drawSelfMasked( 24,  13, lilFish, 2);
  arduboy.setCursor(5, 21);
  arduboy.println(F("lilFish, avoid until "));
  arduboy.setCursor(5, 31);
  arduboy.println(F("can catch with"));
  arduboy.setCursor(5, 41);
  arduboy.println(F("the tentacles."));
  break;

  case 5:
  sprite.drawSelfMasked( 10, 13, bigFishArray, 0);
  sprite.drawSelfMasked( 2,  13, bigFishArray, 2);
  sprite.drawSelfMasked( 28,  13, bigFishArray, 1);
  sprite.drawSelfMasked( 20,  13, bigFishArray, 3);
  arduboy.setCursor(5, 21);
  arduboy.println(F("bigFish, avoid at "));
  arduboy.setCursor(5, 31);
  arduboy.println(F("all costs"));
  break;

  case 6:
  arduboy.drawPixel( 7,  23, WHITE);
  arduboy.setCursor(13, 20);
  arduboy.println(F("Food, catch in  "));
  arduboy.setCursor(13, 30);
  arduboy.println(F("your mouth. "));
  arduboy.setCursor(13, 40);
  arduboy.print(F(""));

  break;
  case 7:
  arduboy.setCursor(2, 21);
  arduboy.println(F("A jelli bell is weak "));
  arduboy.setCursor(2, 31);
  arduboy.println(F("Living life will"));
  arduboy.setCursor(2, 41);
  arduboy.println(F("grant higher scores"));
  break;
}
    if (menuCounter > 7 || menuCounter < 0){
      GameStage = Intro;
    }
    if (arduboy.justPressed(B_BUTTON)){
       GameStage = Intro;
    }
}




