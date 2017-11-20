#ifndef PLAYER_PHYSICS_COMPONENT_HPP
#define PLAYER_PHYSICS_COMPONENT_HPP

#include <stdint.h>

class Location;
class Player;

class PlayerPhysicsComponent
{
public:
	void update(Player *player);
private:
	bool checkMapPassability(Location *location, int8_t velocityX, int8_t velocityY);
};

#endif
