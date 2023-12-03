#include "includes.h"
#include "ComboStars.h"

void ComboStars::generateStars(const float& posX, const float& posY, int count)
{
	for (int i = 0; i < count; i++)
	{
		magicStars.push_back(Star(posX, posY));
	}
}

void ComboStars::display(sf::RenderWindow& window)
{
	std::cout << magicStars.size() << "\n";
	if (magicStars.size() != 0)
	{
		for (auto it = magicStars.begin(); it != magicStars.end();)
		{
			if (it->getPosY() > 1120)
			{
				it = magicStars.erase(it);
			}
			else
			{
				window.draw(it->getDrawable());
				++it;
			}
		}
	}
}

void ComboStars::move(float timeMove, float playerMove)
{
	if (magicStars.size() != 0)
	{
		for (auto& i : magicStars)
		{
			i.logic(timeMove, playerMove);
		}
	}
}

void ComboStars::generateSprite()
{
}

void ComboStars::setPosition()
{
}
