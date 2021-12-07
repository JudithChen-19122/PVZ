#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtGlobal>
#include<QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::setMouseTracking(true);
    QMainWindow::centralWidget()->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    if(!start) {
        painter.drawPixmap(0, 0, 1050, 700,p.main_menu);
        return;
    }
    painter.drawPixmap(0, 0, 1402, 700,p.background);
    painter.drawPixmap(300, 0, 610, 90,p.store);
    painter.drawPixmap(900,0,p.ShovelBank);


    QString s = QString::number(store->sunshine);
    painter.drawText(328,80,s);

    store->store_paint_information(&painter,&p);

    map->map_paint_information(&painter,&p);

    if(buying)
    {
        painter.drawPixmap(mouse_x-40,mouse_y-40,temp_plant);
    }

    if(game_over)
        painter.drawPixmap(300,100,p.game_over);

    if(pause)
        painter.drawPixmap(100,20,150,45,p.continue_button);
    else
        painter.drawPixmap(100,20,150,45,p.pause_button);

    if(root_out)
        painter.drawPixmap(mouse_x-40,mouse_y-40,p.shovel);
    else
        painter.drawPixmap(900,0,p.shovel);

    for(int i=0;i<5;i++)
        if(carts[i]!=NULL)
            carts[i]->paintCart(&painter,&p);
}

void MainWindow::updatecart(){
    for(int i=0;i<5;i++)
        if(carts[i]!=NULL)
            carts[i]->func0(this,map);
}
void MainWindow::killcart(int ty){
    carts[ty]=NULL;
}

void MainWindow::initScene(){
    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sound/Grasswalk.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();


    setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    setWindowTitle(GAME_TITLE);
    //paintEvent(NULL);
    myTimer.setInterval(16);
    pause=false;
    start=false;
    //setMouseTracking(true);
}

void MainWindow::initgame(){
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    map = new Map;
    store= new Store;
    map->init();
    zombie_addspeed = 400;
    zombie_addcounter = 0;
    store->sunshine = 3000;
    store->init();
    buying=false;
    game_over=false;
    root_out=false;

    for(int i=0;i<5;i++){
        Cart* t= new Cart;
        t->init_location(i);
        carts.push_back(t);
    }

    natural_sunshine_speed = 360;
    natural_sunshine_counter = 0;


}

void MainWindow::makeZombie(){
    zombie_addcounter++;
    if (zombie_addcounter >= zombie_addspeed) {
        addZombie(8, qrand()%ROW);
        zombie_addcounter = 0;
    }

}
void MainWindow::addZombie(int tx, int ty) {
    if (tx < 0 || tx >= COL || ty < 0 || ty >= ROW) return;
    int temp = qrand()%18;
    Zombie* z;
    switch (temp) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        z = new Zombie; break;
    case 5:
    case 6:
    case 7:
    case 8:
        z = new Conehead_Zombie; break;
    case 9:
    case 10:
    case 11:
        z = new Pole_Vaulting_Zombie; break;
    case 12:
    case 13:
    case 14:
        z = new Newspaper_Zombie; break;
    case 15:
    case 16:
        z = new Jack_in_the_box_Zombie; break;
    case 17:
        z = new Catapult_Zombie; break;
    default:  z = NULL;
    }

    z->setstartloc(tx, ty);
    map->map_addZombie(tx,ty,z);
    zombies.push_back(z);
}

