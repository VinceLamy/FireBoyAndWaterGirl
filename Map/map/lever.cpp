#include "lever.h"
#include <iostream>

using namespace	std;

Lever::Lever(int x, int y)
{
	SetPosition(x, y);
	SetType(LEVER);
}

Lever::Lever()
{
}

void Lever::Show()
{
	cout << 'L';
}