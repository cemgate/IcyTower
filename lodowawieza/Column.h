#pragma once
#include "Screen.h"

class Column : public Screen
{
public:
	sf::RenderTexture ColumnTextureRenderer;
	sf::Sprite ColumnSpriteRenderer;
	sf::Texture ColumnTexture;
	sf::Sprite ColumnSprite;
	sf::Vector2f pos;
	sf::Vector2f acceleration;

	void display(sf::RenderWindow& window) override;
	void move() override;
	void generateSprite() override;
	void setPosition() override;
	void loadColumnTexture();
	void loadColumnSprite();
	void generateColumn();

};
