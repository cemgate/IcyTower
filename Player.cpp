#include "includes.h"
#include "Player.h"

void Player::move(float timeMove, float playerMove)
{
	if (PlayerSprite.getPosition().y + velocity.y < SCROLL_LIMIT && velocity.y<0)
	{
		if (PlayerSprite.getPosition().y + velocity.y < 0)
		{
			PlayerSprite.move(velocity.x, 0);
			this->playerMove = std::abs(velocity.y);
		}
		else
		{
			PlayerSprite.move(velocity.x, (PlayerSprite.getPosition().y/SCROLL_LIMIT)* velocity.y);
			this->playerMove = std::abs( (1 - (PlayerSprite.getPosition().y / SCROLL_LIMIT)) * velocity.y);
		}	
	}

	else
	{
		if (this->grounded)
		{
			PlayerSprite.move(velocity.x, timeMove);
			velocity.y = timeMove;
		}
		else
		{
			PlayerSprite.move(velocity.x, velocity.y);
		}
		this->playerMove = 0;
	}
		
	
	positionUpdate();
}

void Player::generateSprite()
{
	PlayerTexture.loadFromFile("grafics/kwadrat_tp.png");
	PlayerSprite.setTexture(PlayerTexture);	
	PlayerSprite.setScale(0.3, 0.3);
	PlayerSprite.setOrigin((PlayerSprite.getLocalBounds().width)/2, (PlayerSprite.getLocalBounds().height) / 2);
} 

void Player::setPosition()
{
	PlayerSprite.setPosition(500, 700);
	positionUpdate();
}

void Player::display(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(PlayerSprite);
}

void Player::positionUpdate()
{
	position = PlayerSprite.getPosition();
}

bool  Player::readyToStartTheGame()
{
	return position.y < 250.0f;
}

