#include "Map.hpp"

#include <Arduboy2.h>
#include "globals.h"

Map::Map(Room *rooms, uint8_t nbRooms)
	: rooms(rooms)
	,nbRooms(nbRooms)
{
	uint8_t maxWidth = 0, maxHeight = 0;
	for (int i = 0; i != nbRooms; i++)
	{
		Rect roomDimensions = rooms[i].getRoomRect();

		if (maxWidth < roomDimensions.x + roomDimensions.width)
			maxWidth = roomDimensions.x + roomDimensions.width;

		if (maxHeight < roomDimensions.y + roomDimensions.height)
			maxHeight = roomDimensions.y + roomDimensions.height;
	}

	width = maxWidth;
	height = maxHeight;
}

uint8_t Map::getWidth() const
{
	return width;
}

uint8_t Map::getHeight() const
{
	return height;
}

uint16_t Map::getPixelWidth() const
{
	return width << 4; // width * 16
}

uint16_t Map::getPixelHeight() const
{
	return height << 4; // height * 16
}

uint8_t Map::getTile(uint8_t x, uint8_t y) const
{
	Room * room = getRoom(x, y);
	if (room == nullptr)
		return DEFAULT_TILE;

	return room->getTile(x, y);
}

bool Map::isPassable(uint8_t x, uint8_t y) const
{
	Room * room = getRoom(x, y);
	if (room == nullptr)
		return DEFAULT_PASSIBILITY;

	return room->isPassable(x, y);
}

Room * Map::getRoom(uint8_t x, uint8_t y) const
{
	for (int i = 0; i != nbRooms; i++)
		if (rooms[i].isInsideRoom(x, y))
			return &rooms[i];

	return nullptr;
}
