#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void main()
{
	//cout << "출력할 내용 어쩌구 저쩌구" << endl;
	//system("pause");	//일시정지
	//system("cls");		//clear screen 화면 싹지움.
	

	// 콘솔 색상바꾸기
	// 콘솔 폰트크기 바꾸기

	printf("┌──────────────────────────┐\n");
	printf("│                          │\n");
	printf("│       Game Start         │\n");
	printf("│       Exit               │\n");
	printf("│                          │\n");
	printf("└──────────────────────────┘\n");
	int sel = 0;
	while (true)
	{
		char input;
		if (_kbhit())
		{
			input = _getch();
			gotoxy(4, sel + 2); printf("  ");
			switch (input)
			{
			case 'w':
				sel--;
				break;
			case 's':
				sel++;
				break;
			default:
				break;
			}
			gotoxy(4, sel + 2); printf("★");
		}
	}
}