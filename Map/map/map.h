#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "tile.h"

using namespace std;

class Map
{
public:
	Map(const char* nomNiveau);
	~Map();

	void ReadMap();
	void ShowMap();

	void AddTile(int x, int y);
	void AddCharacter(int x, int y, char e);
	void AddExit(int x, int y);
	void AddPool(int x, int y, char e);
	void AddWall(int x, int y);
	void AddGate(int x, int y);
	void AddLever(int x, int y);
	void AddButton(int x, int y);

private:
	const char* nom;
	vector<vector<Tile*>> grid;
};

#endif MAP_H

