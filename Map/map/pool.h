#ifndef POOL_H
#define POOL_H

#include "tile.h"

class Pool : public Tile
{
public:
	Pool(int x, int y, char e);
	~Pool();
	void Show();

private:
	char element;
};

#endif POOL_H