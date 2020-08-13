#pragma once
#include "IDrawable.h"
#include "Consts.h"

class BoardCell: public IDrawable
{
public:
	State cellState;
	Position position;
	Vertex center;
	BoardCell() 
	{ 
		cellState = State::None; 
		position = { 0,0 }; 
		center = { BOARD_CELL_WIDTH_PIXEL / 2, BOARD_CELL_HEIGHT_PIXEL / 2 };
	};
	void draw(HGE *hge);
	BoardCell(State cellState, Position position);
};
