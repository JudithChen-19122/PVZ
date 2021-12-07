#ifndef PLANT_H
#define PLANT_H


class MainWindow;
class Map;
class Store;

#include"mainwindow.h"
#include"Map.h"
#include"Store.h"

class Plant {
protected:
    //种植位置
    int x;
    int y;
    int type;
    int HP;
    int maxHP;
    int status;

    int ATK;
    int speed;
    int counter;
    bool jump;//是否可跳过
    bool pushaway;//是否驱赶到相邻行

    void init(int type, int health, int tspeed, int tATK);

public:
    void plantloc(int tx, int ty);//种植位置
    int getHP() { return HP; }//返回生命值
    int gettype() { return type ; } //返回名字
    virtual void func1(MainWindow* game, Map* map, Store* store) { ; };
    bool jumpable() { return jump; }
    bool ifpushaway() { return pushaway; }
    int getstatus(){return status;}
    int gety(){return y;}
    int getx(){return x;}

    friend class Grid;
};


class Peashooter : public Plant{
public:
    Peashooter() { init(0, 300, 120, 20); }
    void func1(MainWindow *game, Map* map, Store* store);
};


class Sunflower: public Plant{
public:
    Sunflower() { init(1, 300, 1200, 0); }
    void func1(MainWindow* game, Map* map, Store* store);
};


//双发射手
class Repeater:public Plant {
public:
    Repeater() { init(2, 300, 60, 20); }// 由于没有做动画，不好显示一次射出两枚，直接加速
    void func1(MainWindow* game, Map* map, Store* store);
};

//寒冰射手
class SnowPea:public Plant {
public:
    SnowPea() { init(3, 300, 120, 20); }
    void func1(MainWindow* game, Map* map, Store* store);
};

//坚果墙
class Wallnut :public Plant {
public:
    Wallnut() { init(4, 4000, 2, 0); status=0;}
    void func1(MainWindow* game, Map* map, Store* store) ;
};

//高坚果
class Tallnut :public Plant {
public:
    Tallnut() { init(5, 8000, 2, 0); jump = false; status=0; }
    void func1(MainWindow* game, Map* map, Store* store);
};

//倭瓜
class Squash :public Plant {
    int vanish;
public:
    Squash() { init(6, 300, 120, 1800); status=0; vanish=60;}
    void func1(MainWindow* game, Map* map, Store* store);
};

//樱桃炸弹
class Cherry_Bomb :public Plant {
    int vanish;
public:
    Cherry_Bomb() { init(7, 300, 180, 1800); status=0;vanish=60;}
    void func1(MainWindow* game, Map* map, Store* store);
};

//大蒜
class Garlic:public Plant {
public:
    Garlic() { init(8, 400, 180, 0); pushaway = true; }
    void func1(MainWindow* game, Map* map, Store* store) { ; }
};

class Pumpkin :public Plant {
public:
    Pumpkin() { init(9, 4000, 180, 0); }
    friend class Grid;
};








#endif // PLANT_H
