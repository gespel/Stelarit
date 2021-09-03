#include "player.h"

Player::Player() {
	hp = 10;
	stamina = 20;
	level = 1;
	exp = 0;
	strength = 5;
	intelligence = 5;
	speech = 5;
	memory = 5;
	money = 0;
	playerName = "Unnamed";
	posX = 1;
	posY = 1;
}


int Player::getHealth() {
	return hp;
}
int Player::getLevel() {
	return level;
}
int Player::getExp() {
	return exp;
}
int Player::getStrength() {
	return strength;
}
int Player::getIntelligence() {
	return intelligence;
}
int Player::getSpeech() {
	return speech;
}
int Player::getMemory() {
	return memory;
}
int Player::getMoney() {
	return money;
}

void Player::setPlayerName(string input) {
	playerName = input;
}
void Player::addExp(int amount) {
	exp += amount;
	updateLevel();
}
void Player::addMoney(int amount) {
	money += amount;
}
void Player::removeMoney(int amount) {
	money -= amount;
}
void Player::setMoney(int amount) {
	money = amount;
}
void Player::doDmg(int amount) {
	hp -= amount;
	if(hp <= 0) {
		hp = 0;
		//Tot!
	}
}
void Player::drainStamina(int amount) {
	stamina -= amount;
	if(stamina < 0) {
		stamina = 0;
	}
}

void Player::updateLevel() {
	if(exp >= level*100) {
		exp -= level*100;
		level++;
		updateLevel();
	}
	
}	
