#include "gate.h"
#include <iostream>

using namespace std;

Gate::Gate(int x, int y)
{
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

void Gate::setWidth(width)
{
    this->width = width;
}

void Gate::setHeight(height)
{
    this->height = height;
}

void Gate::Show()
{
    if (state == gateState::Closed) {
        if (orientation == gateOrientation::Horizontal) {
            cout << '--';
        } else if (orientation == gateOrientation::Vertical) {
            cout << '|';
        }
    }
