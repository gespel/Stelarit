#include <iostream>
#include "map.h"
#include "stdlib.h"
#include <termios.h>

using namespace std;

int main() {
	Player me;
	Map haupt("stelarit.map");
	haupt.checkCurrentTile(&me, me.posX, me.posY);
	string input;
	string nameIn;
	system("clear");
	cout << "Enter the character name: ";
	cin >> nameIn;
	me.setPlayerName(nameIn);
	//me.addToSpellbook(Spell(fireBolt, fire, dmg, 3));
	//me.addToSpellbook(Spell(holyHeal, holy, heal, 5));
	while(1) {
		cout << "===== MAP =====" << endl << endl;
		haupt.printMap(&me);
		cout << endl << "input> ";
		system("stty raw");
		input = getchar();
		system("stty cooked");
		if(input == "w") {
			haupt.moveNorth(&me);
		}
		else if(input == "s") {
			haupt.moveSouth(&me);
		}
		else if(input == "a") {
			haupt.moveWest(&me);
		}
		else if(input == "d") {
			haupt.moveEast(&me);
		}
		else if(input == "q") {
			system("clear");
			return 0;
		}
		else if(input == "c") {
			me.showCharacterMenu();
		}
		else {
			cout << "Not a valid key!" << endl;
		}
		system("clear");
	}
}
