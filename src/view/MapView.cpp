#include "MapView.hpp"

#include "globals.h"
#include "../data/chunksdata.h"
#include "../data/bitmaps.h"


void MapView::handleInput()
{
	game->getPlayer()->update();

	std::vector<Entity *> entities = game->getEntities();
	for (std::vector<Entity *>::iterator it = entities.begin(); entities.end(); ++it)
		(*it)->update();
}

void MapView::draw()
{
	Player *player = game->getPlayer();

	tilesGraphicsComponent->draw();
	player->draw();

	std::vector<Entity *> entities = game->getEntities();
	for (std::vector<Entity *>::iterator it = entities.begin(); entities.end(); ++it)
		(*it)->draw();
}
