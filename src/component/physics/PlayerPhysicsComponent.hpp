#ifndef PLAYER_PHYSICS_COMPONENT_HPP
#define PLAYER_PHYSICS_COMPONENT_HPP

#include "PhysicsComponent.hpp"

class Player;

class PlayerPhysicsComponent : public PhysicsComponent
{
public:
	void update(Player *player);
};

#endif
