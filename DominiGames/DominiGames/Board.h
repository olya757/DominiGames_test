#pragma once
#include "BoardCell.h"
#include "HelpStructures.h"
#include "IDrawable.h"
#include "Algorithm.h"

/*класс Доска*/
class Board : public IDrawable
{
private:
	//клетки
	BoardCell **boardCells=new BoardCell*[BOARD_WIDTH];
	//выбранная клетка
	BoardCell* selectedCell;
	//инициализация
	void initBoard();
	//проверить, что все клетки из области имеют одинаковое состояние state
	bool checkStateForRect(Rect rect , State state);
	//доска имеет указанную позицию
	bool isPositionExists(Position position);
	//переместить фигуру
	bool tryMovePawn(Position position1, Position position2, State state);

public:
	Board();
	//проверить нет ли победителей
	State getGameState();
	//получить пешку из клетки
	BoardCell getPawnFromCell(Position pos);
	//установить пешку (свободно, не в центре клетки)
	void setPawn(BoardCell cell);
	//поставить пешку в клетку
	void setPawnInCell(BoardCell cell, Position lastPos);
	//ход бота
	bool computerMove(Algorithm *algorithm);
	//получить клетки
	BoardCell** getBoardCells() { return boardCells; }
	//отрисовка доски
	void draw(HGE* hge);
};
