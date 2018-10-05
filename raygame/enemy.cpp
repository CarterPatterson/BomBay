#include"enemy.h"

void Enemy::moveAround() {
	int dir = GetRandomValue(0, 7);

	switch (dir) {
	case 0: posX += 100; break;
	case 1: posX -= 100; break;
	case 2: posY += 100; break;
	case 3: posY -= 100; break;
	}
}