#include "enemy.h"

Enemy::Enemy(string enemyName) {
	if(enemyName == "Rat") {
		hp = 10;
		normalDmg = 3;
		name = "Rat";
		level = 1;
		killExp = 15;
	}
	else if(enemyName == "Troll") {
		hp = 15;
		normalDmg = 2;
		name = "Troll";
		level = 2;
		killExp = 20;

	}
	else if(enemyName == "Wolf") {
		hp = 10;
		normalDmg = 4;
		name = "Wolf";
		level = 3;
		killExp = 30;
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
