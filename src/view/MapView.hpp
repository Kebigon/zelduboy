#ifndef MAP_VIEW_HPP
#define MAP_VIEW_HPP

#include "View.hpp"

class MapView: public View
{
	void drawMap(Player *player);
	void drawPlayer(Player *player);

public:
	MapView(Game *game);
	virtual void handleInput();
	virtual void draw();
};

#endif
