#include "Game.h"

Game::Game(const int screenWidth, const int screenHeight, const char* title)
	: screenWidth(screenWidth), screenHeight(screenHeight), title(title)
{
	InitWindow(screenWidth, screenHeight, title);
	SetTargetFPS(60);

	ball = new Ball(screenWidth, screenHeight, screenWidth / 2, screenHeight / 2, 5, 5, 20.0f, BLUE);
}

Game::~Game()
{
	CloseWindow();
	
	title = nullptr;

	delete ball;
}

void Game::Run()
{
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		// Update positions
		ball->Update();

		// Main ball
		ball->Draw();

		// Left player
		DrawPlatform(0, screenHeight / 2 - boardHeight / 2, GREEN);

		// Right player
		DrawPlatform(screenWidth - 1 - boardWidth, screenHeight / 2 - boardHeight / 2, ORANGE);

		EndDrawing();
	}
}

void Game::DrawPlatform(int coordX, int coordY, Color color)
{
	DrawRectangle(coordX, coordY, boardWidth, boardHeight, color);
}