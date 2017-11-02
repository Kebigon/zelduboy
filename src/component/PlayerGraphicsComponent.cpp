#include "PlayerGraphicsComponent.hpp"

#include <Arduboy2.h>

#include "../Location.hpp"
#include "../entity/Player.hpp"
#include "../globals.h"
#include "../data/bitmaps.h"

void PlayerGraphicsComponent::draw(Player *player)
{
	Location *location = player->getLocation();

	uint16_t playerX = location->getX();
	uint16_t playerY = location->getY();
	Map *map = location->getMap();

	uint8_t displayPlayerX, displayPlayerY;

	switch (player->getHorizontalPosition())
	{
		case PlayerHorizontalPosition::LEFT:
			displayPlayerX = playerX;
			break;
		case PlayerHorizontalPosition::CENTER:
			displayPlayerX = PLAYER_CENTER_POS_LEFT;
			break;
		case PlayerHorizontalPosition::RIGHT:
			displayPlayerX = playerX - (map->getWidth() - MAP_CANVAS_WIDTH);
			break;
	}

	switch (player->getVerticalPosition())
	{
		case PlayerVerticalPosition::TOP:
			displayPlayerY = playerY;
			break;
		case PlayerVerticalPosition::CENTER:
			displayPlayerY = PLAYER_CENTER_POS_TOP;
			break;
		case PlayerVerticalPosition::BOTTOM:
			displayPlayerY = playerY - (map->getHeight() - MAP_CANVAS_HEIGHT);
			break;
	}

	Animation *playerAnimation = player->getCurrentAnimation();
	if (playerAnimation != nullptr)
	{
		playerAnimation->display(player, MAP_CANVAS_X + displayPlayerX, MAP_CANVAS_Y + displayPlayerY);
		return;
	}

	uint8_t frame = static_cast<int>(player->direction) << 1;

	if (player->isMoving)
	{
		switch (player->direction)
		{
			case Direction::LEFT:
			case Direction::RIGHT:
				frame += (playerX >> 2) % 2;
				break;
			case Direction::UP:
			case Direction::DOWN:
				frame += (playerY >> 2) % 2;
				break;
		}
	}

	Sprites::drawPlusMask(MAP_CANVAS_X + displayPlayerX, MAP_CANVAS_Y + displayPlayerY, link_plus_mask, frame);
}
