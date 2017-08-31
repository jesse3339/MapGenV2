#include "Map.h"
#include <time.h>


Tile Map2D::ValueAt(int x, int y) const
{
	return mapContents.at(y*(width_)+x);
}



Tile & Map2D::ValueAt(int x, int y)
{
	return mapContents.at(y*(width_)+x);
}


Map2D::Map2D(std::vector<Tile> &startData)
{
	//takes square root of the starting data to set the width and height and then copies the data to map contents
	width_ = sqrt(startData.size());
	height_ = sqrt(startData.size());
	mapContents = startData;
	randDet.seed(time(nullptr));
}



void Map2D::SetValue(int x, int y, Tile val)
{
	mapContents.at(y*(width_)+x) = val;
}



void Map2D::ImportData(std::vector<Tile> impdat)
{
	mapContents = impdat;
}



void Map2D::Expand()
{
	//expands rows
	for (int h = 1; h < height_; h++)
	{
		for (int x = 0; x < width_; x++)
		{
			mapContents.insert(mapContents.begin() + (width_ * ((h) * 2)) - width_, blank);
		}
		height_++;

		//sets the values of the blank tiles to that of their neighbors
		for (int x = 0; x < width_; x++)
		{
			Tile child = blank;
			Tile below = ValueAt(x, h + 1);
			Tile above = ValueAt(x, h - 1);
			if (above.color == below.color)
			{
				child.color = below.color;
				SetValue(x, h, child);
			}
			else
			{
				int det = randDet() % 2 + 1;
				if (det == 1)
				{
					child.color = below.color;
					SetValue(x, h, child);
				}
				else
				{
					child.color = above.color;
					SetValue(x, h, child);
				}
			}
		}
	}

	//expands columns
	for (int w = 1; w < width_; w++)
	{
		for (int y = 0; y < height_; y++)
		{
			mapContents.insert(mapContents.begin() + ((w - 1) * 2) + (y * (width_ + 1)) + 1, blank);
		}
		width_++;

		//checks nearest neighbors then sets the color to one of them
		for (int y = 0; y < height_; y++)
		{
			Tile child = blank;
			Tile left = ValueAt(w - 1, y);
			Tile right = ValueAt(w + 1, y);

			if (left.color == right.color)
			{
				child.color = left.color;
				SetValue(w, y, child);
			}
			else
			{
				int det = randDet() % 2 + 1;
				if (det == 1)
				{
					child.color = left.color;
					SetValue(w, y, child);
				}
				else
				{
					child.color = right.color;
					SetValue(w, y, child);
				}
			}
		}
	}

	//sets the correct positions for the new tiles
	for (int x = 0; x < width_; x++)
	{
		for (int y = 0; y < height_; y++)
		{
			Tile copied = ValueAt(x, y);
			sf::Vector2f currentPos(x, y);
			copied.position = currentPos;
			SetValue(x, y, copied);
		}
	}
}
