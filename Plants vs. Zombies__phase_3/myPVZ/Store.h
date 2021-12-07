#ifndef STORE_H
#define STORE_H


class Plant;
class Map;

#include "Plant.h"
#include "Map.h"



class Good{
private:
    int cold;//冷却时间
    int counter;
    int num;
    int price;
    int index;

public:
    void addGood(int index, int tcold, int tnum, int tprice);
    void coldtime();
    void setcold(int point);
    bool boughtable();
    bool priceok(int sun){ return sun >= price; }
    friend class Store;
};

class Store {
private:
    int type;
    Good goods[20];
    int point;

public:
    int sunshine;
    Store() { type = 10; sunshine=0; }
    void init();
    Plant* buy_good(Map*& map, int num, int x, int y);
    void cold_time();
    void setpoint(int p) { point = p % type; };
    int getpoint() { return point; }
    bool ifnotcold(int type){ return goods[type].boughtable();}
    bool ifpriceok(int type){ return goods[type].priceok(sunshine);}
    void store_paint_information(QPainter* painter , picture* p);
    //friend class Sunflower;
    friend class Game;
};







#endif // STORE_H
