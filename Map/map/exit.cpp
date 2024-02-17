#include "exit.h"
#include <iostream>

using namespace	std;

Exit::Exit(int x, int y)
{
	SetPostition(x, y);
}

Exit::~Exit()
{
}

void Exit::Show()
{
	cout << 'P';
}
