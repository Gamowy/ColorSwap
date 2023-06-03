#include "ColorSwap.h"
#include "Item.h"

Item::Item()
{
	item.setScale(0.9f, 0.9f);
}

Item::~Item()
{

}

void Item::initItem(float yPosition, Texture& texture)
{
	item.setTexture(texture);
	item.setPosition(WINDOW_WIDTH / 2 - 30.f, yPosition);
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
