#ifndef MAP_HPP
#define MAP_HPP

#include <stdint.h>

class Map
{
public:
	Map(const uint8_t *);
	uint8_t getWidth() const;
	uint8_t getHeight() const;
	uint8_t getTile(uint8_t, uint8_t) const;
	bool isPassable(uint8_t, uint8_t) const;

	const uint8_t * map;
	const uint8_t width, height;
	const uint8_t * mapTiles;
	const uint8_t * mapPassable;
	uint16_t getTileAddress(uint8_t, uint8_t) const;
};

#endif
