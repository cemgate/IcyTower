#include "Player.h"




void Player::move()
{

}

void Player::generateSprite()
{
	PlayerTexture.loadFromFile("grafics/kwadrat.png");
	PlayerSprite.setTexture(PlayerTexture);
}

void Player::setPosition()
{
	PlayerSprite.setPosition(pos.x, pos.y);
}

void Player::display(sf::RenderWindow& window)
{
	window.draw(PlayerSprite);
}


