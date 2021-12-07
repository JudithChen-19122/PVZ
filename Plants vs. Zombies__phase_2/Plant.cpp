#include "Plant.h"


void Plant::plantloc(int tx, int ty) {
	x = tx;
	y = ty;
}

void Plant::init(const string& str, int health, int tspeed, int tATK) {
	name = str;
	maxHP = HP = health;
	speed = tspeed;
	counter = 0;
	ATK = tATK;
	jump = true;
	pushaway = false;
}

//sunflower
void Sunflower::func1(Game* game, Map* map, Store* store){
	counter += 1;
	if (counter >= speed) {
		store->sunshine += 25;
		counter = 0;
	}
}

//Peashooter
void Peashooter::func1(Game* game, Map* map, Store* store) {

	bool temp=false; 
	for (int j = x; j < 7; j++) {
		if (map->map_haszombie(j,y)) {
			temp = true;  //该行上有僵尸
			break;
		}
	}

	if (!temp) return;
	counter += 1;
	if (counter >= speed) {
		Bullet* b = new Bullet;
		game->addbullet(x, y, b);
		counter = 0;
	}
}

//Repeater
void Repeater::func1(Game* game, Map* map, Store* store) {

	bool temp = false;
	for (int j = x; j < 7; j++) {
		if (map->map_haszombie(j, y)) {
			temp = true;  //该行上有僵尸
			break;
		}
	}

	if (!temp) return;
	counter += 1;
	if (counter >= speed) {
		Bullet* b = new Bullet;
		game->addbullet(x, y, b);
		counter = 0;
	}
}

//SnowPea
void SnowPea::func1(Game* game, Map* map, Store* store) {
	bool temp = false;
	for (int j = x; j < 7; j++) {
		if (map->map_haszombie(j, y)) {
			temp = true;  //该行上有僵尸
			break;
		}
	}
	if (!temp) return;
	counter += 1;
	if (counter >= speed) {
		Bullet* b = new SnowBullet;
		game->addbullet(x, y, b);
		counter = 0;
	}
}

//倭瓜
void Squash::func1(Game* game, Map* map, Store* store) {
	int temp = 3;
	if (x < 6)
		if (map->map_haszombie(x+1, y))
			temp = 1;
	if (map->map_haszombie(x, y))
		temp = 0;

	if (temp == 3) return;

	map->map_killallZombie(x+temp,y,game);
	map->map_delplant(x,y,game);
}

//Cherry_Bomb
void Cherry_Bomb::func1(Game* game, Map* map, Store* store) {
	counter += 1;
	if (counter >= speed) {
		map->map_killallZombie(x, y, game);
		map->map_killallZombie(x + 1, y, game);
		map->map_killallZombie(x - 1, y, game);
		map->map_killallZombie(x, y - 1, game);
		map->map_killallZombie(x + 1, y - 1, game);
		map->map_killallZombie(x - 1, y - 1, game);
		map->map_killallZombie(x, y + 1, game);
		map->map_killallZombie(x + 1, y + 1, game);
		map->map_killallZombie(x - 1, y + 1, game);
		map->map_delplant(x, y, game);
	}
}


