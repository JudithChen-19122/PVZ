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
	plant = NULL;
	pumpkin = NULL;
}

void Grid::snowdraw(const string s) {   //寒冰效果输出
	color(0x01);//黑底蓝色字体
	cout << s;
	color(0x07);//黑底白色字体
}

//信息输出
void Grid::drawinfor() {

	if (!zombies.empty()) {
		gotoxy(dx, dy);
		if (zombies.front()->ifsnow()) {
			snowdraw(zombies.front()->getName());
			gotoxy(dx, dy + 1);
			snowdraw( "HP:");
			snowdraw(to_string(zombies.front()->getHP()));
			
		}
		else {
			cout << zombies.front()->getName();
			gotoxy(dx, dy + 1);
			cout << "HP:";
			cout << zombies.front()->getHP();
		}
		cout << "  ";
		gotoxy(dx, dy + 2);
		cout <<"数量: "<<zombies.size()<<" ";
	}
	else if (!bullets.empty()) {
		gotoxy(dx, dy);
		if (bullets.front()->ifsnow())
			snowdraw("  O       ");
		else
			cout << "  O       ";
		gotoxy(dx, dy + 1);
		cout << "         ";
		gotoxy(dx, dy + 2);
		cout << "         ";
	}
	else {
		gotoxy(dx, dy);
		cout << "        "; //清空
		gotoxy(dx, dy + 1);
		cout << "        ";
		gotoxy(dx, dy + 2);
		cout << "        ";
	}
	if (pumpkin != NULL)
	{
		gotoxy(dx, dy + 2);
		cout << "南:";
		cout << pumpkin->getHP()<<"   ";
	}
	if (plant != NULL) {
		gotoxy(dx, dy + 3);
		cout << plant->getName();
		gotoxy(dx, dy + 4);
		cout << "HP:";
		cout << plant->getHP();
		cout << "   ";
	}
	else {
		gotoxy(dx, dy + 3);
		cout << "        "; //清空
		gotoxy(dx, dy + 4);
		cout << "        ";
	}

	//gotoxy(0, ROW*GH+10);


	refresh = false;
}

//僵尸相关
void Grid::delZombie(Zombie* x) {
	for (int i = 0; i < zombies.size(); i++)
		if (x == zombies[i])
		{
			zombies[i] = zombies[zombies.size() - 1];
			zombies.pop_back();
			break;
		}
	refresh = true;
}
void Grid::killZombie(Game* game, Zombie* x) {
	for (int i = 0; i < zombies.size(); i++)
		if (x == zombies[i])
		{
			zombies[i] = zombies[zombies.size() - 1];
			zombies.pop_back();
			break;
		}

	game->killzombie(x);
	delete x;
	refresh = true;
}
void Grid::killallZombie(Game* game) {
	if (zombies.empty()) return;
	for (int i = 0; i < zombies.size(); i++) {
		game->killzombie(zombies[i]); 
	}
	while (!zombies.empty()) {
		Zombie* temp = zombies.back();
		zombies.pop_back();
		delete temp;
	}
	refresh = true;
}
void Grid::addZombie(Zombie *z) {
	zombies.push_back(z);
	refresh = true;
}
bool Grid::haszombie() {
	if (zombies.empty())
		return false;
	else
		return true;
}
void Grid::attackZombie(int ATK, Game* game) {
	if (!zombies.empty()) {
		zombies.front()->HP -= ATK;
		if (zombies.front()->HP <= 0) {
			killZombie(game, zombies.front());
		}
	}
	refresh = true;
}
void Grid::snow_attackZombie(int ATK, Game* game) {
	if (!zombies.empty()) {
		zombies.front()->snow_attack();
		zombies.front()->HP -= ATK;
		if (zombies.front()->HP <= 0) {
			killZombie(game, zombies.front());
		}
	}
	refresh = true;
}


//植物相关
Plant* Grid::addplant(int type) {
	if (type != 9) { //除南瓜头以外的植物
		if (plant != NULL) return NULL;
		Plant* p = NULL;
		switch (type) {
		case 0: p = new Peashooter; break;
		case 1: p = new Sunflower; break;
		case 2: p = new Repeater; break;
		case 3: p = new SnowPea; break;
		case 4: p = new Wallnut; break;
		case 5: p = new Tallnut; break;
		case 6: p = new Squash; break;//倭瓜
		case 7: p = new Cherry_Bomb; break;
		case 8: p = new Garlic; break;//大蒜
		default: return NULL;
		}
		plant = p;
		refresh = true;
		drawinfor();
		return p;
	}
	if (type == 9) { //南瓜头
		if (pumpkin != NULL) return NULL;
		Pumpkin* p = new Pumpkin;
		pumpkin = p;
		refresh = true;
		drawinfor();
		return p;
	}
}

