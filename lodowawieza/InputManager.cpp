#include "includes.h"
#include "InputManager.h"


void InputManager::checkInput()
{
}

void InputManager::inputFirstScreen()
{
}

void InputManager::inputGame(Player& player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rightMovement = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		leftMovement = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		jumpMovement = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		exit(0);
	}


	if (rightMovement && !leftMovement)
	{
		if (player.velocity.x < MAX_SPEED)
		{
			player.velocity.x += ACCELERATION;
		}
	}

	if (leftMovement && !rightMovement)
	{
		if (player.velocity.x > MIN_SPEED)
		{
			player.velocity.x -= ACCELERATION;
		}
	}

	if (rightMovement && leftMovement)
	{
		if (player.velocity.x > 0)
		{
			player.velocity.x -= ACCELERATION;
			if (player.velocity.x < 0)
			{
				player.velocity.x = 0;
			}
		}

		else if (player.velocity.x < 0)
		{
			player.velocity.x += ACCELERATION;
			if (player.velocity.x > 0)
			{
				player.velocity.x = 0;
			}
		}

	}
	//hamowanie przy ruchu w prawo jak puscimy przycisk

	if (!rightMovement && player.velocity.x != 0.0f && player.velocity.x > 0.0f)
	{
		player.velocity.x -= ACCELERATION;
		if (player.velocity.x < 0.0f)
		{
			player.velocity.x = 0.0f;
		}
	}

	// hamowanie przy lewo w prawo jak puscimy przycisk

	if (!leftMovement && player.velocity.x != 0.0f && player.velocity.x < 0.0f)
	{
		player.velocity.x += ACCELERATION;
		if (player.velocity.x > 0.0f)
		{
			player.velocity.x = 0.0f;
		}
	}

	if (jumpMovement)
	{
		player.velocity.y -= JUMP_ACCELERATION;
	}
    

	player.velocity.y += .5*G;


	rightMovement = leftMovement = jumpMovement =false;

}
