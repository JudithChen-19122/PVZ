#include"Map.h"

void Grid::addZombie(Zombie *z) {
    zombies.push_back(z);
}
void Grid::delZombie(Zombie* x) {
    for (int i = 0; i < zombies.size(); i++)
        if (x == zombies[i])
        {
            zombies[i] = zombies[zombies.size() - 1];
            zombies.pop_back();
            break;
        }
}
void Grid::paint_informtion(QPainter* painter , picture* p){
    for(int i=0;i<zombies.size();i++){
        switch(zombies[i]->gettype()){
        case 0:
            switch(zombies[i]->getstatus()){
            case 0:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->walking_zombie); break;
            case 1:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->waling_zombie_frozen); break;
            }
            break;
        case 1:
            switch(zombies[i]->getstatus()){
            case 0:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->pole_vaulting_zombie); break;
            case 1:painter->drawPixmap(290 + 82 * x - zombies[i]->get_inloction(), 10 + 116 * y, 150,225, p->pole_vaulting_zombie_jumping); break;
            case 2:painter->drawPixmap(290 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->pole_vaulting_zombie_jumped); break;
            case 3:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->pole_vaulting_zombie_frozen); break;
            case 4:painter->drawPixmap(290 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->pole_vaulting_zombie_jumped_frozen); break;
            }
            break;
        case 2:
            switch(zombies[i]->getstatus()){
            case 0:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y,75,120, p-> conehead_zombie); break;
            case 1:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y,p-> walking_zombie); break;
            case 2:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y,75,120,p-> conehead_zombie_frozen); break;
            case 3:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p-> waling_zombie_frozen); break;
            }
            break;
        case 3:
            switch(zombies[i]->getstatus()){
            case 0:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->newspaper_zombie); break;
            case 1:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->newspaper_zombie_empty); break;
            case 2:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->newspaper_zombie_frozen);break;
            case 3:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->newspaper_zombie_empty_frozen);break;
            }
            break;
        case 4:
            switch(zombies[i]->getstatus()){
            case 0:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, 75,120,p->jack_in_the_box_zombie); break;
            case 1:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, 75,120,p->jack_in_the_box_zombie_frozen); break;
            }
            break;
        case 5:
            switch(zombies[i]->getstatus()){
            case 0:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 50 + 116 * y, p->capture_zombie); break;
            case 1:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 50 + 116 * y, p->capture_zombie_frozen); break;
            }
            break;
        }
    }

    if(plant!=NULL){
        switch(plant->gettype()){
        case 0:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->shooter); break;
        case 1:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->sun_flower); break;
        case 2:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->repeater); break;
        case 3:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->ice_shooter); break;
        case 4:switch(plant->getstatus()){
            case 0:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->nut); break;
            case 1:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->nut2);break;
            case 2:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->nut3);break;
            }
            break;
        case 5:switch(plant->getstatus()){
            case 0:painter->drawPixmap(290 + 82 * x - 41,90 + 116 * y,80,120, p->tall_nut); break;
            case 1:painter->drawPixmap(290 + 82 * x - 41,90 + 116 * y,80,120, p->tallnut2);break;
            case 2:painter->drawPixmap(290 + 82 * x - 41,90 + 116 * y,80,120, p->tallnut3);break;
            }
            break;
        case 6:switch(plant->getstatus()){
            case 0:painter->drawPixmap(290 + 82 * x - 55,110 + 116 * y, 120,100,p->squash); break;
            case 1:painter->drawPixmap(290 + 82 * x - 55,110 + 116 * y, 120,100,p->squash); break;
            case 2:painter->drawPixmap(290 + 82 * x + 82 - 55,110 + 116 * y, 120,100,p->squash); break;
            }
            break;
        case 7:switch(plant->getstatus()){
            case 0:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->cherry_bomb); break;
            case 1:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->boom); break;
            }
            break;
        case 8:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, 70,70,p->garlic); break;
        }
    }
    if(pumpkin!=NULL){
        painter->drawPixmap(290 + 82 * x - 41,150 + 116 * y,70,35, p->pumpkin);
    }
    for(int i=0;i<bullets.size();i++){
        if(!bullets[i]->ifsnow()){
            painter->drawPixmap(300 - 41 + 82 * x + bullets[i]->get_inloction(),
                                110 + 116 * y, p->pea);
        }
        else{
            painter->drawPixmap(300 - 41 + 82 * x + bullets[i]->get_inloction(),
                                110 + 116 * y, p->snow_pea);
        }
    }

    if(sunshine_droped>0)
        painter->drawPixmap(300 - 50 + 82 * x , 130 + 116 * y, 60, 60, p->sunshine_p);
}


