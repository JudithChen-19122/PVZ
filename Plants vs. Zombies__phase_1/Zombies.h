#pragma once
#include<string>
#include"Map.h"
#include"Game.h"
using namespace std;
class Game;
class Map;

//普通僵尸
class Zombie {
private:
	string name;
	int HP;
	int maxHP;
	int x, y;//当前所处位置
	int ATK;  //攻击力/s
	int speed; //移动速度  （数值越大，速度越小)
	int counter;
	void init(const string& str, int health, int tspeed, int attack);
	bool eating;//是否正在吃植物（停止不动，攻击前一格的植物）

public:
	Zombie() { init("普通僵尸", 270, 10, 100);  eating = false;}
	const string& getName() const { return name; } //返回僵尸名字
	int getHP() { return HP; }//返回生命值
	void setstartloc(int tx, int ty);//设置起始位置
	bool move(Map*& map, Game* game);//僵尸移动/攻击
	void judgeifeating(Map*& map); //判断是否在吃植物

	friend class Grid;
};