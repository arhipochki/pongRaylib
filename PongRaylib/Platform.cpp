#include "Platform.h"

Platform::Platform(const int coordX, const int coordY, const int width, const int height, Color color, bool cpuMode = false)
	: coordX(coordX), coordY(coordY), width(width), height(height), color(color), cpuMode(cpuMode)
{
}

Platform::~Platform()
{
}

void Platform::Update()
{
	if (cpuMode)
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
		if (IsKeyDown(KEY_W))
		{
			coordY -= speedY;
		}
		else if (IsKeyDown(KEY_S))
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
	DrawRectangle(coordX, coordY, width, height, color);
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