#pragma once
#include <iostream>
#include <string.h>
#include "player.h"
#include <fstream>
#include <time.h>

using namespace std;

class Map {
	public:
		Map(string mapName);
		void moveNorth(Player *p);
		void moveSouth(Player *p);
		void moveWest(Player *p);
		void moveEast(Player *p);
		void printMap(Player *p);
		bool checkCurrentTile(Player *p, int pX, int pY);
		string map[32][16];
	private:
		//void checkCurrentTile(Player *p);
		string currentPlayerTile;	
};
