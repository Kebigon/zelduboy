#include "MapView.hpp"

#include "globals.h"
#include "../data/chunksdata.h"
#include "../data/bitmaps.h"


void MapView::handleInput()
{
	game->getPlayer()->update();
}

void MapView::draw()
{
	Player *player = game->getPlayer();

	tilesGraphicsComponent->draw();
	player->draw();
}
