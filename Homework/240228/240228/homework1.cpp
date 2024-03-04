#include <iostream>
#include <Windows.h>

using namespace std;

int _myBoard[25] = {};
int _comBoard[25] = {};
int _myBingo = 0;
int _comBingo = 0;
bool _myTurn = true;


void GenarateBoardNum(int* board, int size);
bool IsContinue();
void PrintBingoBoard(int* board, int size);
int ChooseNum(int size);
void DeleteNum(int* myBoard, int* comBoard, int size, int input);
int HowManyBingo(int* board, int size);
void PrintBingoState();
bool IsWin();

void main()
{
	srand(time(NULL));
	// ���� 1
	// ������� (vs Com)
	
	// 1. �������� �����Ѵ�.
	GenarateBoardNum(_myBoard, 25);
	GenarateBoardNum(_comBoard, 25);

	// 2. ������� ���� ���� Ȯ��
	// 2-1. ���� ���� �ľ�
	while (IsContinue())
	{
		system("cls");

		// 3. ������ ���
		cout << "�÷��̾� ������ " << endl;
		PrintBingoBoard(_myBoard, 25);
		cout << "��ǻ�� ������ " << endl;
		PrintBingoBoard(_comBoard, 25);

		// 4. �����ǿ��� ���� ��ȣ ����
		int input = ChooseNum(25);

		// 5. ������ ��ȣ ������ -1�� ��ü
		DeleteNum(_myBoard, _comBoard, 25, input);

		// 6. ���� ���� ���� ���
		PrintBingoState();

		system("pause");
	}

	// 7. 3���� �����Ǹ� �ش� ���� �¸�
	// 7-1. �� ���� ������ 3���� ���� ������ ����� �¸�
	if (IsWin())
	{
		cout << "�÷��̾� �¸�" << endl;
	}
	else
	{
		cout << "��ǻ�� �¸�" << endl;
	}

}

// 1. �������� �����Ѵ�.
// 1-1. 5*5 �������� ������ְ�
// 1-2. 1 ~ 25 ���� ������ ���ڰ� �����ִ�.
void GenarateBoardNum(int* board, int size)
{
	for (int i = 0; i < size; i++)
	{
		board[i] = i + 1;
	}

	for (int i = 0; i < 100000; i++)
	{
		int firstIndex = rand() % size;
		int secondIndex = rand() % size;

		int temp = board[firstIndex];
		board[firstIndex] = board[secondIndex];
		board[secondIndex] = temp;
	}
}

// 2. ������� ���� ���� Ȯ��
// 2-1. ���� ���� �ľ�
bool IsContinue()
{
	// 2-1. �÷��̾� ���� ���� �ľ�
	_myBingo = HowManyBingo(_myBoard, 25);
	// 2-2. ��ǻ�� ���� ���� �ľ�
	_comBingo = HowManyBingo(_comBoard, 25);

	if (_myBingo == 3)
	{
		return false;
	}
	else if (_comBingo == 3)
	{
		return false;
	}

	return true;
}

// 2-1. ���� ���� �ľ�
int HowManyBingo(int* board, int size)
{
	// ���� �� �ʱ�ȭ (ó������ �ٽ� ���� ������)
	int bingo = 0;

	// ���� ���� Ȯ���� ���� ���� ����
	int num = 0;

	// ���� ���� ����
	for (int i = 0; i < size; i++)
	{
		// �� �ึ�� num �ʱ�ȭ
		if (i % 5 == 0)
		{
			num = 0;
		}

		if (board[i] == -1)
		{
			num++;
		}

		if (num == 5)
		{
			bingo++;
		}
	}

	// ���� ���� ����
	for (int i = 0; i < 5; i++)
	{
		// �� ������ num �ʱ�ȭ
		num = 0;

		for (int j = 0; j < 5; j++)
		{
			if (board[i + j * 5] == -1)
			{
				num++;
			}
		}

		if (num == 5)
		{
			bingo++;
		}
	}

	// �밢��(\)����
	num = 0;
	for (int i = 0; i < 5; i++)
	{
		if (board[i + i * 5] == -1)
		{
			num++;
		}
	}
	if (num == 5)
	{
		bingo++;
	}

	// �밢��(/)����
	num = 0;
	for (int i = 0; i < 5; i++)
	{
		if (board[i * 5 + 4 - i] == -1)
		{
			num++;
		}
	}
	if (num == 5)
	{
		bingo++;
	}

	return bingo;
}

// 3. ������ ���
void PrintBingoBoard(int* board, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i % 5 == 0)
		{
			cout << endl;
		}
		cout << board[i] << "\t";
	}
	cout << endl;
	cout << endl;
}


// 4. �����ǿ��� ���� ��ȣ ����
int ChooseNum(int size)
{
	int input = 0;
	if (_myTurn)
	{
		cout << "���� ��ȣ�� �����ϼ��� : ";
		cin >> input;
		_myTurn = false;
	}
	else if(!_myTurn)
	{
		cout << "��ǻ�Ͱ� ���� ��ȣ�� �����մϴ�. " << endl;
		input = rand() % size + 1;
		_myTurn = true;
	}

	return input;
}

// 5. ������ ��ȣ ������ -1�� ��ü
void DeleteNum(int* _myBoard, int* _comBoard, int size, int input)
{
	for (int i = 0; i < size; i++)
	{
		if (_myBoard[i] == input)
		{
			_myBoard[i] = -1;
		}

		if (_comBoard[i] == input)
		{
			_comBoard[i] = -1;
		}
	}
}

void PrintBingoState()
{
	cout << "�÷��̾� ���� �� : " << _myBingo << endl;
	cout << "��ǻ�� ���� �� : " << _comBingo << endl;
}


// 7. 3���� �����Ǹ� �ش� ���� �¸�
// 7-1. �� ���� ������ 3���� ���� ������ ����� �¸�
bool IsWin()
{
	// �÷��̾� ������ �÷��̾ ���� �Ǹ� �÷��̾� �¸�
	// �÷��̾� ������ �÷��̾ ���� �ȵƴµ� ��ǻ�Ͱ� ���� �Ǹ� ��ǻ�� �¸�
	if (_myTurn)
	{
		if (_myBingo == 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// ��ǻ�� ������ ��ǻ�Ͱ� ���� �Ǹ� ��ǻ�� �¸�
	// ��ǻ�� ������ ��ǻ�Ͱ� ���� �ȵƴµ� �÷��̾ ���� �Ǹ� �÷��̾� �¸�
	else
	{
		if (_comBingo == 3)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}