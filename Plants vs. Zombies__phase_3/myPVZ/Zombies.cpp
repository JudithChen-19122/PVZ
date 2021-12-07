#include"Zombies.h"

void Zombie::init(int xtype, int health, int tspeed, int attack,int aspeed) {
    type = xtype;
    maxHP = HP = health;
    speed = tspeed;
    ATK = attack;
    counter = 0;
    eating = false;
    snow = false;
    snowcounter = 600;
    snowtime = 600;
    snow_wait = 0;
    attack_speed=aspeed;
    attack_counter=0;
}

bool Zombie::move(Map*& map, MainWindow* game) {
    bool temp = false;
    judgeifeating(map);
    if (eating) {
        attack_counter++;
        if(attack_counter>=attack_speed){
            if(snow){
                temp = map->map_been_eating(x,y, ATK/2, game);
            }
            else{
                temp = map->map_been_eating(x,y, ATK, game);
            }

            if (temp)//吃到大蒜
            {
                map->map_delZombie(x, y, this);
                if (y < 2) {
                    y++;
                    map->map_addZombie(x, y, this);
                }
                else {
                    y--;
                    map->map_addZombie(x, y, this);
                }
            }
            attack_counter=0;
        }
        return true;
    }
    if (snow) {
        snowcounter++;
        if (snowcounter >= snowtime) { snow_wait = 0; snow = false; counter++; }
        else {
            snow_wait++;
            if (snow_wait >= 2)
            {
                snow_wait = 0;
                counter++;
            }
        }
    }
    else{
        counter += 1;
    }
    if (counter >= speed) {
        map->map_delZombie(x,y,this);
        x--;
        if (x < 0) //Zombies ate your brain
            return false;
        map->map_addZombie(x,y,this);
        counter = 0;
    }
    return true;
}
void Zombie::func2(Map*& map, MainWindow* game){
        if(snow) status=1;
        else status=0;
}


void Zombie::setstartloc(int tx, int ty) {
    x = tx;
    y = ty;
}

void Zombie::judgeifeating(Map*& map) {
    if (x >= 0)
        if (map->map_hasplant(x,y))
            eating = true;
        else
            eating = false;
    else
        eating = false;
}

void Zombie::snow_attack() {
    snow = true;
    snowcounter = 0;
}

bool Pole_Vaulting_Zombie::jumpable(Map*& map) {
    if (x >= 0)
        if (map->map_jumpable(x,y))
            return true;
    return false;
}

bool Pole_Vaulting_Zombie::move(Map*& map,  MainWindow* game) {
    bool temp = false;
    judgeifeating(map);
    bool j=jumpable(map);
    if (eating && jumped) {
        attack_counter++;
        if(attack_counter>=attack_speed){
            if (snow){
                status=4;
                temp = map->map_been_eating(x, y, ATK / 2, game);
            }
            else{
                status=2;
                temp = map->map_been_eating(x, y, ATK, game);
            }
            if (temp)//吃到大蒜
            {
                map->map_delZombie(x, y, this);
                if (y < 3) {
                    y++;
                    map->map_addZombie(x, y, this);
                }
                else {
                    y--;
                    map->map_addZombie(x, y, this);
                }
            }
            attack_counter=0;
        }

        return true;
    }
    if (eating && !jumped) { //闪现一秒钟跳过
        if (!j) { jumped = true; speed = speed2; return true; status=2;} //丢杆子
        status=1;//跳跃中
        counter++;
        speed=speed3;
        if(counter>=speed3){
            eating = false;
            jumped = true;
            counter = 0;
            speed = speed2;
            if(!snow) status=2;
            else status=4;
            if (x <= 0) return false;
            map->map_delZombie(x, y, this);
            x--;
            map->map_addZombie(x, y, this);
        }
        return true;
    }
    if (snow) {
        if(jumped) status=4;
        else status=3;
        snowcounter++;
        if (snowcounter >= snowtime) { snow_wait = 0; snow = false; counter++; }
        else {
            snow_wait++;
            if (snow_wait >= 2)
            {
                snow_wait = 0;
                counter++;
            }
        }
    }
    else{
        if(jumped) status=2;
        else status=0;
        counter += 1;
    }
    if (counter >= speed) {
        map->map_delZombie(x, y, this);
        x--;
        if (x < 0) //Zombies ate your brain
            return false;
        map->map_addZombie(x, y, this);
        counter = 0;
    }
    return true;
}


void  Conehead_Zombie::func2(Map*& map, MainWindow* game){
      if(snow){
          if(HP<=270) status = 3;
          else status = 2;
      }
      else{
          if(HP<=270) status = 1;
          else status = 0;
      }
}


