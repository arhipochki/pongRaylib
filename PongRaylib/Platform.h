#pragma once

#include <raylib.h>

class Platform
{
private:
	int score = 0;
	int coordX = 0, coordY = 0;
	int width = 0, height = 0;
	int speedY = 5;
	
	// 0 - leftPlayer, 1 - rightPlayer, 2 - computer
	int cpuMode = 0;
	int keyMoveUp = KEY_W;
	int keyMoveDown = KEY_S;

	Color color = WHITE;

public:
	Platform(const int coordX, const int coordY, const int width, const int height, Color color, int cpuMode);
	~Platform();

	void Update();
	void Draw();

	int GetHeight();
	int GetWidth();
	int GetCoordX();
	int GetCoordY();

	int GetScore();
	void IncScore();
};