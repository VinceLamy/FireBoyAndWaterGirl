#include "character.h"
#include <iostream>

using namespace std;

Caracter::Caracter(int x, int y, Element e)
{
	_element = e;
	SetPostition(x, y);
	SetType(CHARACTER);
}

Caracter::~Caracter()
{
}

void Caracter::Show()
{
	if (_element == WATER)
	{
		cout << 'E';
	}
	else if (_element == FIRE)
	{
		cout << 'F';
	}		
}
