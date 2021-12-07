#pragma once
#include<string>
#include"General_Tools.h"
#include"Plant.h"
#include"Map.h"
using namespace std;

class Map;
class Peashooter;

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
	void setcold();
	void showinfo();
	bool boughtable();

	friend class Store;

};


class Store {
private:
	int sunshine;
	int sunspeed;
	int counter;
	int type;
	Good goods[2];
public:
	Store() { type = 2; sunshine = 0; }
	void init();
	void print_good();
	Peashooter* buy_good(Map*& map, int num, int x, int y);
	void natural_sun();
	void cold_time();

	friend class Sunflower;
	friend class Game;
};
