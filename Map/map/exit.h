#ifndef EXIT_H
#define EXIT_H

#include "tile.h"

class Exit : public Tile
{
public:
	Exit(int x, int y);
	~Exit();
	void Show();
};

#endif EXIT_H