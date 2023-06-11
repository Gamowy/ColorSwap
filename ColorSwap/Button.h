#pragma once
#include "ColorSwap.h"

using namespace sf;

class Button
{
public:
	bool soundPlayed;
	Text buttonText;
	Sound hoverSound;
	Button();
	virtual ~Button();
	bool mouseOverButton(RenderWindow* window);
	bool isPressed(RenderWindow* window);
	void setHoverSound(SoundBuffer& hoverSoundFile);
	void update(RenderWindow* window);
	void render(RenderTarget* target);
};
