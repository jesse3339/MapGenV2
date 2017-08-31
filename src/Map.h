#pragma once
#include <vector>
#include <random>
#include "Tile.h"

class Map2D 
{
public:
	///custom iterators
	using iterator = typename std::vector<Tile>::iterator;
	using const_iterator = typename std::vector<Tile>::const_iterator;

	///iterator and size functions
	//the data vector is only accessible through these
	iterator begin() { return mapContents.begin(); }
	iterator end() { return mapContents.end(); }
	const_iterator begin() const { return mapContents.begin(); }
	const_iterator end() const { return mapContents.end(); }
	size_t size() const { return mapContents.size(); }
	int width() { return width_; };
	int height() { return height_; };

	///methods
	//finds value at a position in data
	Tile ValueAt(int x, int y) const;
	Tile& ValueAt(int x, int y);

	//sets data at a given point to the value given
	void SetValue(int x, int y, Tile val);

	//replaces the map contents with pre-made data
	void ImportData(std::vector<Tile> impdat);

	//expands the map contents
	void Expand();

	///operators
	Map2D(std::vector<Tile> &startData);
	~Map2D() = default;
	Map2D& operator=(Map2D other)
	{
		std::swap(mapContents, other.mapContents);
		return *this;
	}

	std::minstd_rand randDet;
private:
	Tile blank = Tile(0, sf::Vector2f(0, 0), sf::Color::Black);
	std::vector<Tile> mapContents;
	int width_;
	int height_;
};

