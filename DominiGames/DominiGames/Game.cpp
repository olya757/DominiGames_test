#include "Game.h"


Game::Game() {
	this->board= new Board();
}

void Game::Render(HGE *hge) {
	board->draw(hge);
}

bool Game::computerMove() {
	return board->computerMove();
}

State Game::getWinner() {
	return board->getGameState();
}