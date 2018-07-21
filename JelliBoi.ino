/* Game Jam May 1st
 * Jelli Boi
 * 
 * @FreezingSnail
 * 
 * 
 */
#include <stdint.h>
#include <EEPROM.h>
#include <ATMlib.h>
 
#include "Globals.h"
#include "gameEngine.h"
#include "worldMap.h"
#include "help.h"
#include "EEPROM.h"
#include "song.h"


ATMsynth ATM;


void setup() {
  arduboy.begin();
  beep.begin();
  arduboy.setFrameRate(15);
  arduboy.clear();
  GameStage = Intro;
  playerDirection = left;
  initEEPROM();
  EEPROM.get(EEPROM_SCORE, Hscore);
  arduboy.audio.on();
  ATM.play(music);
  
  
  
   
}

//Main loop
void loop() {
  if(!arduboy.nextFrame()){
    return;
  }
  arduboy.pollButtons();
  arduboy.clear();
  beep.timer();


  drawMap();
  getDirection();
  frameCounter ++;
  if(frameCounter > 24){
  frameCounter = 0;}
  

  
  switch (GameStage) {
    case GameState::Larva:
      larvaStage();
     break;
    case GameState::Polyp:
      PolypStage();
      break;
    case GameState::Strobilate:
      StrobilateStage();
      break;
    case GameState::GameOver:
      gameOver();
      break;
    case GameState::Intro:
      intro();
     break;
    case GameState::Medusa:
      MedusaStage();
      break;
    case GameState::help:
      helpmenu();
      break;
      
    case GameState::HighScore:
//      getName();
      break;

  }
  
  

  
  arduboy.display();
}




