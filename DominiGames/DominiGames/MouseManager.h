#pragma once
#include <hge.h>
#include "Board.h"

enum class MouseState 
{
	Up,
	Down,
	DownWithPawn
};

class MouseManager 
{
private:
	HGE* hge;
	Board * board;
	Position positionFrom;
	MouseState mouseState;
	BoardCell selectedPawn;

	void mouseDown(double x, double y);
	bool mouseUp(double x, double y);
	void mouseMove(double x, double y);
public:
	MouseManager(HGE* hge, Board *board) {
		this->hge = hge;
		this->board = board;
		mouseState = MouseState::Up;
		selectedPawn = BoardCell();
		positionFrom = { 0,0 };
	}

	bool pawnMoved();

};