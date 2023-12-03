#include "includes.h"
#include "Wall.h"


void Wall::display(sf::RenderWindow& window)
{
	window.draw(WallSprite);
}

void Wall::move(float timeMove, float playerMove)
{
	WallSprite.move(0, 0.2*(timeMove + playerMove));
}

void Wall::generateSprite()
{
	BrickTexture.loadFromFile("grafics/cegla.png");
	BrickSprite.setTexture(BrickTexture);

	WallTexture.create(20 * BrickTexture.getSize().x, 100 * BrickTexture.getSize().y);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			BrickSprite.setPosition(i * BrickTexture.getSize().x, j * BrickTexture.getSize().y);
			WallTexture.draw(BrickSprite);
		}
	}
	WallSprite.setTexture(WallTexture.getTexture());
}

void Wall::setPosition()
{
	WallSprite.setPosition(350, -(int)WallTexture.getSize().y + 1080);	
}



