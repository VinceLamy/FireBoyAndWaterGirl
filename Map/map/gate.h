#ifndef GATE_H
#define GATE_H

#include "tile.h"

class Gate : public Tile
{
private:
	int width;
	int height;
	State state;
	Orientation orientation;
	Controller controller;

public:
	Gate(int x, int y);
	~Gate();

	void Show();

	// Getters
	int getWidth();
	int getHeight();
	int getDimension();
	State getState();
	Orientation getOrientation();
	Controller getController();
	
	//Setters
	void setWidth(width);
	void setHeight(height);
	void setDimension(width, height);
	void setState(state);
	void setOrientation(orientation);
	void setController(controller);
};

#endif GATE_H
