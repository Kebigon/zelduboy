#ifndef MOVABLE_BLOCK_HPP
#define MOVABLE_BLOCK_HPP

#include "Location.hpp"
#include "entity/Entity.hpp"
#include "component/graphics/MovableBlockGraphicsComponent.hpp"
#include "component/physics/MovableBlockPhysicsComponent.hpp"

class MovableBlock : public Entity
{
	static MovableBlockGraphicsComponent graphicsComponent;
	static MovableBlockPhysicsComponent physicsComponent;
public:
	MovableBlock(Location *location);
	virtual bool isPassable() const;
	virtual void update();
	virtual void draw();
	virtual EntityType getType() const;

	bool push(int8_t velocityX, int8_t velocityY);
};

#endif
