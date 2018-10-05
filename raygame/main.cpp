/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "bomb.h"
#include "player.h"
#include "tile.h"
#include <string>
#include <iostream>
#include "enemy.h"

int endGame(bool won) {
	bool waiting = true;
	BeginDrawing();
	ClearBackground(SKYBLUE);
	DrawText("Game Over\nPress Space", 250, 500, 70, RED);
	EndDrawing();
	while (waiting) {
		std::cout << "Looping\n";
		if (IsKeyDown(KEY_SPACE)) {
			std::cout << "Key Press Detect\n";
			waiting = false;
		}
	}
	return 0;
}

Color randColor() {
	int color = GetRandomValue(0, 8);

	switch (color) {
	case 0: return GOLD;
	case 1: return PINK;
	case 3: return RED;
	case 4: return LIME;
	case 5: return BLUE;
	case 6: return PURPLE;
	case 7: return MAGENTA;
	case 8: return ORANGE;
	}
}

void seek(Vector2& vec, Vector2 vecSeek, float speed) {
	if (vec.x > vecSeek.x)
		vec.x-=speed;
	if (vec.y > vecSeek.y)
		vec.y-=speed;
	if (vec.x < vecSeek.x)
		vec.x+=speed;
	if (vec.y < vecSeek.y)
		vec.y+=speed;
}


int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1000;
	int screenHeight = 1000;
	const int maxBombs = 100;
	int startingBombs = 3;
	bool gameDone = false;


	InitWindow(screenWidth, screenHeight, "raylib - BomBay");

	Texture2D shipImage = LoadTexture("ship.png");
	Vector2 start = { 950, 950 };
	Tile board[10][10];
	int playerPosX, playerPosY;
	Bomb bombs[maxBombs];
	Player player;
	Enemy enemies[3];
	player.setPlayerPosition(start);
	player.setBombs(startingBombs);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j].setPosition({50.0f+i*100, 50.0f+j*100});
			board[i][j].setType(GetRandomValue(0,100));
		}
	}

	for (int i = 0; i < startingBombs; i++) {
		bombs[i].setState(1);
	}
	
    SetTargetFPS(60);       // Set target frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
			// Update
			//----------------------------------------------------------------------------------\
		
		gameDone = true;

		if (!player.getPlayerAlive()) {
			std::cout << "DEAD" << std::endl;
			return endGame(false);
			return 0;
		}
			playerPosX = (player.getPlayerPosition().x - 50) / 100;
			playerPosY = (player.getPlayerPosition().y - 50) / 100;


			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (board[i][j].getType() > 78) {
						gameDone = false;
						break;
					}
				}
			}

			if (gameDone) {
				endGame(true);
			}

			if (player.getPlayerPosition().x < screenWidth - 50 && board[playerPosX + 1][playerPosY].getType() < 79) {
				if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) player.movePlayer(1, 0);
			}
			if (player.getPlayerPosition().x > 0 + 50 && board[playerPosX - 1][playerPosY].getType() < 79) {
				if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) player.movePlayer(-1, 0);
			}
			if (player.getPlayerPosition().y > 0 + 50 && board[playerPosX][playerPosY - 1].getType() < 79) {
				if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) player.movePlayer(0, -1);
			}
			if (player.getPlayerPosition().y < screenHeight - 50 && board[playerPosX][playerPosY + 1].getType() < 79) {
				if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) player.movePlayer(0, 1);
			}
			if (player.getBombs() > 0) {
				if (IsKeyPressed(KEY_SPACE)) {
					player.placeBomb(bombs);
					board[playerPosX][playerPosY].setType(101);
					board[playerPosX][playerPosY].setTimer(180);
				}
			}

			for (int i = 0; i < maxBombs; i++) {
				if (bombs[i].getState() >= 2) {
					bombs[i].countdown();
					if (bombs[i].getState() == 1) {
						player.addBombs(1);
					}
				}
			}

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (board[i][j].getType() == 102) {
						for (int k = 0; k < player.radius; k++) {
							if (i + k < 10)
								board[i + k][j].setType(103);
							if (i - k > -1)
								board[i - k][j].setType(103);
							if (j + k < 10)
								board[i][j + k].setType(103);
							if (j - k > -1)
								board[i][j - k].setType(103);
						}
					}
					if (board[playerPosX][playerPosY].getType() == 103)
						player.setPlayerAlive(false);
					if (board[i][j].getType() == 102 || board[i][j].getType() == 103) {
						board[i][j].setType(0);
					}
					if (board[i][j].getType() == 101) {
						board[i][j].timer--;
						std::cout << board[i][j].timer << std::endl;
						if (board[i][j].timer <= 0) {
							board[i][j].setType(102);
						}
					}
				}
			}

			if (board[playerPosX][playerPosY].getType() > 75 && board[playerPosX][playerPosY].getType() < 79) {
				board[playerPosX][playerPosY].setType(0);
				player.iterateRadius();
			}


			//----------------------------------------------------------------------------------
			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();

			ClearBackground(SKYBLUE);


			for (int i = 0; i < 10; i++) {
				DrawLine(i * 100, 0, i * 100, screenHeight, BLACK);
				DrawLine(0, i * 100, screenWidth, i * 100, BLACK);
			}

			DrawTextureV(shipImage, { player.getPlayerPosition().x - 30, player.getPlayerPosition().y - 48 }, WHITE);



			for (int i = 0; i < maxBombs; i++) {
				if (bombs[i].getState() == 2) {
					DrawCircleV(bombs[i].getPosition(), 30, GRAY);
				}
			}

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					switch (board[i][j].getType()) {
					default: break;
					case 76:
					case 77:
					case 78: DrawCircleV(board[i][j].getPosition(), 30, GOLD);
						break;
					case 79:
					case 80:
					case 81:
					case 82:
					case 83:
					case 84:
					case 85:
					case 86:
					case 87:
					case 88:
					case 89:
					case 90:
					case 91:
					case 92:
					case 93:
					case 94:
					case 95:
					case 96:
					case 97:
					case 98:
					case 99:
					case 100: DrawCircleV(board[i][j].getPosition(), 49, DARKGRAY);
						break;
					}
				}
			}
			DrawText(("Bombs: " + (std::to_string(player.getBombs()))).c_str(), 30, 30, 50, BLACK);
			DrawText("Clear the Rocks!", 30, 75, 50, GOLD);

			EndDrawing();
			//----------------------------------------------------------------------------------
		}

		// De-Initialization
		//--------------------------------------------------------------------------------------
		CloseWindow();        // Close window and OpenGL context
		//--------------------------------------------------------------------------------------

	return 0;
}

