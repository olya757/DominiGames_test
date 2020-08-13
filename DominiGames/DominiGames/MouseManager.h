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
	//место откуда взята пешка
	Position positionFrom;
	//состояние мышки
	MouseState mouseState;
	//выбранная пешка
	BoardCell selectedPawn;
	//ЛКМ нажата
	void mouseDown(double x, double y);
	//ЛКМ отжата
	bool mouseUp(double x, double y);
	//мышь двигается
	void mouseMove(double x, double y);
public:
	MouseManager(HGE* hge, Board *board) {
		this->hge = hge;
		this->board = board;
		mouseState = MouseState::Up;
		selectedPawn = BoardCell();
		positionFrom = { 0,0 };
	}
	//получить, перемещена ли пешка
	bool pawnMoved();

};