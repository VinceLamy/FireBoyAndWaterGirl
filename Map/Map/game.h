#ifndef GAME_H
#define GAME_H

#include "map.h"

class Game
{
	Map _map;
	bool _gameOver;
	bool _isJumping;
public:
	Game();
	~Game();

	void init();

	void GetInput();

	void Play();

	void Show();

};

#endif CARACTER_H
