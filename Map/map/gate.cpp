#include "gate.h"
#include <iostream>

using namespace	std;

Gate::Gate(int x, int y)
{
	SetPosition(x, y);
	SetType(GATE);
}

Gate::~Gate()
{
}

void Gate::Show()
{
	cout << '|';
}
