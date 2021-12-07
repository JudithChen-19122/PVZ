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
class Plant;
class Pumpkin;

class Grid {
private:
	//����������λ��(�����ϷͥԺ����)
	int x;
	int y;
	//ƫ��������Ի�ͼ
	int dx;
	int dy;
	vector<Zombie*> zombies;
	Plant* plant;  
	Pumpkin* pumpkin;//�Ϲ�ͷ ����û���������ܣ�ֻ����map��, ������game���ɾ������
	vector<Bullet*> bullets;

	bool refresh;  //�Ƿ�ˢ��

	void snowdraw(const string s); //����Ч�����

public:
	void init() { refresh = false;  plant = NULL; pumpkin = NULL; }
	void locateGrid_init(int tx, int ty);//ȷ��λ�ò���ʼ��
	void drawinfor(); //�����ڲ���Ϣ��ӡ

	void delZombie(Zombie* x);//ɾ����ʬ�����������ƶ�����ĸ��ӣ�
	void addZombie(Zombie* z);//��ӽ�ʬ�����ɻ����ƶ�����һ��
	void killZombie(Game* game, Zombie* x);//��ʬ��ɱ��
	void attackZombie(int ATK, Game* game);//��ʬ�ܵ�����
	void snow_attackZombie(int ATK, Game* game);//��ʬ�ܵ��������ֹ���
	bool haszombie();//�ж��Ƿ��н�ʬ
	void killallZombie(Game* game);//ɱ�����н�ʬ

	
	Plant* addplant(int type);//��ֲֲ��
	bool hasplant();//�ж��Ƿ���ֲ��
	void delplant(Game* game);//ֲ�ﱻ�Ե�
	bool been_eating(int ATK, Game* game);//ֲ�ﱻ��,�����Ƿ���ⱻ��
	void attack_plant(int ATK, Game* game);//ֲ�ﱻͶʯ��ʬ���򹥻�
	bool jumpable();//�ж�ֲ���Ƿ������
	void boomplant(Game* game);////ը������ֲ��

	
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


	void map_delZombie(int x, int y, Zombie* t);//ɾ����ʬ�����������ƶ�����ĸ��ӣ�
	void map_addZombie(int x, int y, Zombie* z);//��ӽ�ʬ�����ɻ����ƶ�����һ��
	void map_killZombie(int x, int y, Game* game, Zombie* t);//��ʬ��ɱ��
	void map_attackZombie(int x, int y, int ATK, Game* game);//��ʬ�ܵ�����
	void map_snow_attackZombie(int x, int y, int ATK, Game* game);//��ʬ�ܵ��������ֹ���
	bool map_haszombie(int x, int y);//�ж��Ƿ��н�ʬ
	void map_killallZombie(int x, int y, Game* game);//ɱ�����н�ʬ


	Plant* map_addplant(int x, int y,int type);//��ֲֲ��
	bool map_hasplant(int x, int y);//�ж��Ƿ���ֲ��
	void map_delplant(int x, int y, Game* game);//ֲ�ﱻ�Ե�
	bool map_been_eating(int x, int y,int ATK, Game* game);//ֲ�ﱻ��
	bool map_jumpable(int x, int y);//�ж�ֲ���Ƿ������
	void map_boomplant(int x, int y, Game* game);//ը������ֲ��
	void map_attack_plant(int x, int y, int ATK, Game* game);//ֲ�ﱻͶʯ��ʬ���򹥻�


	void  map_addBullet(int x, int y, Bullet* bullet);//����ӵ�
	void  map_delBullet(int x, int y, Bullet* bullet);//ɾ���ӵ�(����)
	void  map_killBullet(int x, int y, Bullet* bullet, Game* game);//ɾ���ӵ�(����)
};