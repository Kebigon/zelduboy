#include "Room.hpp"

#include <avr/pgmspace.h>
#include "globals.h"

Room::Room(uint8_t roomX, uint8_t roomY,const uint8_t * roomData)
	: width(pgm_read_byte(roomData))
	, height(pgm_read_byte(roomData + 1))
	, mapTiles(roomData + 2)
	, mapPassable(roomData + 2 + pgm_read_byte(roomData) * pgm_read_byte(roomData + 1))
	, roomX(roomX)
	, roomY(roomY)
{}

uint8_t Room::getX() const
{
	return roomX;
}

uint8_t Room::getY() const
{
	return roomY;
}

uint8_t Room::getWidth() const
{
	return width;
}

uint8_t Room::getHeight() const
{
	return height;
}

uint16_t Room::getPixelX() const
{
	return roomX << 4; // roomX * 16
}

uint16_t Room::getPixelY() const
{
	return roomY << 4; // roomY * 16
}

uint16_t Room::getPixelWidth() const
{
	return width << 4; // width * 16
}

uint16_t Room::getPixelHeight() const
{
	return height << 4; // height * 16
}

uint16_t Room::getTileAddress(uint8_t x, uint8_t y) const
{
	return y * width + x;
}

uint8_t Room::getTile(uint8_t mapX, uint8_t mapY) const
{
	uint8_t x = mapX - roomX;
	uint8_t y = mapY - roomY;

	// The player cannot see outside of the room
	if (x >= width || y >= height)
		return DEFAULT_TILE;  // Default tile

	uint8_t tileAddress = getTileAddress(x, y);

	return pgm_read_byte(mapTiles + tileAddress);
}

bool Room::isPassable(uint8_t mapX, uint8_t mapY) const
{
	uint8_t x = mapX - roomX;
	uint8_t y = mapY - roomY;

	// The player cannot walk outside of the room
	if (x >= width || y >= height)
		return DEFAULT_PASSIBILITY;

	uint16_t arrayAddr = y * width + x;
	uint16_t byteAddr = arrayAddr >> 3; // arrayAddr / 8
	uint8_t bitAddr = 0x07 - (arrayAddr & 0x07);

	return (pgm_read_byte(mapPassable + byteAddr) >> bitAddr) & 0x01;
}

Rect Room::getRoomRect() const
{
	return { roomX, roomY, width, height};
}

bool Room::isInsideRoom(uint8_t x, uint8_t y) const
{
	return roomX <= x && x < roomX+width && roomY <= y && y < roomY+height;
}
