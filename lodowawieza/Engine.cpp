#include "includes.h"
#include "Engine.h"

void Engine::load_grafics()
{

	//                     Wgranie tekstur 

	sf::Texture column, background_left, background_right, character,cegla;
	sf::Sprite cegla_tmp;
	column.loadFromFile("grafics/sciana.png");
	character.loadFromFile("grafics/kwadrat.png");
	cegla.loadFromFile("grafics/cegla.png");
	//background_left.loadFromFile();
	//background_right.loadFromFile();


	//                    Przypisanie tekstur do spritow

	tower_left_column_sprite.setTexture(column);
	tower_right_column_sprite.setTexture(column);
	character_sprite.setTexture(character);
	cegla_tmp.setTexture(cegla);
	//left_background_sprite.setTexture(background_left);
	//right_background_sprite.setTexture(background_right);

	const int numRows = 100;
	const int numColumns = numRows;
	
	
    //                   Wyrenderowanie wiezy 

	sf::RenderTexture render_texture;
	render_texture.create(numColumns * cegla_tmp.getTexture()->getSize().x, numRows * cegla_tmp.getTexture()->getSize().y);
	for (int i = 0; i < numColumns; ++i) {
		for (int j = 0; j < numRows; ++j) {
			cegla_tmp.setPosition(i * cegla_tmp.getTexture()->getSize().x, j * cegla_tmp.getTexture()->getSize().y);
			render_texture.draw(cegla_tmp);
		}
	}
	tower_sprite.setTexture(render_texture.getTexture());

	//                   Ustawienie kordynatow

	tower_left_column_sprite.setPosition(320 - column.getSize().x,0);
	tower_right_column_sprite.setPosition(1920 - 320, 0);
	tower_sprite.setPosition(320, -1.0f * static_cast<float>(render_texture.getSize().y) + 1080);


}


void Engine::make_first_platforms()
{

	sf::Texture left_part_platform, middle_part_platform, right_part_platform;
	sf::Sprite tmp_left, tmp_middle, tmp_right, tmp_platform;
	left_part_platform.loadFromFile("grafics/platforma_lewa_fioletowa.png");
	middle_part_platform.loadFromFile("grafics/platforma_srodek_fioletowa.png");
	right_part_platform.loadFromFile("grafics/platforma_prawa_fioletowa.png");

	tmp_left.setTexture(left_part_platform);
	tmp_middle.setTexture(middle_part_platform);
	tmp_right.setTexture(right_part_platform);

	const int num = 20;

	render.create(num * tmp_middle.getTexture()->getSize().x, tmp_middle.getTexture()->getSize().y);
	for (int i = 0; i < num; ++i) 
	{
		tmp_middle.setPosition(i * tmp_middle.getTexture()->getSize().x, 0);
		render.draw(tmp_middle);
	}
	
	tmp_platform.setTexture(render.getTexture());
	
	platforms.push_back(tmp_platform);

	srand(time(nullptr));

	for (int k = 0; k < 7; k++)
	{
		int random_number = rand() % 19 + 2;

		for (int i = 0; i < random_number; ++i)
		{
			if (i == 0)
			{
				tmp_left.setPosition(i * tmp_left.getTexture()->getSize().x, 0);
				render.draw(tmp_left);
			}
			if (i == random_number - 1)
			{
				tmp_right.setPosition(i * tmp_right.getTexture()->getSize().x,0);
				render.draw(tmp_right);
			}
			if(i!=0 && i!= random_number-1)
			{
				tmp_middle.setPosition(i * tmp_middle.getTexture()->getSize().x, 0);
				render.draw(tmp_middle);
			}
		}

		tmp_platform.setTexture(render.getTexture());
		platforms.push_back(tmp_platform);
	}
}


void Engine::add_new_platform()
{
	platforms.erase(platforms.begin());


}


void Engine::play_game()
{

}

