#include "button.h"
#include <iostream>

using namespace	std;

Button::Button(int x, int y)
{
	SetPostition(x, y);
	SetType(BUTTON);
}

Button::Button()
{
}

void Button::Show()
{
	cout << 'B';
}
