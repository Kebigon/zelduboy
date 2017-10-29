#include "Entity.hpp"

Entity::Entity(Location * location)
	: location(location)
{}

Location * Entity::getLocation() const
{
	return location;
}
