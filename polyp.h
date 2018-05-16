#pragma once
#include "Globals.h"

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

class polyp{
  public: 
    uint8_t spriteDirection;
    int16_t x;
    int16_t y;
    int16_t tentX;
    int16_t tentY;
    uint8_t growCounter;

    polyp(int16_t x, int16_t y, uint8_t direct);
    
    void setDirection();
    void drawPolyp();
    void updatePolyp();
};

//Float downward stage.
