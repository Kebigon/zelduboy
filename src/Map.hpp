#ifndef MAP_HPP
#define MAP_HPP

#include <stdint.h>
#include "Room.hpp"

class Map
{
	const uint8_t nbRooms;
	const Room **rooms;
	uint8_t width;
	uint8_t height;

public:
	Map(Room **rooms, uint8_t nbRooms);

	/** \brief
	 * Width of the map in tiles
	 */
	uint8_t getWidth() const;

	/** \brief
	 * Height of the map in tiles
	 */
	uint8_t getHeight() const;

	/** \brief
	 * Width of the map in pixels
	 */
	uint16_t getPixelWidth() const;

	/** \brief
	 * Height of the map in pixels
	 */
	uint16_t getPixelHeight() const;

	uint8_t getTile(uint8_t x, uint8_t y) const;
	bool isPassable(uint8_t x, uint8_t y) const;

private:
	Room* getRoom(uint8_t x, uint8_t y) const;
};

#endif
