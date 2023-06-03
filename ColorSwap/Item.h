#pragma once
#include "ColorSwap.h"

using namespace sf;

class Item
{
private:
	Sprite item;

public:
	Item();
	virtual ~Item();

	void initItem(float yPosition, Texture& texture);
	FloatRect getBounds();
	void update();
	void render(RenderTarget* target);
};

