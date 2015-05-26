#include "Game1.h"


int main(int argc, char **argv)
{
	Game1 *pGame = new Game1(640, 480, false, "How does sanic go fast");
	pGame->RunGame();
	delete pGame;

	return 0;
};