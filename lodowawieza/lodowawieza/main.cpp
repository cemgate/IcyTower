#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>

int main()
{
	sf::Texture square, background;
	sf::Sprite square_real, background_real;
	sf::RenderWindow okno(sf::VideoMode(2000, 2000), "Kurs SFML 2.0 - http://cpp0x.pl");
	float acceleration = 0.2f;
	float gravity = 0.981f;
	float actual_height = 0.0f;
	int move = 0;
	sf::Vector2f velocity;
	sf::Vector2f floor = { 100,1800 };
	sf::Vector2f floor2 = { 1000,1400 };
	sf::Vector2f floor3 = { 700, 900 };
	sf::Vector2f floor4 = { 1200, 400 };
	std::vector<int> dlugosci = { 1800 , 400 , 400,600 };
	int counterjump = 0;
	int tmpjump = 0;
	int whichplatform = 0;
	int whichplatform1 = 0;
	std::vector <sf::Vector2f> platform_cords = { floor, floor2, floor3, floor4 };
	bool right, left, down, up, jump, fall;
	right = left = up = down = jump = fall = false;
	square.loadFromFile("kwadrat.png");
	background.loadFromFile("background.png");
	background_real.setTexture(background);
	square_real.setTexture(square);
	sf::Clock animatetime;
	square_real.setPosition(200, 1100);
	while (okno.isOpen())
	{
		if (animatetime.getElapsedTime().asMilliseconds() >= 17)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				up = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				right = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{

				down = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				left = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && jump != true && fall != true)
			{

				tmpjump++;

			}

			sf::Event event;
			while (okno.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::D)
					{

						right = false;

					}
					else if (event.key.code == sf::Keyboard::A)
					{

						left = false;
					}
					else if (event.key.code == sf::Keyboard::S)
					{

						down = false;
					}
					else if (event.key.code == sf::Keyboard::W)
					{

						up = false;
					}
					else if (event.key.code == sf::Keyboard::Space)
					{
						tmpjump = 0;
					}



					break;


				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Space && tmpjump == 1)
					{
						velocity.y = -40;
						jump = true;

					}

				}


			}

			okno.clear();
			//poruszanie w prawo

			if (right)
			{
				if (velocity.x < 10.0f)
				{

					velocity.x += acceleration;
				}

			}

			//poruszanie w lewo

			if (left)
			{

				if (velocity.x > -10.f)
				{

					velocity.x -= acceleration;
				}


			}

			//poruszanie w gore

			/*

			if (up)
			{
				if (velocity.y > -10.f)
				{
					velocity.y -= acceleration;
				}

			}
			*/

			//poruszanie w dol


			/*
			if (down)
			{
				if (velocity.y < 10.f)
				{
					velocity.y += acceleration;
				}
			}

			*/

			//hamowanie dla dwoch wcisnietych przyciskow

			if (right && left)
			{

				if (velocity.x > 0)
				{
					velocity.x -= acceleration;
					if (velocity.x < 0)
					{
						velocity.x = 0;
					}
				}
				if (velocity.x < 0)
				{
					velocity.x += acceleration;
					if (velocity.x > 0)
					{
						velocity.x = 0;
					}
				}
				if (velocity.x == 0)
				{
					velocity.x = 0;
				}
			}

			//hamowanie dla dwoch wcisnietych przyciskow


			/*
			if (up && down)
			{
				if (velocity.y > 0)
				{
					velocity.y -= acceleration;
					if (velocity.y < 0)
					{
						velocity.y = 0;
					}
				}
				if (velocity.y < 0)
				{
					velocity.y += acceleration;
					if (velocity.y > 0)
					{
						velocity.y = 0;
					}
				}
				if (velocity.y == 0)
				{
					velocity.y = 0;
				}
			}
			*/

			// hamowanie przy ruchu w prawo jak puscimy przycisk

			if (!right && velocity.x != 0.0f && velocity.x > 0.0f)
			{

				velocity.x -= acceleration;
				if (velocity.x < 0.0f)
				{
					velocity.x = 0.0f;
				}


			}

			// hamowanie przy lewo w prawo jak puscimy przycisk

			if (!left && velocity.x != 0.0f && velocity.x < 0.0f)
			{

				velocity.x += acceleration;
				if (velocity.x > 0.0f)
				{
					velocity.x = 0.0f;
				}


			}

			// hamowanie przy ruchu w dol jak puscimy przycisk
			/*
			if (!down && velocity.y != 0.0f && velocity.y > 0.0f)
			{
				velocity.y -= acceleration;
				if (velocity.y < 0.0f)
				{
					velocity.y = 0.0f;
				}


			}
			*/


			// hamowanie przy ruchu w gore jak puscimy przycisk

			/*
			if (!up && velocity.y != 0.0f && velocity.y < 0.0f)
			{
				velocity.y += acceleration;
				if (velocity.y > 0.0f)
				{
					velocity.y = 0.0f;
				}


			}
			*/

			//sprawdzanie w ktorym chunku sie znajdujemy
			for (int i = 0; i < platform_cords.size(); i++)
			{
				if (square_real.getPosition().y <= platform_cords[i].y - square.getSize().y + move)
				{
					whichplatform++;
				}
			}

			//sprawdzanie czy znajdujemy sie na platformie, jesli nie to zaczynamy spadac
			if (square_real.getPosition().y < platform_cords[static_cast<std::vector<sf::Vector2f, std::allocator<sf::Vector2f>>::size_type>(whichplatform) - 1].y - square.getSize().y + move || square_real.getPosition().x < platform_cords[whichplatform - 1].x - square.getSize().x || square_real.getPosition().x>dlugosci[whichplatform - 1] + platform_cords[whichplatform - 1].x)
			{
				fall = true;
			}




			if (jump || fall)
			{
				velocity.y += gravity;
			}

			square_real.move(velocity.x, velocity.y);

			//sprawdzanie czy po przesunieciu zmienilismy chunk
			for (int i = 0; i < platform_cords.size(); i++)
			{
				if (square_real.getPosition().y <= platform_cords[i].y - square.getSize().y + move)
				{
					whichplatform1++;
				}
			}

			//odbijanie od scian
			if (square_real.getPosition().x > 1900 - square.getSize().x || square_real.getPosition().x < 100)
			{
				velocity.x = -velocity.x;
				if (square_real.getPosition().x > 1900 - square.getSize().x)
				{
					square_real.setPosition(1900 - square.getSize().x, square_real.getPosition().y);
				}
				if (square_real.getPosition().x < 100)
				{
					square_real.setPosition(100, square_real.getPosition().y);
				}
			}

			// ustawienie naszej postaci na wysokosci przeszkody zebysmy przez nia nie przelecieli lub nie spadli pod ziemie
			if (whichplatform - whichplatform1 == 1 && square_real.getPosition().x >= platform_cords[whichplatform1].x - square.getSize().x && square_real.getPosition().x <= dlugosci[whichplatform1] + platform_cords[whichplatform1].x)
			{

				square_real.setPosition(square_real.getPosition().x, platform_cords[whichplatform1].y - square.getSize().y + move);
				velocity.y = 0;
				jump = false;
				fall = false;
			}

			if (square_real.getPosition().y < 100)
			{
				move += 4;
				background_real.move(0, 4);
			}




			std::cout << whichplatform << std::endl;

			okno.draw(background_real);
			okno.draw(square_real);
			okno.display();
			animatetime.restart();
			whichplatform = 0;
			whichplatform1 = 0;
		}
	}
	return 0;
}
