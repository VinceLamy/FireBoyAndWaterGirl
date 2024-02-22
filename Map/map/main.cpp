#include "map.h"

int main()
{
	Map niveau1("mapConsoleTexte.txt");
	niveau1.ReadMap();
	niveau1.ShowMap();
	//niveau1.CheckPlatforms();
	//niveau1.ShowMap();

	return 0;
}