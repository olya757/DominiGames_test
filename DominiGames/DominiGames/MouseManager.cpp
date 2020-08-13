#include "MouseManager.h"
#include <math.h>

void MouseManager::mouseDown(double x, double y) {
	mouseState = MouseState::Down;
	int p_x = 0, p_y = 0;
	p_x = (int)trunc(x / BOARD_CELL_WIDTH_PIXEL);
	p_y= (int)trunc(y / BOARD_CELL_HEIGHT_PIXEL);
	if (p_x >= 0 && p_x < BOARD_WIDTH && p_y >= 0 && p_y < BOARD_HEIGHT) {
		if (board->getBoardCells()[p_x][p_y].cellState == USER_COLOR) {
			selectedPawn = board->getPawnFromCell({ p_x,p_y });
			positionFrom = { p_x,p_y };
			mouseState = MouseState::DownWithPawn;
		}
	}
}

bool MouseManager::mouseUp(double x, double y) {
	
	if (mouseState != MouseState::DownWithPawn) {
		mouseState = MouseState::Up;
		return false;
	}
	mouseState = MouseState::Up;
	int p_x = 0, p_y = 0;
	p_x = (int)trunc(x / BOARD_CELL_WIDTH_PIXEL);
	p_y = (int)trunc(y / BOARD_CELL_HEIGHT_PIXEL);
	if (p_x >= 0 && p_x < BOARD_WIDTH && p_y >= 0 && p_y < BOARD_HEIGHT) {
		if (board->getBoardCells()[p_x][p_y].cellState == State::None) {
			if (abs(selectedPawn.position.X - p_x) + abs(selectedPawn.position.Y - p_y) == 1) {
				auto lastPos = selectedPawn.position;
				selectedPawn.position = { p_x,p_y };
				board->setPawnInCell(selectedPawn, lastPos);
				selectedPawn = {};
				positionFrom = { 0,0};
				return true;
			}
			
		}
	}
	board->setPawnInCell(selectedPawn,selectedPawn.position);
	return false;
}

void MouseManager::mouseMove(double x, double y) {
	selectedPawn.center = { x,y };
	board->setPawn(selectedPawn);
}

bool MouseManager::pawnMoved() {
	float x,  y;
	x = 0;
	y = 0;
	hge->Input_GetMousePos(&x, &y);

	bool isMouseDown = hge->Input_GetKeyState(HGEK_LBUTTON);

	switch (mouseState) 
	{
		case MouseState::Up:
			if (isMouseDown) {				
				mouseDown(x, y);
			}
			break;
		case MouseState::Down:
		case MouseState::DownWithPawn:
			if (!isMouseDown) {
				if (mouseUp(x, y)) {
					return true;
				}
			}
			else {
				mouseMove(x, y);
			}
			break;
	
	default:
		break;
	}	

	return false;
}