#include "gate.h"
#include <iostream>

using namespace	std;

Gate::Gate(int x, int y)
{
	SetPostition(x, y);
}

Gate::~Gate()
{
}

void Gate::Show()
{
	cout << '|';
}
