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

	vector<vector<Tile*>> GetGrid;
	const char* GetFilename;

	void SetGrid(vector<vector<Tile*>> g);

	void AddTile(int x, int y);
	void AddCharacter(int x, int y, Element e);
	void AddExit(int x, int y);
	void AddPool(int x, int y, Element e);
	void AddWall(int x, int y);
	void AddGate(int x, int y);
	void AddLever(int x, int y);
	void AddButton(int x, int y);

	void Clear();

private:
	const char* _fileName;
	vector<vector<Tile*>> _grid;
};

#endif MAP_H

