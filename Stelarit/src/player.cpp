#include "player.h"

Player::Player() {
	hp = 10;
	maxHp = 10;
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

void Player::restoreHealth() {
	hp = maxHp;
}
int Player::getHealth() {
	return hp;
}
int Player::getMaxHealth() {
	return maxHp;
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
		maxHp = 10 + (level-1)*5;
		hp = 10 + (level-1)*5;
		system("clear");
		cout << "=================" << endl;
		cout << "=== LEVEL UP! ===" << endl;
		cout << "=================" << endl;
		cout << "Choose the skill you want to improve by 1 point!" << endl;
		cout << "Strength => [s]" << endl << "Intelligence => [i]" << endl << "Speech => [p]" << endl << "Memory => [m]" << endl;
		cout << endl << "input> ";
		bool leveled = false;
		while(leveled == false) {
			string input;
			cin >> input;
			if(input == "s") {
				strength++;
				leveled = true;
			}
			else if(input == "i") {
				intelligence++;
				leveled = true;
			}
			else if(input == "p") {
				speech++;
				leveled = true;
			}
			else if(input == "m") {
				memory++;
				leveled = true;
			}
			else {
				cout << "This is not a skill!" << endl;
			}
		}

		updateLevel();
	}
	
}
void Player::showCharacterMenu() {
	system("clear");
	cout << "===== Character =====" << endl;
	cout << "\tName:\t\t" << playerName << endl;
	cout << "\tLevel:\t\t" << level << endl;
	cout << "\tExperience:\t" << exp << endl;
	cout << "\tHealth:\t\t" << hp << " / " << maxHp << endl;
	cout << "\tMoney:\t\t" << money << endl;
	cout << "=== Skills ===" << endl;
	cout << "\tStrength:\t" << strength << endl;
	cout << "\tIntelligence:\t" << intelligence << endl;
	cout << "\tSpeech:\t\t" << speech << endl;
	cout << "\tMemory:\t\t" << memory << endl;
	
	cout << endl << "=== Press a key to leave the menu ===" << endl;
	system("stty raw");
	getchar();
	system("stty cooked");

}
int Player::getNormalDmg() {
	return 3 + ((strength * strength)/10);
}
int Player::getSpellDmg() {
	return ((intelligence * intelligence * intelligence)/100);
}
