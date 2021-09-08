#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "enemy.h"
#include "curses.h"
#include <time.h>

class Fight {
	public:
		Fight(string event, Player *p);
	private:
		Player *p;
		void fightingLoop(Player *p, Enemy *e);
};
