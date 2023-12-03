#include "includes.h"
#include "Column.h"


void Column::display(sf::RenderWindow& window)
{
	window.draw(ColumnSpriteRenderer);
	ColumnSpriteRenderer.setPosition(1630, 0);
	window.draw(ColumnSpriteRenderer);
	setPosition();
}

void Column::move(float timeMove, float playerMove)
{
}

void Column::generateSprite()
{
	loadColumnTexture();
	loadColumnSprite();
	generateColumn();
}

void Column::setPosition()
{
	ColumnSpriteRenderer.setPosition(350 - ColumnTexture.getSize().x, 0);
}

void Column::loadColumnTexture()
{
	ColumnTexture.loadFromFile("grafics/filar.png");
}

void  Column::loadColumnSprite()
{
	ColumnSprite.setTexture(ColumnTexture);
}

void  Column::generateColumn()
{
	ColumnTextureRenderer.create(ColumnTexture.getSize().x, 5 * ColumnTexture.getSize().y);

	for (int i = 0; i < 5; i++)
	{
		ColumnSprite.setPosition(0, i*ColumnTexture.getSize().y);
		ColumnTextureRenderer.draw(ColumnSprite);
	}
	ColumnSpriteRenderer.setTexture(ColumnTextureRenderer.getTexture());
}

