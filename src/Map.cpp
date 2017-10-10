#include "Map.hpp"

#include <avr/pgmspace.h>
#include "Arduboy2.h"
#include "chunksdata.h"

Map::Map(const uint8_t * mapt)
	: width(pgm_read_byte(mapt))
	, height(pgm_read_byte(mapt + 1))
	, mapTiles(mapt + 2)
	, mapPassable(mapt + 2 + pgm_read_byte(mapt) * pgm_read_byte(mapt + 1))
{
	map = mapHouseData;
	if (map == mapHouseData)
		checkMap = false;
}

// Width of the map in pixels
uint16_t Map::getWidth() const
{
	return width << 4;
}

// Height of the map in pixels
uint16_t Map::getHeight() const
{
	return height << 4;
}

// Width of the map in tiles
uint8_t Map::getTileWidth() const
{
	return width;
}

// Height of the map in tiles
uint8_t Map::getTileHeight() const
{
	return height;
}


uint16_t Map::getTileAddress(uint8_t tileX, uint8_t tileY) const
{
	return tileY * width + tileX;
}

uint8_t Map::getTile(uint8_t tileX, uint8_t tileY) const
{
	// The player cannot walk outside of the map
	if (tileX >= width || tileY >= height)
		return 0; // Default tile

	uint8_t tileAddress = getTileAddress(tileX, tileY);

	return pgm_read_byte(mapTiles + tileAddress);
}

bool Map::isPassable(uint8_t tileX, uint8_t tileY) const
{
	// The player cannot walk outside of the map
	if (tileX >= width || tileY >= height)
		return false;

	uint16_t arrayAddr = tileY * width + tileX;
	uint16_t byteAddr = arrayAddr >> 3; // arrayAddr / 8
	uint8_t  bitAddr = 0x07 - (arrayAddr & 0x07);

	return (pgm_read_byte(mapPassable + byteAddr) >> bitAddr) & 0x01;
}
