#ifndef CARACTER_H
#define CARACTER_H

#include "tile.h"

class Character : public Tile 
{
public:
	Character(int x, int y, Element e);
	~Character();
	void Show();

private:
	Element _element;
};

#endif CARACTER_H
