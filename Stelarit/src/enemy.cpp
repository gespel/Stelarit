#include "enemy.h"

Enemy::Enemy(string enemyName) {
	if(enemyName == "Rat") {
		hp = 10;
		normalDmg = 3;
		name = "Rat";
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
