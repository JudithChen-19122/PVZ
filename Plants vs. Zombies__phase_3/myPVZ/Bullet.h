#ifndef BULLET_H
#define BULLET_H

#include"Map.h"
class Map;

class Bullet {
protected:
    //当前所属位置
    int x;
    int y;
    int ATK;
    int speed;
    int counter;
    int snow;
public:
    Bullet() { x = 0; y = 0; ATK = 20; speed = 60; counter = 40; snow = false; }
    virtual void move(Map* map, MainWindow* game);//子弹移动/攻击
    void locate(int tx, int ty);
    bool judgeifattack(Map* map); //判断是否在攻击
    bool ifsnow() { return snow; }
    int get_inloction(){return counter*82/speed;}
};

class SnowBullet: public Bullet{

public:
    SnowBullet() { x = 0; y = 0; ATK = 20; speed = 60; counter = 40; snow = true; }
    void move(Map* map, MainWindow* game);//子弹移动/攻击
};








#endif // BULLET_H
