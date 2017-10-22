#ifndef VIEW_HPP
#define VIEW_HPP

#include "../Game.hpp"

class View
{
public:
	virtual void handleInput() = 0;
	virtual void draw() = 0;
};

#endif
