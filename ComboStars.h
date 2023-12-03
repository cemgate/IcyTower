#pragma once
#include "Screen.h"
#include "Star.h"

class ComboStars : public Screen
{
private:

	std::list<Star> magicStars;

public:
	
	void generateStars(const float& posX, const float& posY, int count);
	void display(sf::RenderWindow& window) override;
	void move(float timeMove, float playerMove) override;
	void generateSprite() override;
	void setPosition() override;

};

