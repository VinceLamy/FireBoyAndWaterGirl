#include "map.h"

int main()
{
	Map niveau1("testPlatform.txt");
	niveau1.ReadMap();
	niveau1.ShowMap();
	niveau1.MovePlatform(17, 5);
	niveau1.MovePlatform(2, 2);
	niveau1.ShowMap();
	niveau1.MovePlatform(7, 2);
	niveau1.MovePlatform(6, 5);
	niveau1.ShowMap();

	return 0;
}