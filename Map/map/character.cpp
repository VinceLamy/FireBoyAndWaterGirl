#include "character.h"
#include <iostream>

using namespace std;

Character::Character(int x, int y, Element e)
{
	_element = e;
	SetPosition(x, y);
	SetType(CHARACTER);
}

Character::~Character()
{
}

void Character::Show()
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
