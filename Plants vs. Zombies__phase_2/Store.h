#pragma once
#include<string>
#include"General_Tools.h"
#include"Plant.h"
#include"Map.h"
using namespace std;

class Map;
class Peashooter;
class Plant;

class Good{
private:
	int cold;//¿‰»¥ ±º‰
	int counter;
	int num;
	int price;
	string name;

public:
	void addGood(string tname, int tcold, int tnum, int tprice);
	void coldtime();
	void setcold(int point);
	void showinfo(int point);
	bool boughtable();
	friend class Store;

};


class Store {
private:
	int sunshine;
	int sunspeed;
	int counter;
	int type;
	Good goods[20];
	int point;

public:
	Store() { type = 10; sunshine = 0; counter = 0; }
	void init();
	void print_good();
	Plant* buy_good(Map*& map, int num, int x, int y);
	void natural_sun();
	void cold_time();
	void setpoint(int p) { point = p % type; };
	int getpoint() { return point; }

	friend class Sunflower;
	friend class Game;
};
