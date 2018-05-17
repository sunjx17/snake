#include <stdio.h> 
#include <stdlib.h>   
#include <conio.h>
#include<windows.h>
#pragma warning(disable:4996)
#pragma warning(disable:4305)


void gotoc(COORD coord){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
void gotoxy(int x, int y)
	{
	COORD coord = {x, y};   
	/*COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标。其定义为：
	typedef struct _COORD {
	SHORT X; // horizontal coordinate
	SHORT Y; // vertical coordinate
	} COORD;*/
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
COORD keypos(COORD c){
	int key;
	key=getch();
	switch(key)
		{
		case VK_UP:
			c.Y=c.Y-1;
			return c;break;
		case VK_DOWN:
			c.Y=c.Y+1;
			return c;break;
		case VK_LEFT:
			c.X=c.X-1;
			return c;break;    
		case VK_RIGHT:
			c.X=c.X+1;
			return c;break;
		}
	return c;
	}
void sleep(DWORD mil){
	Sleep(mil);
	}