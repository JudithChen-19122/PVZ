#pragma once
#include<Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;




//改变光标位置 调用<Window.h>中的库函数(便于绘图刷新)
void gotoxy(int x, int y);
//改变输出字符颜色
void color(WORD c);