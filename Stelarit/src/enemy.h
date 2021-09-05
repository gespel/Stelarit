#include <iostream>
#include <string.h>

using namespace std;

class Enemy {
	public:
		Enemy(string enemyName);
		void dealDmg(int amount);
		int getDmgAmount();
		bool isAlive();
		int getHealth();
		string getName();
		int getKillExp();
		int getLevel();
	private:
		int hp;
		int level;
		int normalDmg;
		string name;
		int killExp;
};
