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
	private:
		int hp;
		int normalDmg;
		string name;
};
