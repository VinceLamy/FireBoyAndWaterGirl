#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "tile.h"

class Controller : public Tile
{
public:
	Controller();
	~Controller();

	void ChangeState();
	bool GetState();

	virtual void Show() = 0;

private:
	bool _state = false;

};

#endif CONTROLLER_H
