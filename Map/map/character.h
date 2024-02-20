#ifndef CARACTER_H
#define CARACTER_H

#include "tile.h"

class Caracter : public Tile 
{
public:
	Caracter(int x, int y, Element e);
	~Caracter();
	void Show();

private:
	Element _element;
};

#endif CARACTER_H
