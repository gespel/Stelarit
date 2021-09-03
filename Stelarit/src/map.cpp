#include "map.h"
#include "fight.h"

using namespace std;

void Map::printMap(string map[8][8], Player *p) {
	for(int y = 7; y >= 0; y--) {
		for(int x = 0; x < 8; x++) {
			if(x == p->posX && y == p->posY) {
				cout << "p";
			}
			else {
				cout << map[x][y];
			}
		}
		cout << endl;
	}
	cout << currentPlayerTile << endl;
}
void Map::moveNorth(Player *p) {
	if(((p->posY)+1) < 8) {
		p->posY += 1;
		checkCurrentTile(p);
	}
}
void Map::moveSouth(Player *p) {
	if(((p->posY)-1) >= 0) {
		p->posY -= 1;
		checkCurrentTile(p);	
	}
}
void Map::moveEast(Player *p) {
	if(((p->posX)+1) < 8) {
		p->posX += 1;
		checkCurrentTile(p);
	}
}
void Map::moveWest(Player *p) {
	if(((p->posX)-1) >= 0) {
		p->posX -= 1;
		checkCurrentTile(p);
	}
}
void Map::checkCurrentTile(Player *p) {
	if(stelarit[p->posX][p->posY] == "-") {
		currentPlayerTile = "Grass";
	}
	else if(stelarit[p->posX][p->posY] == "|") {
		currentPlayerTile = "Forrest";
		Fight a("forrestMove", p);
	}
	else if(stelarit[p->posX][p->posY] == "~") {
		currentPlayerTile = "Water";
	}
}
