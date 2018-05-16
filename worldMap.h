#ifndef worldMap_h
#define worldMap_h
#include "Globals.h"

// map is a single slice of height repeated horizontilly

enum TileTypes {
  openOcean,
  surface,
  seaFloor,
};

//0 = open ocean
//1 = surface
//2 = sea floor


//void getTile(int tileType);
void drawMap();


#endif
