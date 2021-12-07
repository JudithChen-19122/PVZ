#include"Zombies.h"


void Zombie::init(const string& str, int health, int tspeed, int attack) {
	name = str;
	maxHP = HP = health;
	speed = tspeed;
	ATK = attack;
	counter = 0;
	eating = false;
}

void Zombie::setstartloc(int tx, int ty) {
	x = tx;
	y = ty;
}

bool Zombie::move(Map*& map, Game* game) {
	judgeifeating(map);
	if (eating) {
		map->grid[x-1][y].been_eating(ATK, game);
	    return true;
	}  
	counter += 1;
	if (counter >= speed) {
		map->grid[x][y].delZombie();
		x--;
		if (x < 0) //Zombies ate your brain
			return false;
		map->grid[x][y].addZombie(this);
		counter = 0;
	}
	return true;
}


void Zombie::judgeifeating(Map*& map) {
	if (x > 0)
		if (map->grid[x - 1][y].hasplant())
			eating = true;
		else
			eating = false;
	else
		eating = false;
}