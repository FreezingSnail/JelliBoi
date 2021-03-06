#pragma once
#include "Globals.h"

//Courtesy of Filmote from Steve the Dino

/* ----------------------------------------------------------------------------
 *   Is the EEPROM initialised? 
 *   
 *   Looks for the characters 'S' and 'T' in the first two bytes of the EEPROM
 *   memory range starting from byte EEPROM_STORAGE_SPACE_START.  If not found,
 *   it resets the settings ..
 * ----------------------------------------------------------------------------
 */
void initEEPROM() {

  unsigned char c1 = EEPROM.read(EEPROM_START_C1);
  unsigned char c2 = EEPROM.read(EEPROM_START_C2);

  if (c1 != 'S' || c2 != 'T') { 
  
    EEPROM.update(EEPROM_START_C1, 'S');
    EEPROM.update(EEPROM_START_C2, 'T');
    EEPROM.put(EEPROM_SCORE, (unsigned int)0);
      
  }

}

