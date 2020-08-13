#pragma once
#include "BoardCell.h"


class Algorithm 
{
private:
	BoardCell** boardCells;
public:
	Algorithm(BoardCell **cells);
	virtual Move getOptimalMove(BoardCell** cells)=0;
};