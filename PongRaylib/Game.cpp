#include "Game.h"

Game::Game(const int width, const int height, const char* title)
{
	this->width = width;
	this->height = height;
	this->title = title;

	SetTargetFPS(60);

	InitWindow(width, height, title);
}

Game::~Game()
{
	CloseWindow();
}

void Game::Run()
{
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		DrawBall();

		// Left player
		DrawPlatform(0, height / 2 - boardHeight / 2, GREEN);

		// Right player
		DrawPlatform(width - 1 - boardWidth, height / 2 - boardHeight / 2, ORANGE);

		EndDrawing();
	}
}

void Game::DrawBall()
{
	DrawCircle(width / 2, height / 2, ballRadius, WHITE);
}

void Game::DrawPlatform(int coordX, int coordY, Color color)
{
	DrawRectangle(coordX, coordY, boardWidth, boardHeight, color);
}