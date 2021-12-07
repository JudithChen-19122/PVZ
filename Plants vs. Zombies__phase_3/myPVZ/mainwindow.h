#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



#include "Load_picture.h"
#include "Map.h"
#include "Zombies.h"
#include "Plant.h"
#include "Bullet.h"
#include "public_parameter.h"
#include "Weeding_cart.h"
#include <QPaintEvent>
#include <QTimer>
#include <QVector>
#include <QPainter>

#include <QMediaPlaylist>
#include <QMediaPlayer>

class Cart;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    picture p;
    QTimer myTimer;
    Map* map;
    Store* store;
    QVector<Zombie*> zombies;
    QVector<Plant*> plants;
    QVector<Bullet*> bullets;
    QVector<Cart*> carts;

    int zombie_addspeed;
    int zombie_addcounter;
    bool buying;
    bool game_over;

    int natural_sunshine_speed;
    int natural_sunshine_counter;

    bool pause;
    bool root_out;

    int start;


    QMediaPlaylist *playlist;
    QMediaPlayer *music;


public:
    QPixmap temp_plant;
    int new_plant_type;
    int mouse_x;
    int mouse_y;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initgame();
    void initScene(); //初始化地图
    void paintEvent(QPaintEvent *event);


    void makeZombie();//随机生成僵尸
    bool moveZombies();//僵尸移动
    void addZombie(int tx, int ty);//添加僵尸
    void killzombie(Zombie* x);

    void addPlant(int tx, int ty, int type);//种植植物
    void makePlant();//植物发射炮弹等操作
    void killplant(Plant* x);

    void makebullet();//炮弹飞行
    void addbullet(int tx, int ty, Bullet* b);
    void killbullet(Bullet* b);

    //阳光相关
    void natural_sunshine();
    void get_sunshine(int tx, int ty);

    void root_out_plant(int tx, int ty);
    void killcart(int ty);
    void updatecart();

    void playgame();
    bool updatePosition();

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent * event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
