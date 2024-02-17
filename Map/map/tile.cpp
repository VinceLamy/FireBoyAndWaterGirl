#include "tile.h"
#include <iostream>
using namespace std;

Tile::Tile()
{
}

Tile::Tile(int x, int y)
{
	position.x = x;
	position.y = y;
}

Tile::~Tile()
{
}

Coordinate Tile::GetPosition()
{
	return Coordinate();
}

void Tile::SetPostition(int x, int y)
{
	position.x = x;
	position.y = y;
}

void Tile::Show()
{
	cout << ' ';
}
