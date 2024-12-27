#include "Ball.h"
#include <iostream>

Ball::Ball()
{

}

Ball::Ball(const int coordX, const int coordY, 
		   const int speedX, const int speedY,
		   const float radius, Color color)
	: coordX(coordX), coordY(coordY),
	  speedX(speedX), speedY(speedY),
	  radius(radius), color(color)
{
}

Ball::~Ball()
{
}

void Ball::Draw()
{
	DrawCircle(coordX, coordY, radius, color);
}

void Ball::Update()
{
	coordX += speedX;
	coordY += speedY;

	if (IsGoal().x)
	{
		coordX = GetScreenWidth() / 2;
		coordY = GetScreenHeight() / 2;
		
		speedX *= -1;
	}

	if (coordY + radius >= GetScreenHeight() || coordY - radius <= 0)
	{
		speedY *= -1;
	}
}

void Ball::CheckPlatformCollision(Platform* platform)
{
	Vector2 center = { coordX, coordY };
	Rectangle rec = { platform->GetCoordX(), platform->GetCoordY(), platform->GetWidth(), platform->GetHeight() };
	if (CheckCollisionCircleRec(center, radius, rec))
	{
		speedX *= -1;
	}
}

Vector2 Ball::IsGoal()
{
	if (coordX >= GetScreenWidth())
	{
		result.x = 1;
		result.y = 1;
	}
	else if (coordX <= 0)
	{
		result.x = 1;
		result.y = -1;
	}

	return result;
}

void Ball::ResetResult()
{
	result = Vector2{ 0, 0 };
}