#pragma once
#include"Map.h"
class Map;

class Bullet {
protected:
	//当前所属位置
	int x;
	int y;
	int ATK;
	int speed;
	int counter;
	int snow;
public:
	Bullet() { x = 0; y = 0; ATK = 20; speed = 1; counter = 0; snow = false; }
	virtual void move(Map* map, Game* game);//子弹移动/攻击
	void locate(int tx, int ty);
	bool judgeifattack(Map* map); //判断是否在攻击
	bool ifsnow() { return snow; }
};

class SnowBullet: public Bullet{

public:
	SnowBullet() { x = 0; y = 0; ATK = 20; speed = 1; counter = 0; snow = true; }
	void move(Map* map, Game* game);//子弹移动/攻击
};