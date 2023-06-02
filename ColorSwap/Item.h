#pragma once
#include "ColorSwap.h"

using namespace sf;

class Item
{
private:
	Sprite item;
	Texture itemTexture;

public:
	Item(Vector2f position);
	virtual ~Item();

	void update();
	void render(RenderTarget* target);
};

