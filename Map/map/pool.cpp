#include "pool.h"
#include <iostream>

using namespace std;

Pool::Pool(int x, int y, char e)
{
	element = e;
	SetPostition(x, y);
}

Pool::~Pool()
{
}

void Pool::Show()
{
	if (element == 'E')
	{
		cout << '-';
	}
	else if (element == 'F')
	{
		cout << '+';
	}
}
