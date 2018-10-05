#pragma once
#include "raylib.h"

class Bomb {
private:
	Vector2 position;
	int timer = -1;
	int explosionLifeTimer = 0;
	int explosionRadius = -1;
	int state = 0;

public:
	void setPosition(Vector2);
	Vector2 getPosition();
	void setTimer(int);
	void setExplosionRadius(int);
	int getTimer();
	int getExplosionRadius();
	void setState(int);
	int getState();
	void countdown();
	void explode();
};