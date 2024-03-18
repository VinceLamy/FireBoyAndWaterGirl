#ifndef PLATFORM_H
#define PLATFORM_H

#include "tile.h"
#include "button.h"
#include "lever.h" 
#include <vector>

#define PLATFORMSPEED 1

using namespace std;

class Platform : public Tile
{
public:
	Platform(int x, int y);
	Platform(int x, int y, int xFinal, int yFinal, int size, Orientation o, vector<Tile*> slave, vector<Controller*> controllers);
	~Platform();

	int GetSize();
	bool GetMoveMe();
	Coordinate GetFinal();
	Coordinate GetInitial();
	State GetState();
	Orientation GetOrientation();
	vector<Controller*> GetControllers();
	vector<Tile*> GetSlaves();

	void MovePlatform();
	void CheckControllers();

	void SetState(State s);
	void SetMoveMe(bool b);

	void Show();
	void Clear();

private:
	bool _moveMe = false;
	int _size;
	Coordinate _initial;
	Coordinate _final;
	State _state = CLOSED;
	Orientation _orientation;
	vector<Controller*> _controllers;
	vector<Tile*> _slavePlatform;
};

#endif PLATFORM_H
