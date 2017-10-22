#ifndef ITEM_STACK_HPP
#define ITEM_STACK_HPP

#include <stdint.h>

enum class ItemType
{
	NONE,
	SWORD,
	SHIELD,
	FEATHER,
	BRACELET,
	BOOTS,
	BOW,
	HOOKSHOT,
	ROD,
	OCARINA,
	SHOVEL,
	POWDER,
	BOMB
};

class ItemStack
{
	ItemType type;
	uint8_t amount;

public:
	ItemStack(ItemType = ItemType::NONE, uint8_t = 1);

	ItemType getType() const;
	uint8_t getAmount() const;
};

#endif
