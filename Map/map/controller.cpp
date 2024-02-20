#include "controller.h"

Controller::Controller()
{
	_state = false;
}

Controller::~Controller()
{
}



void Controller::ChangeState()
{
	if (_state == true)
		_state = false;

	else
		_state = true;
}

bool Controller::GetState()
{
	return _state;
}
