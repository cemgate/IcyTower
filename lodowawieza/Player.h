#pragma once
#include "Screen.h"

class Player : public Screen
{
public:
	sf::Texture PlayerTexture;
	sf::Sprite PlayerSprite;
	sf::Vector2f velocity = { 0,0 };
	sf::Vector2f acceleration;
	sf::Vector2f position;
	int playerChunkBeforeMove = -1;
	int playerChunkAfterMove = -1;

	void generateSprite() override;
	void display(sf::RenderWindow& mainWindow) override;
	void move() override;
	void setPosition() override;
	void positionUpdate();
	
};

