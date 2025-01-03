#pragma once

#include <iostream>
#include <raylib.h>

#include "Ball.h"
#include "Platform.h"

class Game
{
private:
	int screenWidth  = 0;
	int screenHeight = 0;
	
	const char* title = nullptr;

	Ball *ball = nullptr;

	Platform* leftPlatform  = nullptr;
	Platform* rightPlatform = nullptr;

	const int platformWidth = 24;
	const int platformHeight = 130;
	const int fontSize = 60;

	const Color backgroundColor = Color{ 17, 174, 209, 255 };
public:
	Game(const int width, const int height, const char* title);
	~Game();

	void Run();
};