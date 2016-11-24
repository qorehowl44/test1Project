/*
#include<process.h>
#include"KeyEvent.h"

using namespace std;
class Game
{
private:
	int x;
	int y;
	int direction;
	void gotoXY(int x, int y)
	{
		COORD	pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
public:
	Game()
	{
		x = 5;
		y = 5;
		direction = 0;
	}
	void setDirection(int i)
	{
		direction = i;
	}
	void move()
	{
		if (direction == 37)
		{
			x--;
		}
		else if (direction == 38)
		{
			y--;
		}
		else if (direction == 39)
		{
			x++;
		}
		else if (direction == 40)
		{
			y++;
		}
		system("cls");
		this->gotoXY(x, y);
		cout << x << " " << y;
		cout << "бс";
	}
};
Game* game = new Game();
unsigned int __stdcall mythread(void*)
{
	int i = 0;
	while (1)
	{
		game->move();
		Sleep(500);
	}
	return 0;
}
unsigned int __stdcall keyEvent(void *)
{
	KeyEvent k;
	int i;
	while (1)
	{
		i = k.getkey();
		if (i != -1)game->setDirection(i);
	}
	return 0;
}
int main()
{
	HANDLE handleA, handleB;

	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	CloseHandle(handleA);
	CloseHandle(handleB);

	return 0;
}
*/
/* Thread
#include<process.h>
#include "KeyEvent.h"
using namespace std;
unsigned int __stdcall mythread(void*)
{
	int i = 0;
	while (1)
	{
		cout << GetCurrentThreadId() << ": " << i++ << endl;
		Sleep(500);
	}
	return 0;
}
unsigned int __stdcall keyEvent(void *)
{
	KeyEvent k;
	int i;
	while (1)
	{
		i = k.getkey();
		switch (i)
		{
		case 37: cout << "Left key is pressed" << endl; break;
		case 38: cout << "Up key is pressed" << endl; break;
		case 39: cout << "Right key is pressed" << endl; break;
		case 40: cout << "Down key is pressed" << endl; break;
		}
	}
	return 0;
}
int main()
{
	HANDLE handleA, handleB;

	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	CloseHandle(handleA);
	CloseHandle(handleB);

	return 0;
}*/
/*
#include"Frame.h"
void main()
{
	try
	{
		Frame *f1 = new Frame;
		Frame *f2 = new Frame[10];

		delete f1;
		delete[] f2;
	}
	catch (string msg)
	{
		cout << "Error msg :" << msg << endl;
	}
}*/
#pragma once
#include<string>
#include"Frame.h"
#include"ExArray.h"

template<typename T>
void mySwap(T& num1, T& num2)
{
	T temp = num1;
	num1 = num2;
	num2 = temp;
}
void main()
{
	ExArray<int> arr1(3);
	ExArray<char> arr2(4);
	ExArray<double> arr3(5);

	arr1.addData(2);
	arr2.addData('A');
	arr3.addData(32.12);

	arr1.printData();
	arr2.printData();
	arr3.printData();

	int num1 = 10, num2 = 40;
	cout << "before : " << num1 << ", " << num2 << endl;
	mySwap<int>(num1, num2);
	cout << "after : " << num1 << ", " << num2 << endl;

	double num1b = 121.11, num2b = 10.5;
	cout << "before : " << num1b << ", " << num2b << endl;
	mySwap<double>(num1b, num2b);
	cout << "after : " << num1b << ", " << num2b << endl;

	ExArray<int> arr4(5);
	arr4.addData(10);

	mySwap<ExArray<int>>(arr1, arr4);
	arr1.printData();
	arr4.printData();

}