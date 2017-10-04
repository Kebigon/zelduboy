#include "Map.hpp"

#include <avr/pgmspace.h>

Map::Map(const uint8_t * map)
	:map(map)
	,width(pgm_read_byte(map))
	,height(pgm_read_byte(map + 1))
	,mapTiles(map + 2)
	,mapPassable(mapTiles + width * height)
{}

uint8_t Map::getWidth() const
{
	return width;
}

uint8_t Map::getHeight() const
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

	return pgm_read_byte(mapTiles + getTileAddress(tileX, tileY));
}

bool Map::isPassable(uint8_t tileX, uint8_t tileY) const
{
	// The player cannot walk outside of the map
	if (tileX >= width || tileY >= height)
		return false;

	uint16_t arrayAddr = tileY * width + tileX;
	uint16_t byteAddr = arrayAddr >> 3; // arrayAddr / 8
	uint8_t  bitAddr = 0x07 - (byteAddr & 0x07);

	return (pgm_read_byte(mapPassable + byteAddr) >> bitAddr) & 0x01;
}
