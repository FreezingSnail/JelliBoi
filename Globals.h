#ifndef Globals_h
#define Globals_h


#include <Arduboy2.h>
#include <Sprites.h>

extern Arduboy2 arduboy;
extern Sprites sprite;
extern BeepPin1 beep;

enum GameState {
  Intro,
  Larva,
  Polyp,
  Strobilate,
  Medusa,
  GameOver,
  
};
enum Directions {
  up,
  down,
  left,
  right,

};

extern GameState GameStage;
extern Directions playerDirection;
extern uint8_t frameCounter;
extern bool enteringStage;
extern uint16_t score;
extern uint8_t CycleCount;

#endif
