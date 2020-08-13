#pragma once
#include "IDrawable.h"
#include "Consts.h"
//клетка доски
class BoardCell: public IDrawable
{
public:
	//состояние клетки
	State cellState;
	//место клетки
	Position position;
	//центр пешки
	Vertex center;
	BoardCell() 
	{ 
		cellState = State::None; 
		position = { 0,0 }; 
		center = { BOARD_CELL_WIDTH_PIXEL / 2, BOARD_CELL_HEIGHT_PIXEL / 2 };
	};
	//наследованный метод, отрисовка
	void draw(HGE *hge);
	BoardCell(State cellState, Position position);
};
