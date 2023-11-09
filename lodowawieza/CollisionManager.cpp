#include "includes.h"
#include "CollisionManager.h"


void CollisionManager::checkCollision(Player& player, Platform& platforms)
{
	leftRightWallCollision(player, platforms);
	platformsCollision(player, platforms);
}

void CollisionManager::leftRightWallCollision(Player& player, Platform& platforms)
{
	if (player.position.x < LEFT_WALL + player.PlayerSprite.getGlobalBounds().width / 2)
	{
		player.PlayerSprite.setPosition(LEFT_WALL + player.PlayerSprite.getGlobalBounds().width / 2, player.PlayerSprite.getPosition().y);
		player.velocity.x *= -1;
	}
	if (player.position.x > RIGHT_WALL - player.PlayerSprite.getGlobalBounds().width / 2)
	{
		player.PlayerSprite.setPosition(RIGHT_WALL - player.PlayerSprite.getGlobalBounds().width / 2, player.PlayerSprite.getPosition().y);
		player.velocity.x *= -1;
	}
}

void CollisionManager::platformsCollision(Player& player, Platform& platforms)
{
	sf::FloatRect playerBounds = player.PlayerSprite.getGlobalBounds();
	sf::FloatRect platformBounds;
	
	
	if (player.velocity.y < 0)
	{
		checkChunkToPlayer(player, platforms);
	}

	
	if(player.velocity.y>=0)
	{
		for (int i = 0; i < platforms.RenderedPlatformTextures.size() - 1; i++)
		{
			if (player.XLevelBounce == platforms.RenderedPlatformTextures[i])
			{
				platformBounds = platforms.PlatformSprites[i].getGlobalBounds();

				if (playerBounds.intersects(platformBounds))
				{
					player.velocity.y = 0;
					player.PlayerSprite.setPosition(player.position.x, PLATFORM_DEPTH + platforms.position[i].y - playerBounds.height / 2);
					player.grounded = true;
					player.positionUpdate();
					
					if (!setChunkToPlayer(playerBounds, platformBounds))
					{
						player.grounded = false;
					}
				}
				else
				{
					checkChunkToPlayer(player, platforms);
					break;
				}
			}
			if (player.XLevelBounce == nullptr)
			{
				player.XLevelBounce = platforms.RenderedPlatformTextures[0];
				break;
			}
		}
	}
}

bool CollisionManager::setChunkToPlayer(sf::FloatRect& playerBounds, sf::FloatRect& platformBounds)
{
	if (platformBounds.top + PLATFORM_DEPTH > playerBounds.top + playerBounds.height &&
		platformBounds.left <= playerBounds.left + playerBounds.width &&
		platformBounds.left + platformBounds.width >= playerBounds.left)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CollisionManager::checkChunkToPlayer(Player& player, Platform& platforms)
{
	sf::FloatRect playerBounds = player.PlayerSprite.getGlobalBounds();
	sf::FloatRect platformBounds;

	for (int i = 0; i < platforms.PlatformSprites.size() - 1; i++)
	{
		platformBounds = platforms.PlatformSprites[i].getGlobalBounds();
		
		if (platformBounds.top + PLATFORM_DEPTH > playerBounds.top + playerBounds.height )
		{
			if (setChunkToPlayer(playerBounds, platformBounds))
			{
				player.XLevelBounce = platforms.RenderedPlatformTextures[i];
			}
			else
			{
				continue;
			}
		}
		else
		{
			break;
		}
	}
}

