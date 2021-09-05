#include "enemy.h"

Enemy::Enemy(string enemyName) {
	if(enemyName == "Rat") {
		hp = 10;
		normalDmg = 3;
		name = "Rat";
		level = 1;
		killExp = 15;
	}
}
void Enemy::dealDmg(int amount) {
	hp -= amount;
	if(hp < 0) {
		hp = 0;
	}
}
int Enemy::getDmgAmount() {
	return normalDmg;
}
int Enemy::getKillExp() {
	return killExp;
}
int Enemy::getLevel() {
	return level;
}
bool Enemy::isAlive() {
	if(hp <= 0) {
		return false;
	}
	else {
		return true;
	}
}
int Enemy::getHealth() {
	return hp;
}
string Enemy::getName() {
	return name;
}
