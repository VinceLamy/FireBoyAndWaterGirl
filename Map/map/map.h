#include <string>
#include <vector>

using namespace std;

class Map
{
public:
	Map(const char* nomNiveau);
	~Map();

	void LireMap();
	void AfficherMap();

private:
	const char* nom;
	vector<vector<char>> charLevel;
};

