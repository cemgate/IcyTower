#include "includes.h"
#include "Screen.h"
#include "Player.h"
#include "Background.h"


//int main()
//{
//	srand(time(nullptr));
//
//	sf::Texture square, background, cegla, column,tmp,tmpl,tmpr;
//	sf::Sprite square_real, background_real, sbackground_real, cegla_real, big, scolumn_left, scolumn_right, tmp_real, platforma,tmp_real_left,tmp_real_right, platforma1;
//	sf::RenderWindow okno(sf::VideoMode(1920, 1080), "lodowieza");
//	float acceleration = 0.2f;
//	float gravity = 0.981f;
//	float actual_height = 0.0f;
//	int move = 0;
//	float scal = 2.0f;
//	sf::Vector2f velocity;
//	
//	sf::Vector2f floor = { (100 / scal),(1800 / scal)};
//	sf::Vector2f floor2 = { (1000 / scal),(1400 / scal)};
//	sf::Vector2f floor3 = { (700 / scal), (900 / scal)};
//	sf::Vector2f floor4 = { (1200 / scal), (400 / scal)};
//	std::vector<float> dlugosci = { (1800 / scal) ,(400 / scal) , (400 / scal),(600 / scal) };
//
//
//	int counterjump = 0;
//	int tmpjump = 0;
//	int whichplatform = 0;
//	int whichplatform1 = 0;
//	std::vector <sf::Vector2f> platform_cords = { floor, floor2, floor3, floor4 };
//	bool right, left, down, up, jump, fall;
//	right = left = up = down = jump = fall = false;
//
//	column.loadFromFile("grafics/sciana.png");
//	cegla.loadFromFile("grafics/cegla.png");
//	cegla_real.setTexture(cegla);
//	const int numColumns = 20;
//	const int numRows = 20;
//	
//
//	
//	
//
//
//	sf::RenderTexture render_texture;
//	render_texture.create(numColumns * cegla_real.getTexture()->getSize().x, numRows * cegla_real.getTexture()->getSize().y);
//	for (int i = 0; i < numColumns; ++i) {
//		for (int j = 0; j < numRows; ++j) {
//			cegla_real.setPosition(i * cegla_real.getTexture()->getSize().x, j * cegla_real.getTexture()->getSize().y);
//			render_texture.clear();
//			render_texture.draw(cegla_real);
//		}
//	}
//	render_texture.display();
//
//	big.setTexture(render_texture.getTexture());
//	big.setPosition(0, 0);
//	
//
//	const int num = 20;
//	tmpl.loadFromFile("grafics/platforma_lewa_fiolet.png");
//	tmp_real_left.setTexture(tmpl);
//
//	tmpr.loadFromFile("grafics/platforma_prawa_fiolet.png");
//	tmp_real_right.setTexture(tmpr);
//
//	tmp.loadFromFile("grafics/platforma_srodek_fioletowa.png");
//	tmp_real.setTexture(tmp);
//
//	int random_number = rand() % 19 + 2;;
//
//	sf::RenderTexture render_texture1;
//    render_texture.create(random_number * tmp_real.getTexture()->getSize().x, tmp_real.getTexture()->getSize().y);
//	
//	for (int i = 0; i < random_number; i++) 
//	{	
//		if (i == 0)
//		{
//			tmp_real_left.setPosition(i * tmp_real_left.getTexture()->getSize().x, 0);
//			render_texture.draw(tmp_real_left);
//		}
//		if (i == random_number - 1)
//		{
//			std::cout << "coi jet s" << std::endl;
//			tmp_real_right.setPosition(i * tmp_real_right.getTexture()->getSize().x, 0);
//			render_texture.draw(tmp_real_right);
//		}
//		if(i!=0 && i!=random_number-1)
//		{
//			
//			tmp_real.setPosition(i * tmp_real.getTexture()->getSize().x, 0);
//			render_texture.draw(tmp_real);
//		}
//	}
//	render_texture.display();
//	platforma.setTexture(render_texture.getTexture());
//	
//	
//	
//
//
//
//	platforma.setPosition(320, 900);
//	//platforma1.setPosition(620, 300);
//
//	scolumn_left.setTexture(column);
//	scolumn_right.setTexture(column);
//	square.loadFromFile("grafics/kwadrat.png");
//	background.loadFromFile("grafics/pink.png");
//	background_real.setTexture(background);
//	sbackground_real.setTexture(background);
//	square_real.setTexture(square);
//	square_real.setScale(0.25, 0.25);
//	background_real.setScale(1 / scal, 1 / scal);
//	sbackground_real.setScale(1 / scal, 1 / scal);
//	sbackground_real.setPosition(0, -1000);
//	scolumn_left.setPosition(320-32, 0);
//	scolumn_right.setPosition(1920 - 320, 0);
//	
//	sf::Clock animatetime;
//	square_real.setPosition(320, 600);
//	cegla_real.setPosition(0, 0);
//	while (okno.isOpen())
//	{
//		move = 0;
//	
//		if (animatetime.getElapsedTime().asMilliseconds() >= 17)
//		{
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//			{
//				up = true;
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//			{
//				velocity.x += acceleration;
//				right = true;
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//			{
//				down = true;
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//			{
//				left = true;
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && jump != true && fall != true)
//			{
//				tmpjump++;
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//			{
//				exit(0);
//			}
//
//			sf::Event event;
//			while (okno.pollEvent(event))
//			{
//				switch (event.type)
//				{
//				case sf::Event::KeyReleased:
//					if (event.key.code == sf::Keyboard::D)
//					{
//						
//						right = false;
//
//					}
//					else if (event.key.code == sf::Keyboard::A)
//					{
//
//						left = false;
//					}
//					else if (event.key.code == sf::Keyboard::S)
//					{
//
//						down = false;
//					}
//					else if (event.key.code == sf::Keyboard::W)
//					{
//
//						up = false;
//					}
//					else if (event.key.code == sf::Keyboard::Space)
//					{
//						tmpjump = 0;
//					}
//
//
//
//					break;
//
//
//				case sf::Event::KeyPressed:
//					if (event.key.code == sf::Keyboard::Space && tmpjump == 1 && !jump)
//					{
//						velocity.y = -25;
//						jump = true;
//						tmpjump = 0;
//
//					}
//
//				}
//
//
//			}
//
//			okno.clear();
//			//poruszanie w prawo
//
//			if (right)
//			{
//				if (velocity.x < 10.0f)
//				{
//
//					//velocity.x += acceleration;
//				}
//
//			}
//
//			//poruszanie w lewo
//
//			if (left)
//			{
//
//				if (velocity.x > -10.f)
//				{
//
//					velocity.x -= acceleration;
//				}
//
//
//			}
//
//			//poruszanie w gore
//
//			/*
//
//			if (up)
//			{
//				if (velocity.y > -10.f)
//				{
//					velocity.y -= acceleration;
//				}
//
//			}
//			*/
//
//			//poruszanie w dol
//
//
//			/*
//			if (down)
//			{
//				if (velocity.y < 10.f)
//				{
//					velocity.y += acceleration;
//				}
//			}
//
//			*/
//
//			//hamowanie dla dwoch wcisnietych przyciskow
//
//			if (right && left)
//			{
//
//				if (velocity.x > 0)
//				{
//					velocity.x -= acceleration;
//					if (velocity.x < 0)
//					{
//						velocity.x = 0;
//					}
//				}
//				if (velocity.x < 0)
//				{
//					velocity.x += acceleration;
//					if (velocity.x > 0)
//					{
//						velocity.x = 0;
//					}
//				}
//				if (velocity.x == 0)
//				{
//					velocity.x = 0;
//				}
//			}
//
//			//hamowanie dla dwoch wcisnietych przyciskow
//
//
//			/*
//			if (up && down)
//			{
//				if (velocity.y > 0)
//				{
//					velocity.y -= acceleration;
//					if (velocity.y < 0)
//					{
//						velocity.y = 0;
//					}
//				}
//				if (velocity.y < 0)
//				{
//					velocity.y += acceleration;
//					if (velocity.y > 0)
//					{
//						velocity.y = 0;
//					}
//				}
//				if (velocity.y == 0)
//				{
//					velocity.y = 0;
//				}
//			}
//			*/
//
//			// hamowanie przy ruchu w prawo jak puscimy przycisk
//
//			if (!right && velocity.x != 0.0f && velocity.x > 0.0f)
//			{
//
//				velocity.x -= acceleration;
//				if (velocity.x < 0.0f)
//				{
//					velocity.x = 0.0f;
//				}
//
//
//			}
//
//			// hamowanie przy lewo w prawo jak puscimy przycisk
//
//			if (!left && velocity.x != 0.0f && velocity.x < 0.0f)
//			{
//
//				velocity.x += acceleration;
//				if (velocity.x > 0.0f)
//				{
//					velocity.x = 0.0f;
//				}
//
//
//			}
//
//			// hamowanie przy ruchu w dol jak puscimy przycisk
//			/*
//			if (!down && velocity.y != 0.0f && velocity.y > 0.0f)
//			{
//				velocity.y -= acceleration;
//				if (velocity.y < 0.0f)
//				{
//					velocity.y = 0.0f;
//				}
//
//
//			}
//			*/
//
//
//			// hamowanie przy ruchu w gore jak puscimy przycisk
//
//			/*
//			if (!up && velocity.y != 0.0f && velocity.y < 0.0f)
//			{
//				velocity.y += acceleration;
//				if (velocity.y > 0.0f)
//				{
//					velocity.y = 0.0f;
//				}
//
//
//			}
//			*/
//
//			//sprawdzanie w ktorym chunku sie znajdujemy
//			for (int i = 0; i < platform_cords.size(); i++)
//			{
//				if (square_real.getPosition().y <= platform_cords[i].y - square.getSize().y * square_real.getScale().y )
//				{
//					whichplatform++;
//				}
//			}
//
//			//sprawdzanie czy znajdujemy sie na platformie, jesli nie to zaczynamy spadac
//			if (square_real.getPosition().y < platform_cords[static_cast<std::vector<sf::Vector2f, std::allocator<sf::Vector2f>>::size_type>(whichplatform) - 1].y - square.getSize().y * square_real.getScale().y || square_real.getPosition().x < platform_cords[static_cast<std::vector<sf::Vector2f, std::allocator<sf::Vector2f>>::size_type>(whichplatform) - 1].x - square.getSize().x * square_real.getScale().x || square_real.getPosition().x>dlugosci[whichplatform - 1] + platform_cords[whichplatform - 1].x)
//			{
//				fall = true;
//			}
//
//
//
//
//			if ((jump && tmpjump==1)||fall)
//			{
//				velocity.y += gravity;
//			}
//
//			square_real.move(velocity.x, velocity.y);
//
//			//sprawdzanie czy po przesunieciu zmienilismy chunk
//			for (int i = 0; i < platform_cords.size(); i++)
//			{
//				if (square_real.getPosition().y <= platform_cords[i].y - square.getSize().y * square_real.getScale().y )
//				{
//					whichplatform1++;
//				}
//			}
//
//			//odbijanie od scian
//			if (square_real.getPosition().x > (1900 / scal) - square.getSize().x * square_real.getScale().x || square_real.getPosition().x < (100 / scal))
//			{
//				velocity.x = -velocity.x;
//				if (square_real.getPosition().x > (1900 / scal) - square.getSize().x * square_real.getScale().x)
//				{
//					square_real.setPosition((1900 / scal) - square.getSize().x * square_real.getScale().x, square_real.getPosition().y);
//				}
//				if (square_real.getPosition().x < (100 / scal))
//				{
//					square_real.setPosition((100 / scal), square_real.getPosition().y);
//				}
//			}
//
//			// ustawienie naszej postaci na wysokosci przeszkody zebysmy przez nia nie przelecieli lub nie spadli pod ziemie
//			if (whichplatform - whichplatform1 == 1 && square_real.getPosition().x >= platform_cords[whichplatform1].x - square.getSize().x * square_real.getScale().x && square_real.getPosition().x <= dlugosci[whichplatform1] + platform_cords[whichplatform1].x)
//			{
//
//				square_real.setPosition(square_real.getPosition().x, platform_cords[whichplatform1].y - square.getSize().y * square_real.getScale().y );
//				velocity.y = 0;
//				jump = false;
//				fall = false;
//			}
//
//			if (square_real.getPosition().y < (100 / scal))
//			{
//				move = 10;
//				background_real.move(0, move);
//				sbackground_real.move(0, move);
//			}
//
//			if (background_real.getPosition().y > 1000)
//			{
//				background_real.setPosition(0, -background_real.getPosition().y);
//			}
//
//			if (sbackground_real.getPosition().y > 1000)
//			{
//				sbackground_real.setPosition(0, -sbackground_real.getPosition().y);
//			}
//
//			if (platform_cords[0].y > 1000)
//			{
//				std::cout << platform_cords[0].y << " " <<  platform_cords[1].y<< " " << platform_cords.size() << std::endl;
//				platform_cords.push_back(platform_cords[0]);
//				
//				platform_cords.erase(platform_cords.begin());
//				dlugosci.push_back(dlugosci[0]);
//				dlugosci.erase(dlugosci.begin());
//
//			}
//			
//			okno.draw(background_real);
//			okno.draw(sbackground_real);
//			okno.draw(big);
//			okno.draw(scolumn_left);
//			okno.draw(scolumn_right);
//			okno.draw(platforma);
//			okno.draw(square_real);
//			
//			
//			okno.display();
//			animatetime.restart();
//			whichplatform = 0;
//			whichplatform1 = 0;
//
//			floor = { (100 / scal), floor.y + move };
//			floor2 = { (1000 / scal),floor2.y + move };
//			floor3 = { (700 / scal), floor3.y + move };
//			floor4 = { (1200 / scal), floor4.y + move };
//			
//		}
//	}
//	return 0;
//}

int main()
{
	Player skrin;
	skrin.generateSprite();
	Screen* back = new Background;
	back->generateSprite();
	
	
	auto* mainWindow = back->getWind();
	sf::RenderWindow mainnn(sf::VideoMode(1920, 1080), "lodowieza");
	
	while (mainnn.isOpen())
	{
		sf::Event event;
		while (mainnn.pollEvent(event))
		{
			mainnn.clear();
			skrin.display2(mainnn);
			mainnn.display();
		}
	}
}

