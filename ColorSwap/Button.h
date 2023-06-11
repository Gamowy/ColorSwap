#pragma once
#include "ColorSwap.h"

using namespace sf;

class Button
{
public:
	Text buttonText;
	Button();
	virtual ~Button();
	bool mouseOverButton(RenderWindow* window);
	bool isPressed(RenderWindow* window);
	void update(RenderWindow* window);
	void render(RenderTarget* target);
};
