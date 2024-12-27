#include "Platform.h"

Platform::Platform(const int coordX, const int coordY, const int width, const int height, Color color, int cpuMode)
	: coordX(coordX), coordY(coordY), width(width), height(height), color(color), cpuMode(cpuMode)
{
	if (cpuMode == 1)
	{
		keyMoveUp = KEY_UP;
		keyMoveDown = KEY_DOWN;
	}
}

Platform::~Platform()
{
}

void Platform::Update()
{
	if (cpuMode == 2)
	{
		coordY += speedY;

		if (coordY + height > GetScreenHeight())
		{
			coordY = GetScreenHeight() - height;
			speedY *= -1;
		}

		if (coordY <= 0)
		{
			coordY = 0;
			speedY *= -1;
		}
	}
	else
	{
		if (IsKeyDown(keyMoveUp))
		{
			coordY -= speedY;
		}
		else if (IsKeyDown(keyMoveDown))
		{
			coordY += speedY;
		}

		if (coordY + height > GetScreenHeight())
		{
			coordY = GetScreenHeight() - height;
		}

		if (coordY <= 0)
		{
			coordY = 0;
		}
	}
}

void Platform::Draw()
{
	DrawRectangleRounded(Rectangle{ static_cast<float>(coordX), static_cast<float>(coordY), static_cast<float>(width), static_cast<float>(height) },
		0.8, 0, color);
}

int Platform::GetHeight()
{
	return height;
}

int Platform::GetWidth()
{
	return width;
}

int Platform::GetCoordX()
{
	return coordX;
}

int Platform::GetCoordY()
{
	return coordY;
}

void Platform::IncScore()
{
	score++;
}

int Platform::GetScore()
{
	return score;
}