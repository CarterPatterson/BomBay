#pragma once
#include"raylib.h"

class Enemy {
public:
	int posX;
	int posY;
	bool isDead = false;

	void moveAround();
};