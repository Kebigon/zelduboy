#ifndef ENTITY_STATE_HPP
#define ENTITY_STATE_HPP

#include "Location.hpp"

class EntityState
{
	Location *location;
public:
	Location * getLocation() const;
};

#endif
