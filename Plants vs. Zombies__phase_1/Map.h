#pragma once
#include"General_Tools.h"
#include"Zombies.h"
#include"Plant.h"
#include"Bullet.h"
#include"Game.h"
#include<vector>
#include<iostream>

#define ROW 3
#define COL 7
#define GW  11
#define GH  6
#define MAPWITCH 75


class Zombie;
class Peashooter;
class Bullet;
class Game;

class Grid {
private:
	//����������λ��(�����ϷͥԺ����)
	int x;
	int y;
	//ƫ��������Ի�ͼ
	int dx;
	int dy;
	Zombie* zombie;
	Peashooter* peashooter;
	vector<Bullet*> bullets;

	bool refresh;  //�Ƿ�ˢ��

	

public:
    void init() { refresh = false; zombie = NULL; peashooter = NULL;}
	void locateGrid_init(int tx, int ty);//ȷ��λ�ò���ʼ��
	void drawinfor(); //�����ڲ���Ϣ��ӡ

	void delZombie();//ɾ����ʬ�����������ƶ�����ĸ��ӣ�
	void addZombie(Zombie* z);//��ӽ�ʬ�����ɻ����ƶ�����һ��
	void killZombie(Game* game);//��ʬ��ɱ��
	void attackZombie(int ATK, Game* game);//��ʬ�ܵ�����
	bool haszombie();//�ж��Ƿ��н�ʬ

	
	Peashooter* addplant(int type);//��ֲֲ��
	bool hasplant();//�ж��Ƿ���ֲ��
	void delplant(Game* game);//ֲ�ﱻ�Ե�
	void been_eating(int ATK, Game* game);//ֲ�ﱻ��

	
	void addBullet(Bullet* bullet);//����ӵ�
	void delBullet(Bullet* bullet);//ɾ���ӵ�(����)
	void killBullet(Bullet* bullet,Game* game);//ɾ���ӵ�(����)

	
	bool needrefresh() { return refresh; }

    friend class Map;
};


class Map{
private:
	Grid grid[COL][ROW];//grid[x][y]Ϊ����Ϊ��x��y�����ڵĵؿ�

public:
	Map();
	void init();//��ʼ��
	void drawGrid(); //��ܻ���
	void refresh();//�������и��ӣ�����Ƿ���Ҫˢ��
	
	friend class Game;
	friend class Zombie;
	friend class Peashooter;
	friend class Sunflower;
	friend class Store;
	friend class Bullet;
};