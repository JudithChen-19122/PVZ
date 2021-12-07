#pragma once
#include<string>
#include"Game.h"
#include"Store.h"
#include"Map.h"
using namespace std;

class Game;
class Map;
 
class Plant {
protected:
	//种植位置
	int x;
	int y;
	string name;
	int HP;
	int maxHP;

	int ATK;
	int speed; 
	int counter;
	bool jump;//是否可跳过
	bool pushaway;//是否驱赶到相邻行

	void init(const string& str, int health, int tspeed, int tATK);

public:
	void plantloc(int tx, int ty);//种植位置
	int getHP() { return HP; }//返回生命值
	const string& getName() const { return name; } //返回名字
	virtual void func1(Game* game, Map* map, Store* store) { ; };
	bool jumpable() { return jump; }
	bool ifpushaway() { return pushaway; }

	friend class Grid;
};

class Sunflower: public Plant{
public:
	Sunflower() { init("向日葵  ",300, 24, 0); }
	void func1(Game* game, Map* map, Store* store);
};

class Peashooter : public Plant{
public:
	Peashooter() { init("豌豆射手", 300, 2, 20); }
	void func1(Game *game, Map* map, Store* store);
};

//双发射手
class Repeater:public Plant {
public:
	Repeater() { init("双发射手", 300, 1, 20); }// 由于没有做动画，不好显示一次射出两枚，直接加速
	void func1(Game* game, Map* map, Store* store);
};

//寒冰射手
class SnowPea:public Plant {
public:
	SnowPea() { init("寒冰射手", 300, 2, 20); }
	void func1(Game* game, Map* map, Store* store);
};

//坚果墙
class Wallnut :public Plant {
public:
	Wallnut() { init("坚果墙", 4000, 2, 0); }
	void func1(Game* game, Map* map, Store* store) { ; };
};

//高坚果
class Tallnut :public Plant {
public:
	Tallnut() { init("高坚果", 8000, 2, 0); jump = false; }
	void func1(Game* game, Map* map, Store* store) { ; };
};

//倭瓜
class Squash :public Plant {
public:
	Squash() { init("倭瓜", 300, 2, 1800);}
	void func1(Game* game, Map* map, Store* store);
};

//樱桃炸弹
class Cherry_Bomb :public Plant {
public:
	Cherry_Bomb() { init("樱桃炸弹", 300, 3, 1800); }
	void func1(Game* game, Map* map, Store* store);
};

//大蒜
class Garlic:public Plant {
public:
	Garlic() { init("大蒜", 400, 3, 0); pushaway = true; }
	void func1(Game* game, Map* map, Store* store) { ; }
};

class Pumpkin :public Plant {
public:
	Pumpkin() { init("南瓜头", 4000, 3, 0); }
	friend class Grid;
};