#pragma once
#include <iostream>
#include <string.h>
#include "console.h"

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

		void restoreHealth();
		int getMaxHealth();
		void setPlayerName(string input);
		void addExp(int amount);
		void addMoney(int amount);
		void removeMoney(int amount);
		void setMoney(int amount);
		void doDmg(int amount);
		void drainStamina(int amount);
		void showCharacterMenu();
		int posX;
		int posY;
		int getNormalDmg();
		int getSpellDmg();
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
		int maxHp;
		int stamina;
		void updateLevel();
		bool isBroke(int cost);


};
