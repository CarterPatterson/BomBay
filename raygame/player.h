#pragma once
#include "raylib.h"

class Player {
private:
	Vector2 position;
	int bombs;
	bool playerAlive;

public:
	int radius = 2;
	void setBombs(int);
	void addBombs(int);
	int getBombs();
	void setPlayerPosition(Vector2);
	Vector2 getPlayerPosition();
	void placeBomb(class Bomb*);
	void movePlayer(int, int);
	void iterateRadius();
	void setPlayerAlive(bool);
	bool getPlayerAlive();
};