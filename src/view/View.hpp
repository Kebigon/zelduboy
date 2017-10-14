#ifndef VIEW_HPP
#define VIEW_HPP

#include "../Game.hpp"

class View
{
public:
	View(Game *game);
	virtual void handleInput() = 0;
	virtual void draw() = 0;
protected:
	Game *game;
};

#endif
