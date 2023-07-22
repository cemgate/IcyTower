#pragma once
#include "includes.h"
#include "Screen.h"

class Platform : public Screen
{
public:
	sf::RenderTexture PlatformTextureRenderer;
	sf::Texture PlatformTexture;
	sf::Sprite PlatformSprite;
	sf::Vector2f pos;
	sf::Vector2f acceleration;

private:
	void display(sf::RenderWindow& window) override;
	void move() override;
	void generateSprite() override;
};

