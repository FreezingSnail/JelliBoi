/* Game Jam May 1st
 * Jelli Boi
 * 
 * @FreezingSnail
 * 
 * 
 */
#include <stdint.h>
 
#include "Globals.h"
#include "gameEngine.h"
#include "worldMap.h"
#include "help.h"




void setup() {
  arduboy.begin();
  arduboy.setFrameRate(15);
  arduboy.clear();
  GameStage = Intro;
  playerDirection = left;
  
   
}

//Main loop
void loop() {
  if(!arduboy.nextFrame()){
    return;
  }
  arduboy.pollButtons();
  arduboy.clear();
  beep.timer();
  arduboy.audio.on();


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
  
  }

  
  arduboy.display();
}





