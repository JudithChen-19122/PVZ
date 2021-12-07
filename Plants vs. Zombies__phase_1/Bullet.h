#pragma once
#include"Map.h"
class Map;

class Bullet {
private:
	//当前所属位置
	int x;
	int y;
	int ATK;
	int speed;
	int counter;
public:
	Bullet() { x = 0; y = 0; ATK = 20; speed = 1; counter = 0; }
	void move(Map* map, Game* game);//子弹移动/攻击
	void locate(int tx, int ty);
	bool judgeifattack(Map* map); //判断是否在攻击
};