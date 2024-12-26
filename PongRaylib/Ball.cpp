#include <iostream>
#include "Ball.h"

Ball::Ball()
{

}

Ball::Ball(const int screenWidth, const int screenHeight,
		   const int coordX, const int coordY, 
		   const int speedX, const int speedY,
		   const float radius, Color color)
	: screenWidth(screenWidth), screenHeight(screenHeight), 
	  coordX(coordX), coordY(coordY),
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

	if (coordX + radius >= screenWidth || coordX - radius <= 0)
	{
		speedX *= -1;
	}

	if (coordY + radius >= screenHeight || coordY - radius <= 0)
	{
		speedY *= -1;
	}
}