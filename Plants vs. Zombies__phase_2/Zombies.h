#pragma once
#include<string>
#include"Map.h"
#include"Game.h"
using namespace std;
class Game;
class Map;

//普通僵尸
class Zombie {
protected:
	string name;
	int HP;
	int maxHP;
	int x, y;//当前所处位置
	int ATK;  //攻击力/s
	int speed; //移动速度  （数值越大，速度越小)
	int counter;
	void init(const string& str, int health, int tspeed, int attack);
	bool eating;//是否正在吃植物（停止不动，攻击前一格的植物）
	bool snow;
	int snowcounter;
	int snowtime;
	int snow_wait;

public:
	Zombie() { init("普通僵尸", 270, 10, 100);  }
	const string& getName() const { return name; } //返回僵尸名字
	int getHP() { return HP; }//返回生命值
	void setstartloc(int tx, int ty);//设置起始位置
	virtual bool move(Map*& map, Game* game);//僵尸移动/攻击
	void judgeifeating(Map*& map); //判断是否在吃植物
	void snow_attack();
	bool ifsnow() { return snow; }

	virtual void func2(Map*& map, Game* game) { ; }//额外的一些功能


	friend class Grid;
};


//撑杆僵尸
  
class Pole_Vaulting_Zombie : public Zombie {
private:
	int speed2;
	bool jumped;
	bool jumpable(Map*& map);
public:
	Pole_Vaulting_Zombie() { init("撑杆僵尸", 500, 5, 100); jumped = false; speed2 = 9; }
	bool move(Map*& map, Game* game);

};

//路障僵尸
class Conehead_Zombie : public Zombie {
public:
	Conehead_Zombie() { init("路障僵尸", 640, 10, 100); }
};

//报纸僵尸
class Newspaper_Zombie : public Zombie {
private:
	int health2;
	int speed2;
public:
	Newspaper_Zombie() { init("报纸僵尸", 420, 10, 100); speed2 = 4; health2 = 270; }
	bool move(Map*& map, Game* game);
};


//小丑僵尸
class Jack_in_the_box_Zombie : public Zombie {
private:
	int bomb;
	void init_bomb();
public:
	Jack_in_the_box_Zombie() { init("小丑僵尸", 500, 10, 100); init_bomb(); }
	void func2(Map*& map, Game* game);
};


//投石僵尸CATAPULT ZOMBIE
class Catapult_Zombie : public Zombie {
private:
	int ball;
public:
	Catapult_Zombie() { init("投石僵尸", 850, 5, 20); ball=20; }
	bool move(Map*& map, Game* game);
};