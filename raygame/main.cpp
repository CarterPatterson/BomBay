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
#include <string>

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

    InitWindow(screenWidth, screenHeight, "raylib - BomBay");

	Vector2 start = {950, 950};
	Bomb bombs[3];
	Player player;
	player.setPlayerPosition(start);
	player.setBombs(3);
	bombs[0].setState(1);

    SetTargetFPS(60);       // Set target frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------\
		
		if (player.getPlayerPosition().x < screenWidth - 50) {
			if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) player.movePlayer(1, 0);
		}
		if (player.getPlayerPosition().x > 0 + 50) {
			if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) player.movePlayer(-1, 0);
		}
		if (player.getPlayerPosition().y > 0 + 50) {
			if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) player.movePlayer(0, -1);
		}
		if (player.getPlayerPosition().y < screenHeight - 50) {
			if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_D)) player.movePlayer(0, 1);
		}
		if (player.getBombs() > 0) {
			if (IsKeyPressed(KEY_SPACE)) player.placeBomb(bombs);
		}

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(SKYBLUE);


			for (int i = 0; i < 10; i++) {
				DrawLine(i*100, 0, i*100, screenHeight, BLACK);
				DrawLine(0, i*100, screenWidth, i*100, BLACK);
			}

			DrawCircleV(player.getPlayerPosition(), 49, PURPLE);
			DrawText(("Bombs: " + (std::to_string(player.getBombs()))).c_str(), 30, 30, 50, BLACK);

			for (int i = 0; i < 3; i++) {
				DrawCircleV(bombs[i].getPosition(), 30, GRAY);
			}


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}