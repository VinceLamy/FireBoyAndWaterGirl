#include "gate.h"
#include <iostream>

using namespace std;

Gate::Gate(int x, int y)
{
    SetPosition(x, y);
    SetType(GATE);
}

Gate::~Gate()
{
}

int Gate::getWidth() 
{
    return width;
}

int Gate::getHeight()
{
    return height;
}

pair<int, int> Gate::getDimension()
{
    return make_pair(width, height);
}

State Gate::getState()
{
    return state;
}

Orientation Gate::getOrientation()
{
    return orientation;
}

int Gate::getSpeed()
{
    // Implementation
}

Controller Gate::getController()
{
    // Implementation
}

void Gate::setWidth(width)
{
    this->width = width;
}

void Gate::setHeight(height)
{
    this->height = height;
}

void Gate::setDimension(width, height)
{
    this->width = width;
    this->height = height;
}

void Gate::setState(state)
{
    this->state = state;
}

void Gate::setOrientation(orientation)
{
    this->orientation = orientation;
}

void Gate::setController(controller)
{
    this->controller = controller;
}

void Gate::Show()
{
    cout << '|';
}
