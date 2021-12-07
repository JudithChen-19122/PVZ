#include<iostream>
#include "Game.h"
using namespace std;


int main() {
	Game game;
	game.init();
	game.run();
	gotoxy(45,26);
	cout << "Game over:Zombies eat your brain";
	gotoxy(0, 40);
	system("pause");
	return 0;
}