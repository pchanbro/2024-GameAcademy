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
	//cout << "����� ���� ��¼�� ��¼��" << endl;
	//system("pause");	//�Ͻ�����
	//system("cls");		//clear screen ȭ�� ������.
	

	// �ܼ� ����ٲٱ�
	// �ܼ� ��Ʈũ�� �ٲٱ�

	printf("��������������������������������������������������������\n");
	printf("��                          ��\n");
	printf("��       Game Start         ��\n");
	printf("��       Exit               ��\n");
	printf("��                          ��\n");
	printf("��������������������������������������������������������\n");
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
			gotoxy(4, sel + 2); printf("��");
		}
	}
}