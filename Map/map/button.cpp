#include "button.h"
#include <iostream>

using namespace	std;

Button::Button(int x, int y)
{
	SetPostition(x, y);
}

Button::Button()
{
}

void Button::Show()
{
	cout << 'B';
}
