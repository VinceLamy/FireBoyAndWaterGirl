#include "wall.h"
#include <iostream>

using namespace	std;

Wall::Wall(int x, int y)
{
	SetPostition(x, y);
}

Wall::~Wall()
{
}

void Wall::Show()
{
	cout << '#';
}
