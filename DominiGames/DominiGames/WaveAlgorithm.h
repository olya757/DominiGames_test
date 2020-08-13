#pragma once
#include "Algorithm.h"
#include <list>
using namespace std;
class WaveAlgorithm: public Algorithm
{
	bool** busyCells;
	BoardCell** boardCells;
	list<BoardCell> cellsList;
	bool hasMove(Position start);
	int** getWave(Position start);
	void updateBoard(BoardCell** boardCells);
	pair<Move, int> getMoveAndRating(int** wave);

public:
	Move getOptimalMove(BoardCell** boardCells);
	WaveAlgorithm(BoardCell** boardCells);
};

