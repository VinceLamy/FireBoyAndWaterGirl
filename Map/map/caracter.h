#ifndef CARACTER_H
#define CARACTER_H

#include "tile.h"

class Caracter : public Tile 
{
public:
	Caracter(int x, int y, char e);
	~Caracter();
	void Show();

private:
	char element;
};

#endif CARACTER_H
