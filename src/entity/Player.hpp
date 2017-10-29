#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "inventory/Inventory.hpp"
#include "Entity.hpp"
#include "../animation/Animation.hpp"

enum class Direction
{
	DOWN,
	LEFT,
	UP,
	RIGHT
};

enum class PlayerHorizontalPosition
{
	LEFT,
	CENTER,
	RIGHT
};

enum class PlayerVerticalPosition
{
	TOP,
	CENTER,
	BOTTOM
};

class Player : public Entity
{
	Inventory * inventory = new Inventory();
	Animation *currentAnimation = nullptr;

public:
	Player(Location *);
	Inventory * getInventory() const;
	void draw();
	bool isMoving;
	Direction direction;
	PlayerHorizontalPosition getHorizontalPosition() const;
	PlayerVerticalPosition getVerticalPosition() const;
	Animation * getCurrentAnimation() const;
	void setCurrentAnimation(Animation *animation);
	void useItem(ItemStack *item);
};

#endif
