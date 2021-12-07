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

class Grid {
private:
	//格子所处的位置(针对游戏庭院布置)
	int x;
	int y;
	//偏移量，针对绘图
	int dx;
	int dy;
	Zombie* zombie;
	Peashooter* peashooter;
	vector<Bullet*> bullets;

	bool refresh;  //是否刷新

	

public:
    void init() { refresh = false; zombie = NULL; peashooter = NULL;}
	void locateGrid_init(int tx, int ty);//确定位置并初始化
	void drawinfor(); //格子内部信息打印

	void delZombie();//删除僵尸（死亡或者移动到别的格子）
	void addZombie(Zombie* z);//添加僵尸（生成或者移动到这一格）
	void killZombie(Game* game);//僵尸被杀死
	void attackZombie(int ATK, Game* game);//僵尸受到攻击
	bool haszombie();//判断是否有僵尸

	
	Peashooter* addplant(int type);//种植植物
	bool hasplant();//判断是否有植物
	void delplant(Game* game);//植物被吃掉
	void been_eating(int ATK, Game* game);//植物被吃

	
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
	
	friend class Game;
	friend class Zombie;
	friend class Peashooter;
	friend class Sunflower;
	friend class Store;
	friend class Bullet;
};