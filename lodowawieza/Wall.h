#pragma once
#include "includes.h"
#include "Screen.h"

class Wall :public Screen
{
public:
	sf::Texture WallTexture;
	sf::Sprite WallSprite;
	sf::Vector2f pos;

private:
	void display(sf::RenderWindow& window) override;
	void move() override;
	void generateSprite() override;
	void setPosition() override;
};

