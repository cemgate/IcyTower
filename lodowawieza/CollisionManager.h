#pragma once
#include "Player.h" 
#include "Platform.h"

class CollisionManager
{
public:
	void checkCollision(Player& player, Platform& platforms);
	void leftRightWallCollision(Player& player, Platform& platforms);
	void platformsCollision(Player& player, Platform& platforms);
};

