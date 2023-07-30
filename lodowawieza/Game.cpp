#include "includes.h"
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
	generateObjectes();
	generateAll(obj);
	setPositionAll(obj);
	
	while (mainWindow->isOpen())
	{
			if (animateTime.getElapsedTime().asMilliseconds() >= 17)
			{
				mainWindow->clear();
				input.inputGame(*mainPlayer);
				moveAll(obj);
				collision.checkCollision(*mainPlayer, *mainPlatforms);
				displayAll(obj, *mainWindow);
				mainWindow->display();
				mainWindow->clear();
				animateTime.restart();
			}
	}
}

void Game::screenDead()
{
}

void Game::screenHighlights()
{
}

void Game::generateObjectes()
{
	std::unique_ptr<Screen> player = std::make_unique<Player>();
	std::unique_ptr<Screen> wall = std::make_unique<Wall>();
	std::unique_ptr<Screen> column = std::make_unique<Column>();
	std::unique_ptr<Screen> platform = std::make_unique<Platform>();
	
	if (mainPlayer = dynamic_cast<Player*>(player.get()))
	{
		std::cout << "rzutowanie powiodlo sie";
	}

	if (mainPlatforms = dynamic_cast<Platform*>(platform.get()))
	{
		std::cout << "rzutowanie powiodlo sie dla platform";
	}


	obj.push_back(std::move(wall));
	obj.push_back(std::move(column));
	obj.push_back(std::move(platform));
	obj.push_back(std::move(player));
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

