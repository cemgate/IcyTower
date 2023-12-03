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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.grounded==true)
	{
		jumpMovement = true;
		player.grounded = false;	
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		player.PlayerSprite.rotate(20);
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
		player.velocity.x += 1.2 * ACCELERATION;
		if (player.velocity.x > 0.0f)
		{
			player.velocity.x = 0.0f;
		}
	}

	if (jumpMovement)
	{
		if (std::abs(player.velocity.x)>14.0f)
		{
			player.jumpStrength = 3;
			player.velocity.y = -1.0f * (std::abs(player.velocity.x)) - JUMP_ACCELERATION;
		}

		else if (std::abs(player.velocity.x)>9.0f)
		{
			player.jumpStrength = 2;
			player.velocity.y = -0.5f * (std::abs(player.velocity.x)) - JUMP_ACCELERATION;
		}

		else
		{
			player.jumpStrength = 1;
			player.velocity.y -= JUMP_ACCELERATION;
		}
	}
    
	if (!player.grounded)
	{
		player.velocity.y += .5 * G;
	}


	rightMovement = leftMovement = jumpMovement = false;

}
