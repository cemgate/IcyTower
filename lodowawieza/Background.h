#pragma once
#include "includes.h"
#include "Screen.h"

class Background : public Screen
{
public:
	sf::RenderTexture BackgroundTextureRenderer;
	sf::Texture BackgroundTexture;
	sf::Sprite BackgroundSprite;
	sf::Vector2f pos;
	sf::Vector2f acceleration;

	void display(sf::RenderWindow& window) override;
	void move() override;
	void generateSprite() override;
	void setPosition() override;

};

