#include "includes.h"
#include "Player.h"

void Player::move(float timeMove, float playerMove)
{
	if (PlayerSprite.getPosition().y + velocity.y < SCROLL_LIMIT && velocity.y < 0)
	{
		if (PlayerSprite.getPosition().y + velocity.y < 0)
		{
			PlayerSprite.move(velocity.x, 0);
			this->playerMove = std::abs(velocity.y);
		}
		else
		{
			PlayerSprite.move(velocity.x, (PlayerSprite.getPosition().y / SCROLL_LIMIT) * velocity.y);
			this->playerMove = std::abs((1 - (PlayerSprite.getPosition().y / SCROLL_LIMIT)) * velocity.y);
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
	PlayerTexture[0].loadFromFile("grafics/stoi.png");
	PlayerTexture[1].loadFromFile("grafics/uginanie.png");
	PlayerTexture[2].loadFromFile("grafics/ruchlewo1.png");
	PlayerTexture[3].loadFromFile("grafics/ruchlewo2.png");
	PlayerTexture[4].loadFromFile("grafics/ruchlewo3.png");
	PlayerTexture[5].loadFromFile("grafics/ruchprawo1.png");
	PlayerTexture[6].loadFromFile("grafics/ruchprawo2.png");
	PlayerTexture[7].loadFromFile("grafics/ruchprawo3.png");
	PlayerTexture[8].loadFromFile("grafics/skoklewo1.png");
	PlayerTexture[9].loadFromFile("grafics/skoklewo2.png");
	PlayerTexture[10].loadFromFile("grafics/skokprawo1.png");
	PlayerTexture[11].loadFromFile("grafics/skokprawo2.png");
	PlayerTexture[12].loadFromFile("grafics/skok.png");
	PlayerTexture[13].loadFromFile("grafics/combo.png");


	PlayerSprite.setTexture(PlayerTexture[0]);
	PlayerSprite.setScale(0.19, 0.19);
	PlayerSprite.setOrigin((PlayerSprite.getLocalBounds().width) / 2, (PlayerSprite.getLocalBounds().height) / 2);
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

void Player::changeSprite(const std::string& actionAnimation)
{

	this->currentFrame++;

	if (currentFrame == 60)
	{
		currentFrame = 0;
	}


	//Combo animation and jump animations
	if (!this->grounded)
	{
		//combo animation
		if (jumpStrength == 3)
		{
			PlayerSprite.setTexture(PlayerTexture[13], true);
			PlayerSprite.setRotation(PlayerSprite.getRotation() + 10);
		}
		//normal jump animation
		else if (jumpStrength == 1)
		{
			PlayerSprite.setRotation(0);
			PlayerSprite.setTexture(PlayerTexture[12], true);

		}

		//jump left
		else if (jumpStrength == 2 && this->velocity.x < 0)
		{
			PlayerSprite.setRotation(0);

			if (this->actualAnimationFrame != 8 &&
				this->actualAnimationFrame != 9)
			{
				PlayerSprite.setTexture(PlayerTexture[8], true);
				actualAnimationFrame = 8;
			}

			if (currentFrame % 45 == 0)
			{
				if (this->actualAnimationFrame == 8)
				{
					PlayerSprite.setTexture(PlayerTexture[9], true);
					actualAnimationFrame == 9;

				}
			}
		}


		//jump right
		else if (jumpStrength == 2 && this->velocity.x > 0)
		{
			PlayerSprite.setRotation(0);

			if (this->actualAnimationFrame != 10 &&
				this->actualAnimationFrame != 11)
			{
				PlayerSprite.setTexture(PlayerTexture[10], true);
				actualAnimationFrame = 10;
			}

			if (currentFrame % 45 == 0)
			{
				if (this->actualAnimationFrame == 10)
				{
					PlayerSprite.setTexture(PlayerTexture[11], true);
					actualAnimationFrame == 11;

				}
			}
		}

	}

	//walking animation
	if (this->grounded)
	{

		PlayerSprite.setRotation(0);

		//walk to right
		if (velocity.x > 0 && actionAnimation=="right")
		{
			if (this->actualAnimationFrame != 5 &&
				this->actualAnimationFrame != 6 &&
				this->actualAnimationFrame != 7)
			{
				PlayerSprite.setTexture(PlayerTexture[5], true);
				actualAnimationFrame = 5;
			}


			if (currentFrame % 10 == 0)
			{
				if (this->actualAnimationFrame == 5)
				{
					PlayerSprite.setTexture(PlayerTexture[6], true);
					actualAnimationFrame = 6;
				}
				else if (this->actualAnimationFrame == 6)
				{
					PlayerSprite.setTexture(PlayerTexture[7], true);
					actualAnimationFrame = 7;
				}
				else if (this->actualAnimationFrame == 7)
				{
					PlayerSprite.setTexture(PlayerTexture[5], true);
					actualAnimationFrame = 5;
				}
			}
		}

		//walk left
		if (velocity.x < 0 && actionAnimation == "left")
		{
			if (this->actualAnimationFrame != 2 &&
				this->actualAnimationFrame != 3 &&
				this->actualAnimationFrame != 4)
			{
				PlayerSprite.setTexture(PlayerTexture[2], true);
				actualAnimationFrame = 2;
			}


			if (currentFrame % 10 == 0)
			{
				if (this->actualAnimationFrame == 2)
				{
					PlayerSprite.setTexture(PlayerTexture[3], true);
					actualAnimationFrame = 3;
				}
				else if (this->actualAnimationFrame == 3)
				{
					PlayerSprite.setTexture(PlayerTexture[4], true);
					actualAnimationFrame = 4;
				}
				else if (this->actualAnimationFrame == 4)
				{
					PlayerSprite.setTexture(PlayerTexture[2], true);
					actualAnimationFrame = 2;
				}
			}
		}

		//standing
		if (velocity.x == 0 && actionAnimation == "")
		{
			
			if (this->actualAnimationFrame != 0 &&
				this->actualAnimationFrame != 1)
			{
				PlayerSprite.setTexture(PlayerTexture[0], true);
				actualAnimationFrame = 0;
			}


			if (currentFrame % 20 == 0)
			{
				if (this->actualAnimationFrame == 0)
				{
					PlayerSprite.setTexture(PlayerTexture[1], true);
					actualAnimationFrame = 1;
				}
				else if (this->actualAnimationFrame == 1)
				{
					PlayerSprite.setTexture(PlayerTexture[0], true);
					actualAnimationFrame = 0;
				}

			}
		}
	}
}

