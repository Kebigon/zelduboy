#ifndef MAP_VIEW_HPP
#define MAP_VIEW_HPP

#include "View.hpp"
#include "entity/Player.hpp"
#include "component/graphics/TilesGraphicsComponent.hpp"

class MapView: public View
{
	TilesGraphicsComponent *tilesGraphicsComponent = new TilesGraphicsComponent();
	void drawMap(Player *player);
	void drawPlayer(Player *player);

public:
	virtual void handleInput();
	virtual void draw();
};

#endif
