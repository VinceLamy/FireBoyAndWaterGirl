#include "game.h"

#include <iostream>

#include "conio.h"
#include "pool.h"

using namespace std;

Game::Game()
{
	_map = Map("mapConsoleTexte.txt");

	_gameOver = _isJumping = false;
}

Game::~Game()
{
	
}

void Game::GetInput()
{
	vector<vector<Tile*>> grid = _map.GetGrid();
	Coordinate ActivePlayerPos = _map.GetActiveCharacter()->GetPosition();

	switch (_getch()) {
	case 'w':
		break;
	case 's':
		break;
	case 'a':
		if (grid[ActivePlayerPos.y][ActivePlayerPos.x - 1]->GetType() == WALL)
			return;

		if (grid[ActivePlayerPos.y - 1][ActivePlayerPos.x - 1]->GetType() == POOL)
		{
			Pool* pool = _map.GetPoolAt(ActivePlayerPos.x - 1, ActivePlayerPos.y - 1);
			if (pool->GetElement() != _map.GetActiveCharacter()->getElement())
				_gameOver = true;
		}
		
		grid[ActivePlayerPos.y][ActivePlayerPos.x - 1] = grid[ActivePlayerPos.y][ActivePlayerPos.x];
		grid[ActivePlayerPos.y][ActivePlayerPos.x] = new Tile();
		_map.GetActiveCharacter()->SetPosition(ActivePlayerPos.x - 1, ActivePlayerPos.y);
		break;
	case 'd':
		if (grid[ActivePlayerPos.y][ActivePlayerPos.x + 1]->GetType() == WALL)
			return;

		if (grid[ActivePlayerPos.y + 1][ActivePlayerPos.x + 1]->GetType() == POOL)
		{
			Pool* pool = _map.GetPoolAt(ActivePlayerPos.x + 1, ActivePlayerPos.y + 1);
			if (pool->GetElement() != _map.GetActiveCharacter()->getElement())
				_gameOver = true;
			else
			{
				grid[ActivePlayerPos.y][ActivePlayerPos.x + 1] = grid[ActivePlayerPos.y][ActivePlayerPos.x];
				grid[ActivePlayerPos.y][ActivePlayerPos.x] = new Tile();
				_map.GetActiveCharacter()->SetPosition(ActivePlayerPos.x + 1, ActivePlayerPos.y);
			}
		}
		else
		{
			grid[ActivePlayerPos.y][ActivePlayerPos.x + 1] = grid[ActivePlayerPos.y][ActivePlayerPos.x];
			grid[ActivePlayerPos.y][ActivePlayerPos.x] = new Tile();
			_map.GetActiveCharacter()->SetPosition(ActivePlayerPos.x + 1, ActivePlayerPos.y);

		}
		break;
	case 'q':
		_map.SwitchCharacter();
	default:
		
		if(grid[ActivePlayerPos.y + 1][ActivePlayerPos.x]->GetType() != WALL && _isJumping == false)
		{
			_map.GetActiveCharacter()->SetPosition(ActivePlayerPos.x, ActivePlayerPos.y - 0.25);
			if(_map.GetActiveCharacter()->GetPosition().y - (ActivePlayerPos.y - 0.25) * floor(_map.GetActiveCharacter()->GetPosition().y - (ActivePlayerPos.y - 0.25)))
				grid[ActivePlayerPos.y][ActivePlayerPos.x] =
				
		}
		break;
	}

	_map.SetGrid(grid);
}


void Game::Play()
{
	_map.ReadMap();
	_map.ShowMap();

	do
	{
		GetInput();
		system("CLS");
		_map.ShowMap();

	} while (!_gameOver);

	system("CLS");
	cout << "Gameover\n";
}
