#include "map.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "button.h"
#include "caracter.h"
#include "controller.h"
#include "exit.h"
#include "gate.h"
#include "lever.h"
#include "pool.h"
#include "wall.h"


using namespace std;

Map::Map(const char* nomNiveau)
{
	nom = nomNiveau;
}

Map::~Map()
{
}

void Map::ReadMap()
{
	ifstream niveau;
	niveau.open(nom, ios_base::in);
	if (niveau.is_open())
	{
		string ligne;
		getline(niveau, ligne);
		int x = stoi(ligne);
		getline(niveau, ligne);
		int y = stoi(ligne);
		grid.resize(y, vector<Tile*>(x));

		//Remplie la map de Tile
		for (int a = 0; a < grid.size(); a++)
		{
			for (int b = 0; b < grid[a].size(); b++)
			{
				AddTile(b, a);
			}
		}

		//Ajoute les contours en Wall
		for (int i = 0; i < x; i++)
		{
			AddWall(i, 0);
			AddWall(i, y - 1);
		}
		for (int i = 0; i < y; i++)
		{
			AddWall(0, i);
			AddWall(x - 1, i);
		}

		//Ajoute tout le reste
		while (niveau.good())
		{
			getline(niveau, ligne);
			string s;
			stringstream ss(ligne);
			vector<string> v;

			while (getline(ss, s, ' ')) {
				v.push_back(s);
			}

			switch (ligne.c_str()[0])
			{
			case 'S':
				for (int i = stoi(v[1]); i <= stoi(v[2]); i++)
				{
					AddWall(i, stoi(v[3]));
				}
				break;
			case 'M':
				for (int i = stoi(v[2]); i <= stoi(v[3]); i++)
				{
					AddWall(stoi(v[1]), i);
				}
			case '-':
				for (int i = stoi(v[1]); i <= stoi(v[2]); i++)
				{
					AddPool(i, stoi(v[3]), 'E');
				}
				break;
			case '+':
				for (int i = stoi(v[1]); i <= stoi(v[2]); i++)
				{
					AddPool(i, stoi(v[3]), 'F');
				}
				break;
			case 'E':
				AddCharacter(stoi(v[1]), stoi(v[2]), 'E');
				break;
			case 'F':
				AddCharacter(stoi(v[1]), stoi(v[2]), 'F');
				break;
			case 'P':
				AddExit(stoi(v[1]), stoi(v[2]));
				break;
			case '|':
				for (int i = stoi(v[2]); i <= stoi(v[3]); i++)
				{
					AddGate(stoi(v[1]), i);
				}
				break;
			case 'B':
				AddButton(stoi(v[1]), stoi(v[2]));
				break;
			case 'L':
				AddLever(stoi(v[1]), stoi(v[2]));
				break;
			}
		}
		niveau.close();
	}
}

void Map::ShowMap()
{
	for (int a = 0; a < grid.size(); a++)
	{
		for (int b = 0; b < grid[a].size(); b++)
		{
			grid[a][b]->Show();
		}
		cout << endl;
	}
}

void Map::AddTile(int x, int y)
{
	Tile* nTile = new Tile(x, y);
	grid[y][x] = nTile;
}

void Map::AddCharacter(int x, int y, char e)
{
	Tile* nCaracter = new Caracter(x, y, e);
	delete grid[y][x];
	grid[y][x] = nCaracter;
}

void Map::AddExit(int x, int y)
{
	Tile* nExit = new Exit(x, y);
	delete grid[y][x];
	grid[y][x] = nExit;
}

void Map::AddPool(int x, int y, char e)
{
	Tile* nPool = new Pool(x, y, e);
	delete grid[y][x];
	grid[y][x] = nPool;
}

void Map::AddWall(int x, int y)
{
	Tile* nWall = new Wall(x, y);
	delete grid[y][x];
	grid[y][x] = nWall;
}

void Map::AddGate(int x, int y)
{
	Tile* nGate = new Gate(x, y);
	delete grid[y][x];
	grid[y][x] = nGate;
}

void Map::AddLever(int x, int y)
{
	Tile* nLever = new Lever(x, y);
	delete grid[y][x];
	grid[y][x] = nLever;
}

void Map::AddButton(int x, int y)
{
	Tile* nButton = new Button(x, y);
	delete grid[y][x];
	grid[y][x] = nButton;
}
