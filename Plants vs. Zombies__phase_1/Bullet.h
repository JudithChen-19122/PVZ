#pragma once
#include"Map.h"
class Map;

class Bullet {
private:
	//��ǰ����λ��
	int x;
	int y;
	int ATK;
	int speed;
	int counter;
public:
	Bullet() { x = 0; y = 0; ATK = 20; speed = 1; counter = 0; }
	void move(Map* map, Game* game);//�ӵ��ƶ�/����
	void locate(int tx, int ty);
	bool judgeifattack(Map* map); //�ж��Ƿ��ڹ���
};