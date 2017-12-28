#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Location.hpp"
#include "EntityType.hpp"
#include "EntityState.hpp"
#include <Arduboy2.h>

class Entity
{
	uint8_t spawnX, spawnY;
	EntityState *state = nullptr;

public:
	Entity(uint8_t spawnX, uint8_t spawnY);

	/** \brief
	 * Spawn the entity into the world
	 */
	void spawn();

	/** \brief
	 * Despawn the entity from the world
	 */
	void despawn();

	/** \brief
	 * Current location of the entity if it is spawned, nullptr otherwise
	 */
	Location * getLocation() const;


	Rect getCollisionBox() const;
	bool collideWith(Rect otherCollisionBox) const;
	virtual bool isPassable() const;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual EntityType getType() const = 0;
};

#endif
