#pragma once
class Star
{
private:
	int colorChangeIndex;
	float gravity;
	int startPosX;
	int startPosY;
	float startXSpeed;
	float startYSpeed;
	float xSpeed;
	float ySpeed;
	sf::ConvexShape candy;

	void changeColor();
	void createStarShape();
public:
	Star(const float& posX, const float& posY);
	sf::ConvexShape& getDrawable();
	int getPosY();
	void logic(float timeMove,float playerMove);
};

