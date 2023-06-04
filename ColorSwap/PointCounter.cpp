#include "ColorSwap.h"
#include "PointCounter.h"

using namespace sf;

PointCounter::PointCounter(Font& font)
{
	message.setFont(font);
	message.setCharacterSize(FONT_SIZE);
	message.setFillColor(Color::White);
}

PointCounter::~PointCounter()
{
}

void PointCounter::update(Vector2f viewCenter, unsigned int score)
{
	message.setPosition(viewCenter.x - 0.49f * WINDOW_WIDTH, viewCenter.y - 0.5f * WINDOW_HEIGHT);
	message.setString("Score: " + std::to_string(score));
}

void PointCounter::render(RenderTarget* target)
{
	target->draw(message);
}
