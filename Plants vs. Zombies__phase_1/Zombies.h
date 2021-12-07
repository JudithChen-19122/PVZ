#pragma once
#include<string>
#include"Map.h"
#include"Game.h"
using namespace std;
class Game;
class Map;

//��ͨ��ʬ
class Zombie {
private:
	string name;
	int HP;
	int maxHP;
	int x, y;//��ǰ����λ��
	int ATK;  //������/s
	int speed; //�ƶ��ٶ�  ����ֵԽ���ٶ�ԽС)
	int counter;
	void init(const string& str, int health, int tspeed, int attack);
	bool eating;//�Ƿ����ڳ�ֲ�ֹͣ����������ǰһ���ֲ�

public:
	Zombie() { init("��ͨ��ʬ", 270, 10, 100);  eating = false;}
	const string& getName() const { return name; } //���ؽ�ʬ����
	int getHP() { return HP; }//��������ֵ
	void setstartloc(int tx, int ty);//������ʼλ��
	bool move(Map*& map, Game* game);//��ʬ�ƶ�/����
	void judgeifeating(Map*& map); //�ж��Ƿ��ڳ�ֲ��

	friend class Grid;
};