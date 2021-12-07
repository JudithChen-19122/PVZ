#ifndef ZOMBIES_H
#define ZOMBIES_H

class Map;
class MainWindow;
#include"Map.h"
#include"mainwindow.h"
#include<QtGlobal>

class Zombie {
protected:
    int status;
    int type ;
    int HP;
    int maxHP;
    int x, y;//当前所处位置
    int ATK;  //攻击力/s
    int speed; //移动速度  （数值越大，速度越小)
    int counter;
    void init(int xtype, int health, int tspeed, int attack, int aspeed);
    bool eating;//是否正在吃植物（停止不动，攻击前一格的植物）
    bool snow;
    int snowcounter;
    int snowtime;
    int snow_wait;
    int attack_speed;
    int attack_counter;

public:
    Zombie() { init(0, 270, 600, 100, 60); snow=false; eating=false; status=0; }
    int gettype() const { return type; }
    int getHP() { return HP; }//返回生命值
    void setstartloc(int tx, int ty);//设置起始位置
    virtual bool move(Map*& map, MainWindow* game);//僵尸移动/攻击
    void judgeifeating(Map*& map); //判断是否在吃植物
    void snow_attack();
    bool ifsnow() { return snow; }
    virtual void func2(Map*& map, MainWindow* game);//额外的一些功能
    int get_inloction(){return counter*82/speed;}
    int getstatus(){return status;}

    friend class Grid;
};


//撑杆僵尸

class Pole_Vaulting_Zombie : public Zombie {
private:
    int speed2;
    bool jumped;
    int speed3;
    bool jumpable(Map*& map);
public:
    Pole_Vaulting_Zombie() { init(1, 500, 300, 100, 60); jumped = false; speed2 = 540; speed3= 40 ;status=0;snow=false; eating=false; }
    bool move(Map*& map,  MainWindow* game);
    void func2(Map*& map, MainWindow* game){;};
};

//路障僵尸
class Conehead_Zombie : public Zombie {
public:
    Conehead_Zombie() { init(2, 640, 600, 100, 60); status=0; snow=false; eating=false;}
    void func2(Map*& map, MainWindow* game);
};

//报纸僵尸
class Newspaper_Zombie : public Zombie {
private:
    int health2;
    int speed2;
public:
    Newspaper_Zombie() { init(3, 420, 600, 100, 60); speed2 = 240; health2 = 270;status=0;snow=false; eating=false;}
    bool move(Map*& map,  MainWindow* game);
    void func2(Map*& map, MainWindow* game);
};


//小丑僵尸
class Jack_in_the_box_Zombie : public Zombie {
private:
    int bomb;
    void init_bomb();
public:
    Jack_in_the_box_Zombie() { init(4, 500, 600, 100, 60); init_bomb(); status=0;snow=false; eating=false;}
    void func2(Map*& map,  MainWindow* game);
};


//投石僵尸CATAPULT ZOMBIE
class Catapult_Zombie : public Zombie {
private:
    int ball;
public:
    Catapult_Zombie() { init(5, 850, 300, 20, 60); ball=20; status=0;snow=false; eating=false;}
    bool move(Map*& map,  MainWindow* game);
    void func2(Map*& map, MainWindow* game);
};


#endif // ZOMBIES_H
