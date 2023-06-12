#pragma once
#include "ColorSwap.h"

using namespace sf;

class Button
{
private:
	Sound hoverSound;
	bool soundPlayed;

public:
	Text buttonText;

	Button();
	virtual ~Button();
	bool mouseOverButton(RenderWindow* window);
	bool isPressed(RenderWindow* window);
	void setHoverSound(SoundBuffer& hoverSoundFile);
	void update(RenderWindow* window);
	void render(RenderTarget* target);
};