void Grid::locateGrid_init(int tx, int ty) {
    x = tx;
    y = ty;
    plant=NULL;
    pumpkin=NULL;
    sunshine_droped=0;
}


//僵尸相关
void Grid::killZombie(MainWindow* game, Zombie* x) {
    for (int i = 0; i < zombies.size(); i++)
        if (x == zombies[i])
        {
            zombies[i] = zombies[zombies.size() - 1];
            zombies.pop_back();
            break;
        }

    game->killzombie(x);
    delete x;

}
void Grid::killallZombie(MainWindow* game) {
    if (zombies.empty()) return;
    for (int i = 0; i < zombies.size(); i++) {
        game->killzombie(zombies[i]);
    }
    while (!zombies.empty()) {
        Zombie* temp = zombies.back();
        zombies.pop_back();
        delete temp;
    }
}
bool Grid::haszombie() {
    if (zombies.empty())
        return false;
    else
        return true;
}
void Grid::attackZombie(int ATK, MainWindow* game) {
    if (!zombies.empty()) {
        zombies.front()->HP -= ATK;
        if (zombies.front()->HP <= 0) {
            killZombie(game, zombies.front());
        }
    }
}
void Grid::snow_attackZombie(int ATK, MainWindow* game) {
    if (!zombies.empty()) {
        zombies.front()->snow_attack();
        zombies.front()->HP -= ATK;
        if (zombies.front()->HP <= 0) {
            killZombie(game, zombies.front());
        }
    }

}



//植物相关
Plant* Grid::addplant(int type) {
    if (type != 9) { //除南瓜头以外的植物
        if (plant != NULL) return NULL;
        Plant* p = NULL;
        switch (type) {
        case 0: p = new Peashooter; break;
        case 1: p = new Sunflower; break;
        case 2: p = new Repeater; break;
        case 3: p = new SnowPea; break;
        case 4: p = new Wallnut; break;
        case 5: p = new Tallnut; break;
        case 6: p = new Squash; break;//倭瓜
        case 7: p = new Cherry_Bomb; break;
        case 8: p = new Garlic; break;//大蒜
        default: return NULL;
        }
        plant = p;
        return p;
    }
    if (type == 9) { //南瓜头
        if (pumpkin != NULL) return NULL;
        Pumpkin* p = new Pumpkin;
        pumpkin = p;
        return p;
    }
}
void Grid::delplant(MainWindow* game) {
    if (plant == NULL) return;
    game->killplant(plant);
    delete plant;
    plant = NULL;
}
bool Grid::been_eating(int ATK, MainWindow* game)
{
    bool temp = false;
    if (pumpkin != NULL) {
        pumpkin->HP -= ATK;
        if (pumpkin->HP <= 0) {
            delete pumpkin;
            pumpkin = NULL; //没存在game里直接清除
        }
    }
    else if (plant != NULL) {
        plant->HP -= ATK;
        temp = plant->ifpushaway();
        if (plant->HP <= 0) {
            delplant(game);
        }
    }
    return temp;
}
void Grid::attack_plant(int ATK, MainWindow* game) {
    if (plant != NULL) {
        plant->HP -= ATK;
        plant->ifpushaway();
        if (plant->HP <= 0) {
            delplant(game);
        }
    }
    else if (pumpkin != NULL) {
        pumpkin->HP -= ATK;
        if (pumpkin->HP <= 0) {
            delete pumpkin;
            pumpkin = NULL; //没存在game里直接清除
        }
    }
}
bool Grid::hasplant() {
    if (plant == NULL && pumpkin==NULL) return false;
    else return true;
}
bool Grid::jumpable() {
    if (plant != NULL && plant->jumpable()) return true; //有植物，植物可跳过时可跳过
    else if (plant == NULL && pumpkin != NULL) return true; //只有南瓜头时可跳过
    else return false;
}
void Grid::boomplant(MainWindow* game) {
    delplant(game);
    if (pumpkin != NULL) {
        delete pumpkin;
        pumpkin = NULL;
    }
}

