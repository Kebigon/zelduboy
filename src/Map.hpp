#ifndef MAP_HPP
#define MAP_HPP

#include <stdint.h>

class Map
{
	const uint8_t width, height;
	const uint8_t * mapTiles;
	const uint8_t * mapPassable;

public:
	Map(const uint8_t *mapt);

	/** \brief
	 * Width of the map in pixels
	 */
	uint16_t getWidth() const;

	/** \brief
	 * Height of the map in pixels
	 */
	uint16_t getHeight() const;

	/** \brief
	 * Width of the map in tiles
	 */
	uint8_t getTileWidth() const;

	/** \brief
	 * Height of the map in tiles
	 */
	uint8_t getTileHeight() const;

	uint8_t getTile(uint8_t tileX, uint8_t tileY) const;
	bool isPassable(uint8_t tileX, uint8_t tileY) const;

private:
	uint16_t getTileAddress(uint8_t, uint8_t) const;
};

#endif
