#include "Game.h"

const int WIDTH = 1280;
const int HEIGHT = 720;
const char* TITLE = "Pong game";

int main()
{
	Game game(WIDTH, HEIGHT, TITLE);

	game.Run();

	return 0;
}