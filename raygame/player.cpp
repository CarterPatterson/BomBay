#include"player.h"
#include"bomb.h"

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
		bombs--;
		for (int i = 0; i < bombs; i++) {
			if (bombArr[i].getState() == 1) {
				bombArr[i].setState(2);
				bombArr[i].setPosition(position);
				bombArr[i].setTimer(240);
				break;
			}
		}
	}
}

void Player::movePlayer(int x, int y) {
	position.x += x*100;
	position.y += y*100;
}