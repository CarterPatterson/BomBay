#include"player.h"
#include "bomb.h"

void Player::setBombs(int count) {
	bombs = count;
}
void Player::addBombs(int count) {
	bombs += count;
}
int Player::getBombs() {
	return bombs;
}

Vector2 Player::getPlayerPosition() {
	return position;
}

void Player::setPlayerPosition(Vector2 pos) {
	position = pos;
}

void Player::placeBomb(Bomb* bombArr) {
	if (bombs > 0) {
		for (int i = 0; i < 3; i++) {
			if (bombArr[i].getState() == 1) {
				bombArr[i].setState(2);
				bombArr[i].setPosition(position);
				bombArr[i].setExplosionRadius(radius);
				bombArr[i].setTimer(180);
				bombs--;
				break;
			}
		}
	}
}

void Player::movePlayer(int x, int y) {
	position.x += x*100;
	position.y += y*100;
}