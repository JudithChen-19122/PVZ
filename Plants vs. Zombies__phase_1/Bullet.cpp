#include "Bullet.h"


void Bullet::locate(int tx, int ty) {
	x = tx;
	y = ty; 
	ATK = 20; 
	speed = 1;
	counter = 0;
}


void Bullet::move(Map* map, Game* game) {
	if (judgeifattack(map)) {
		map->grid[x][y].attackZombie(ATK, game);
		map->grid[x][y].killBullet(this, game);
		return;
	}
	counter += 1;
	if (counter >= speed) {
		if (x >= 6) {
			map->grid[x][y].killBullet(this, game);
		}
		else {
			map->grid[x][y].delBullet(this);
			x++;
			map->grid[x][y].addBullet(this);
			counter = 0;
			//添加在移动之后立即进行的攻击判断，否则由于僵尸移动子弹可能错过攻击
			if (judgeifattack(map)) {
				map->grid[x][y].attackZombie(ATK, game);
				map->grid[x][y].killBullet(this, game);
			}
		}
	}
}

bool Bullet::judgeifattack(Map* map) {
	if (map->grid[x][y].haszombie())
		return true;
	else
		return false;
}