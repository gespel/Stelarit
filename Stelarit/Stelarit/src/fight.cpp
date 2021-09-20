#include "fight.h"
#include "console.h"

Fight::Fight(string event, Player *p) {
	system("clear");
	if(event == "forrestMove") {
		srand(time(NULL));
		int decider = rand() % 3 + 1;

		if(decider == 1) {
			Enemy a("Rat");
			fightingLoop(p, &a);
		}
		else if(decider == 2) {
			Enemy b("Troll");
			fightingLoop(p, &b);
		}
		else {
			Enemy c("Wolf");
			fightingLoop(p, &c);
		}
	}
}

void Fight::fightingLoop(Player *p, Enemy *e) {
	bool fight = true;
	string input;
	cout << "===================" << endl << "A fight against " << e->getName() << " started!" << endl << "===================" << endl << endl;
	while(fight == true) {
		cout << "===== FIGHT =====" << endl;
		cout << "Your Health: " << p->getHealth() << " Your Level: " << p->getLevel() << endl;
		cout << "Enemys Health: " << e->getHealth() << " Enemys Level: " << e->getLevel() << endl;
		cout << "Menu:" << endl << "========================" << endl << "[a] Attack" << endl << "[s] Spell" << endl << "[d] Dodge" << endl << "=======================" << endl;
		cout << "fight> ";
		cin >> input;
		system("clear");
		if(input == "a") {
			int dmg = p->getNormalDmg();
			e->dealDmg(dmg);
			cout << "=======================" << endl;
			cout << "You dealt " << dmg << " damage!" << endl;
		}
		else if(input == "s") {
			p->spellBookDialog();
			int dmg = p->getSpellDmg();
			e->dealDmg(dmg);
			cout << "=======================" << endl;
			cout << "You casted a spell and did " << dmg << " damage!" << endl;

		}
		if(e->getHealth() <= 0) {
			system("clear");
			cout << "YOU WON! YOU EARNED " << e->getKillExp() << " EXP." << endl;
			p->addExp(e->getKillExp());
			p->restoreHealth();
			fight = false;
			Console::pause();
		}
		else {
			int dmg = e->getDmgAmount();
			cout << "" << e->getName() << " attacks with " << e->getDmgAmount() << " damage!" << endl;
			p->doDmg(dmg);
			cout << "=======================" << endl << endl;
		}
	}
}
