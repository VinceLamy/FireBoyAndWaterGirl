#ifndef TILE_H
#define TILE_H

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
	void SetPostition(int x, int y);
	virtual void Show();

private:
	Coordinate position;
};

#endif TILE_H