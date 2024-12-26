#pragma once

#include <iostream>
#include <raylib.h>
#include "Ball.h"

class Game
{
private:
	int screenWidth  = 0;
	int screenHeight = 0;
	const char* title = nullptr;

	Ball *ball = nullptr;

	int boardWidth = 30;
	int boardHeight = 120;
public:
	Game(const int width, const int height, const char* title);
	~Game();

	void Run();
	void DrawPlatform(int coordX, int coordY, Color color);
};