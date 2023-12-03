#pragma once
#include "Player.h"
#include "Background.h"
#include "Platform.h"
#include "Wall.h"
#include "Column.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "ScoreManager.h"
#include "Clock.h"
#include "ComboStars.h"

class Game
{
public:
	Game();
	~Game();
	std::vector<std::unique_ptr<Screen>> obj;

	Player* mainPlayer;
	Platform* mainPlatforms;
	ComboStars* stars;

	ScoreManager score;
	Clock clock;

	InputManager input;
	CollisionManager collision;

protected:
	sf::Clock animateTime;
	sf::Clock clockTime;
	sf::Event event;
	sf::RenderWindow* mainWindow;

	void screenOptions();
	void screenGame();
	void screenDead();
	void screenHighlights();
	void generateObjectes();
	void displayAll();
	void generateAll();
	void moveAll();
	void setPositionAll();
	bool death();
};

