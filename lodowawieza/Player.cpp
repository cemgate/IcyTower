#include "includes.h"
#include "Player.h"

void Player::move()
{
	PlayerSprite.move(velocity.x, velocity.y);
	positionUpdate();
}

void Player::generateSprite()
{
	PlayerTexture.loadFromFile("grafics/kwadrat.png");
	PlayerSprite.setTexture(PlayerTexture);	
	PlayerSprite.setScale(0.2, 0.2);
}

void Player::setPosition()
{
	PlayerSprite.setPosition(500, 900-PlayerSprite.getScale().y*PlayerTexture.getSize().y);
	positionUpdate();
}

void Player::display(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(PlayerSprite);
}

void Player::positionUpdate()
{
	position = PlayerSprite.getPosition();
}

