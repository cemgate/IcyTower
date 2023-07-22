#pragma once
#include "includes.h"
#include "Player.h"

class Game
{
private:
	std::unique_ptr<sf::RenderWindow> mainWindow;
	Game();
	void screenone();
	void screentwo();
};

