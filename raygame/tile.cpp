#include"tile.h"

void Tile::setType(int count) {
	type = count;
}

int Tile::getType() {
	return type;
}

void Tile::setPosition(Vector2 pos) {
	position = pos;
}

Vector2 Tile::getPosition() {
	return position;
}

void Tile::setTimer(int count){
	timer = count;
}