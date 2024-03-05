#include <iostream>
#include <Windows.h>

using namespace std;

int _myBingo[5 * 5] = {};
int _comBingo[5 * 5] = {};
// 0, 0,0,0,0, ... (25��)
// 0��° �ε��� ~ 4��° �ε��� ���� ==> 1��
// 5��° �ε��� ~ 9��° �ε��� ���� ==> 2��
// 10 ~ 14 => 3��
// 15 ~ 19 => 4��
// 20 ~ 24 => 5��

// 0 : ����
// 1 : ��벨
int _removeNumber[2] = {};
int _bingoCount[2] = {};

void GenerateMyBingo();
void GenerateComBingo();
void PrintBingo();
void InputRemoveNumber();
void RemoveBingoNumber();
void CheckBingoCount();

void main()
{
	// �����ڵ�
	
	// ���� ��
	//  - 1. ���� ������ 5X5�� �����.
	//		- �������� ���鶧, 1~25�� ���ڰ� �������� ����.
	//		- ������ ���� �ִ� ����
	//  - 2. ��ǻ�� ������ 5X5�� �����.
	//		- �������� ���鶧, 1~25�� ���ڰ� �������� ����.
	// 
	//  [3~6�� �ݺ��Ѵ�]
	//		- 3. �������� ����Ѵ�.
	//		- 4. �÷��̾�� ��ǻ�Ͱ� ���ڸ� �Է��Ѵ�. (�÷��̾�� cin, ��ǻ�ʹ� rand() )
	//		- 5. �Է��� ���ڰ� Xǥ�ð� �ȴ�.
	//			- _myBingo[~~~] = {1,~, 25} 
	//				25�� �Է�!
	//			- _myBingo[~~~] = {1,~, -1} 
	//		- 6. ���࿡ ���� 3���� �Ǹ�, �ش� ������ �¸��Ѵ�.


	//MMO RPG�� ĳ���͸� �����.
	srand(time(NULL));

	::GenerateMyBingo();
	::GenerateComBingo();

	while (true)
	{
		system("cls");
		::PrintBingo();
		::InputRemoveNumber();
		::RemoveBingoNumber();
		::CheckBingoCount();

		if (_bingoCount[0] == 3)
		{
			printf("�¸��߽��ϴ�.");

			break;			//break�� ���� ����� �ݺ����� Ż��
			return;			//return�� �����ϰ��ִ� �Լ��� ����
			exit(1);		//���α׷��� ����
		}
		if (_bingoCount[1] == 3)
		{
			printf("�й��߽��ϴ�.\n");

			break;			//break�� ���� ����� �ݺ����� Ż��
			return;			//return�� �����ϰ��ִ� �Լ��� ����
			exit(1);		//���α׷��� ����
		}
	}
}


void GenerateMyBingo()
{
	printf("GenerateMyBingo\n");
	// 01 02 03 04 05
	// 06 07 08 09 10
	// 11 12 13 14 15
	// 16 17 18 19 20
	// 21 22 23 24 25

	// 0 ~ 4   => 1��
	// 5 ~ 9   => 2��
	// 10 ~ 14 => 3��
	// 15 ~ 19 => 4��
	// 20 ~ 24 => 5��
	//_myBingo[0] = 1;
	//_myBingo[1] = 2;
	//_myBingo[2] = 3;
	//_myBingo[3] = 4;
	//_myBingo[4] = 5;
	//_myBingo[5] = 6;
	//_myBingo[6] = 7;
	//_myBingo[7] = 8;
	//_myBingo[8] = 9;
	//_myBingo[9] = 10;
	//_myBingo[10] = 11;
	//_myBingo[11] = 12;
	////...
	//_myBingo[24] = 25;

	for (int i = 0; i < 25; i++)
	{
		_myBingo[i] = i + 1;
	}

	for (int i = 0; i < 100000; i++)
	{
		int src = rand() % 25;
		int dst = rand() % 25;

		int tmp = _myBingo[src];
		_myBingo[src] = _myBingo[dst];
		_myBingo[dst] = tmp;
	}
}

