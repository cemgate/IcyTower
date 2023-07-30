#pragma once

#include "Screen.h"

class Platform : public Screen
{
public:
	
	std::vector<sf::Texture> SidePlatformTextures;
	std::vector<sf::Sprite> SidePlatformSprites;
	std::deque<sf::RenderTexture> RenderedPlatformTextures;
	std::deque<sf::Sprite> PlatformSprites;
	std::vector<sf::Vector2f> position;
	double acceleration = 0;


	Platform()
		: SidePlatformTextures(3),
		SidePlatformSprites(3), 
		RenderedPlatformTextures(20),
		PlatformSprites(20),
		position(20) {};
	
		
	
private:
	void display(sf::RenderWindow& window) override;
	void move() override;
	void generateSprite() override;
	void setPosition() override;
	void loadSideTextures();
	void loadSideSprites();
	void generateLongPlatform();
	void generateShortPlatforms();
	void updatePosition();


};

