#ifndef CHUNKSDATA_H
#define CHUNKSDATA_H

#include "Map.hpp"

#define MAP_HOUSE_ID 0

extern Map mapHouse;
const unsigned char PROGMEM mapHouseData[]  =
{
	// width, height,
	8, 8,
	// tles data
	0,  1,  2,  2, 2,  2,  3,  0,
	1, 13,  5,  5, 5,  5, 12,  3,
	4,  5,  5,  5, 5,  5,  5,  6,
	4,  5,  5,  5, 5,  5,  5,  6,
	4,  5,  5,  5, 5,  5,  5,  6,
	4,  5,  5,  5, 5,  5,  5,  6,
	7, 11,  5,  5, 5,  5, 10,  9,
	0,  7,  8,  8, 8,  8,  9,  0,
	// Passable data,
	0b01111110, // Line 0
	0b11111111, // Line 1
	0b11111111, // Line 2
	0b11111111, // Line 3
	0b11111111, // Line 4
	0b11111111, // Line 5
	0b11111111, // Line 6
	0b01111110 // Line 7
};

#endif
