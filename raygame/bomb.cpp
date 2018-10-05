#include "bomb.h"

void Bomb::setPosition(Vector2 pos) {
	position = pos;
}

Vector2 Bomb::getPosition() {
	return position;
}

void Bomb::setTimer(int time) {
	timer = time;
}

void Bomb::setExplosionRadius(int radius) {
	explosionRadius = radius;
}

int Bomb::getTimer() {
	return timer;
}

int Bomb::getExplosionRadius() {
	return explosionRadius;
}

void Bomb::setState(int count) {
	state = count;
}

int Bomb::getState() {
	return state;
}

void Bomb::countdown() {
	if (timer <= 0) {
		explode();
	}
	timer--;
}

void Bomb::explode() {
	state = 3;
	DrawCircleV(position, 49, RED);
	for (int i = 0; i < explosionRadius; i++) {
		DrawCircleV({ position.x + i * 100, position.y }, (49 - 5) / (i + 1), RED);
		DrawCircleV({ position.x - i * 100, position.y }, (49 - 5) / (i + 1), RED);
		DrawCircleV({ position.x, position.y - i * 100 }, (49 - 5) / (i + 1), RED);
		DrawCircleV({ position.x, position.y + i * 100 }, (49 - 5) / (i + 1), RED);
	}
	explosionLifeTimer++;
	if (explosionLifeTimer >= 50) {
		state = 1;
		explosionLifeTimer = 0;
	}
}