#pragma once
#include "ColorSwap.h"

using namespace sf;

class Item
{
private:
	Sprite item;

public:
	Item(Vector2f position, Texture& texture);
	virtual ~Item();

	void update();
	void render(RenderTarget* target);
};

