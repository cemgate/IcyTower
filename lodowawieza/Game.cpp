#include "Game.h"

Game::Game() 
{
	mainWindow = new sf::RenderWindow(sf::VideoMode(1920, 1080), "lodowieza");
	screenGame();
}

Game::~Game()
{
	delete mainWindow;
}

void Game::screenOptions()
{
}

void Game::screenGame()
{
	std::unique_ptr<Screen> skrin = std::make_unique<Player>();
	std::unique_ptr<Screen> skrin2 = std::make_unique<Background>();
	std::vector<std::unique_ptr<Screen>> obj;
	obj.push_back(std::move(skrin));
	obj.push_back(std::move(skrin2));
	generateAll(obj);

	while (mainWindow->isOpen())
	{
		sf::Event event;
		while (mainWindow->pollEvent(event))
		{
			mainWindow->clear();
			displayAll(obj, *mainWindow);
			mainWindow->display();
		}
	}
}

void Game::screenDead()
{
}

void Game::screenHighlights()
{
}


void displayAll(std::vector<std::unique_ptr<Screen>>& obj, sf::RenderWindow& main)
{
	
	for (const auto& i : obj)
	{
		i->display(main);
	}
	
}

void generateAll(std::vector<std::unique_ptr<Screen>>& obj)
{
	for (const auto& i : obj)
	{
		i->generateSprite();
	}
}

void moveAll(std::vector<std::unique_ptr<Screen>>& obj)
{
	for (const auto& i : obj)
	{
		i->move();
	}
}

void setPositionAll(std::vector<std::unique_ptr<Screen>>& obj)
{
	for (const auto& i : obj)
	{
		i->setPosition();
	}
}

