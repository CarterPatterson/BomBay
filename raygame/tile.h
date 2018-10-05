#pragma once
#include"raylib.h"


class Tile {
private:
	int type;
	Vector2 position;
public:
	int timer;
	void setType(int);
	int getType();
	void setPosition(Vector2);
	Vector2 getPosition();
	void setTimer(int);
};