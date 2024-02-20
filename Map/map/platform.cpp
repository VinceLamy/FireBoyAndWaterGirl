#include "platform.h"
#include "map.h"
#include <iostream>

Platform::Platform(int x, int y)
{
	SetPosition(x, y);
}

Platform::Platform(int x, int y, int xFinal, int yFinal, int size, Orientation o, vector<Tile*> slave, vector<Controller*> controllers)
{
	SetPosition(x, y);
	_initial.x = x;
	_initial.y = y;
	_final.x = xFinal;
	_final.y = yFinal;
	_size = size;
	_orientation = o;
	_slavePlatform = slave;
	_controllers = controllers;
}

Platform::~Platform()
{
	Clear();
}

int Platform::GetSize()
{
	return _size;
}

Coordinate Platform::GetFinal()
{
	return _final;
}

Coordinate Platform::GetInitial()
{
	return _initial;
}

State Platform::GetState()
{
	return _state;
}

Orientation Platform::GetOrientation()
{
	return _orientation;
}

vector<Controller*> Platform::GetControllers()
{
	return _controllers;
}

vector<Tile*> Platform::GetSlaves()
{
	return _slavePlatform;
}

void Platform::MovePlatform()
{
	Coordinate position = GetPosition();

	if (_state == CLOSED)
	{
		if (_orientation == HORIZONTAL)
		{
			SetPosition(_final.x, _final.y);
			for (int i = 0; i < _slavePlatform.size(); i++)
			{
				_slavePlatform[i]->SetPosition(_final.x + i + 1, _final.y);
			}
		}
		else if (_orientation == VERTICAL)
		{
			SetPosition(_final.x, _final.y);
			for (int i = 0; i < _slavePlatform.size(); i++)
			{
				_slavePlatform[i]->SetPosition(_final.x, _final.y - i - 1);
			}
		}
	}
	else if (_state == OPEN)
	{
		if (_orientation == HORIZONTAL)
		{
			SetPosition(_initial.x, _initial.y);
			for (int i = 0; i < _slavePlatform.size(); i++)
			{
				_slavePlatform[i]->SetPosition(_initial.x + i + 1, _final.y);
			}

		}
		else if (_orientation == VERTICAL)
		{
			SetPosition(_initial.x, _initial.y);
			for (int i = 0; i < _slavePlatform.size(); i++)
			{
				_slavePlatform[i]->SetPosition(_initial.x, _initial.y - i - 1);
			}
		}
	}
}

void Platform::SetState(State s)
{
	_state = s;
}


void Platform::Show()
{
	cout << '%';
}

void Platform::Clear()
{
	_size = 0;
	_slavePlatform.clear();
	_initial.x = 0;
	_initial.y = 0;
	_final.x = 0;
	_final.y = 0;
	_controllers.clear();
}
