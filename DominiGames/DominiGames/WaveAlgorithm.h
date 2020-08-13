#pragma once
#include "Algorithm.h"
#include <list>
using namespace std;
//волновой алгоритм
class WaveAlgorithm: public Algorithm
{
	//матрица занятости
	bool** busyCells;
	BoardCell** boardCells;
	//пешки бота
	list<BoardCell> cellsList;
	//есть ли возможность хода из позиции start
	bool hasMove(Position start);
	//получить волновую матрицу из стартовой точки
	int** getWave(Position start);
	//обновить доску
	void updateBoard(BoardCell** boardCells);
	//получить рекомендованный ход и уровень полезности по волновой матрице
	pair<Move, int> getMoveAndRating(int** wave);

public:
	//наследованный метод, получить оптимальный ход бота
	Move getOptimalMove(BoardCell** boardCells);
	
	WaveAlgorithm(BoardCell** boardCells);
};

