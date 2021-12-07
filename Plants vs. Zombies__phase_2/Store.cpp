#include"Store.h"

void Good::addGood(string tname, int tcold, int tnum, int tprice) {
	name = tname;
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
	showinfo(point);
}

void Good::showinfo(int point) {
	gotoxy(3, ROW * GH + 5 + num);
	if (num == point) {
		color(0x06);//黑底黄色字体
		cout << num << "." << name << "   $" << price << "  " << counter << "/" << cold << "  ";
		color(0x07);//黑底白色字体
		;
	}
	else
		cout << num << "." << name << "   $" << price << "  " << counter << "/" << cold << "  ";
}

bool Good::boughtable() {
	if (cold == counter)
		return true;
	else
		return false;
}


void Store::init() {
	type = 10;
	goods[0].addGood("豌豆射手", 8, 0, 100);
	goods[1].addGood("向日葵  ", 8, 1, 50 );
	goods[2].addGood("双发射手", 8, 2, 200);
	goods[3].addGood("寒冰射手", 8, 3, 175);
	goods[4].addGood("坚果墙", 30, 4, 50);
	goods[5].addGood("高坚果", 30, 5, 125);
	goods[6].addGood("倭瓜", 30, 6, 50);
	goods[7].addGood("樱桃炸弹", 50, 7, 150);
	goods[8].addGood("大蒜", 8, 8, 50);
	goods[9].addGood("南瓜头", 30, 9, 125);
	print_good();
	sunspeed = 6;
	counter = 0;
	point = 0;
}

void Store::print_good() {
	gotoxy(0, ROW * GH + 3);
	for (int i = 0; i < 30; i++)
		cout << "*";
	cout << "  Store  ";
	for (int i = 0; i < 30; i++)
		cout << "*";
	for (int i = 0; i < type; i++) {
		goods[i].showinfo(point);
	}
}

Plant* Store::buy_good(Map* &map, int num, int x, int y) {
	if (goods[num].boughtable()) {
		if (goods[num].price <= sunshine)
		{
			Plant* p = map->map_addplant(x,y,num);
			if (p != NULL) {
				sunshine -= goods[num].price;
				//直接更新阳光数量
				gotoxy(85, 1);
				cout << "Sunshine:        ";
				gotoxy(85, 1);
				cout << "Sunshine: " << sunshine;
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

void Store::natural_sun() {
	if (counter >= sunspeed)
	{
		sunshine += 25;
		counter = 0;
	}
	else
		counter++;
}

void Store::cold_time() {
	for (int i = 0; i < type; i++)
		goods[i].coldtime();
}