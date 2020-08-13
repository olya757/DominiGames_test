#pragma once

#include "Board.h"
#include "hge.h"

class Game
{
private:
	//�����
	Board *board;
	//�������� ����
	Algorithm* algorithm;
public:
	Game();
	//��� ����
	bool computerMove();
	//�������� ����������
	State getWinner();
	//�������� �����
	Board *getBoard() { return board; }
	//����������
	void Render(HGE *hge);
};