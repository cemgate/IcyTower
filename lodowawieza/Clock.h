#pragma once

#include "Screen.h"

class Clock :public Screen
{
public:
	sf::Texture ClockTexture;
	sf::Sprite ClockSprite;
	sf::Vector2f pos;
	float getClockTimeStep();
	void setClockTimeStep();

private:
	float clockTimeStep = 1;
	void display(sf::RenderWindow& window) override;
	void move(float timeMove, float playerMove) override;
	void generateSprite() override;
	void setPosition() override;
};

