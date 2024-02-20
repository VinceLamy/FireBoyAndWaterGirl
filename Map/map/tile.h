#ifndef TILE_H
#define TILE_H

#include "enum.h"

struct Coordinate 
{
	int x;
	int y;
};

class Tile 
{
public:
	Tile();
	Tile(int x, int y);
	virtual ~Tile();

	Coordinate GetPosition();
	Type GetType();

	void SetPosition(int x, int y);
	void SetType(Type t);

	virtual void Show();
	void Clear();

private:
	Coordinate _position;
	Type _type;
};

#endif TILE_H