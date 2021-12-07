#pragma once
#include<string>
#include"Map.h"
#include"Game.h"
using namespace std;
class Game;
class Map;

//��ͨ��ʬ
class Zombie {
protected:
	string name;
	int HP;
	int maxHP;
	int x, y;//��ǰ����λ��
	int ATK;  //������/s
	int speed; //�ƶ��ٶ�  ����ֵԽ���ٶ�ԽС)
	int counter;
	void init(const string& str, int health, int tspeed, int attack);
	bool eating;//�Ƿ����ڳ�ֲ�ֹͣ����������ǰһ���ֲ�
	bool snow;
	int snowcounter;
	int snowtime;
	int snow_wait;

public:
	Zombie() { init("��ͨ��ʬ", 270, 10, 100);  }
	const string& getName() const { return name; } //���ؽ�ʬ����
	int getHP() { return HP; }//��������ֵ
	void setstartloc(int tx, int ty);//������ʼλ��
	virtual bool move(Map*& map, Game* game);//��ʬ�ƶ�/����
	void judgeifeating(Map*& map); //�ж��Ƿ��ڳ�ֲ��
	void snow_attack();
	bool ifsnow() { return snow; }

	virtual void func2(Map*& map, Game* game) { ; }//�����һЩ����


	friend class Grid;
};


//�Ÿ˽�ʬ
  
class Pole_Vaulting_Zombie : public Zombie {
private:
	int speed2;
	bool jumped;
	bool jumpable(Map*& map);
public:
	Pole_Vaulting_Zombie() { init("�Ÿ˽�ʬ", 500, 5, 100); jumped = false; speed2 = 9; }
	bool move(Map*& map, Game* game);

};

//·�Ͻ�ʬ
class Conehead_Zombie : public Zombie {
public:
	Conehead_Zombie() { init("·�Ͻ�ʬ", 640, 10, 100); }
};

//��ֽ��ʬ
class Newspaper_Zombie : public Zombie {
private:
	int health2;
	int speed2;
public:
	Newspaper_Zombie() { init("��ֽ��ʬ", 420, 10, 100); speed2 = 4; health2 = 270; }
	bool move(Map*& map, Game* game);
};


//С��ʬ
class Jack_in_the_box_Zombie : public Zombie {
private:
	int bomb;
	void init_bomb();
public:
	Jack_in_the_box_Zombie() { init("С��ʬ", 500, 10, 100); init_bomb(); }
	void func2(Map*& map, Game* game);
};


//Ͷʯ��ʬCATAPULT ZOMBIE
class Catapult_Zombie : public Zombie {
private:
	int ball;
public:
	Catapult_Zombie() { init("Ͷʯ��ʬ", 850, 5, 20); ball=20; }
	bool move(Map*& map, Game* game);
};