void Grid::addsunshine(){
    sunshine_droped +=25;
}
int Grid::picksunshine(){
    int ans=sunshine_droped;
    sunshine_droped=0;
    return ans;
}
bool Grid::root_out_plant(MainWindow* game){
   bool temp=hasplant();
   boomplant(game);
   return temp;
}
bool Grid::judge_if_cart(){
    for(int i=0;i<zombies.size();i++){
            if(zombies[i]->get_inloction() >= 75)
                     return true;
    }
    return false;
}


//子弹相关
void Grid::addBullet(Bullet* b) {
    bullets.push_back(b);
}
void Grid::delBullet(Bullet* b) {
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets[i] == b)
        {
            bullets[i] = bullets[bullets.size() - 1];
            bullets.pop_back();
            break;
        }
    }
}
void Grid::killBullet(Bullet* b, MainWindow* game) {
    delBullet(b);
    game->killbullet(b);
    delete b;
    b = NULL;
}


void  Map::map_paint_information(QPainter* painter, picture* p){
    for(int i=0;i<COL;i++){
        for(int j=0;j<ROW;j++){
            grid[i][j].paint_informtion(painter,p);
        }
    }
}
void  Map::init() {
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < ROW; j++) {
            grid[i][j].locateGrid_init(i, j);
        }
    }
}

//Map 封装取代友元对grid的直接调用

Plant* Map::map_addplant(int x, int y, int type) {
    return grid[x][y].addplant(type);
}
bool Map::map_hasplant(int x, int y) {
    return grid[x][y].hasplant();
}
void Map::map_delplant(int x, int y, MainWindow* game) {
    grid[x][y].delplant(game);
}
bool Map::map_been_eating(int x, int y, int ATK, MainWindow* game) {
    return grid[x][y].been_eating(ATK, game);
}
bool Map::map_jumpable(int x, int y) {
    return grid[x][y].jumpable();
}
void Map::map_boomplant(int x, int y, MainWindow* game) {
    if (x >= 0 && x < COL && y >= 0 && y < ROW)
        grid[x][y].boomplant(game);
}
void Map::map_attack_plant(int x, int y, int ATK, MainWindow* game) {
    grid[x][y].attack_plant(ATK, game);
}

void Map::map_addsunshine(int x,int y){

    grid[x][y].addsunshine();

}

int Map::map_picksunshine(int x,int y){
        return grid[x][y].picksunshine();
}

bool Map::map_root_out_plant(int x, int y, MainWindow *game){
    return grid[x][y].root_out_plant(game);
}

bool Map::map_judge_if_cart(int y){
    return grid[0][y].judge_if_cart();
}

void  Map::map_addBullet(int x, int y, Bullet* bullet) {
    grid[x][y].addBullet(bullet);
}
void  Map::map_delBullet(int x, int y, Bullet* bullet) {
    grid[x][y].delBullet(bullet);
}
void  Map::map_killBullet(int x, int y, Bullet* bullet, MainWindow* game) {
    grid[x][y].killBullet(bullet, game);
}


void  Map::map_delZombie(int x, int y, Zombie* t) {
    grid[x][y].delZombie(t);
}
void  Map::map_addZombie(int x, int y, Zombie* z) {
    grid[x][y].addZombie(z);
}
void  Map::map_killZombie(int x, int y, MainWindow* game, Zombie* t) {
    grid[x][y].killZombie(game ,t);
}
void  Map::map_attackZombie(int x, int y, int ATK, MainWindow* game) {
    grid[x][y].attackZombie(ATK, game);
}
void  Map::map_snow_attackZombie(int x, int y, int ATK, MainWindow* game) {
    grid[x][y].snow_attackZombie(ATK, game);
}
bool  Map::map_haszombie(int x, int y) {
    return grid[x][y].haszombie();
}
void  Map::map_killallZombie(int x, int y, MainWindow* game) {
    if (x >= 0 && x < COL && y >= 0 && y < ROW)
        grid[x][y].killallZombie(game);
}
