#include "includes.h"
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
	BackgroundTexture.loadFromFile("grafics/sciana.png");
	BackgroundSprite.setTexture(BackgroundTexture);
	BackgroundSprite.setPosition(300, 300);
}

void Background::setPosition()
{
}
