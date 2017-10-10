#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Location.hpp"

enum class Direction
{
	DOWN,
	LEFT,
	UP,
	RIGHT
};

enum class PlayerHorizontalPosition
{
	LEFT,
	CENTER,
	RIGHT
};

enum class PlayerVerticalPosition
{
	TOP,
	CENTER,
	BOTTOM
};

class Player
{
	Location * location;

public:
	Player(Location *);
	Location * getLocation() const;
	void draw();
	bool isMoving;
	Direction direction;
	PlayerHorizontalPosition getHorizontalPosition() const;
	PlayerVerticalPosition getVerticalPosition() const;
};

#endif
