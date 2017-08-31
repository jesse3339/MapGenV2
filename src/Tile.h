#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
struct Tile 
{
	int tileType;
	sf::Color color;
	sf::Vector2f position;


	Tile(int type, sf::Color col);
};