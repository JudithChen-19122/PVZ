#pragma once

#include "Map.h"
#include "Zombies.h"
#include "Plant.h"
#include "Store.h"
#include "Bullet.h"
#include<vector>

class Map;
class Peashooter;
class Plant;
class Zombie;
class Store;
class Bullet;

class Game {
private:

	int state; //0:正常运行 1:暂停购买种植
	int score;
	Map* map;
	Store* store;

	//光标所在位置
	int x;
	int y;

	vector<Zombie*> zombies;
	vector < Plant* > plants;
	vector<Bullet*> bullets;

	void addZombie(int tx, int ty); //生成僵尸
	int zombie_addspeed; //僵尸生成速度
	int zombie_addcounter;
	void makeZombies();//随机生成僵尸
	bool moveZombies();//僵尸移动

	void refresh_base();//刷新阳光和分数

	void addPlant(int tx, int ty, int type);//种植植物
	void makePlant();//植物发射炮弹等操作

	void makebullet();//炮弹飞行
	void moving_point(int ch);//改变商店选择对象

	void refresh_locinfo();//更新选择地块信息输出
	void change_r2w();//将地块改为白色
	void change_w2r();//将地块改为红色
	void addsign();//添加标记
	void clearsign();//清除标记


	bool run_normal();//正常运行的基础操作
	void store_operator();//在商店中进行购买种植等操作
	void choose_plant_location();//选择种植的地块


public:
	void init();
	void run();//运行游戏

	void killplant(Plant* x);
	void killzombie(Zombie* x);
	void killbullet(Bullet* x);
	void addbullet(int tx, int ty, Bullet* b); //产生炮弹
};