#pragma once

#include <raylib.h>

#include "Platform.h"

class Ball
{
private:
	int coordX = 0, coordY = 0;
	int speedX = 0, speedY = 0;

	float radius = 0.0f;
	Color color = WHITE;

	// result.x - is a status, does ball left the screen of not
	// result.y - 0 - none, -1 - left side, 1 - right side
	Vector2 result = { 0, 0 };

public:
	
	Ball();
	Ball(const int coordX, const int coordY,
		 const int speedX, const int speedY,
		 const float radius, Color color);
	~Ball();

	void Draw();
	void Update();
	void CheckPlatformCollision(Platform* platform);
	void ResetResult();

	Vector2 IsGoal();
};