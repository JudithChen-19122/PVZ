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
public:
	void plantloc(int tx, int ty);//种植位置
	int getHP() { return HP; }//返回生命值
	const string& getName() const { return name; } //返回名字

	friend class Grid;
};



class Sunflower: public Plant{
private:
	int speed;//生成阳光的速度
	int counter;
	void init(const string& str, int health, int tspeed);
	
public:
	Sunflower() { init("向日葵  ",300, 24); }
	void produce_sun(Store*& store );
};


class Peashooter : public Plant{
private:
	int ATK;
	int speed; //发射子弹的速度
	int counter;
	void init(const string& str, int health, int tspeed, int ATK);
public:
	Peashooter() { init("豌豆射手", 300, 2, 20); }
	void shoot(Game *game, Map* map);
};