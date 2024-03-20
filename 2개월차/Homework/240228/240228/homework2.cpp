// 숙제 2
// GOTO XY 사용해서 캐릭터 하나 만들기

#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void main()
{
	gotoxy(20, 5);
	cout << "■              ■";
	gotoxy(20, 6);
	cout << "■■          ■■" << endl;
	gotoxy(20, 7);
	cout << "■■■      ■■■" << endl;
	gotoxy(20, 8);
	cout << "■    ■■■    ■" << endl;
	gotoxy(19, 9);
	cout << "■                ■" << endl;
	gotoxy(18, 10);
	cout << "■    ■      ■    ■" << endl;
	gotoxy(17, 11);
	cout << "■   ■  ■  ■  ■   ■" << endl;
	gotoxy(17, 12);
	cout << "■     ■      ■     ■" << endl;
	gotoxy(17, 13);
	cout << "■                    ■" << endl;
	gotoxy(18, 14);
	cout << "■   ■■■■■■   ■" << endl;
	gotoxy(19, 15);
	cout << "■    ■■■■    ■" << endl;
	gotoxy(20, 16);
	cout << "■              ■" << endl;
	gotoxy(21, 17);
	cout << "■   ■  ■   ■" << endl;
	gotoxy(21, 18);
	cout << "■   ■  ■   ■" << endl;
	gotoxy(22, 19);
	cout << "■  ■  ■  ■" << endl;
	gotoxy(22, 20);
	cout << "■  ■  ■  ■" << endl;
	gotoxy(22, 21);
	cout << "■■■  ■■■" << endl;
}