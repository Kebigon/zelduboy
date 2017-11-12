#include "MapView.hpp"

#include "globals.h"
#include "../data/chunksdata.h"
#include "../data/bitmaps.h"

#include "utils/DArray.hpp"

void MapView::handleInput()
{
	game->getPlayer()->update();

	DArray<Entity *> entities = game->getEntities();
	for (uint8_t i = 0; i != entities.getSize(); i++)
		entities.get(i)->update();
}

void MapView::draw()
{
	Player *player = game->getPlayer();

	tilesGraphicsComponent->draw();
	player->draw();

	DArray<Entity *> entities = game->getEntities();
	for (uint8_t i = 0; i != entities.getSize(); i++)
		entities.get(i)->draw();
}
