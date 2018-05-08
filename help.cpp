#include "help.h"
#include "fish.h"

const uint8_t PROGMEM larvaBMPH[] =
{
// width, height,
8, 8,
// TILE 00 left
0x80, 0xf0, 0x7c, 0x56, 0x6b, 0x35, 0x1d, 0x0e, 
// TILE 01 right
0x0e, 0x1d, 0x35, 0x6b, 0x56, 0x7c, 0xf0, 0x80, 
};



const uint8_t PROGMEM polypBMPH[] =
{
// width, height,
16, 16,
// TILE 00
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x68, 0xc4, 0xc4, 0x44, 0xc4, 0xe8, 0xf0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x1e, 0x37, 0xb4, 0xfe, 0xe7, 0x93, 0x08, 0x07, 0x01, 0x00, 0x00, 0x00, 
};
const uint8_t PROGMEM polupTentaclesH[] =
{
// width, height,
8, 8,
// TILE 00
0xe0, 0x18, 0x06, 0x91, 0xad, 0xa2, 0x52, 0x48,
};

const uint8_t PROGMEM strobSwimH[] =
{
// width, height,
8, 8,
// TILE 00 a1 00
0x20, 0x38, 0x0c, 0x3c, 0x0c, 0x3c, 0x18, 0x20, 
 
// TILE 01 a2 01
0x18, 0x1c, 0x0c, 0x1c, 0x0c, 0x1c, 0x0c, 0x18, 
 
// TILE 02 a3 02
0x00, 0x38, 0x0c, 0x7c, 0x7c, 0x0c, 0x38, 0x00, 

// TILE 03 a4 03
0x00, 0x18, 0x2c, 0x7c, 0x7c, 0x2c, 0x18, 0x00, 

};

const uint8_t PROGMEM jelliH[] =
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
uint8_t swimJelliPatternH[] = { 4, 5,6,7,7,6,5,4};

uint8_t swimPatternH[] = { 0, 1, 0, 2, 3, 3, 3, 2, 0};
int swimframeH =0;


const uint8_t PROGMEM lilFishH[] =
{
// width, height,
8, 8,
// TILE 00
0x3c, 0x18, 0x7d, 0x67, 0x3f, 0x36, 0x6c, 0x48, 
// TILE 01
0x3c, 0x18, 0x1d, 0x3f, 0x36, 0x3c, 0x66, 0x42, 
// TILE 02
0x38, 0x10, 0x3a, 0x7c, 0x68, 0x30, 0x20, 0x20, 
};

const uint8_t PROGMEM bigFishArrayH[] =
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
};






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
  sprite.drawSelfMasked(1,20, larvaBMPH, 0);
  arduboy.setCursor(13, 20);
  arduboy.println(F("Larva, coast to  "));
  arduboy.setCursor(13, 30);
  arduboy.println(F("the seafloor. "));
  arduboy.setCursor(13, 40);
  arduboy.print(F("< > to move"));
  break;

  case 1:
  sprite.drawSelfMasked(-4, 24, polypBMPH, 0);
  sprite.drawSelfMasked(4, 20, polupTentaclesH, 0);
   arduboy.setCursor(13, 20);
  arduboy.println(F("Polyp, catch food"));
  arduboy.setCursor(13, 30);
  arduboy.println(F("with the tentacles. "));
  arduboy.setCursor(13, 40);
  arduboy.print(F("< > to move"));
  break;
  
  case 2:
  sprite.drawSelfMasked(1, 20, strobSwimH, swimPatternH[swimframeH]);
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
   sprite.drawSelfMasked(2, 10, jelliH, swimJelliPatternH[swimframeH]);
   sprite.drawSelfMasked(2, 18, jelliH, swimJelliPatternH[swimframeH]+ 4);
   sprite.drawSelfMasked(2, 30, jelliH, 0);
   sprite.drawSelfMasked(2, 38, jelliH, 2);
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
  sprite.drawSelfMasked( 2,  13, lilFishH, 0);
  sprite.drawSelfMasked( 14,  13, lilFishH, 1);
  sprite.drawSelfMasked( 24,  13, lilFishH, 2);
  arduboy.setCursor(5, 21);
  arduboy.println(F("lilFish, avoid until "));
  arduboy.setCursor(5, 31);
  arduboy.println(F("can catch with"));
  arduboy.setCursor(5, 41);
  arduboy.println(F("the tentacles."));
  break;

  case 5:
  sprite.drawSelfMasked( 10, 13, bigFishArrayH, 0);
  sprite.drawSelfMasked( 2,  13, bigFishArrayH, 2);
  sprite.drawSelfMasked( 28,  13, bigFishArrayH, 1);
  sprite.drawSelfMasked( 20,  13, bigFishArrayH, 3);
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




