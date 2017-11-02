#ifndef GRAPHICS_COMPONENT_HPP
#define GRAPHICS_COMPONENT_HPP

#include <stdint.h>

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

class GraphicsComponent
{
protected:
	static PlayerHorizontalPosition getPlayerHorizontalPosition();
	static PlayerVerticalPosition getPlayerVerticalPosition();
	static uint16_t getDisplayStartX();
	static uint16_t getDisplayStartY();
};

#endif
