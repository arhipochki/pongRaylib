#include "Game.h"

#include <string>

Game::Game(const int screenWidth, const int screenHeight, const char* title)
	: screenWidth(screenWidth), screenHeight(screenHeight), title(title)
{
	InitWindow(screenWidth, screenHeight, title);
	SetTargetFPS(60);

	ball = new Ball(screenWidth / 2, screenHeight / 2, 7, 7, 20.0f, GOLD);

	leftPlatform = new Platform(0, screenHeight / 2 - platformHeight / 2, platformWidth, platformHeight, WHITE, false);
	rightPlatform = new Platform(screenWidth - 1 - platformWidth, screenHeight / 2 - platformHeight / 2, platformWidth, platformHeight, WHITE, true);
}

Game::~Game()
{
	CloseWindow();
	
	title = nullptr;

	delete ball, leftPlatform, rightPlatform;
}

void Game::Run()
{
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(backgroundColor);

		// Update objects
		ball->Update();
		leftPlatform->Update();
		rightPlatform->Update();

		// Check for the ball collision
		ball->CheckPlatformCollision(leftPlatform);
		ball->CheckPlatformCollision(rightPlatform);

		// Check if the ball left the screen
		if (ball->IsGoal().x)
		{
			if (ball->IsGoal().y == -1)
				rightPlatform->IncScore();
			else
				leftPlatform->IncScore();

			ball->ResetResult();
		}

		// Draw objects
		// Screen separator
		DrawRectangle(0, 0, screenWidth / 2, screenHeight, Color{ 17, 139, 209, 255 });
		DrawCircle(screenWidth / 2, screenHeight / 2, 100, LIGHTGRAY);
		DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
		ball->Draw();
		leftPlatform->Draw();
		rightPlatform->Draw();

		// Draw text
		DrawText(std::to_string(leftPlatform->GetScore()).c_str(), screenWidth / 4 - fontSize / 2, 0, fontSize, WHITE);
		DrawText(std::to_string(rightPlatform->GetScore()).c_str(), screenWidth * 3 / 4 - fontSize / 2, 0, fontSize, WHITE);

		EndDrawing();
	}
}