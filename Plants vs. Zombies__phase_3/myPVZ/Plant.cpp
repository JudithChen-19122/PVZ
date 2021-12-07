#include"Plant.h"


void Plant::plantloc(int tx, int ty) {
    x = tx;
    y = ty;
}

void Plant::init(int ttype, int health, int tspeed, int tATK) {
    type = ttype;
    maxHP = HP = health;
    speed = tspeed;
    counter = 0;
    ATK = tATK;
    jump = true;
    pushaway = false;
}

//sunflower
void Sunflower::func1(MainWindow* game, Map* map, Store* store){
    counter += 1;
    if (counter >= speed) {
        map->map_addsunshine(x,y);
        counter = 0;
    }
}

//Peashooter
void Peashooter::func1(MainWindow* game, Map* map, Store* store) {

    bool temp=false;
    for (int j = x; j < 9; j++) {
        if (map->map_haszombie(j,y)) {
            temp = true;  //该行上有僵尸
            break;
        }
    }

    if (!temp) return;
    counter += 1;
    if (counter >= speed) {
        Bullet* b = new Bullet;
        game->addbullet(x, y, b);
        counter = 0;
    }
}

//Repeater
void Repeater::func1(MainWindow* game, Map* map, Store* store) {

    bool temp = false;
    for (int j = x; j < 9; j++) {
        if (map->map_haszombie(j, y)) {
            temp = true;  //该行上有僵尸
            break;
        }
    }

    if (!temp) return;
    counter += 1;
    if (counter >= speed) {
        Bullet* b = new Bullet;
        game->addbullet(x, y, b);
        counter = 0;
    }
}

//SnowPea
void SnowPea::func1(MainWindow* game, Map* map, Store* store) {
    bool temp = false;
    for (int j = x; j < 9; j++) {
        if (map->map_haszombie(j, y)) {
            temp = true;  //该行上有僵尸
            break;
        }
    }
    if (!temp) return;
    counter += 1;
    if (counter >= speed) {
        Bullet* b = new SnowBullet;
        game->addbullet(x, y, b);
        counter = 0;
    }
}

void Wallnut::func1(MainWindow* game, Map* map, Store* store) {
    if(HP<=2700) status=1;
    if(HP<=1400) status=2;
}

void Tallnut::func1(MainWindow* game, Map* map, Store* store) {
    if(HP<=5400) status=1;
    if(HP<=2700) status=2;
}

//倭瓜
void Squash::func1(MainWindow* game, Map* map, Store* store) {
    if(status==0){
        int temp = 3;
        if (x < 8)
            if (map->map_haszombie(x+1, y))
                temp = 1;
        if (map->map_haszombie(x, y))
            temp = 0;

        if (temp == 3) return;

        status=1;
        if(temp==0) status =1;
        else status = 2;
        map->map_killallZombie(x+temp,y,game);
    }
    if(status!=0){
        counter++;
        if(counter>=vanish)
            map->map_delplant(x,y,game);
    }
}

//Cherry_Bomb
void Cherry_Bomb::func1(MainWindow* game, Map* map, Store* store) {
    if(status==0){
        counter += 1;
        if (counter >= speed) {
            map->map_killallZombie(x, y, game);
            map->map_killallZombie(x + 1, y, game);
            map->map_killallZombie(x - 1, y, game);
            map->map_killallZombie(x, y - 1, game);
            map->map_killallZombie(x + 1, y - 1, game);
            map->map_killallZombie(x - 1, y - 1, game);
            map->map_killallZombie(x, y + 1, game);
            map->map_killallZombie(x + 1, y + 1, game);
            map->map_killallZombie(x - 1, y + 1, game);
            status=1;
            counter=0;
        }
    }
    if(status==1){
        counter++;
        if(counter>=vanish)
            map->map_delplant(x,y,game);
    }

}
