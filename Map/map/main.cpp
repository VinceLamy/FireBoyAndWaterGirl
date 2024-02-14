#include "map.h"

int main()
{
	Map niveau1("mapConsole.txt");
	niveau1.LireMap();
	niveau1.AfficherMap();

	return 0;
}