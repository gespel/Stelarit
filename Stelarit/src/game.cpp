#include <iostream>
#include "map.h"
#include "stdlib.h"
#include <termios.h>

using namespace std;

int main() {
	struct termios old_tio, new_tio;
	//unsigned char input;
	Player me;
	Map haupt("stelarit.map");
	haupt.checkCurrentTile(&me, me.posX, me.posY);
	string input;
	system("clear");
	while(1) {
		system("clear");
		cout << "===== MAP =====" << endl << endl;
		haupt.printMap(&me);
		cout << endl << "Level: " << me.getLevel() << " Exp: " << me.getExp() << endl;
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
	}
}
