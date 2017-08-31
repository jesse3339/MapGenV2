#pragma once
#include "Tile.h"
#include <vector>

sf::Vector2f pos(0, 0);

Tile water = Tile(1, pos , sf::Color::Blue);

std::vector<Tile> data = 
{
	water, water, water, water, water,
	water, water, water, water, water,
	water, water, water, water, water,
	water, water, water, water, water,
	water, water, water, water, water

};

