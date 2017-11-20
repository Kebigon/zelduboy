#ifndef MOVABLE_BLOCK_GRAPHICS_COMPONENT_HPP
#define MOVABLE_BLOCK_GRAPHICS_COMPONENT_HPP

#include "GraphicsComponent.hpp"

class MovableBlock;

class MovableBlockGraphicsComponent : public GraphicsComponent
{
public:
	void draw(MovableBlock *block);
};

#endif
