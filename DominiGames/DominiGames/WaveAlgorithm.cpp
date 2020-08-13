#include "WaveAlgorithm.h"
#include <queue>
using namespace std;

const int X_MOVE[] = { -1,0,1,0 };
const int Y_MOVE[] = { 0,-1,0,1 };


void WaveAlgorithm::updateBoard(BoardCell** boardCells)
{
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			busyCells[i][j] = boardCells[i][j].cellState != State::None;
		}
	}
}


Move WaveAlgorithm::getOptimalMove(BoardCell **boardCells) {
	updateBoard(boardCells);
	int min = INT_MAX;
	list<BoardCell>::iterator link;
	Move move_min;
	for (auto b = cellsList.begin(); b != cellsList.end(); b++) {
		if (hasMove((*b).position)) {
			auto move=getMoveAndRating( getWave((*b).position));
			if (move.second < min) {
				move_min = move.first;
				min = move.second;
				link = b;
			}
		}
	}
	(*link).position = move_min.to;
	return move_min;
}

WaveAlgorithm::WaveAlgorithm(BoardCell** boardCells) :Algorithm(boardCells) {
	this->boardCells = boardCells;
	this->cellsList = list<BoardCell>();
	busyCells = new bool* [BOARD_WIDTH];
	for (int i = 0; i < BOARD_WIDTH; i++) {
		busyCells[i] = new bool[BOARD_HEIGHT];
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			busyCells[i][j] = boardCells[i][j].cellState != State::None;
			if (boardCells[i][j].cellState == COMPUTER_COLOR) {
				cellsList.push_back(boardCells[i][j]);
			}
		}
	}
}

bool WaveAlgorithm::hasMove(Position start) {
	for (int i = 0; i < 4; i++) {
		Position p = { start.X + X_MOVE[i],start.Y + Y_MOVE[i] };
		if (p.X >= 0 && p.X < BOARD_WIDTH && p.Y >= 0 && p.Y < BOARD_HEIGHT && !busyCells[p.X][p.Y]) {
			return true;
		}
	}
	return false;
}

int** WaveAlgorithm::getWave(Position start) {
	int** wave = new int* [BOARD_WIDTH];
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		wave[i] = new int[BOARD_HEIGHT];
		for (int j = 0; j < BOARD_HEIGHT;j++) {
			wave[i][j] = INT_MAX;
		}
	}
	queue<pair<Position,int>> que = queue<pair<Position,int>>();
	que.push({ start,0 });
	while (!que.empty()) {
		auto first = que.front();
		wave[first.first.X][first.first.Y] = first.second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			Position p = { first.first.X + X_MOVE[i],first.first.Y + Y_MOVE[i] };
			if (p.X >= 0 && p.X < BOARD_WIDTH && p.Y >= 0 && p.Y < BOARD_HEIGHT && !busyCells[p.X][p.Y] && wave[p.X][p.Y]>first.second) {
				que.push({ p,first.second + 1 });
			}
		}
	}
	return wave;
}

pair<Move, int> WaveAlgorithm::getMoveAndRating( int** wave) {
	Position goal;
	int min=INT_MAX;
	
	int start_lvl = 0;
	while (min == INT_MAX) {
		for (int i = 0; i <= start_lvl; i++) {
			if (wave[start_lvl][i] < min) {
				min = wave[start_lvl][i];
				goal = { start_lvl,i };
			}
			if (wave[i][start_lvl] < min) {
				min = wave[i][start_lvl];
				goal = { i,start_lvl };
			}
		}
		start_lvl++;
	}
	
	if (min == INT_MAX) return {};

	int lvl = wave[goal.X][goal.Y];
	if (lvl == 0) {
		Position moveTo;
		for (int i = 0; i < 4; i++) {
			Position p = { goal.X + X_MOVE[i],goal.Y + Y_MOVE[i] };
			if (p.X >= 0 && p.X < BOARD_WIDTH && p.Y >= 0 && p.Y < BOARD_HEIGHT && wave[p.X][p.Y] == 1) {
				moveTo = { p.X,p.Y };
				break;
			}
		}
		return { {goal,moveTo} , INT_MAX-1 };
	}
	Position step = goal;
	while (lvl > 1) {
		for (int i = 0; i < 4; i++) {
			Position p = { step.X + X_MOVE[i],step.Y + Y_MOVE[i] };
			if (p.X >= 0 && p.X < BOARD_WIDTH && p.Y >= 0 && p.Y < BOARD_HEIGHT && wave[p.X][p.Y]==lvl-1) {
				step = { p.X,p.Y };
				lvl = lvl - 1;
				break;
			}
		}
	}
	Position from = {-1,-1};
	for (int i = 0; i < 4; i++) {
		Position p = { step.X + X_MOVE[i],step.Y + Y_MOVE[i] };
		if (p.X >= 0 && p.X < BOARD_WIDTH && p.Y >= 0 && p.Y < BOARD_HEIGHT && wave[p.X][p.Y] == 0) {
			from = { p.X,p.Y };
			break;
		}
	}

	if (from.X == -1) {
		int a = 2;
	}

	return { {from,step} ,min };
}