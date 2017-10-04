#ifndef CHUNKSDATA_H
#define CHUNKSDATA_H

#include "Map.hpp"

#define MAP_HOUSE_ID 0

const unsigned char PROGMEM mapHouseData[]  =
{
	// width, height,
	6, 6,
	// tles data
	0,  1,  2,  2,  3,  0,
	1, 13,  5,  5, 12,  3,
	4,  5,  5,  5,  5,  6,
	4,  5,  5,  5,  5,  6,
	7, 11,  5,  5, 10,  9,
	0,  7,  8,  8,  9,  0,
	// Passable data,
	0b01111011, 0b11111111, 0b11111111, // Lines 1 to 4
	0b11111101, 0b11100000 // Lines 5 to 6
};
static Map mapHouse(mapHouseData);

#endif
