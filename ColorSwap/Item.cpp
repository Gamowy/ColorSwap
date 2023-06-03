#include "ColorSwap.h"
#include "Item.h"

Item::Item(Vector2f position, Texture& texture)
{
	item.setTexture(texture);
	item.setScale(Vector2f(0.1f, 0.1f));
	item.setPosition(position);
}

Item::~Item()
{

}

void Item::update()
{

}

void Item::render(RenderTarget* target)
{
	target->draw(item);
}
