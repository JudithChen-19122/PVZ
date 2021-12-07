#include"Weeding_cart.h"


void Cart::func0(MainWindow *game, Map* map){
    if(!carting){
        if(map->map_judge_if_cart(y))
            carting=true;
    }
    if(carting){
        dx++;
        int temp = dx / 82;
        map->map_boomplant(temp,y,game);
        map->map_killallZombie(temp,y,game);
    }
    if(dx>=930){
                game->killcart(y);
    }
}

void Cart::paintCart(QPainter* painter, picture* p){
      painter->drawPixmap(260 - 80 + dx , 120 + 116 * y, 80, 80, p->cart_p);
}

