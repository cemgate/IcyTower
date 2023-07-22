#pragma once
#include "includes.h"
#include "Screen.h"

class Cloak :public Screen
{
public:
	sf::Texture CloakTexture;
	sf::Sprite CloakSprite;
	sf::Vector2f pos;
private:
	void display(sf::RenderWindow& window) override;
	void move() override;
	void generateSprite() override;

};

