#include "includes.h"
#include "CollisionManager.h"


void CollisionManager::checkCollision(Player& player, Platform& platforms, ScoreManager& score)
{
	leftRightWallCollision(player, platforms);
	platformsCollision(player, platforms, score);
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

void CollisionManager::platformsCollision(Player& player, Platform& platforms, ScoreManager& score)
{
	// Do porownywania hitboxow roznych obiektow malowanych na scenie sluzy do tego klasa FloatReact 
	// ktora zwraca nam prostakat o wymiarach danego sprite dlatego tworzymy playerBounds ktory odpowiada za hitbox postaci
	// oraz platformBounds ktory odpowiada za hitboxy platform

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
					score.rewardScore( i+1 , platforms.platformCounter, player.grounded);
					player.velocity.y = 0;
					player.PlayerSprite.setPosition(player.position.x, PLATFORM_DEPTH + platforms.position[i].y - playerBounds.height / 2);
					player.grounded = true;
					player.jumpStrength = 0;
					player.positionUpdate();
					break;
					
				}
				else
				{
					checkChunkToPlayer(player, platforms);
					player.grounded = false;
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
	// Do porownywania hitboxow roznych obiektow malowanych na scenie sluzy do tego klasa FloatReact 
	// ktora zwraca nam prostakat o wymiarach danego sprite dlatego tworzymy playerBounds ktory odpowiada za hitbox postaci
	// oraz platformBounds ktory odpowiada za hitboxy platform

	sf::FloatRect playerBounds = player.PlayerSprite.getGlobalBounds();
	sf::FloatRect platformBounds;


	// Petla w ktorej bedziemy przeszukiwac po kazdej platformie czy nasza postac moze na niej wyladowac
	for (int i = 0; i < platforms.PlatformSprites.size() - 1; i++)
	{
		// Zainicjowanie hitboxa dla pierwszej platformy
		platformBounds = platforms.PlatformSprites[i].getGlobalBounds();
		
		// Sprawdzenie czy nasza platforma znajduje sie pod nami a nie nad nami, jesli jest nad nami to nie chcemy jej sprawdzac
		if (platformBounds.top + PLATFORM_DEPTH > playerBounds.top + playerBounds.height )
		{

			// Wywolanie funkcji checkPossibleLanding() ktora zwraca true jesli mozemy wyladowac na platformie
			// oraz false jesli nie mozemy na niej wyladowac
			if (setChunkToPlayer(playerBounds, platformBounds))
			{
				//przypisanie wskaznika na platforme na ktorej mozemy wyladowac
				player.XLevelBounce = platforms.RenderedPlatformTextures[i];
			}
			else
			{
				//jesli nie mozemy na danej platformie wyladowac to kontynuujemy przeszukiwanie
				continue;
			}
		}

		// Jesli platforma ktora sprawdzilismy znajduje sie nad nami to konczymy dzialanie tej funkcji
		// poniewaz nie potrzebujemy sprawdzac platform nad glowa postaci
		else
		{
			break;
		}
	}
}

