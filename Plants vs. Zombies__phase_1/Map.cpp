#include "Map.h"

//Grid
void Grid::locateGrid_init(int tx, int ty) {
	refresh = false;
	x = tx;
	y = ty;
	//获取绘图所需坐标，加的1是预留的外框的位置
	dx = x * GW + 1;
	dy = y * GH + 1;
	//初始化基础成员数据
	zombie = NULL;
	peashooter = NULL;
}

//信息输出
void Grid::drawinfor() {
	gotoxy(dx, dy+2);
	if (zombie != NULL) {
		cout << zombie->getName();
		gotoxy(dx, dy + 3);
		cout << "HP:";
		cout << zombie->getHP();
		cout << "  ";
	}
	else if (peashooter != NULL) {
		cout << peashooter->getName();
		gotoxy(dx, dy + 3);
		cout << "HP:";
		cout << peashooter->getHP();
		cout << "  ";
	}
	else if (!bullets.empty()) {
		cout << "  OOO   ";
		gotoxy(dx, dy + 3);
		cout << "        ";
	}
	else {
		cout << "        "; //清空
		gotoxy(dx, dy + 3);
		cout << "        ";
	}

	//gotoxy(0, ROW*GH+10);


	refresh = false;
}

//僵尸相关
void Grid::delZombie() {
	zombie = NULL;
	refresh = true;
}
void Grid::killZombie(Game* game) {
	for(int i=0;i<game->zombies.size();i++)
		if (zombie == game->zombies[i])
		{
			game->zombies[i] = game->zombies[game->zombies.size() - 1];
			game->zombies.pop_back();
			break;
		}
	delete zombie;
	zombie = NULL;
	refresh = true;
}
void Grid::addZombie(Zombie *z) {
	zombie = z;
	refresh = true;
}
bool Grid::haszombie() {
	if (zombie == NULL)
		return false;
	else
		return true;
}
void Grid::attackZombie(int ATK, Game* game) {
	if (zombie != NULL) {
		zombie->HP -= ATK;
		if (zombie->HP <= 0) {
			killZombie(game);
		}
		refresh = true;
	}
}

//植物相关
Peashooter* Grid::addplant(int type) {
	if (peashooter != NULL || zombie!= NULL) return NULL;
	Peashooter* p=NULL;
	switch (type) {
	case 0: p = new Peashooter; break;
	default: return NULL;
	}
	peashooter = p;
	refresh = true;
	drawinfor();
	return p;
}
void Grid::delplant(Game* game) {
	for (int i = 0; i < game->peashooters.size(); i++) {
		if (peashooter == game->peashooters[i])
		{    
			game->peashooters[i] = game->peashooters[game->peashooters.size() - 1];
			game->peashooters.pop_back();
			break;
		}
	}
	delete peashooter;
	peashooter = NULL;
	refresh = true;
}
void Grid::been_eating(int ATK, Game* game)
{
	if (peashooter != NULL) {
		peashooter->HP -= ATK;
		if (peashooter->HP <= 0) {
			delplant(game);
		}
		refresh = true;
	}
}
bool Grid::hasplant() {
	if (peashooter == NULL) return false;
	else return true;
}


//子弹相关
void Grid::addBullet(Bullet* b) {
	bullets.push_back(b);
	refresh = true;
}
void Grid::delBullet(Bullet* b) {
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i] == b)
		{
			bullets[i] = bullets[bullets.size() - 1];
			bullets.pop_back();
			refresh = true;
			break;
		}
	}
}
void Grid::killBullet(Bullet* b, Game* game) {
	delBullet(b);
	for (int i = 0; i < game->bullets.size(); i++) {
		if (b == game->bullets[i])
		{
			game->bullets[i] = game->bullets[game->bullets.size() - 1];
			game->bullets.pop_back();
			break;
		}
	}
	delete b;
	b = NULL;
	refresh = true;

}

//Map
Map::Map() {
	for (int i = 0; i < COL; i++) {
		for (int j = 0; j < ROW; j++) {
			grid[i][j].locateGrid_init(i,j);
		}
	}
}
void Map::init() {
	drawGrid();
	for (int i = 0; i < COL; i++) {
		for (int j = 0; j < ROW; j++) {
			grid[i][j].locateGrid_init(i, j);
		}
	}
}
void Map::drawGrid() {
	for (int i = 0; i < ROW+1; i++) {
		gotoxy(0, i * GH);
		for (int j = 0; j < COL * GW + 1; j++)
			cout << "#";
	}
	for (int k = 0; k < ROW; k++) {
		for (int j = 0; j < GH-1; j++) {
			for (int i = 0; i < COL+1; i++) {
				gotoxy(i * GW, j + 1 + k * GH);
				cout << "#";
			}
		}
	}
	//gotoxy(0, ROW*GH+10);
}
void Map::refresh() {
	for (int i = 0; i < COL; i++) {
		for (int j = 0; j < ROW; j++) {
			if (grid[i][j].refresh) {
				grid[i][j].drawinfor();
			}
		}
	}
}
