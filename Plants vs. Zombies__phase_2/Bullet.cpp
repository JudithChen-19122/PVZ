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
		map->map_attackZombie(x,y,ATK, game);
		map->map_killBullet(x,y,this, game);
		return;
	}
	counter += 1;
	if (counter >= speed) {
		if (x >= 6) {
			map->map_killBullet(x, y,this, game);
		}
		else {
			map->map_delBullet(x, y, this);
			x++;
			map->map_addBullet(x, y, this);
			counter = 0;
			//添加在移动之后立即进行的攻击判断，否则由于僵尸移动子弹可能错过攻击
			if (judgeifattack(map)) {
				map->map_attackZombie(x, y, ATK, game);
				map->map_killBullet(x, y, this, game);
			}
		}
	}
}

bool Bullet::judgeifattack(Map* map) {
	if (map->map_haszombie(x,y))
		return true;
	else
		return false;
}

void SnowBullet::move(Map* map, Game* game) {
	if (judgeifattack(map)) {
		map->map_attackZombie(x, y, ATK, game);
		map->map_killBullet(x, y, this, game);
		return;
	}
	counter += 1;
	if (counter >= speed) {
		if (x >= 6) {
			map->map_killBullet(x,y,this, game);
		}
		else {
			map->map_delBullet(x,y,this);
			x++;
			map->map_addBullet(x,y,this);
			counter = 0;
			//添加在移动之后立即进行的攻击判断，否则由于僵尸移动子弹可能错过攻击
			if (judgeifattack(map)) {
				map->map_snow_attackZombie(x, y, ATK, game);//带寒冰效果的攻击
				map->map_killBullet(x, y, this, game);
			}
		}
	}


}