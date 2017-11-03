#ifndef PLAYER_GRAPHICS_COMPONENT_HPP
#define PLAYER_GRAPHICS_COMPONENT_HPP

#include "GraphicsComponent.hpp"

class Player;

class PlayerGraphicsComponent : public GraphicsComponent
{
public:
	void draw(Player *player);
};

#endif
