#include "fight.h"

Fight::Fight(string event, Player *p) {
	system("clear");
	if(event == "forrestMove") {
		Enemy e("Rat");
		fightingLoop(p, &e);
	}
}

void Fight::fightingLoop(Player *p, Enemy *e) {
	bool fight = true;
	string input;
	cout << "A fight against " << e->getName() << " started!" << endl; 
	while(fight == true) {
		cout << "Your Health: " << p->getHealth() << " Your Level: " << p->getLevel() << endl;
		cout << "Enemys Health: " << e->getHealth() << endl;
		cout << "fight> ";
		cin >> input;
		if(input == "a") {
			e->dealDmg(p->getStrength());
		}
		if(e->getHealth() <= 0) {
			cout << "You won! You earned 50 Exp." << endl;
			cin.clear();
			fflush(stdin);
			if(cin.get() == '\n') {
				p->addExp(50);
				fight = false;
			}
		}
	}	
}
