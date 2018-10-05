#pragma once
#include "raylib.h"

class Player {
private:
	Vector2 position;
	int bombs;
	int radius = 5;

public:
	void setBombs(int);
	void addBombs(int);
	int getBombs();
	void setPlayerPosition(Vector2);
	Vector2 getPlayerPosition();
	void placeBomb(class Bomb*);
	void movePlayer(int, int);
};