#pragma once
#include "BoardCell.h"
#include "HelpStructures.h"
#include "IDrawable.h"
#include "Algorithm.h"

/*����� �����*/
class Board : public IDrawable
{
private:
	//������
	BoardCell **boardCells=new BoardCell*[BOARD_WIDTH];
	//��������� ������
	BoardCell* selectedCell;
	//�������������
	void initBoard();
	//���������, ��� ��� ������ �� ������� ����� ���������� ��������� state
	bool checkStateForRect(Rect rect , State state);
	//����� ����� ��������� �������
	bool isPositionExists(Position position);
	//����������� ������
	bool tryMovePawn(Position position1, Position position2, State state);

public:
	Board();
	//��������� ��� �� �����������
	State getGameState();
	//�������� ����� �� ������
	BoardCell getPawnFromCell(Position pos);
	//���������� ����� (��������, �� � ������ ������)
	void setPawn(BoardCell cell);
	//��������� ����� � ������
	void setPawnInCell(BoardCell cell, Position lastPos);
	//��� ����
	bool computerMove(Algorithm *algorithm);
	//�������� ������
	BoardCell** getBoardCells() { return boardCells; }
	//��������� �����
	void draw(HGE* hge);
};
