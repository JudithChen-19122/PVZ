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
	//��ֲλ��
	int x;
	int y;
	string name;
	int HP;
	int maxHP;
public:
	void plantloc(int tx, int ty);//��ֲλ��
	int getHP() { return HP; }//��������ֵ
	const string& getName() const { return name; } //��������

	friend class Grid;
};



class Sunflower: public Plant{
private:
	int speed;//����������ٶ�
	int counter;
	void init(const string& str, int health, int tspeed);
	
public:
	Sunflower() { init("���տ�  ",300, 24); }
	void produce_sun(Store*& store );
};


class Peashooter : public Plant{
private:
	int ATK;
	int speed; //�����ӵ����ٶ�
	int counter;
	void init(const string& str, int health, int tspeed, int ATK);
public:
	Peashooter() { init("�㶹����", 300, 2, 20); }
	void shoot(Game *game, Map* map);
};