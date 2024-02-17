#include <string>
#include <vector>

using namespace std;

class Map
{
public:
	Map(const char* nomNiveau);
	~Map();

	void ReadMap();
	void ShowMap();

private:
	const char* nom;
	vector<vector<char>> charLevel;
};

