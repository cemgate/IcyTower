#pragma once
#include "includes.h"
#include "Player.h"
#include "Background.h"

class Game
{
public:
	Game();
	~Game();
protected:
	sf::RenderWindow* mainWindow;
	void screenOptions();
	void screenGame();
	void screenDead();
	void screenHighlights();
};

void displayAll(std::vector<std::unique_ptr<Screen>>& obj, sf::RenderWindow& main);
void generateAll(std::vector<std::unique_ptr<Screen>>& obj);
void moveAll(std::vector<std::unique_ptr<Screen>>& obj);
void setPositionAll(std::vector<std::unique_ptr<Screen>>& obj);