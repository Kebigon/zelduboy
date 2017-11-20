#ifndef MOVABLE_BLOCK_HPP
#define MOVABLE_BLOCK_HPP

#include "Location.hpp"
#include "entity/Entity.hpp"
#include "component/graphics/MovableBlockGraphicsComponent.hpp"

class MovableBlock : public Entity
{
	static MovableBlockGraphicsComponent graphicsComponent;
public:
	MovableBlock(Location *location);
	virtual bool isPassable() const;
	virtual void update();
	virtual void draw();
};

#endif
