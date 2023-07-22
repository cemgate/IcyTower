#include "Background.h"

void Background::display(sf::RenderWindow& window)
{
	window.draw(BackgroundSprite);
}

void Background::move()
{
}

void Background::generateSprite()
{
	BackgroundTexture.loadFromFile("grafics/kwadrat.png");
	BackgroundSprite.setTexture(BackgroundTexture);
	BackgroundSprite.setPosition(100, 100);
}
