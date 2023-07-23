#pragma once
#include "includes.h"
#include "CollisionManager.h"
#include "InputManager.h"
#include "Screen.h"

class Player : public Screen
{
public:
	sf::Texture PlayerTexture;
	sf::Sprite PlayerSprite;
	sf::Vector2f pos;
	sf::Vector2f acceleration;

	void generateSprite() override;
	void display(sf::RenderWindow& mainWindow) override;
	void move() override;
	void setPosition() override;
	
};

