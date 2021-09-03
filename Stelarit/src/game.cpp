#include <iostream>
#include "map.h"
#include "stdlib.h"

using namespace std;

int main() {
	Player me;
	Map haupt;
	string input;
	system("clear");
	while(1) {
		haupt.printMap(haupt.stelarit, &me);
		cout << endl << "Level: " << me.getLevel() << " Exp: " << me.getExp() << endl;
		cout << endl << "input> ";
		cin >> input;
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
		system("clear");
	}
}
