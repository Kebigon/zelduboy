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

EntityType Player::getType() const
{
	return EntityType::PLAYER;
}

Inventory * Player::getInventory() const
{
	return inventory;
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
		default:
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

	inputComponent.update(this);
	physicsComponent.update(this);
}

void Player::draw()
{
	graphicsComponent.draw(this);
}
