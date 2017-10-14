#include "ItemStack.hpp"

ItemStack::ItemStack(ItemType type, uint8_t amount)
	: type(type)
	, amount(amount)
{}

ItemType ItemStack::getType() const
{
	return type;
}
