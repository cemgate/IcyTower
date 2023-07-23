#pragma once
#include "includes.h"


class Engine
{
	void make_first_platforms();
	void add_new_platform();
	void load_grafics();
	void play_game();
	

private:
	const float acceleration = 0.2f;
	const float gravity = 0.981f;
	sf::Vector2f velocity;
	std::vector <sf::Vector2f> platform_cords;
	std::vector <sf::Sprite> platforms; 
	sf::RenderTexture render;
	sf::Sprite character_sprite, left_background_sprite, right_background_sprite, tower_sprite, tower_left_column_sprite, tower_right_column_sprite;


};

