#pragma once
#include "ColorSwap.h"

using namespace sf;

class Item
{
private:
	Sprite item;

public:
	Item(float yPosition, Texture& texture);
	virtual ~Item();

	FloatRect getBounds();
	void update();
	void render(RenderTarget* target);
};

