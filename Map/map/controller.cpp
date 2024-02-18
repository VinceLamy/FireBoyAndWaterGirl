#include "controller.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::ChangeState()
{
	if (_state)
		_state = false;

	if (!_state)
		_state = true;
}

bool Controller::GetState()
{
	return _state;
}
