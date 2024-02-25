#ifndef GATE_H
#define GATE_H

#include "tile.h"
#include "controller.h"

class Gate : public Tile
{
private:
	int width; //Largeur
	int height; //Hauteur
	enum class gateState{ Closed, Opened };
	enum class gateOrientation{ Vertical, Horizontal };
	Controller controller;

public:
	Gate(int x, int y);
	~Gate();

	void Show();

	// Getters
	int getWidth();
	int getHeight();
	
	//Setters
	void setWidth(int width);
	void setHeight(int height);
};

#endif //GATE_H
