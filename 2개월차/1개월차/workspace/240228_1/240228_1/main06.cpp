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
	cout << "����� ���� ~~~" << endl;
	system("pause"); // �Ͻ�����
	system("cls");   // clear screen ȭ�� ������.

	// �ܼ� ����ٲٱ�
	// �ܼ� ��Ʈũ�� �ٲٱ�
}

// ���� 1
	// ������� (vs Com)
	// 5*5 �������� ������ְ�
	// 1 ~ 25 ���� ������ ���ڰ� �����ִ�.
	// ���� �� �� ���ڸ� �Է��ϸ�
	// �� �����ǿ��� �����ϳ� ��������
	// ��� �����ǿ��� �����ϳ� ��������

	// �״��� ��밡 �������� ���ڸ� �ϳ� �Է�
	// �� �����ǿ��� �����ϳ� ��������
	// ��� �����ǿ��� �����ϳ� ��������
	// 3���� �����Ǹ� �ش� ���� �¸�

	// ���� 2
	// GOTO XY ����ؼ� ĳ���� �ϳ� �����