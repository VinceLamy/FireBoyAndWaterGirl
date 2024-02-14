#include "map.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

Map::Map(const char* nomNiveau)
{
	nom = nomNiveau;
}

Map::~Map()
{
}

void Map::LireMap()
{
	ifstream niveau;
	niveau.open(nom, ios_base::in);
	if (niveau.is_open())
	{
		string dimension;
		getline(niveau, dimension);
		x = stoi(dimension);
		getline(niveau, dimension);
		y = stoi(dimension);
		niveau.get();

		charLevel.resize(y, vector<char>(x));
		for (int a = 0; a < y; a++)
		{
			for (int b = 0; b < x; b++)
			{
				charLevel[a][b] = niveau.get();
			}
			niveau.get();
		}
		niveau.close();
	}
}

void Map::AfficherMap()
{
	for (int a = 0; a < charLevel.size(); a++)
	{
		for (int b = 0; b < charLevel[a].size(); b++)
		{
			cout << charLevel[a][b];
		}
	}
}
