#ifndef GRAPHICS_COMPONENT_HPP
#define GRAPHICS_COMPONENT_HPP

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
};

#endif
