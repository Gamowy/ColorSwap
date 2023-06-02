#include "ColorSwap.h"
#include "Item.h"

Item::Item(Vector2f position)
{
	itemTexture.loadFromFile("Assets/Images/star.png");
	item.setTexture(itemTexture);
	item.setScale(Vector2f(0.10f, 0.10f));
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
