#pragma once

#include <iostream>
#include <raylib.h>

class Game
{
private:
	int width = 0;
	int height = 0;
	const char* title = nullptr;

	float ballRadius = 20.0f;

	int boardWidth = 30;
	int boardHeight = 120;

public:
	Game(const int width, const int height, const char* title);
	~Game();

	void Run();
	void DrawBall();
	void DrawPlatform(int coordX, int coordY, Color color);
};