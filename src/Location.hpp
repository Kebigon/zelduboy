#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "Map.hpp"

class Location
{
	Map map;
	uint16_t x;
	uint16_t y;

public:
	Location (const Map &, const uint16_t, const uint16_t);
	Map getMap() const;
	uint16_t getX() const;
	uint16_t getY() const;
	uint8_t getTileX() const;
	uint8_t getTileY() const;
	void updateX(int8_t);
	void updateY(int8_t);
};

#endif
