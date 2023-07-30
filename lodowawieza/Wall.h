#pragma once

#include "Screen.h"

class Wall :public Screen
{
public:
	sf::Sprite BrickSprite;
	sf::Texture BrickTexture;
	sf::RenderTexture WallTexture;
	sf::Sprite WallSprite;
	sf::Vector2f pos;

private:
	void display(sf::RenderWindow& window) override;
	void move() override;
	void generateSprite() override;
	void setPosition() override;
};

