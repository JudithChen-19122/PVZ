#pragma once
#include"General_Tools.h"
#include"Zombies.h"
#include"Plant.h"
#include"Bullet.h"
#include"Game.h"
#include<vector>
#include<iostream>

#define ROW 3
#define COL 7
#define GW  11
#define GH  6
#define MAPWITCH 75


class Zombie;
class Peashooter;
class Bullet;
class Game;
class Plant;
class Pumpkin;

class Grid {
private:
	//格子所处的位置(针对游戏庭院布置)
	int x;
	int y;
	//偏移量，针对绘图
	int dx;
	int dy;
	vector<Zombie*> zombies;
	Plant* plant;  
	Pumpkin* pumpkin;//南瓜头 由于没有其他功能，只存在map里, 不存在game里，简化删除操作
	vector<Bullet*> bullets;

	bool refresh;  //是否刷新

	void snowdraw(const string s); //寒冰效果输出

public:
	void init() { refresh = false;  plant = NULL; pumpkin = NULL; }
	void locateGrid_init(int tx, int ty);//确定位置并初始化
	void drawinfor(); //格子内部信息打印

	void delZombie(Zombie* x);//删除僵尸（死亡或者移动到别的格子）
	void addZombie(Zombie* z);//添加僵尸（生成或者移动到这一格）
	void killZombie(Game* game, Zombie* x);//僵尸被杀死
	void attackZombie(int ATK, Game* game);//僵尸受到攻击
	void snow_attackZombie(int ATK, Game* game);//僵尸受到寒冰射手攻击
	bool haszombie();//判断是否有僵尸
	void killallZombie(Game* game);//杀死所有僵尸

	
	Plant* addplant(int type);//种植植物
	bool hasplant();//判断是否有植物
	void delplant(Game* game);//植物被吃掉
	bool been_eating(int ATK, Game* game);//植物被吃,返回是否大蒜被吃
	void attack_plant(int ATK, Game* game);//植物被投石僵尸篮球攻击
	bool jumpable();//判断植物是否可跳过
	void boomplant(Game* game);////炸毁所有植物

	
	void addBullet(Bullet* bullet);//添加子弹
	void delBullet(Bullet* bullet);//删除子弹(移走)
	void killBullet(Bullet* bullet,Game* game);//删除子弹(击中)

	
	bool needrefresh() { return refresh; }

    friend class Map;
};


class Map{
private:
	Grid grid[COL][ROW];//grid[x][y]为坐标为（x，y）所在的地块

public:
	Map();
	void init();//初始化
	void drawGrid(); //框架绘制
	void refresh();//遍历所有格子，检查是否需要刷新


	void map_delZombie(int x, int y, Zombie* t);//删除僵尸（死亡或者移动到别的格子）
	void map_addZombie(int x, int y, Zombie* z);//添加僵尸（生成或者移动到这一格）
	void map_killZombie(int x, int y, Game* game, Zombie* t);//僵尸被杀死
	void map_attackZombie(int x, int y, int ATK, Game* game);//僵尸受到攻击
	void map_snow_attackZombie(int x, int y, int ATK, Game* game);//僵尸受到寒冰射手攻击
	bool map_haszombie(int x, int y);//判断是否有僵尸
	void map_killallZombie(int x, int y, Game* game);//杀死所有僵尸


	Plant* map_addplant(int x, int y,int type);//种植植物
	bool map_hasplant(int x, int y);//判断是否有植物
	void map_delplant(int x, int y, Game* game);//植物被吃掉
	bool map_been_eating(int x, int y,int ATK, Game* game);//植物被吃
	bool map_jumpable(int x, int y);//判断植物是否可跳过
	void map_boomplant(int x, int y, Game* game);//炸毁所有植物
	void map_attack_plant(int x, int y, int ATK, Game* game);//植物被投石僵尸篮球攻击


	void  map_addBullet(int x, int y, Bullet* bullet);//添加子弹
	void  map_delBullet(int x, int y, Bullet* bullet);//删除子弹(移走)
	void  map_killBullet(int x, int y, Bullet* bullet, Game* game);//删除子弹(击中)
};