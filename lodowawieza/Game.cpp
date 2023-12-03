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
	bool isGameStarted = false;
	generateObjectes();
	generateAll();
	setPositionAll();
	
	while (mainWindow->isOpen())
	{
			if (animateTime.getElapsedTime().asMilliseconds() >= 16 )
			{
				if (isGameStarted)
				{
					if (clockTime.getElapsedTime().asSeconds() >= 25)
					{
						clock.setClockTimeStep();
						clockTime.restart();
					}
				}

				else if (mainPlayer->readyToStartTheGame() && !isGameStarted)
				{
					clock.setClockTimeStep();
					isGameStarted = true;
				}

				mainWindow->clear();
				input.inputGame(*mainPlayer);
				moveAll();

				collision.checkCollision(*mainPlayer, *mainPlatforms);
				
				displayAll(); 
				mainWindow->display();
				animateTime.restart();

				if (death())
				{
					break;
				}
				
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

	//obj.push_back(std::move(player));
	obj.push_back(std::move(wall));
	obj.push_back(std::move(column));
	obj.push_back(std::move(platform));
	obj.push_back(std::move(player));
	
}

void Game::displayAll()
{
	for (const auto& i : obj)
	{
		i->display(*mainWindow);
	}	
}

void Game::generateAll()
{
	for (const auto& i : obj)
	{
		i->generateSprite();
	}
}

void Game::moveAll()
{
	for (const auto& i : obj)
	{
		i->move(clock.getClockTimeStep(), mainPlayer->playerMove);
	}
}

void Game::setPositionAll()
{
	for (const auto& i : obj)
	{
		i->setPosition();
	}
}

bool Game::death()
{
	return mainPlayer->position.y > mainWindow->getSize().y+200;
}

