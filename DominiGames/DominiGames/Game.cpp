#include "Game.h"
#include "WaveAlgorithm.h"

Game::Game() {
	this->board= new Board();
	algorithm = new WaveAlgorithm(board->getBoardCells());
}

void Game::Render(HGE *hge) {
	board->draw(hge);
}

bool Game::computerMove() {
	return board->computerMove(algorithm);
}

State Game::getWinner() {
	return board->getGameState();
}