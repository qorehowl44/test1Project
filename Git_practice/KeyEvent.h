#include<windows.h>
#include<iostream>
using namespace std;
class KeyEvent
{
private:
	HANDLE hln;
	COORD keyWhere;
	DWORD EventCount;
	INPUT_RECORD lnRec;
	DWORD NumRead;
	int downkey;
public:
	KeyEvent()
	{
		hln = GetStdHandle(STD_INPUT_HANDLE);
		EventCount = 1;
	}
	int getkey()
	{
		ReadConsoleInput(hln, &lnRec, 1, &NumRead);
		if (lnRec.EventType == KEY_EVENT)
		{
			if (lnRec.Event.KeyEvent.bKeyDown)
			{
				downkey = lnRec.Event.KeyEvent.wVirtualKeyCode;
				return downkey;
			}
			else
				return -1;
		}
		return -1;
	}
};

enum {
	BLACK, D_BLUE, D_GREEN, D_SKYBLUE, D_RED,
	D_VIOLET, D_YELLOW, GRAY, D_GRAY, BLUE, GREEN,
	SKYBLUE, RED, VIOLET, TELLOW, WHITE,
};

void gotoXY(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void setColor(char color, char backGround)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (backGround << 4) + color);
}
void clearConsole()
{
	system("cls");
}
#pragma once
