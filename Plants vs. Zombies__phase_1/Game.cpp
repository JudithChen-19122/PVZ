#include"Game.h"
#include <cstdlib>
#include <ctime>
#include <windows.h> //光标移动
#include <conio.h> //监听键盘事件
#define random(x) rand()%(x)
using namespace std;

void Game::init() {
	state = 0;
	map = new Map;
	map->init();
	zombie_addspeed = 15;
	zombie_addcounter = 0;
	srand((int)time(0));//生成随机数所需种子
	store = new Store;
	store->init();
	store->sunshine = 300;
	score = 0;
	addsign();//选择标记
}

void Game::refresh_base() {
	score++;
	gotoxy(85, 1);
	cout << "Sunshine: " << store->sunshine;
	gotoxy(85, 3);
	cout << "Score: " << score;
    
	gotoxy(85, 6);
	cout << "当前选择位置：";

	gotoxy(85, 7);
	cout << "x: " << x << "   y: " << y;

	gotoxy(85, 20);
	cout << "按 B 键进入商店               ";

}

void Game::refresh_locinfo() {
	gotoxy(85, 7);
	cout << "x: " << x << "   y: " << y;

}


void Game::addPlant(int tx, int ty, int type) {
	if (tx < 0 || tx >= COL || ty < 0 || ty >= ROW) return;
	Peashooter* p= store->buy_good(map, type, tx, ty);
	if(p!=NULL)
		peashooters.push_back(p);
}

void Game::addZombie(int tx, int ty) {
	if (tx < 0 || tx >= COL || ty < 0 || ty >= ROW) return;
	Zombie* z = new Zombie;
	z->setstartloc(tx, ty);
	map->grid[tx][ty].addZombie(z);
	zombies.push_back(z);
}

void Game::addbullet(int tx, int ty) {
	if (tx < 0 || tx >= COL || ty < 0 || ty >= ROW) return;
	Bullet* b = new Bullet;
	b->locate(tx, ty);
	map->grid[tx][ty].addBullet(b);
	bullets.push_back(b);
}

void Game::makeZombies() {
	zombie_addcounter++;
	if (zombie_addcounter >= zombie_addspeed) {
		addZombie(6, random(ROW));
		zombie_addcounter = 0;
	}
}

bool Game::moveZombies() {
	int temp = true;
	for (int i = 0; i < zombies.size(); i++) {
		temp = zombies[i]->move(map, this);
		if (!temp) return false;
	}
	return true;
}


void Game::makePlant() {
	for (int i = 0; i < peashooters.size(); i++) {
		peashooters[i]->shoot(this, map);
	}
}

void Game::makebullet() {
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->move(map,this);
	}
}

bool Game::run_normal() {
	int temp = true;
	store->cold_time();
	store->natural_sun();
	store->print_good();
	//pay attention to operation order	
	makeZombies();
	makePlant();
	makebullet();
	temp=moveZombies();
	if (!temp) return false;
	//makePlant();
	//makebullet();
	map->refresh();
	refresh_base();
	Sleep(1000);
	return true;
}


void  Game::choose_plant_location() {
	gotoxy(80, 20);
	cout << "您正处于选择地块界面，按 esc 键退出      ";
	gotoxy(80, 21);
	cout << "A:← W:↑ D:→ S:↓	  PPPP为所选位置  ";
	int ch;
	while (true) {
		if (_kbhit()) {
			ch = _getch();
			if(ch==27)
				break;
			switch (ch) {
			case 65:    //A
			case 97:
				if (x > 0) {
					clearsign();
					x--;
					addsign();
				}
				break;

			case 68:    //D
			case 100:
				if (x < 6) {
					clearsign();
					x++;
					addsign();
				}
				break;

			case 87:    //W
			case 119:
				if (y > 0) {
					clearsign();
					y--;
					addsign();
				} 
				break;

			case 83:    //S
			case 115:
				if (y < 2) {
					clearsign();
				    y++;
					addsign();
				} 
				break;
			default:;
			}
			refresh_locinfo();
		}
	}
	gotoxy(80, 20);
	cout << "您正处于商店界面，按 esc 键退出          ";
	gotoxy(80, 21);
	cout << "按 C 键选择地块， 按对应数字键购买种植   ";

}

void Game::store_operator() {
	gotoxy(80, 20);
	cout << "您正处于商店界面，按 esc 键退出          ";
	gotoxy(80, 21);
	cout << "按 C 键选择地块， 按对应数字键购买种植   ";
	int ch;
	while (true) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 27) //按 esc退出商店
				break;
			else if (ch == 67 || ch == 99) // 按 c/C 选择地块
				choose_plant_location();
			else if (ch == 48) //0
				addPlant(x,y,ch - 48);
		}
	}
	state = 0;
	gotoxy(80, 20);
	cout << "按 B 键进入商店                          ";
	gotoxy(80, 21);
	cout << "                                         ";
}

void Game::run() {
	//addPlant(0, 1, 0);
	//addZombie(6, 1);
	//map->refresh();
	int ch;
	while (true) {
		refresh_base();
		if (_kbhit()) {
			ch = _getch();
			if (state == 0 && (ch == 66 || ch == 98)) // b/B:进入商店 
				state = 1;
		}
	    if(state == 0){
			bool gamenotover=true;
			gamenotover=run_normal();
			if (!gamenotover) break;
		}
		else if (state == 1) {
			store_operator();
		}
	}
}


void Game::change_r2w() {
	color(0x07);//黑底白色字体
	int dx = x * GW;
	int dy = y * GH;
	gotoxy(dx, dy);
	for (int i = 0; i < GW + 1; i++)
		cout << "#";
	for (int i = 1; i < GH; i++)
	{
		gotoxy(dx, dy + i);
		cout << "#";
		gotoxy(dx+GW, dy + i);
		cout << "#";
	}
	gotoxy(dx, dy + GH);
	for (int i = 0; i < GW + 1; i++)
		cout << "#";
	color(0x07);//黑底白色字体
}
void Game::change_w2r() {
	color(0x0c);//黑底红色字体
	int dx = x * GW;
	int dy = y * GH;
	gotoxy(dx, dy);
	for (int i = 0; i < GW + 1; i++)
		cout << "#";
	for (int i = 1; i < GH; i++)
	{
		gotoxy(dx, dy + i);
		cout << "#";
		gotoxy(dx + GW, dy + i);
		cout << "#";
	}
	gotoxy(dx, dy + GH);
	for (int i = 0; i < GW + 1; i++)
		cout << "#";
	color(0x07);//黑底白色字体
}


void Game::addsign() {
	change_w2r();
	//gotoxy(x * GW + 5, y * GH + 1);
	//cout << "PPPP";
}
void Game::clearsign() {
	change_r2w();
	//gotoxy(x * GW + 5, y * GH + 1);
	//cout << "     ";
}