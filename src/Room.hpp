#ifndef ROOM_HPP
#define ROOM_HPP

#include <stdint.h>
#include <Arduboy2.h>

class Room
{
	const uint8_t roomX, roomY;
	const uint8_t width, height;
	const uint8_t * mapTiles;
	const uint8_t * mapPassable;

public:
	Room(uint8_t roomX, uint8_t roomY, const uint8_t *roomData);

	/** \brief
	 *	X position of the room
	 */
	uint8_t getX() const;

	/** \brief
	 *	Y position of the room
	 */
	uint8_t getY() const;

	/** \brief
	 * Width of the room
	 */
	uint8_t getWidth() const;

	/** \brief
	 * Height of the room
	 */
	uint8_t getHeight() const;

	/** \brief
	 *	X position of the room in pixels
	 */
	uint16_t getPixelX() const;

	/** \brief
	 *	Y position of the room in pixels
	 */
	uint16_t getPixelY() const;

	/** \brief
	 * Width of the room in pixels
	 */
	uint16_t getPixelWidth() const;

	/** \brief
	 * Height of the room in pixels
	 */
	uint16_t getPixelHeight() const;

	uint8_t getTile(uint8_t mapX, uint8_t mapY) const;
	bool isPassable(uint8_t mapX, uint8_t mapY) const;

	bool isInsideRoom(uint8_t tileX, uint8_t tileY) const;
	Rect getRoomRect() const;

private:
	uint16_t getTileAddress(uint8_t, uint8_t) const;
};

#endif
