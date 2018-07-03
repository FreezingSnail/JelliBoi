#ifndef Globals_h
#define Globals_h


#include <Arduboy2.h>
#include <Sprites.h>
#include <Arduboy2Beep.h>
#define EEPROM_START_C1                 EEPROM_STORAGE_SPACE_START
#define EEPROM_START_C2                 EEPROM_START_C1 + 1
#define EEPROM_SCORE                    EEPROM_START_C1 + 2

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
  help,
  HighScore,
  
  
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
extern int16_t Hscore;
extern uint8_t CycleCount;
extern int8_t menuCounter;

#endif
