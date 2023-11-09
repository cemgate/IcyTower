#pragma once
#include "Player.h" 
#include "Platform.h"

const float LEFT_WALL = 350.0;
const float RIGHT_WALL = 1630.0;
const float PLATFORM_DEPTH = 13.0;



class CollisionManager
{
public:
	
	void checkCollision(Player& player, Platform& platforms);
	void leftRightWallCollision(Player& player, Platform& platforms);
	void platformsCollision(Player& player, Platform& platforms);
	bool setChunkToPlayer(sf::FloatRect& playerBounds, sf::FloatRect& platformBounds);
	void checkChunkToPlayer(Player& player, Platform& platforms);
};

