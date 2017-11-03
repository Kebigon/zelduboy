#include "InputComponent.hpp"

#include "globals.h"

void InputComponent::update(Player *player)
{
	int8_t velocityX = 0, velocityY = 0;

	if (arduboy.pressed(LEFT_BUTTON))
	{
		player->direction = Direction::LEFT;
		velocityX = -1;
	}
	else if (arduboy.pressed(RIGHT_BUTTON))
	{
		player->direction = Direction::RIGHT;
		velocityX = 1;
	}

	if (arduboy.pressed(UP_BUTTON))
	{
		player->direction = Direction::UP;
		velocityY = -1;
	}
	else if (arduboy.pressed(DOWN_BUTTON))
	{
		player->direction = Direction::DOWN;
		velocityY = 1;
	}

	player->setVelocity(velocityX, velocityY);

	if (arduboy.justPressed(A_BUTTON))
		player->useItem(player->getInventory()->getItemA());
	if (arduboy.justPressed(B_BUTTON))
		player->useItem(player->getInventory()->getItemA());
}
