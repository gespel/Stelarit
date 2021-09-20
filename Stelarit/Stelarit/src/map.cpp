#include "map.h"
#include "fight.h"

using namespace std;

Map::Map(string mapName) {
	string line;
	int lineNr = 0;
	ifstream file(mapName);
	if(file.is_open()) {
		while(getline(file,line)) {
			for(int i = 0; i < line.size(); i++) {
				map[i][lineNr] = line[i];
			}
			lineNr++;
		}
	}

}

void Map::printMap(Player *p) {
	for(int y = 0; y < 16; y++) {
		for(int x = 0; x < 32; x++) {
			if(x == p->posX && y == p->posY) {
				cout << "p";
			}
			else {
				cout << map[x][y];
			}
		}
		cout << endl;
	}
	cout << endl << "Current tile: " << currentPlayerTile << endl;
}
void Map::moveSouth(Player *p) {
	if(checkCurrentTile(p, p->posX, p->posY + 1) == true) {
		p->posY += 1;
	}
}
void Map::moveNorth(Player *p) {
	if(checkCurrentTile(p, p->posX, p->posY - 1) == true) {
		p->posY -= 1;
	}
}
void Map::moveEast(Player *p) {
	if(checkCurrentTile(p, p->posX + 1, p->posY) == true) {
		p->posX += 1;
	}
}
void Map::moveWest(Player *p) {
	if(checkCurrentTile(p, p->posX - 1, p->posY) == true) {
		p->posX -= 1;
	}
}
bool Map::checkCurrentTile(Player *p, int pX, int pY) {
	if(pY > 15 || pY < 0 || pX > 31 || pX < 0) {
		return false;
	}
	
	if(map[pX][pY] == "-") {
		currentPlayerTile = "Grass";
	}
	else if(map[pX][pY] == "|") {
		currentPlayerTile = "Forrest";
		srand(time(NULL));
		int decider = rand() % 10 + 1;
		if(decider <= 4) {
			Fight a("forrestMove", p);
		}
	}
	else if(map[pX][pY] == "~") {
		currentPlayerTile = "Water";
	}
	return true;
}
