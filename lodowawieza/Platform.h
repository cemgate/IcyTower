#pragma once

#include "Screen.h"

class Platform : public Screen
{
public:
	
	std::vector<sf::Texture> SidePlatformTextures;
	std::vector<sf::Sprite> SidePlatformSprites;
	std::deque<sf::RenderTexture*> RenderedPlatformTextures;
	std::deque<sf::Sprite> PlatformSprites;
	std::deque<sf::Vector2f> position;
	double acceleration = 0;
	void erasePlatform();

	Platform()
		: SidePlatformTextures(3),
		SidePlatformSprites(3), 
		RenderedPlatformTextures(20),
		PlatformSprites(20),
		position(20) {};
	
private:

	void display(sf::RenderWindow& window) override;
	void move(float timeMove, float playerMove) override;
	void generateSprite() override;
	void setPosition() override;
	void loadSideTextures();
	void loadSideSprites();
	void generateLongPlatform();
	void generateShortPlatforms(int howManyPlatforms);
	void generateNewPlatform();
	void setNewPlatformPosition();
	void updatePosition();
};

