#include "includes.h"
#include "Clock.h"

void Clock::display(sf::RenderWindow& window)
{
	window.draw(ClockSprite);
}

void Clock::move(float timeMove, float playerMove)
{
}

void Clock::generateSprite()
{
}

void Clock::setPosition()
{
}

float Clock::getClockTimeStep()
{
	return this->clockTimeStep;
}

void Clock::setClockTimeStep()
{
	this->clockTimeStep += 1.0f;
}
