#include "includes.h"
#include "Platform.h"



void Platform::display(sf::RenderWindow& window)
{
	
	for (auto& i : PlatformSprites)
	{
		
			window.draw(i);
		
	}
}

void Platform::move(float timeMove, float playerMove)
{
	for (auto& i : PlatformSprites)
	{
		i.move(0, timeMove + playerMove);
	}
	updatePosition();
}

void Platform::generateSprite()
{
	loadSideTextures();
	loadSideSprites();
	generateLongPlatform();
	generateShortPlatforms(20);
}

void Platform::setPosition()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(0.0f, 10.0f);

	int k = 170;
	float randomFloat;
	bool first = true;
	for (auto& i : PlatformSprites)
	{
		randomFloat = std::abs(std::sin(dis(gen)));
		if (first)
		{
			i.setPosition(350, 1000 - k);
			first = false;
		}
		else
		{
			i.setPosition(350 + randomFloat * (1280 - i.getTexture()->getSize().x), 1000 - k);
		}
		k += 170;
	}

	updatePosition();
}

void Platform::loadSideTextures()
{
	SidePlatformTextures[0].loadFromFile("grafics/platforma_lewa_fiolet.png");
	SidePlatformTextures[1].loadFromFile("grafics/platforma_srodek_fioletowa.png");
	SidePlatformTextures[2].loadFromFile("grafics/platforma_prawa_fiolet.png");
}

void Platform::loadSideSprites()
{
	int textureNumber = 0; // 0-left side platform, 1-mid platform, 2-right side platform
	for (textureNumber; textureNumber < 3; textureNumber++)
	{
		SidePlatformSprites[textureNumber].setTexture(SidePlatformTextures[textureNumber]);
	}
}

void Platform::generateLongPlatform()
{
	RenderedPlatformTextures[0] = new sf::RenderTexture;
	RenderedPlatformTextures[0]->create(20 * SidePlatformTextures[1].getSize().x, SidePlatformTextures[1].getSize().y);

	for (int i = 0; i < 20; i++)
	{
		SidePlatformSprites[1].setPosition(i * SidePlatformTextures[1].getSize().x, 0);
		RenderedPlatformTextures[0]->draw(SidePlatformSprites[1]);
	}
	PlatformSprites[0].setTexture(RenderedPlatformTextures[0]->getTexture());
}

void Platform::generateShortPlatforms(int howManyPlatforms)
{
	for (int i = 1; i < howManyPlatforms; i++)
	{
		sf::Sprite sprite;
		int howMany = std::rand() % 9 + 4;
		RenderedPlatformTextures[i] = new sf::RenderTexture;
		RenderedPlatformTextures[i]->create(howMany * SidePlatformTextures[0].getSize().x, SidePlatformTextures[0].getSize().y);

		for (int j = 0; j < howMany; ++j)
		{
			if (j == 0)
			{
				sprite = SidePlatformSprites[0];
				sprite.setPosition(j * SidePlatformTextures[0].getSize().x, 0);
				RenderedPlatformTextures[i]->draw(sprite);
			}
			else if (j == howMany - 1)
			{
				sprite = SidePlatformSprites[2];
				sprite.setPosition(j * SidePlatformTextures[1].getSize().x, 0);
				RenderedPlatformTextures[i]->draw(sprite);
			}
			else
			{
				sprite = SidePlatformSprites[1];
				sprite.setPosition(j * SidePlatformTextures[2].getSize().x, 0);
				RenderedPlatformTextures[i]->draw(sprite);
			}
		}

		PlatformSprites[i].setTexture(RenderedPlatformTextures[i]->getTexture());
		
		
	}
}

void Platform::generateNewPlatform()
{
	this->platformCounter++;

	sf::Sprite newestSprite;
	sf::RenderTexture* newestTexture = new sf::RenderTexture;

	PlatformSprites.push_back(newestSprite);

	RenderedPlatformTextures.push_back(newestTexture);


	int howMany = std::rand() % 9 + 4;

	RenderedPlatformTextures[RenderedPlatformTextures.size() - 1]->create(howMany * SidePlatformTextures[0].getSize().x, SidePlatformTextures[0].getSize().y);

	for (int j = 0; j < howMany; ++j)
	{
		if (j == 0)
		{
			newestSprite = SidePlatformSprites[0];
			newestSprite.setPosition(j * SidePlatformTextures[0].getSize().x, 0);
			RenderedPlatformTextures[RenderedPlatformTextures.size() - 1]->draw(newestSprite);
		}
		else if (j == howMany - 1)
		{
			newestSprite = SidePlatformSprites[2];
			newestSprite.setPosition(j * SidePlatformTextures[1].getSize().x, 0);
			RenderedPlatformTextures[RenderedPlatformTextures.size() - 1]->draw(newestSprite);
		}
		else
		{
			newestSprite = SidePlatformSprites[1];
			newestSprite.setPosition(j * SidePlatformTextures[2].getSize().x, 0);
			RenderedPlatformTextures[RenderedPlatformTextures.size() - 1]->draw(newestSprite);
		}
	}
	sf::Color newColor(137, 207, 240);
	PlatformSprites[PlatformSprites.size() - 1].setTexture(RenderedPlatformTextures[RenderedPlatformTextures.size() - 1]->getTexture());
	//PlatformSprites[PlatformSprites.size() - 1].setColor(newColor);

}

void Platform::setNewPlatformPosition()
{
	int distanceBetweenPlatforms = 170;
	double randomPositionFactor = std::abs(std::sin(rand()));
	PlatformSprites[PlatformSprites.size() - 1].setPosition(350 + randomPositionFactor * (1280 - PlatformSprites[PlatformSprites.size() - 1].getTexture()->getSize().x), position[position.size() - 2].y - distanceBetweenPlatforms);
}

void Platform::updatePosition()
{
	while (PlatformSprites[0].getPosition().y > 1250)
	{
		erasePlatform();	
	}

	for (int i = 0; i < PlatformSprites.size(); i++)
	{
		position[i] = PlatformSprites[i].getPosition();
	}
}

void Platform::erasePlatform()
{
	PlatformSprites.pop_front();
	RenderedPlatformTextures.pop_front();
	position.pop_front();
	position.push_back({ 0,0 });

	generateNewPlatform();
	setNewPlatformPosition();
}


