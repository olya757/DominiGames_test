#include "Board.h"
#include <math.h>
#include "Algorithm.h"
#include "WaveAlgorithm.h"


void Board::initBoard() {
	boardCells = new BoardCell*[BOARD_WIDTH];
	for (int i = 0; i < BOARD_WIDTH; i++) {
		boardCells[i] = new BoardCell[BOARD_HEIGHT];	
		for (int j = 0; j < BOARD_WIDTH; j++) {
			boardCells[i][j] = BoardCell{ State::None,{i,j} };
		}
	}
	for (int i = 0; i < SQRT_AMOUNT_OF_FIGURES; i++) {
		for (int j = 0; j < SQRT_AMOUNT_OF_FIGURES; j++) {
			boardCells[i][j].cellState = USER_COLOR;
		}
	}

	for (int i = BOARD_WIDTH-SQRT_AMOUNT_OF_FIGURES; i < BOARD_WIDTH; i++) {
		for (int j = BOARD_HEIGHT-SQRT_AMOUNT_OF_FIGURES; j < BOARD_HEIGHT; j++) {
			boardCells[i][j].cellState =COMPUTER_COLOR;
		}
	}
	selectedCell = &boardCells[0][0];
}

Board::Board() {
	initBoard();
}

bool Board::isPositionExists(Position position) 
{
	return position.X >= 0 && position.Y >= 0 && position.X < BOARD_WIDTH && position.Y < BOARD_HEIGHT;
}

bool Board::tryMovePawn(Position position1, Position position2, State state) 
{	
	if (!isPositionExists(position1) || !isPositionExists(position2))
		return false;
	State needStateInPosition = state;
	if (boardCells[position1.X][position1.Y].cellState != needStateInPosition)
		return false;
	if (abs(position2.X - position1.X) > 1 || abs(position1.Y - position2.Y) > 1)
		return false;
	if (boardCells[position2.X][position2.Y].cellState != State::None)
		return false;
	boardCells[position1.X][position1.Y].cellState = State::None;
	boardCells[position2.X][position2.Y].cellState = needStateInPosition;
	return true;
}



bool Board::checkStateForRect(Rect rect, State state) {
	auto p1 = rect.leftTop;
	auto p2 = rect.rightBottom;
	if (!isPositionExists(p1) || !isPositionExists(p2))
		return false;
	if (p1.X > p2.X || p1.Y > p2.Y)
		return false;

	for (int i = p1.X; i <= p2.X; i++) {
		for (int j = p1.Y; j <= p2.Y; j++) {
			if (boardCells[i][j].cellState != state)
				return false;
		}
	}
	return true;
}

State Board::getGameState() 
{
	if (checkStateForRect({ { 0,0 }, { SQRT_AMOUNT_OF_FIGURES - 1, SQRT_AMOUNT_OF_FIGURES - 1 } }, State::Black)) {
		return State::White;
	}
	if (checkStateForRect({ { BOARD_WIDTH - SQRT_AMOUNT_OF_FIGURES,BOARD_HEIGHT - SQRT_AMOUNT_OF_FIGURES }, { BOARD_WIDTH - 1, BOARD_HEIGHT - 1 } }, State::White)) {
		return State::Black;
	}
	return State::None;
}

bool Board::computerMove(Algorithm *algorithm) {
	auto state = getGameState();
	if (state != State::None)
		return true;
	auto move = algorithm->getOptimalMove(boardCells);
	auto moveResult= tryMovePawn(move.from, move.to, COMPUTER_COLOR);
	state = getGameState();
	if (state != State::None)
		return true;
	return false;
}

void Board::draw(HGE* hge) {
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			boardCells[i][j].draw(hge);
		}
	}
	selectedCell->draw(hge);
}

BoardCell Board::getPawnFromCell(Position pos) {
	if (pos.X >= 0 && pos.X < BOARD_WIDTH && pos.Y >= 0 && pos.Y < BOARD_HEIGHT) {
		selectedCell = &boardCells[pos.X][pos.Y];
		return boardCells[pos.X][pos.Y];
	}
	return BoardCell();
}
void Board::setPawn(BoardCell cell) {
	auto pos = cell.position;
	if (pos.X >= 0 && pos.X < BOARD_WIDTH && pos.Y >= 0 && pos.Y < BOARD_HEIGHT) {
		boardCells[pos.X][pos.Y] = cell;
	}
}


void Board::setPawnInCell(BoardCell cell, Position lastPos) {
	auto pos = cell.position;
	if (pos.X >= 0 && pos.X < BOARD_WIDTH && pos.Y >= 0 && pos.Y < BOARD_HEIGHT && lastPos.X>=0 && lastPos.X<BOARD_WIDTH && lastPos.Y>=0 && lastPos.Y< BOARD_HEIGHT) {
		cell.center =
		{
			pos.X * BOARD_CELL_WIDTH_PIXEL + BOARD_CELL_WIDTH_PIXEL / 2,
			pos.Y * BOARD_CELL_HEIGHT_PIXEL + BOARD_CELL_HEIGHT_PIXEL / 2
		};
		boardCells[lastPos.X][lastPos.Y] = BoardCell(State::None, lastPos);
		boardCells[pos.X][pos.Y] = cell;
	}
}