#include "ColorSwap.h"
#include "Button.h"

Button::Button()
{
	soundPlayed = false;
}

Button::~Button()
{
}

bool Button::mouseOverButton(RenderWindow* window)
{
	if (Mouse::getPosition(*window).x >= buttonText.getPosition().x && Mouse::getPosition(*window).x <= buttonText.getPosition().x + buttonText.getLocalBounds().width &&
		Mouse::getPosition(*window).y >= buttonText.getPosition().y && Mouse::getPosition(*window).y <= buttonText.getPosition().y + buttonText.getLocalBounds().height + 10.f)
	{
		return true;
	}
	return false;
}

bool Button::isPressed(RenderWindow* window)
{
	if ((Keyboard::isKeyPressed(Keyboard::Enter) && mouseOverButton(window)) || (Mouse::isButtonPressed(Mouse::Left) && mouseOverButton(window)))
	{
		return true;
	}
	return false;
}

void Button::setHoverSound(SoundBuffer& hoverSoundFile)
{
	hoverSound.setBuffer(hoverSoundFile);
	hoverSound.setPitch(0.7f);
	hoverSound.setVolume(1.5f);
}

void Button::update(RenderWindow* window)
{
	if (mouseOverButton(window))
	{
		if (!soundPlayed)
		{
			hoverSound.play();
			soundPlayed = true;
		}
		buttonText.setFillColor(COLOR_SWAP_YELLOW);
	}
	else
	{
		buttonText.setFillColor(Color::White);
		soundPlayed = false;
	}
}

void Button::render(RenderTarget* target)
{
	target->draw(buttonText);
}
