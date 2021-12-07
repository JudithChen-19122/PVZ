#ifndef WEEDING_CART_H
#define WEEDING_CART_H

class MainWindow;
class Map;

#include"mainwindow.h"
#include"Map.h"

class Cart{
private:
    bool carting;
    int dx;//打印位置
    int y;
public:
    void init_location(int ty){ y=ty; dx=0; carting=false;};
    void func0(MainWindow *game, Map* map);
    void paintCart(QPainter* painter, picture* p);
};


#endif // WEEDING_CART_H
