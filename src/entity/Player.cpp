#include "Player.hpp"

#include <Arduboy2.h>
#include <Sprites.h>
#include "globals.h"
#include "../animation/player/PlayerSwingsSwordAnimation.hpp"

Player::Player(Location * location)
	: Entity(location)
	, isMoving(false)
	, direction(Direction::DOWN)
{}

Inventory * Player::getInventory() const
{
	return inventory;
}

PlayerHorizontalPosition Player::getHorizontalPosition() const
{
	uint16_t playerX = getLocation()->getX();

	if (playerX < PLAYER_CENTER_POS_LEFT) // Close to left border of the map
		return PlayerHorizontalPosition::LEFT;
	else if (playerX > getLocation()->getMap()->getWidth() - PLAYER_CENTER_POS_RIGHT) // Close to the right border of the map
		return PlayerHorizontalPosition::RIGHT;
	else
		return PlayerHorizontalPosition::CENTER;
}

PlayerVerticalPosition Player::getVerticalPosition() const
{
	uint16_t playerY = getLocation()->getY();

	if (playerY < PLAYER_CENTER_POS_TOP) // Close to top border of the map
		return PlayerVerticalPosition::TOP;
	else if (playerY > getLocation()->getMap()->getHeight() - PLAYER_CENTER_POS_BOTTOM) // Close to the bottom border of the map
		return PlayerVerticalPosition::BOTTOM;
	else
		return PlayerVerticalPosition::CENTER;
}

Animation * Player::getCurrentAnimation() const
{
	return currentAnimation;
}

void Player::setCurrentAnimation(Animation *animation)
{
	currentAnimation = animation;
}

void Player::useItem(ItemStack *item)
{
	switch (item->getType())
	{
		case ItemType::SWORD:
			currentAnimation = new PlayerSwingsSwordAnimation();
			break;
	}
}

void Player::setVelocity(int8_t velocityX, int8_t velocityY)
{
	this->velocityX = velocityX;
	this->velocityY = velocityY;
}

int8_t Player::getVelocityX() const
{
	return velocityX;
}

int8_t Player::getVelocityY() const
{
	return velocityY;
}

void Player::update()
{
	// TODO: remove from here
	Animation *animation = getCurrentAnimation();
	if (animation != nullptr && animation->isFinish())
	{
		animation->onAnimationEnd();
		setCurrentAnimation(nullptr);
	}

	// TODO: remove from here
	if (game->isMapInputLocked())
		return;

	inputComponent->update(this);
	physicsComponent->update(this);
}

void Player::draw()
{
	graphicsComponent->draw(this);
}
