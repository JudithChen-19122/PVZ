#pragma once

#include "Map.h"
#include "Zombies.h"
#include "Plant.h"
#include "Store.h"
#include "Bullet.h"
#include<vector>

class Map;
class Peashooter;
class Plant;
class Zombie;
class Store;
class Bullet;

class Game {
private:

	int state; //0:�������� 1:��ͣ������ֲ
	int score;
	Map* map;
	Store* store;

	//�������λ��
	int x;
	int y;

	vector<Zombie*> zombies;
	vector < Plant* > plants;
	vector<Bullet*> bullets;

	void addZombie(int tx, int ty); //���ɽ�ʬ
	int zombie_addspeed; //��ʬ�����ٶ�
	int zombie_addcounter;
	void makeZombies();//������ɽ�ʬ
	bool moveZombies();//��ʬ�ƶ�

	void refresh_base();//ˢ������ͷ���

	void addPlant(int tx, int ty, int type);//��ֲֲ��
	void makePlant();//ֲ�﷢���ڵ��Ȳ���

	void makebullet();//�ڵ�����
	void moving_point(int ch);//�ı��̵�ѡ�����

	void refresh_locinfo();//����ѡ��ؿ���Ϣ���
	void change_r2w();//���ؿ��Ϊ��ɫ
	void change_w2r();//���ؿ��Ϊ��ɫ
	void addsign();//��ӱ��
	void clearsign();//������


	bool run_normal();//�������еĻ�������
	void store_operator();//���̵��н��й�����ֲ�Ȳ���
	void choose_plant_location();//ѡ����ֲ�ĵؿ�


public:
	void init();
	void run();//������Ϸ

	void killplant(Plant* x);
	void killzombie(Zombie* x);
	void killbullet(Bullet* x);
	void addbullet(int tx, int ty, Bullet* b); //�����ڵ�
};