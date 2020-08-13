#include "BoardCell.h"
#include "HelpGraphic.h"

BoardCell::BoardCell(State cellState, Position position) 
{
	this->cellState = cellState;
	this->position = position;
	this->center = { position.X * BOARD_CELL_WIDTH_PIXEL + BOARD_CELL_WIDTH_PIXEL / 2,position.Y * BOARD_CELL_HEIGHT_PIXEL + BOARD_CELL_HEIGHT_PIXEL / 2 };
}

void BoardCell::draw(HGE *hge) 
{
	int x1, x2, y1, y2;//координаты левого верхнего угла и правого нижнего угла клетки
	x1 = position.X * BOARD_CELL_WIDTH_PIXEL;
	y1= position.Y * BOARD_CELL_HEIGHT_PIXEL;
	x2 = x1 + BOARD_CELL_WIDTH_PIXEL;
	y2 = y1 + BOARD_CELL_HEIGHT_PIXEL;

	int c_x=center.X, c_y=center.Y;//координаты центра клетки

	hgeColor cell_color = (position.X + position.Y) % 2 == 0 ? WHITE_COLOR : GRAY_COLOR;
	HelpGraphic::drawCell(hge, { (double)x1,(double)y1 }, { x2*1.0,y2*1.0 }, cell_color);
	if (cellState != State::None) {
		hgeColor pawn_color = cellState == State::Black ? PAWN_COLOR_BLACK : PAWN_COLOR_WHITE;
		HelpGraphic::drawPawn(hge, { c_x*1.0,c_y*1.0 }, BOARD_CELL_HEIGHT_PIXEL * 0.9, pawn_color);
	}
}