void GenerateComBingo()
{
	//�迭�� �Լ��� �������� ������
	// ���� �迭�� �����ؿ�.
	// ���߿� vector��� ���µ�, ��� ���̾��ϴ�.
	printf("GenerateComBingo\n");
	for (int i = 0; i < 25; i++)
	{
		_comBingo[i] = i + 1;
	}

	for (int i = 0; i < 100000; i++)
	{
		int src = rand() % 25;
		int dst = rand() % 25;

		int tmp = _comBingo[src];
		_comBingo[src] = _comBingo[dst];
		_comBingo[dst] = tmp;
	}
}

void PrintBingo()
{
	printf("PrintBingo\n");
	
	printf("�� ������ : \n");
	//int count = 0;
	for (int i = 0; i < 25; i++)
	{
		if (_myBingo[i] == -1)
		{
			printf("X\t");
		}
		else
		{
			printf("%d\t ", _myBingo[i]);
		}

		//5���� ���������� �� ����� ����� ��.
		/*count++;
		if (count == 5)
		{
			count = 0;
			printf("\n");
		}*/

		if (i % 5 == 4)
		{
			printf("\n");
		}
	}


	printf("���� ������ : \n");
	for (int i = 0; i < 25; i++)
	{
		if (_comBingo[i] == -1)
		{
			printf("X\t");
		}
		else
		{
			printf("%d\t ", _comBingo[i]);
		}

		if (i % 5 == 4)
		{
			printf("\n");
		}
	}
}

void InputRemoveNumber()
{
	printf("���� ���� �Է� : ");
	do
	{
		cin >> _removeNumber[0];
	} while (false == (1 <= _removeNumber[0] && _removeNumber[0] <= 25));
	

	//��ǻ�ʹ� 1 ~ 25���� �����߿� �ϳ� ���� �ȴ�.
	_removeNumber[1] = rand() % 25 + 1;


	printf("���� ���� ���� : %d\n", _removeNumber[0]);
	printf("��밡 ���� ���� : %d\n", _removeNumber[1]);
	system("pause");
}


void RemoveBingoNumber()
{
	//_removeNumber[0]
	//���� �����ǿ��� ����
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (_myBingo[i] == _removeNumber[j])
			{
				_myBingo[i] = -1;
			}
		}
	}

	//���� �����ǵ� ����
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (_comBingo[i] == _removeNumber[j])
			{
				_comBingo[i] = -1;
			}
		}
	}
}


void CheckBingoCount()
{
	// �� ��������
	// ���� �������� �����ִ¿���
	
	_bingoCount[0] = 0;
	_bingoCount[1] = 0;

	//0, 1, 2, 3, 4 �� -1 �̸� ����
	if (_myBingo[0] == -1 && _myBingo[1] == -1 && _myBingo[2] == -1 && _myBingo[3] == -1 && _myBingo[4] == -1)
	{
		_bingoCount[0]++;
	}

	//5, 6, 7, 8, 9 �� -1 �̸� ����
	if (_myBingo[5] == -1 && _myBingo[6] == -1 && _myBingo[7] == -1 && _myBingo[8] == -1 && _myBingo[9] == -1)
	{
		_bingoCount[0]++;
	}
	//10, 11, 12, 13, 14 �� -1 �̸� ����
	//15, 16, 17, 18, 19 �� -1 �̸� ����
	//20, 21, 22, 23, 24 �� -1 �̸� ����

	// ...

	// 00 01 02 03 04
	// 05 06 07 08 09
	// 10 11 12 13 14
	// 15 16 17 18 19
	// 20 21 22 23 24
	
	//0, 5, 10, 15, 20 �� -1 �̸� ����
	//1, 6, 11, 16, 21 �� -1 �̸� ����
	//2, 7, 12, 17, 22 �� -1 �̸� ����
	//3, 8, 13, 18, 23 �� -1 �̸� ����
	//4, 9, 14, 19, 24 �� -1 �̸� ����


	//0, 6, 12, 18, 24 �� -1 �̸� ����
	//4, 8, 12, 16, 20 �� -1 �̸� ����
}