#include "ColorSwap.h"
#include "Item.h"

Item::Item(float yPosition, Texture& texture)
{
	item.setTexture(texture);
	item.setScale(0.9f, 0.9f);
	item.setPosition(WINDOW_WIDTH / 2 - 30.f, yPosition);
}

Item::~Item()
{

}

FloatRect Item::getBounds()
{
	return item.getGlobalBounds();
}

void Item::update()
{

}

void Item::render(RenderTarget* target)
{
	target->draw(item);
}
