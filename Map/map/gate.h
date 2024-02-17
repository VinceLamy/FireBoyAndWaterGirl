#ifndef GATE_H
#define GATE_H

#include "tile.h"

class Gate : public Tile
{
public:
	Gate(int x, int y);
	~Gate();
	void Show();
};

#endif GATE_H
