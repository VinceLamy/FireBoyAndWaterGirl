#include "map.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

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
		string ligne;
		getline(niveau, ligne);
		int x = stoi(ligne);
		getline(niveau, ligne);
		int y = stoi(ligne);
		charLevel.resize(y, vector<char>(x));

		//Remplie la map de vide
		for (int a = 0; a < charLevel.size(); a++)
		{
			for (int b = 0; b < charLevel[a].size(); b++)
			{
				charLevel[a][b] = ' ';
			}
		}

		//Ajoute les contours
		for (int i = 0; i < x; i++)
		{
			charLevel[0][i] = '#';
			charLevel[y-1][i] = '#';
		}
		for (int i = 0; i < y; i++)
		{
			charLevel[i][0] = '#';
			charLevel[i][x-1]= '#';
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
					charLevel[stoi(v[3])][i] = '#';
				}
				break;
			case 'M':
				for (int i = stoi(v[2]); i <= stoi(v[3]); i++)
				{
					charLevel[i][stoi(v[1])] = '#';
				}
			case '-':
				for (int i = stoi(v[1]); i <= stoi(v[2]); i++)
				{
					charLevel[stoi(v[3])][i] = '-';
				}
				break;
			case '+':
				for (int i = stoi(v[1]); i <= stoi(v[2]); i++)
				{
					charLevel[stoi(v[3])][i] = '+';
				}
				break;
			case 'E':
				charLevel[stoi(v[2])][stoi(v[1])] = 'E';
				//cree l'objet personnage avec x = stoi(v[1]) et y = stoi(v[2])
				break;
			case 'F':
				charLevel[stoi(v[2])][stoi(v[1])] = 'F';
				//cree l'objet personnage avec x = stoi(v[1]) et y = stoi(v[2])
				break;
			case 'P':
				charLevel[stoi(v[2])][stoi(v[1])] = 'P';
				//cree l'objet porte avec x = stoi(v[1]) et y = stoi(v[2])
				break;
			case '|':
				for (int i = stoi(v[2]); i <= stoi(v[3]); i++)
				{
					charLevel[i][stoi(v[1])] = '|';
				}
				//cree l'objet porte non-fixe avec x = stoi(v[1]) et y = stoi(v[3]) 
				break;
			case 'B':
				charLevel[stoi(v[2])][stoi(v[1])] = 'B';
				//cree l'objet bouton avec x = stoi(v[1]) et y = stoi(v[2]) dans le dernier objet porte non-fixe cree
				break;
			case 'L':
				charLevel[stoi(v[2])][stoi(v[1])] = 'L';
				//cree l'objet levier avec x = stoi(v[1]) et y = stoi(v[2]) dans le dernier objet porte non-fixe cree
				break;
			}
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
		cout << endl;
	}
}
