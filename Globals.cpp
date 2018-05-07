#include "Globals.h"

 GameState GameStage;
 Arduboy2 arduboy;
 Sprites sprite;
 BeepPin1 beep;
 Directions playerDirection;
 uint8_t frameCounter = 0;
 bool enteringStage = true;
 uint16_t score = 0;
 uint8_t CycleCount = 1;
