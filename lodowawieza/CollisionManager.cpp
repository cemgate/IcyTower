#include "includes.h"
#include "CollisionManager.h"


void CollisionManager::checkCollision(Player& player, Platform& platforms)
{
	leftRightWallCollision(player, platforms);
	platformsCollision(player, platforms);
}

void CollisionManager::leftRightWallCollision(Player& player, Platform& platforms)
{
	if (player.position.x < 350)
	{
		player.PlayerSprite.setPosition(350, player.PlayerSprite.getPosition().y);
		player.velocity.x *= -1;
	}
	if (player.position.x > 350 + 1280 - player.PlayerSprite.getScale().x * player.PlayerTexture.getSize().x)
	{
		player.PlayerSprite.setPosition(350 + 1280 - player.PlayerSprite.getScale().x * player.PlayerTexture.getSize().x, player.PlayerSprite.getPosition().y);
		player.velocity.x *= -1;
	}
}

void CollisionManager::platformsCollision(Player& player, Platform& platforms)
{
	sf::FloatRect playerBounds = player.PlayerSprite.getGlobalBounds();
	sf::FloatRect platformBounds;

	for (int i = 0; i < platforms.position.size() - 1; i++)
	{   
		std::cout << player.position.y;
		/*
		if (player.position.y + player.PlayerSprite.getScale().y * player.PlayerTexture.getSize().y > 1890);
		{
			player.PlayerSprite.setPosition(player.PlayerSprite.getPosition().x, platforms.position[0].y - player.PlayerSprite.getScale().y * player.PlayerTexture.getSize().y-100);
		}*/
		if(platforms.position[i].y> player.position.y + player.PlayerSprite.getScale().x * player.PlayerTexture.getSize().y
			&& platforms.position[i+1].y +32 < player.position.y + player.PlayerSprite.getScale().x * player.PlayerTexture.getSize().y)
		{
			player.playerChunkAfterMove = i;
			std::cout << i << std::endl;
		}

		platformBounds = platforms.PlatformSprites[i].getGlobalBounds();

		if (playerBounds.intersects(platformBounds) && player.playerChunkAfterMove==i)
		{
			player.PlayerSprite.setPosition(player.PlayerSprite.getPosition().x, platforms.position[i].y-player.PlayerSprite.getScale().y*player.PlayerTexture.getSize().y);
			player.velocity.y = 0;
			
		}


	}
}


