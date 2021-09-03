#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Player {
	public:
		Player();
		int getLevel();
		int getExp();
		int getStrength();
		int getIntelligence();
		int getSpeech();
		int getMemory();
		int getMoney();
		int getHealth();

		void setPlayerName(string input);
		void addExp(int amount);
		void addMoney(int amount);
		void removeMoney(int amount);
		void setMoney(int amount);
		void doDmg(int amount);
		void drainStamina(int amount);
		int posX;
		int posY;
	private:
		string playerName;
		int level;
		int exp;
		int strength;
		int intelligence;
		int speech;
		int memory;
		int money;
		int hp;
		int stamina;
		void updateLevel();
		bool isBroke(int cost);


};
