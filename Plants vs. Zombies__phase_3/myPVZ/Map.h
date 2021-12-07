#ifndef MAP_H
#define MAP_H
#include"public_parameter.h"
#include<QVector>
#include<QPainter>
class Zombie;
class MainWindow;
class picture;
class Plant;
class Pumpkin;
class Bullet;
#include"Zombies.h"
#include"mainwindow.h"
#include"Load_picture.h"
#include"Plant.h"


class Grid {
private:
    int x;
    int y;
    QVector<Zombie*> zombies;
    Plant* plant;
    Pumpkin* pumpkin;//南瓜头 由于没有其他功能，只存在map里, 不存在game里，简化删除操作
    QVector<Bullet*> bullets;
    int sunshine_droped;

public:

    void paint_informtion(QPainter* painter , picture* p);
    void init() {plant = NULL; pumpkin = NULL; sunshine_droped=0;}
    void locateGrid_init(int tx, int ty);//确定位置并初始化

    void delZombie(Zombie* x);//删除僵尸（死亡或者移动到别的格子）
    void addZombie(Zombie* z);//添加僵尸（生成或者移动到这一格）
    void killZombie(MainWindow* game, Zombie* x);//僵尸被杀死
    void attackZombie(int ATK, MainWindow* game);//僵尸受到攻击
    void snow_attackZombie(int ATK, MainWindow* game);//僵尸受到寒冰射手攻击
    bool haszombie();//判断是否有僵尸
    void killallZombie(MainWindow* game);//杀死所有僵尸
    bool judge_if_cart();//是否启用除草车


    Plant* addplant(int type);//种植植物
    bool hasplant();//判断是否有植物
    void delplant(MainWindow* game);//植物被吃掉
    bool been_eating(int ATK, MainWindow* game);//植物被吃,返回是否大蒜被吃
    void attack_plant(int ATK, MainWindow* game);//植物被投石僵尸篮球攻击
    bool jumpable();//判断植物是否可跳过
    void boomplant(MainWindow* game);////炸毁所有植物

    void addsunshine();
    int picksunshine();
    bool root_out_plant(MainWindow* game);


    void addBullet(Bullet* bullet);//添加子弹
    void delBullet(Bullet* bullet);//删除子弹(移走)
    void killBullet(Bullet* bullet,MainWindow* game);//删除子弹(击中)

};

class Map{
private:
    Grid grid[COL][ROW];//grid[x][y]为坐标为（x，y）所在的地块
public:
    void init();
    void map_delZombie(int x, int y, Zombie* t);//删除僵尸（死亡或者移动到别的格子）
    void map_addZombie(int x, int y, Zombie* z);//添加僵尸（生成或者移动到这一格）
    void map_paint_information(QPainter* painter, picture* p);

    void map_killZombie(int x, int y, MainWindow* game, Zombie* t);//僵尸被杀死
    void map_attackZombie(int x, int y, int ATK, MainWindow* game);//僵尸受到攻击
    void map_snow_attackZombie(int x, int y, int ATK, MainWindow* game);//僵尸受到寒冰射手攻击
    bool map_haszombie(int x, int y);//判断是否有僵尸
    void map_killallZombie(int x, int y, MainWindow* game);//杀死所有僵尸


    Plant* map_addplant(int x, int y,int type);//种植植物
    bool map_hasplant(int x, int y);//判断是否有植物
    void map_delplant(int x, int y, MainWindow* game);//植物被吃掉
    bool map_been_eating(int x, int y,int ATK, MainWindow* game);//植物被吃
    bool map_jumpable(int x, int y);//判断植物是否可跳过
    void map_boomplant(int x, int y, MainWindow* game);//炸毁所有植物
    void map_attack_plant(int x, int y, int ATK, MainWindow* game);//植物被投石僵尸篮球攻击

    void map_addsunshine(int x,int y);
    int map_picksunshine(int x,int y);
    bool map_root_out_plant(int x,int y,MainWindow* game);
    bool map_judge_if_cart(int y);

    void  map_addBullet(int x, int y, Bullet* bullet);//添加子弹
    void  map_delBullet(int x, int y, Bullet* bullet);//删除子弹(移走)
    void  map_killBullet(int x, int y, Bullet* bullet, MainWindow* game);//删除子弹(击中)
};















#endif // MAP_H
