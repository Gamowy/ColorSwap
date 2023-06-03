#include "ColorSwap.h"
#include "Item.h"

Item::Item(float yPosition, Texture& texture)
{
	item.setTexture(texture);
	item.setScale(Vector2f(0.9f, 0.9f));
	item.setPosition(Vector2f(WINDOW_WIDTH / 2 - 30.f, yPosition));
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
