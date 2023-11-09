#pragma once
#include "Screen.h"

const float SCROLL_LIMIT = 300.0;

class Player : public Screen
{
public:
	sf::Texture PlayerTexture;
	sf::Sprite PlayerSprite;
	sf::Vector2f velocity = { 0,0 };
	sf::Vector2f acceleration;
	sf::Vector2f position;

	sf::RenderTexture* YLevelBounce = nullptr;
	sf::RenderTexture* XLevelBounce = nullptr;

	float playerMove = 0;
	bool grounded = false;

	void generateSprite() override;
	void display(sf::RenderWindow& mainWindow) override;
	void move(float timeMove, float playerMove) override;
	void setPosition() override;
	void positionUpdate();
	
};

