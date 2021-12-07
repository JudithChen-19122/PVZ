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

	int ATK;
	int speed; 
	int counter;
	bool jump;//�Ƿ������
	bool pushaway;//�Ƿ����ϵ�������

	void init(const string& str, int health, int tspeed, int tATK);

public:
	void plantloc(int tx, int ty);//��ֲλ��
	int getHP() { return HP; }//��������ֵ
	const string& getName() const { return name; } //��������
	virtual void func1(Game* game, Map* map, Store* store) { ; };
	bool jumpable() { return jump; }
	bool ifpushaway() { return pushaway; }

	friend class Grid;
};

class Sunflower: public Plant{
public:
	Sunflower() { init("���տ�  ",300, 24, 0); }
	void func1(Game* game, Map* map, Store* store);
};

class Peashooter : public Plant{
public:
	Peashooter() { init("�㶹����", 300, 2, 20); }
	void func1(Game *game, Map* map, Store* store);
};

//˫������
class Repeater:public Plant {
public:
	Repeater() { init("˫������", 300, 1, 20); }// ����û����������������ʾһ�������ö��ֱ�Ӽ���
	void func1(Game* game, Map* map, Store* store);
};

//��������
class SnowPea:public Plant {
public:
	SnowPea() { init("��������", 300, 2, 20); }
	void func1(Game* game, Map* map, Store* store);
};

//���ǽ
class Wallnut :public Plant {
public:
	Wallnut() { init("���ǽ", 4000, 2, 0); }
	void func1(Game* game, Map* map, Store* store) { ; };
};

//�߼��
class Tallnut :public Plant {
public:
	Tallnut() { init("�߼��", 8000, 2, 0); jump = false; }
	void func1(Game* game, Map* map, Store* store) { ; };
};

//����
class Squash :public Plant {
public:
	Squash() { init("����", 300, 2, 1800);}
	void func1(Game* game, Map* map, Store* store);
};

//ӣ��ը��
class Cherry_Bomb :public Plant {
public:
	Cherry_Bomb() { init("ӣ��ը��", 300, 3, 1800); }
	void func1(Game* game, Map* map, Store* store);
};

//����
class Garlic:public Plant {
public:
	Garlic() { init("����", 400, 3, 0); pushaway = true; }
	void func1(Game* game, Map* map, Store* store) { ; }
};

class Pumpkin :public Plant {
public:
	Pumpkin() { init("�Ϲ�ͷ", 4000, 3, 0); }
	friend class Grid;
};