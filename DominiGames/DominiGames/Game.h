#pragma once

#include "Board.h"
#include "hge.h"

class Game
{
private:
	//доска
	Board *board;
	//алгоритм бота
	Algorithm* algorithm;
public:
	Game();
	//ход бота
	bool computerMove();
	//получить победителя
	State getWinner();
	//получить доску
	Board *getBoard() { return board; }
	//отрисовать
	void Render(HGE *hge);
};