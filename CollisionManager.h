#pragma once
#include "Player.h" 
#include "Platform.h"
#include "ScoreManager.h"

const float LEFT_WALL = 350.0;
const float RIGHT_WALL = 1630.0;
const float PLATFORM_DEPTH = 13.0;



class CollisionManager
{
public:
	
	void checkCollision(Player& player, Platform& platforms, ScoreManager& score);
	void leftRightWallCollision(Player& player, Platform& platforms);
	void platformsCollision(Player& player, Platform& platforms, ScoreManager& score);
	bool setChunkToPlayer(sf::FloatRect& playerBounds, sf::FloatRect& platformBounds);
	void checkChunkToPlayer(Player& player, Platform& platforms);
};

