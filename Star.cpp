#include "includes.h"
#include "Star.h"


Star::Star(const float& posX, const float& posY)	//used for stars coming out of the player while in combo mode
{
	colorChangeIndex = 5;
	std::random_device rd;
	std::mt19937 rand(rd());
	std::uniform_int_distribution<> randPos(-10, 10);
	std::uniform_real_distribution<> randDir(-2, 2);
	std::uniform_real_distribution<> randGrav(0.8, 1.5);
	startPosX = posX + randPos(rand);
	startPosY = posY + randPos(rand); //CHECK
	startXSpeed = randDir(rand);
	startYSpeed = -2;
	xSpeed = startXSpeed;
	ySpeed = startYSpeed;
	gravity = randGrav(rand)+2;

	createStarShape();
}

void Star::createStarShape()
{
	candy.setPointCount(10);
	candy.setPoint(0, sf::Vector2f(10, 0));   //
	candy.setPoint(1, sf::Vector2f(12, 6));
	candy.setPoint(2, sf::Vector2f(20, 6));
	candy.setPoint(3, sf::Vector2f(16, 12));
	candy.setPoint(4, sf::Vector2f(18, 18));
	candy.setPoint(5, sf::Vector2f(10, 16));
	candy.setPoint(6, sf::Vector2f(2, 18));
	candy.setPoint(7, sf::Vector2f(4, 12)); 	 //
	candy.setPoint(8, sf::Vector2f(0, 6));	 //
	candy.setPoint(9, sf::Vector2f(8, 6));	 //

	candy.setOrigin(5, 4);
	candy.setPosition(startPosX, startPosY);
}

sf::ConvexShape& Star::getDrawable()
{
	return candy;
}

void Star::changeColor()
{
	static sf::Color col[6]{ sf::Color::Blue, sf::Color::Cyan , sf::Color::Green, sf::Color::Magenta, sf::Color::Red, sf::Color::Yellow };

	static std::random_device rd;
	static std::mt19937 mt(rd());
	static std::uniform_int_distribution<> randCol(0, 5);

	if (colorChangeIndex < 4)
		colorChangeIndex++;
	else
	{
		candy.setFillColor(col[randCol(mt)]);
		colorChangeIndex = 0;
	}
}

int Star::getPosY()
{
	return candy.getPosition().y;
}

void Star::logic(float timeMove,float playerMove)
{
	changeColor();
	candy.move(xSpeed, ySpeed+timeMove+playerMove);
	candy.rotate(2);

	if (ySpeed < 8)
	{
		ySpeed += gravity;
	}

	if (xSpeed < -0.5)
		//these make sure that the star loses direction and strives for straight down falling
	{
		xSpeed += 0.02;
	}
	else if (xSpeed > 0.5)
	{
		xSpeed -= 0.02;
	}
}