void Grid::delplant(Game* game) {
	if (plant == NULL) return;
	game->killplant(plant);
	delete plant;
	plant = NULL;
	refresh = true;
}
bool Grid::been_eating(int ATK, Game* game)
{
	bool temp = false;
	if (pumpkin != NULL) {
	   pumpkin->HP -= ATK;
	   refresh = true;
	   if (pumpkin->HP <= 0) {
		   delete pumpkin;
		   pumpkin = NULL; //没存在game里直接清除
	   }
	}
	else if (plant != NULL) {
		plant->HP -= ATK;
		temp = plant->ifpushaway();
		if (plant->HP <= 0) {
			delplant(game);
		}
		refresh = true;
	}
	return temp;
}
void Grid::attack_plant(int ATK, Game* game) {
	if (plant != NULL) {
		plant->HP -= ATK;
		plant->ifpushaway();
		if (plant->HP <= 0) {
			delplant(game);
		}
	}
	else if (pumpkin != NULL) {
		pumpkin->HP -= ATK;
		refresh = true;
		if (pumpkin->HP <= 0) {
			delete pumpkin;
			pumpkin = NULL; //没存在game里直接清除
		}
	}
	refresh = true;
}
bool Grid::hasplant() {
	if (plant == NULL && pumpkin==NULL) return false;
	else return true;
}
bool Grid::jumpable() {
	if (plant != NULL && plant->jumpable()) return true; //有植物，植物可跳过时可跳过
	else if (plant == NULL && pumpkin != NULL) return true; //只有南瓜头时可跳过
	else return false;
}
void Grid::boomplant(Game* game) {
	delplant(game);
	if (pumpkin != NULL) {
		delete pumpkin;
		pumpkin = NULL;
	}
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
	game->killbullet(b);
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



//Map 封装取代友元对grid的直接调用

Plant* Map::map_addplant(int x, int y, int type) {
	return grid[x][y].addplant(type);
}
bool Map::map_hasplant(int x, int y) {
	return grid[x][y].hasplant();
}
void Map::map_delplant(int x, int y, Game* game) {
	grid[x][y].delplant(game);
}
bool Map::map_been_eating(int x, int y, int ATK, Game* game) {
	return grid[x][y].been_eating(ATK, game);
}
bool Map::map_jumpable(int x, int y) {
	return grid[x][y].jumpable();
}
void Map::map_boomplant(int x, int y, Game* game) {
	if (x >= 0 && x < COL && y >= 0 && y < ROW)
		grid[x][y].boomplant(game);
}
void Map::map_attack_plant(int x, int y, int ATK, Game* game) {
	grid[x][y].attack_plant(ATK, game);
}


void  Map::map_addBullet(int x, int y, Bullet* bullet) {
	grid[x][y].addBullet(bullet);
}
void  Map::map_delBullet(int x, int y, Bullet* bullet) {
	grid[x][y].delBullet(bullet);
}
void  Map::map_killBullet(int x, int y, Bullet* bullet, Game* game) {
	grid[x][y].killBullet(bullet, game);
}


void  Map::map_delZombie(int x, int y, Zombie* t) {
	grid[x][y].delZombie(t);
}
void  Map::map_addZombie(int x, int y, Zombie* z) {
	grid[x][y].addZombie(z);
}
void  Map::map_killZombie(int x, int y, Game* game, Zombie* t) {
	grid[x][y].killZombie(game ,t);
}
void  Map::map_attackZombie(int x, int y, int ATK, Game* game) {
	grid[x][y].attackZombie(ATK, game);
}
void  Map::map_snow_attackZombie(int x, int y, int ATK, Game* game) {
	grid[x][y].snow_attackZombie(ATK, game);
}
bool  Map::map_haszombie(int x, int y) {
	return grid[x][y].haszombie();
}
void  Map::map_killallZombie(int x, int y, Game* game) {
	if (x >= 0 && x < COL && y >= 0 && y < ROW)
		grid[x][y].killallZombie(game);
}

