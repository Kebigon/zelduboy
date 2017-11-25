#include "MapView.hpp"

#include "globals.h"
#include "../data/bitmaps.h"

#include "utils/DArray.hpp"
#include "utils/Logger.hpp"

void MapView::handleInput()
{
	game->getPlayer()->update();

	DArray<Entity *> * entities = game->getEntities();
	for (uint8_t i = 0; i != entities->getSize(); i++)
	{
		Entity *entity = entities->get(i);
		if (entity != NULL)
			entity->update();
	}
}

void MapView::draw()
{
	Player *player = game->getPlayer();

	tilesGraphicsComponent->draw();
	player->draw();

	DArray<Entity *> * entities = game->getEntities();
	for (uint8_t i = 0; i != entities->getSize(); i++)
	{
		Entity *entity = entities->get(i);
		if (entity != NULL)
			entity->draw();
	}
}
