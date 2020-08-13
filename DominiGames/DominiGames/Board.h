#pragma once
#include "BoardCell.h"
#include "HelpStructures.h"
#include "IDrawable.h"
#include "Algorithm.h"

class Board : public IDrawable
{
private:
	bool canUserMove;
	BoardCell **boardCells=new BoardCell*[BOARD_WIDTH];
	BoardCell* selectedCell;
	void initBoard();
	bool checkStateForRect(Rect rect , State state);

	bool tryMoveFigure(Position position1, Position position2, State state);
	Algorithm* algorithm;

public:
	Board();
	State getGameState();
	BoardCell getPawnFromCell(Position pos);
	void setPawn(BoardCell cell);
	void setPawnInCell(BoardCell cell, Position lastPos);

	bool computerMove();
	bool moveFigureByUser(Move &move);
	bool isPositionExists(Position position);

	BoardCell** getBoardCells() { return boardCells; }

	void draw(HGE* hge);
};
