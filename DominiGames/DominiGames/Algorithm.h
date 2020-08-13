#pragma once
#include "BoardCell.h"
/*абстрактный класс Алгоритм, все алгоритмы работы бота наследуются от этого класса*/
class Algorithm 
{
private:
	BoardCell** boardCells;
public:
	Algorithm(BoardCell **cells);
	virtual Move getOptimalMove(BoardCell** cells)=0;
};