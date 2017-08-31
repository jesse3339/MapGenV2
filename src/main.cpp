#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Map.h"
#include "Tile.h"
#include "Test.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "MapGen2");
	Map2D mainMap(data);
	for (int r = 0; r < 5; r++)
	{
		mainMap.Expand();
		std::cout << r;
	}





	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//window.clear();
		sf::RectangleShape shape;
		shape.setSize(sf::Vector2f(1, 1));
		shape.setFillColor(sf::Color::Green);
		for (int x = 0; x < mainMap.width(); x++)
		{
			for (int y = 0; y < mainMap.height(); y++)
			{
				shape.setFillColor(mainMap.ValueAt(x, y).color);
				window.draw(shape);
			}
		}
		window.display();
	}

	return 0;
}