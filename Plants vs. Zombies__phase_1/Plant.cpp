#include "Plant.h"


void Plant::plantloc(int tx, int ty) {
	x = tx;
	y = ty;
}


//sunflower
void Sunflower::init(const string& str, int health, int tspeed) {
	name = str;
	maxHP = HP = health;
	speed = tspeed;
	counter = 0;
}

void Sunflower::produce_sun(Store* &store) {
	counter += 1;
	if (counter >= speed) {
		store->sunshine += 25;
		counter = 0;
	}
}

//Peashooter
void Peashooter::init(const string& str, int health, int tspeed, int tATK) {
	name = str;
	maxHP = HP = health;
	speed = tspeed;
	counter = 0;
	ATK = tATK;
}


void Peashooter::shoot(Game* game, Map* map) {

	bool temp=false; 
	for (int j = 0; j < 7; j++) {
		if (map->grid[j][y].haszombie()) {
			temp = true;  //该行上有僵尸
			break;
		}
	}

	if (!temp) return;
	counter += 1;
	if (counter >= speed) {
		game->addbullet(x, y);
		counter = 0;
	}
}
