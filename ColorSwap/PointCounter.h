#pragma once
#include "ColorSwap.h"

using namespace sf;

class PointCounter
{
	Text message;
public:
	PointCounter(Font& font);
	~PointCounter();
	void update(Vector2f viewCenter, unsigned int score);
	void render(RenderTarget* target);
};

