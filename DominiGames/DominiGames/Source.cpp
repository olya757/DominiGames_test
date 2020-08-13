#include <hge.h>
#include "Game.h"
#include "MouseManager.h"

HGE *hge = 0;
Game game;
MouseManager *mouseManager;
bool userTurn = true;

bool FrameFunc()
{
	hge->Gfx_BeginScene();
	
	if (userTurn){
		if (mouseManager->pawnMoved()) {
			userTurn = false;
		}
	}
	else {
		if (game.computerMove()) {
			auto winner = game.getWinner();
			
			return true;
		}
		userTurn = true;
	}

	game.Render(hge);
	hge->Gfx_EndScene();

	return false;
}
int main(void)
{
	hge = hgeCreate(HGE_VERSION);

	game = Game();
	mouseManager = new MouseManager(hge, game.getBoard());

	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_HIDEMOUSE, false);
	hge->System_SetState(HGE_TITLE,
		"DominiGames");

	hge->System_Initiate();
	hge->System_Start();

	hge->System_Shutdown();
	hge->Release();
    return 0;
}