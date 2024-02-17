#include "lever.h"
#include <iostream>

using namespace	std;

Lever::Lever(int x, int y)
{
	SetPostition(x, y);
}

Lever::Lever()
{
}

void Lever::Show()
{
	cout << 'L';
}