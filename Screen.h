#pragma once
#include "includes.h"
class Screen 
{
public:

	Screen();
	virtual void display(sf::RenderWindow& window) = 0;
	virtual void move() = 0;
	virtual void generateSprite() = 0;
	
protected:
	
};

