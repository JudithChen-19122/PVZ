#include"Store.h"

void Good::addGood(int type, int tcold, int tnum, int tprice) {
    index = type ;
    cold = tcold;
    num = tnum;
    price = tprice;
    counter = tcold;
}

void Good::coldtime() {
    if (counter < cold)
        counter++;
}

void Good::setcold(int point) {
    counter = 0;
}


bool Good::boughtable() {
    if (cold == counter)
        return true;
    else
        return false;
}

void Store::init() {
    type = 10;
    goods[0].addGood(0, 480, 0, 100);
    goods[1].addGood(1, 480, 1, 50 );
    goods[2].addGood(2, 480, 2, 200);
    goods[3].addGood(3, 480, 3, 175);
    goods[4].addGood(4, 1800, 4, 50);
    goods[5].addGood(5, 1800, 5, 125);
    goods[6].addGood(6, 1800, 6, 50);
    goods[7].addGood(7, 3000, 7, 150);
    goods[8].addGood(8, 480, 8, 50);
    goods[9].addGood(9, 1800, 9, 125);
    point = 0;
}

Plant* Store::buy_good(Map* &map, int num, int x, int y) {
    if (goods[num].boughtable()) {
        if (goods[num].price <= sunshine)
        {
            Plant* p = map->map_addplant(x,y,num);
            if (p != NULL) {
                sunshine -= goods[num].price;
                //直接更新阳光数量
                goods[num].setcold(point);
                p->plantloc(x, y);
                return p;
            }
            else
                return NULL;
        }
        else
            return NULL;
    }
    else
        return NULL;
}

void Store::cold_time() {
    for (int i = 0; i < type; i++)
        goods[i].coldtime();
}

void Store::store_paint_information(QPainter* painter , picture* p){
    if(ifnotcold(0))
        painter->drawPixmap(400, 12, 48, 67, p->board_shooter);
    else
        painter->drawPixmap(400, 12, 48, 67, p->cool_shooter);
    if(ifnotcold(1))
        painter->drawPixmap(450, 12, 48, 67, p->board_sunflower);
    else
        painter->drawPixmap(450, 12, 48, 67, p->cool_flower);
    if(ifnotcold(2))
        painter->drawPixmap(500, 12, 48, 67, p->board_dbshooter);
    else
        painter->drawPixmap(500, 12, 48, 67, p->cool_dbshooter);
    if(ifnotcold(3))
        painter->drawPixmap(550, 12, 48, 67, p->board_iceshooter);
    else
        painter->drawPixmap(550, 12, 48, 67, p->cool_ice);
    if(ifnotcold(4))
        painter->drawPixmap(600, 12, 48, 67, p->board_nut);
    else
        painter->drawPixmap(600, 12, 48, 67, p->cool_nut);
    if(ifnotcold(5))
        painter->drawPixmap(650, 12, 48, 67, p->board_tallnut);
    else
        painter->drawPixmap(650, 12, 48, 67, p->cool_tn);
    if(ifnotcold(6))
        painter->drawPixmap(700, 12, 48, 67, p->board_squash);
    else
        painter->drawPixmap(700, 12, 48, 67, p->cool_squash);
    if(ifnotcold(7))
        painter->drawPixmap(750, 12, 48, 67, p->board_cherry_bomb);
    else
        painter->drawPixmap(750, 12, 48, 67, p->cool_cherry);
    if(ifnotcold(8))
        painter->drawPixmap(800, 12, 48, 67, p->board_garlic);
    else
        painter->drawPixmap(800, 12, 48, 67, p->cool_garlic);
    if(ifnotcold(9))
        painter->drawPixmap(850, 12, 48, 67, p->board_pumpkin);
    else
        painter->drawPixmap(850, 12, 48, 67, p->cool_pumpkin);

}
