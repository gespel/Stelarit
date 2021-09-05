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
	cout << "=== A fight against " << e->getName() << " started! ===" << endl; 
	while(fight == true) {
		cout << "===== FIGHT =====" << endl;
		cout << "Your Health: " << p->getHealth() << " Your Level: " << p->getLevel() << endl;
		cout << "Enemys Health: " << e->getHealth() << " Enemys Level: " << e->getLevel() << endl;
		cout << "Menu:" << endl << "========================" << endl << "[a] Attack" << endl << "[s] Spell" << endl << "[d] Dodge" << endl << "=======================" << endl;
		cout << "fight> ";
		cin >> input;
		system("clear");
		if(input == "a") {
			int dmg = p->getStrength();
			e->dealDmg(dmg);
			cout << endl << "= You dealt " << dmg << " damage! =" << endl;
		}
		if(e->getHealth() <= 0) {
			cout << "YOU WON! YOU EARNED " << e->getKillExp() << " EXP." << endl;
			p->addExp(e->getKillExp());
			p->restoreHealth();
			fight = false;
		}
		else {
			int dmg = e->getDmgAmount();
			cout << "= " << e->getName() << " attacks with " << e->getDmgAmount() << " =" << endl << endl;
			p->doDmg(dmg);
		}
	}	
}
