#include "GraphicsComponent.hpp"

#include "globals.h"

PlayerHorizontalPosition GraphicsComponent::getPlayerHorizontalPosition() const
{
	Location *playerLocation = game->getPlayer()->getLocation();
	uint16_t playerX = playerLocation->getX();

	if (playerX < PLAYER_CENTER_POS_LEFT) // Close to left border of the map
		return PlayerHorizontalPosition::LEFT;
	else if (playerX > playerLocation->getMap()->getWidth() - PLAYER_CENTER_POS_RIGHT) // Close to the right border of the map
		return PlayerHorizontalPosition::RIGHT;
	else
		return PlayerHorizontalPosition::CENTER;
}

PlayerVerticalPosition GraphicsComponent::getPlayerVerticalPosition() const
{
	Location *playerLocation = game->getPlayer()->getLocation();
	uint16_t playerY = playerLocation->getY();

	if (playerY < PLAYER_CENTER_POS_TOP) // Close to top border of the map
		return PlayerVerticalPosition::TOP;
	else if (playerY > playerLocation->getMap()->getHeight() - PLAYER_CENTER_POS_BOTTOM) // Close to the bottom border of the map
		return PlayerVerticalPosition::BOTTOM;
	else
		return PlayerVerticalPosition::CENTER;
}

uint16_t GraphicsComponent::getDisplayStartX() const
{
	switch (getPlayerHorizontalPosition())
	{
		case PlayerHorizontalPosition::LEFT:
			return 0;
		case PlayerHorizontalPosition::CENTER:
			return game->getPlayer()->getLocation()->getX() - PLAYER_CENTER_POS_LEFT;
		case PlayerHorizontalPosition::RIGHT:
			return game->getPlayer()->getLocation()->getMap()->getWidth() - MAP_CANVAS_WIDTH;
	}
}

uint16_t GraphicsComponent::getDisplayStartY() const
{
	switch (getPlayerVerticalPosition())
	{
		case PlayerVerticalPosition::TOP:
			return 0;
		case PlayerVerticalPosition::CENTER:
			return game->getPlayer()->getLocation()->getY() - PLAYER_CENTER_POS_TOP;
		case PlayerVerticalPosition::BOTTOM:
			return game->getPlayer()->getLocation()->getMap()->getHeight() - MAP_CANVAS_HEIGHT;
	}
}
