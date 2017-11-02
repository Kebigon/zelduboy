#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "inventory/Inventory.hpp"
#include "Entity.hpp"
#include "../animation/Animation.hpp"

#include "../component/PlayerGraphicsComponent.hpp"
#include "../component/InputComponent.hpp"
#include "../component/PhysicsComponent.hpp"

enum class Direction
{
	DOWN,
	LEFT,
	UP,
	RIGHT
};

class Player : public Entity
{
	PlayerGraphicsComponent *graphicsComponent = new PlayerGraphicsComponent();
	InputComponent *inputComponent = new InputComponent();
	PhysicsComponent *physicsComponent = new PhysicsComponent();

	Inventory * inventory = new Inventory();
	Animation *currentAnimation = nullptr;
	int8_t velocityX = 0, velocityY = 0;

public:
	Player(Location *);
	Inventory * getInventory() const;
	bool isMoving;
	Direction direction;
	Animation * getCurrentAnimation() const;
	void setCurrentAnimation(Animation *animation);
	void useItem(ItemStack *item);

	int8_t getVelocityX() const;
	int8_t getVelocityY() const;
	void setVelocity(int8_t velocityX, int8_t velocityY);
	void setDirection(Direction direction);
	void update();
	void draw();
};

#endif
