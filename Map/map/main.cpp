#include "map.h"

int main()
{
	Map niveau1("mapConsoleTexte.txt");
	niveau1.LireMap();
	niveau1.AfficherMap();

	return 0;
}