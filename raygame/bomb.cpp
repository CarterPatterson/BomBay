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