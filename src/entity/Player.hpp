#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "inventory/Inventory.hpp"
#include "Entity.hpp"
#include "../animation/Animation.hpp"

#include "../component/InputComponent.hpp"
#include "../component/PhysicsComponent.hpp"

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
	InputComponent *inputComponent = new InputComponent();
	PhysicsComponent *physicsComponent = new PhysicsComponent();

	Inventory * inventory = new Inventory();
	Animation *currentAnimation = nullptr;
	int8_t velocityX = 0, velocityY = 0;

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

	int8_t getVelocityX() const;
	int8_t getVelocityY() const;
	void setVelocity(int8_t velocityX, int8_t velocityY);
	void setDirection(Direction direction);
	void update();
};

#endif
