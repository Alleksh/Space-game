#include <iostream>
#include <sstream>
#include <thread>
#include "CalcSeed.h"
#include "Object.h"
#include <random>
#include <sstream>
#include "SFML/Graphics.hpp"
int main()
{
	srand(time(0));
	while(1)
	{
		std::cout << std::endl << std::endl;
		std::cout << "enter plz data here: ";
		unsigned char data[32];
		std::cin >> data;
		StarSystem system(0, 0, 0, data);

		sf::RenderWindow window(sf::VideoMode(1001, 1001), "Star system.");
		sf::CircleShape Star(50.f),
			*Planets = new sf::CircleShape[system.getPlanetNum()];
		Star.setFillColor(sf::Color::Yellow);
		Star.setPosition(450,450);

		for (int i = 0; i < system.getPlanetNum(); i++)
		{
			Planets[i] = sf::CircleShape(20);
			Planets[i].setScale(system.Planets[i]->GetOrbit().Minor_Semiaxis / 100,
								system.Planets[i]->GetOrbit().Major_Semiaxis / 100);
			float	x = 1001 - system.Planets[i]->GetOrbit().Minor_Semiaxis,
					y = 1001 - system.Planets[i]->GetOrbit().Major_Semiaxis;
			Planets[i].setPosition(x,y);
		}
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(Star);
			for (int i = 0; i < system.getPlanetNum(); i++)
			{
				window.draw(Planets[i]);
			}
			window.display();
		}
	}
	std::this_thread::sleep_for(std::chrono::hours(1));
}