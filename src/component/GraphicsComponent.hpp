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
	PlayerHorizontalPosition getPlayerHorizontalPosition() const;
	PlayerVerticalPosition getPlayerVerticalPosition() const;
	uint16_t getDisplayStartX() const;
	uint16_t getDisplayStartY() const;
};

#endif
