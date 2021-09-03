#pragma once
#include <iostream>
#include <string.h>
#include "player.h"



using namespace std;

class Map {
	public:
		void moveNorth(Player *p);
		void moveSouth(Player *p);
		void moveWest(Player *p);
		void moveEast(Player *p);
		void printMap(string map[8][8],Player *p);
		string stelarit[8][8] = {
			{"-","-","-","-","-","-","~","-"},
			{"-","-","|","|","-","~","~","-"},
			{"-","|","|","|","|","~","~","~"},
			{"-","-","|","|","-","~","~","-"},
			{"-","|","|","|","|","-","~","-"},
			{"-","-","|","|","|","-","-","-"},
			{"-","-","-","|","-","-","-","-"},
			{"-","-","-","-","-","-","-","-"},
		};
	private:
		void checkCurrentTile(Player *p);
		string currentPlayerTile;	
};
