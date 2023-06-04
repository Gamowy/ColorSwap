#pragma once
#include "ColorSwap.h"

using namespace sf;

class PointCounter
{
	Text message;
public:
	PointCounter(Font& font);
	virtual ~PointCounter();
	void update(Vector2f viewCenter, unsigned int score);
	void render(RenderTarget* target);
};