bool MainWindow::moveZombies(){
    int temp = true;
    for (int i = 0; i < zombies.size(); i++) {
        temp = zombies[i]->move(map, this);
        if (!temp) return false;
        zombies[i]->func2(map, this);
    }
    return true;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(!start){
        if(event->x()>550 && event->x()<845 && event->y()>85 && event->y()<245)
            start=true;
        return;
    }
    if(event->x()>400 && event->x()<900 && event->y()>12 && event->y()<80)
    {
        if(!root_out && !game_over && !pause){
            if(!buying)
            {
                int col = (event->x() - 400) / 50;
                if(!(store->ifnotcold(col))||(!store->ifpriceok(col)))
                    return;
                switch(col)
                {
                case 0: temp_plant.load(SHOOTER); break;
                case 1: temp_plant.load(SUNFLOWER); break;
                case 2: temp_plant.load(REPEATER); break;
                case 3: temp_plant.load(ICESHOOTER); break;
                case 4: temp_plant.load(NUT); break;
                case 5: temp_plant.load(TALLNUT); break;
                case 6: temp_plant.load(SQUASH); break;
                case 7: temp_plant.load(CHERRY); break;
                case 8: temp_plant.load(GARLIC); break;
                case 9: temp_plant.load(PUMPKIN); break;
                }
                new_plant_type = col;
            }
            buying = !buying;
        }
    }
    if(event->x()>260 && event->x()<998 && event->y()>90 && event->y()<670){
        if(!game_over && !pause){
            if(buying){
                int px= (event->x()-260)/82;
                int py= (event->y()-90)/116;
                addPlant(px,py,new_plant_type);
                buying=false;
            }
            else{
                int px= (event->x()-260)/82;
                int py= (event->y()-90)/116;
                get_sunshine(px,py);
            }
            if(root_out){
                int px= (event->x()-260)/82;
                int py= (event->y()-90)/116;
                root_out_plant(px,py);
                root_out = false;
            }
        }
    }
    if(event->x()>100 && event->x()<250 && event->y()> 20 && event->y()<65){
        if(!game_over){
            if(pause) {
                pause=!pause;
                music->play();
                update();
                myTimer.start();
            }
            else {
                pause=!pause;
                music->pause();
                update();
                myTimer.stop();

            }
        }
    }

    if(event->x()>900 && event->x()<970 && event->y()> 0 && event->y()<75){
        if(!buying && !game_over && !pause){
            root_out=!root_out;
        }
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent * event)
{
    mouse_x = event->x();
    mouse_y = event->y();
}


bool MainWindow::updatePosition(){
    bool x=true;
    makeZombie();
    x=moveZombies();
    makePlant();
    makebullet();
    store->cold_time();
    natural_sunshine();
    updatecart();
    return x;
}

void MainWindow::playgame(){
    myTimer.start();
    //监听定时器
    connect(&myTimer,&QTimer::timeout,[=](){
        if(start){
            //更新游戏中元素的坐标
            bool x=updatePosition();
            if(!x) {
                game_over=true;
                music->stop();
                myTimer.stop();
                update();
             }
            //重新绘制图片
             update();
        }
    });
}

void MainWindow::addPlant(int tx, int ty, int type) {
    if (tx < 0 || tx >= COL || ty < 0 || ty >= ROW) return;
    Plant* p= store->buy_good(map, type, tx, ty);
    if (p != NULL && type != 9)//不是南瓜头
        plants.push_back(p);
}
void MainWindow::makePlant() {
    for (int i = 0; i < plants.size(); i++) {
        plants[i]->func1(this, map, store);
    }
}

void MainWindow::natural_sunshine(){
    natural_sunshine_counter++;
    if(natural_sunshine_counter>=natural_sunshine_speed){
        int tx=qrand()%9;
        int ty=qrand()%5;
        map->map_addsunshine(tx,ty);
        natural_sunshine_counter=0;
    }
}

void MainWindow::get_sunshine(int tx,int ty){
    int tsunshine=map->map_picksunshine(tx,ty);
    store->sunshine += tsunshine;
}


void MainWindow::root_out_plant(int tx, int ty){
    bool temp=map->map_root_out_plant(tx,ty,this);
    if(temp) store->sunshine += 30;
}

void MainWindow::makebullet() {
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i]->move(map,this);
    }
}
void MainWindow::addbullet(int tx, int ty, Bullet* b) {
    b->locate(tx, ty);
    map->map_addBullet(tx,ty,b);
    bullets.push_back(b);
}
void MainWindow::killbullet(Bullet* b) {
    for (int i = 0; i < bullets.size(); i++) {
        if (b == bullets[i])
        {
            bullets[i] = bullets[bullets.size() - 1];
            bullets.pop_back();
            break;
        }
    }
}



void MainWindow::killplant(Plant* plant) {
    for (int i = 0; i < plants.size(); i++) {
        if (plant == plants[i])
        {
            plants[i] = plants[plants.size() - 1];
            plants.pop_back();
            break;
        }
    }
}
void MainWindow::killzombie(Zombie* x) {
    for (int i = 0; i < zombies.size(); i++)
        if (x == zombies[i])
        {
            zombies[i] = zombies[zombies.size() - 1];
            zombies.pop_back();
            break;
        }
}

