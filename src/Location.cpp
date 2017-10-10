#include "Location.hpp"

Location::Location(const Map & map,  uint16_t x,  uint16_t y)
	: map(map)
	, x(x)
	, y(y)
{}

Map Location::getMap() const
{
	return map;
}

uint16_t Location::getX() const
{
	return x;
}

uint16_t Location::getY() const
{
	return y;
}

uint8_t Location::getTileX() const
{
	return x >> 4; // x/16
}

uint8_t Location::getTileY() const
{
	return y >> 4; // y/16
}

void Location::updateX(int8_t diffX)
{
	x = x + diffX;
}

void Location::updateY(int8_t diffY)
{
	y = y + diffY;
}
