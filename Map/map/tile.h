#ifndef TILE_H
#define TILE_H

#include "enum.h"

struct Coordinate 
{
	float x;
	float y;
};

class Tile 
{
public:
	Tile();
	Tile(int x, int y);
	virtual ~Tile();

	Coordinate GetPosition();
	Type GetType();

	void SetPosition(float x, float y);
	void SetType(Type t);


	virtual void Show();
	void Clear();

private:
	Coordinate _position;
	Type _type;
	Element _element;
};

#endif TILE_H