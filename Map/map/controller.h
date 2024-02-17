#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "tile.h"

class Controller : public Tile
{
public:
	Controller();
	~Controller();
	virtual void Show() = 0;
};

#endif CONTROLLER_H
