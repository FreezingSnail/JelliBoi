#include "polyp.h"

const uint8_t PROGMEM polypBMP[] =
{
// width, height,
16, 16,
// TILE 00
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x68, 0xc4, 0xc4, 0x44, 0xc4, 0xe8, 0xf0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x1e, 0x37, 0xb4, 0xfe, 0xe7, 0x93, 0x08, 0x07, 0x01, 0x00, 0x00, 0x00, 
// TILE 01
0x00, 0x00, 0xf0, 0xe8, 0xc4, 0x44, 0xc4, 0xc4, 0x68, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x01, 0x07, 0x08, 0x93, 0xe7, 0xfe, 0xb4, 0x37, 0x1e, 0x00, 0x00, 0x00, 0x00, 
};

const uint8_t PROGMEM polupMask[] =
{
// width, height,
16, 16,
// TILE 00
0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 
0x00, 0x00, 0x00, 0x1e, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0x0f, 0x07, 0x01, 0x00, 0x00, 
// TILE 01
0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x01, 0x07, 0x0f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x1e, 0x00, 0x00, 0x00, 
};

const uint8_t PROGMEM polupTentacles[] =
{
// width, height,
8, 8,
// TILE 00
0xe0, 0x18, 0x06, 0x91, 0xad, 0xa2, 0x52, 0x48, 
// TILE 01
0x48, 0x52, 0xa2, 0xad, 0x91, 0x06, 0x18, 0xe0, 
};



polyp::polyp(int xStart, int yStart, int direct){
  x = xStart;
  y = yStart;
  spriteDirection = direct;

  growCounter = 0;
  if(spriteDirection == 1){
    tentX = x- 2;
    tentY = y- 4;
    }
  else if (spriteDirection == 0){
    tentX = x+10;
    tentY = y -4;
  }
}

void polyp::setDirection(){
  if (playerDirection == left){
    spriteDirection = 1;
    tentX = x- 2;
    tentY = y- 4;

  }
  else  if (playerDirection == right){
    spriteDirection = 0;
    tentX = x+10;
    tentY = y -4;

  }
}

void polyp::drawPolyp(){
  sprite.drawExternalMask(x, y, polypBMP, polupMask, spriteDirection, spriteDirection);
  if(spriteDirection == 1){
    sprite.drawSelfMasked(tentX, tentY, polupTentacles, spriteDirection);}
  else if (spriteDirection == 0){
    sprite.drawSelfMasked(tentX, tentY, polupTentacles, spriteDirection);}
  }


void polyp::updatePolyp(){
  setDirection();
  
    growCounter++;

    if (score > 3){
    frameCounter = 0;
    enteringStage = true;
    GameStage = Strobilate;
   
  }
  
}
