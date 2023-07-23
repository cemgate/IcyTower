#include "Player.h"




void Player::move()
{

}

void Player::generateSprite()
{
	PlayerTexture.loadFromFile("grafics/kwadrat.png");
	PlayerSprite.setTexture(PlayerTexture);
	std::cout << "wykonuje sie";
}

void Player::setPosition()
{
	PlayerSprite.setPosition(pos.x, pos.y);
}

void Player::display(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(PlayerSprite);
}


