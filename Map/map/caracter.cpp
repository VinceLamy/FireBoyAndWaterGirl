#include "caracter.h"
#include <iostream>

using namespace std;

Caracter::Caracter(int x, int y, char e)
{
	element = e;
	SetPostition(x, y);
}

Caracter::~Caracter()
{
}

void Caracter::Show()
{
	if (element == 'E')
	{
		cout << 'E';
	}
	else if (element == 'F')
	{
		cout << 'F';
	}		
}