void  Newspaper_Zombie::func2(Map*& map, MainWindow* game){
      if(snow){
          if(HP<=270) status = 3;
          else status = 2;
      }
      else{
          if(HP<=270) status = 1;
          else status = 0;
      }
}



bool Newspaper_Zombie::move(Map*& map,  MainWindow* game) {
    if (HP <= health2) speed = speed2;
    bool temp = false;
    judgeifeating(map);
    if (eating) {
        attack_counter++;
        if(attack_counter>=attack_speed){
            if (snow)
                temp = map->map_been_eating(x, y, ATK / 2, game);
            else
                temp = map->map_been_eating(x, y, ATK, game);

            if (temp)//吃到大蒜
            {
                map->map_delZombie(x, y, this);
                if (y < 2) {
                    y++;
                    map->map_addZombie(x, y, this);
                }
                else {
                    y--;
                    map->map_addZombie(x, y, this);
                }
            }
            attack_counter=0;
        }
        return true;
    }
    if (snow) {
        snowcounter++;
        if (snowcounter >= snowtime) { snow_wait = 0; snow = false; counter++; }
        else {
            snow_wait++;
            if (snow_wait >= 2)
            {
                snow_wait = 0;
                counter++;
            }
        }
    }
    else
        counter += 1;
    if (counter >= speed) {
        map->map_delZombie(x, y, this);
        x--;
        if (x < 0) //Zombies ate your brain
            return false;
        map->map_addZombie(x, y, this);
        counter = 0;
    }
    return true;

}

void Jack_in_the_box_Zombie::init_bomb() {
    int temp = qrand() % 280 ;
    if (temp < 10) bomb = 6;
    else if (temp < 30) bomb = 5;
    else if (temp < 60) bomb = 4;
    else if (temp < 100) bomb = 3;
    else if (temp < 150) bomb = 2;
    else if (temp < 210) bomb = 1;
    else bomb = 0;
}

void Jack_in_the_box_Zombie::func2(Map*& map,  MainWindow* game) {
    if(snow) status=1;
    else status=0;
    if (x == bomb) {
        map->map_boomplant(x, y, game);
        map->map_boomplant(x - 1, y, game);
        map->map_boomplant(x + 1, y, game);
        map->map_boomplant(x, y - 1, game);
        map->map_boomplant(x - 1, y - 1, game);
        map->map_boomplant(x + 1, y - 1, game);
        map->map_boomplant(x, y + 1, game);
        map->map_boomplant(x - 1, y + 1, game);
        map->map_boomplant(x + 1, y + 1, game);
        map->map_killZombie(x,y,game,this);
    }
}

bool Catapult_Zombie::move(Map*& map,  MainWindow* game) {
    if (x > 6 || ball == 0) {  //先压三格, 或者篮球投完了，直接前进
        if (snow) {
            snowcounter++;
            if (snowcounter >= snowtime) { snow_wait = 0; snow = false; counter++; }
            else {
                snow_wait++;
                if (snow_wait >= 2)
                {
                    snow_wait = 0;
                    counter++;
                }
            }
        }
        else
            counter += 1;
        if (counter >= speed) {
            map->map_delZombie(x, y, this);
            x--;
            if (x < 0) //Zombies ate your brain
                return false;
            map->map_addZombie(x, y, this);
            counter = 0;
        }
        map->map_boomplant(x, y, game);
        return true;
    }
    //检查有无植物，没有，前进；有, 投石(已经排除了没球的情况)
    int i = 0;
    for (; i < x; i++) {
        if (map->map_hasplant(i, y))
            break;
    }
    if (i < x) {
        attack_counter++;
        if(attack_counter>=attack_speed){
            ball--;//投石
            map->map_attack_plant(i, y, ATK, game);
            attack_counter = 0;
        }
        return true;
    }
    else {
        if (snow) {
            snowcounter++;
            if (snowcounter >= snowtime) { snow_wait = 0; snow = false; counter++; }
            else {
                snow_wait++;
                if (snow_wait >= 2)
                {
                    snow_wait = 0;
                    counter++;
                }
            }
        }
        else
            counter += 1;
        if (counter >= speed) {
            map->map_delZombie(x, y, this);
            x--;
            if (x < 0) //Zombies ate your brain
                return false;
            map->map_addZombie(x, y, this);
            counter = 0;
        }
        return true;
    }
}

void Catapult_Zombie::func2(Map*& map,  MainWindow* game){
    if(snow) status=1;
    else status=0;
}
