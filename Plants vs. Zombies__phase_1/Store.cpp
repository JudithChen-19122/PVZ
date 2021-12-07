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

void Good::setcold() {
	counter = 0;
	showinfo();
}

void Good::showinfo() {
	gotoxy(3, ROW * GH + 5 + num);
	cout << num << "." << name << "   $" << price<<"  "<<counter<<"/"<<cold;
}


bool Good::boughtable() {
	if (cold == counter)
		return true;
	else
		return false;
}


void Store::init() {
	type = 2;
	goods[0].addGood("Íã¶¹ÉäÊÖ", 8, 0, 100);
	goods[1].addGood("ÏòÈÕ¿û  ", 8, 1, 50 );
	print_good();
	sunspeed = 6;
	counter = 0;
}


void Store::print_good() {
	gotoxy(0, ROW * GH + 3);
	for (int i = 0; i < 30; i++)
		cout << "*";
	cout << "  Store  ";
	for (int i = 0; i < 30; i++)
		cout << "*";
	for (int i = 0; i < type; i++) {
		goods[i].showinfo();
	}
}

Peashooter* Store::buy_good(Map* &map, int num, int x, int y) {
	if (goods[num].boughtable()) {
		if (goods[num].price <= sunshine)
		{
			Peashooter* p = map->grid[x][y].addplant(num);
			if (p != NULL) {
				sunshine -= goods[num].price;
				goods[num].setcold();
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