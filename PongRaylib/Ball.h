#pragma once

#include <raylib.h>

class Ball
{
private:
	int screenWidth = 0, screenHeight = 0;
	float radius = 0.0f;
	Color color = WHITE;

public:
	int coordX = 0, coordY = 0;
	int speedX = 0, speedY = 0;

	Ball();
	Ball(const int screenWidth, const int screenHeight,
		 const int coordX, const int coordY,
		 const int speedX, const int speedY,
		 const float radius, Color color);
	~Ball();

	void Draw();
	void Update();
};