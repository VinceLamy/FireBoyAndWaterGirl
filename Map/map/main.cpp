#include "map.h"

int main()
{
	Map niveau1("testPlatform.txt");
	niveau1.ReadMap();
	niveau1.ShowMap();
	niveau1.MovePlatform(5, 2);
	niveau1.ShowMap();

	return 0;
}