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
	// 숙제 1
	// 빙고게임 (vs Com)
	
	// 1. 빙고판을 생성한다.
	GenarateBoardNum(_myBoard, 25);
	GenarateBoardNum(_comBoard, 25);

	// 2. 빙고게임 진행 여부 확인
	// 2-1. 빙고 개수 파악
	while (IsContinue())
	{
		system("cls");

		// 3. 빙고판 출력
		cout << "플레이어 빙고판 " << endl;
		PrintBingoBoard(_myBoard, 25);
		cout << "컴퓨터 빙고판 " << endl;
		PrintBingoBoard(_comBoard, 25);

		// 4. 빙고판에서 지울 번호 선택
		int input = ChooseNum(25);

		// 5. 선택한 번호 빙고에서 -1로 대체
		DeleteNum(_myBoard, _comBoard, 25, input);

		// 6. 현재 빙고 상태 출력
		PrintBingoState();

		system("pause");
	}

	// 7. 3줄이 빙고가되면 해당 유저 승리
	// 7-1. 단 본인 순서에 3빙고가 먼저 맞춰진 사람이 승리
	if (IsWin())
	{
		cout << "플레이어 승리" << endl;
	}
	else
	{
		cout << "컴퓨터 승리" << endl;
	}

}

// 1. 빙고판을 생성한다.
// 1-1. 5*5 빙고판을 만들어주고
// 1-2. 1 ~ 25 까지 랜덤한 숫자가 적혀있다.
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

// 2. 빙고게임 진행 여부 확인
// 2-1. 빙고 개수 파악
bool IsContinue()
{
	// 2-1. 플레이어 빙고 개수 파악
	_myBingo = HowManyBingo(_myBoard, 25);
	// 2-2. 컴퓨터 빙고 개수 파악
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

// 2-1. 빙고 개수 파악
int HowManyBingo(int* board, int size)
{
	// 빙고 수 초기화 (처음부터 다시 세기 때문에)
	int bingo = 0;

	// 빙고 여부 확인을 위한 변수 선언
	int num = 0;

	// 가로 빙고 개수
	for (int i = 0; i < size; i++)
	{
		// 각 행마다 num 초기화
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

	// 세로 빙고 개수
	for (int i = 0; i < 5; i++)
	{
		// 각 열마다 num 초기화
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

	// 대각선(\)빙고
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

	// 대각선(/)빙고
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

// 3. 빙고판 출력
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


// 4. 빙고판에서 지울 번호 선택
int ChooseNum(int size)
{
	int input = 0;
	if (_myTurn)
	{
		cout << "지울 번호를 선택하세요 : ";
		cin >> input;
		_myTurn = false;
	}
	else if(!_myTurn)
	{
		cout << "컴퓨터가 지울 번호를 선택합니다. " << endl;
		input = rand() % size + 1;
		_myTurn = true;
	}

	return input;
}

// 5. 선택한 번호 빙고에서 -1로 대체
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
	cout << "플레이어 빙고 수 : " << _myBingo << endl;
	cout << "컴퓨터 빙고 수 : " << _comBingo << endl;
}


// 7. 3줄이 빙고가되면 해당 유저 승리
// 7-1. 단 본인 순서에 3빙고가 먼저 맞춰진 사람이 승리
bool IsWin()
{
	// 플레이어 순서에 플레이어가 빙고가 되면 플레이어 승리
	// 플레이어 순서에 플레이어가 빙고가 안됐는데 컴퓨터가 빙고가 되면 컴퓨터 승리
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
	// 컴퓨터 순서에 컴퓨터가 빙고가 되면 컴퓨터 승리
	// 컴퓨터 순서에 컴퓨터가 빙고가 안됐는데 플레이어가 빙고가 되면 플레이어 승리
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