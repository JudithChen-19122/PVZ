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
			//������ƶ�֮���������еĹ����жϣ��������ڽ�ʬ�ƶ��ӵ����ܴ������
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