#include <iostream>
#include <Windows.h>

using namespace std;

int _myBingo[5 * 5] = {};
int _comBingo[5 * 5] = {};
// 0, 0,0,0,0, ... (25개)
// 0번째 인덱스 ~ 4번째 인덱스 까지 ==> 1줄
// 5번째 인덱스 ~ 9번째 인덱스 까지 ==> 2줄
// 10 ~ 14 => 3줄
// 15 ~ 19 => 4줄
// 20 ~ 24 => 5줄

// 0 : 내꺼
// 1 : 상대꺼
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
	// 수도코드
	
	// 빙고 룰
	//  - 1. 내꺼 빙고판 5X5를 만든다.
	//		- 빙고판을 만들때, 1~25의 숫자가 랜덤으로 들어간다.
	//		- 변수에 값을 넣는 행위
	//  - 2. 컴퓨터 빙고판 5X5를 만든다.
	//		- 빙고판을 만들때, 1~25의 숫자가 랜덤으로 들어간다.
	// 
	//  [3~6을 반복한다]
	//		- 3. 빙고판을 출력한다.
	//		- 4. 플레이어와 컴퓨터가 숫자를 입력한다. (플레이어는 cin, 컴퓨터는 rand() )
	//		- 5. 입력한 숫자가 X표시가 된다.
	//			- _myBingo[~~~] = {1,~, 25} 
	//				25를 입력!
	//			- _myBingo[~~~] = {1,~, -1} 
	//		- 6. 만약에 빙고가 3줄이 되면, 해당 유저가 승리한다.


	//MMO RPG의 캐릭터를 만든다.
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
			printf("승리했습니다.");

			break;			//break와 제일 가까운 반복문을 탈출
			return;			//return을 실행하고있는 함수를 종료
			exit(1);		//프로그램을 종료
		}
		if (_bingoCount[1] == 3)
		{
			printf("패배했습니다.\n");

			break;			//break와 제일 가까운 반복문을 탈출
			return;			//return을 실행하고있는 함수를 종료
			exit(1);		//프로그램을 종료
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

	// 0 ~ 4   => 1줄
	// 5 ~ 9   => 2줄
	// 10 ~ 14 => 3줄
	// 15 ~ 19 => 4줄
	// 20 ~ 24 => 5줄
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
	//배열을 함수로 보낼일이 있으면
	// 보통 배열을 사용안해요.
	// 나중에 vector라고 배우는데, 요거 많이씁니다.
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
	
	printf("내 빙고판 : \n");
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

		//5개를 찍을떄마다 줄 띄움을 해줘야 함.
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


	printf("상대방 빙고판 : \n");
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
	printf("지울 숫자 입력 : ");
	do
	{
		cin >> _removeNumber[0];
	} while (false == (1 <= _removeNumber[0] && _removeNumber[0] <= 25));
	

	//컴퓨터는 1 ~ 25까지 숫자중에 하나 고르면 된다.
	_removeNumber[1] = rand() % 25 + 1;


	printf("내가 지울 숫자 : %d\n", _removeNumber[0]);
	printf("상대가 지울 숫자 : %d\n", _removeNumber[1]);
	system("pause");
}


void RemoveBingoNumber()
{
	//_removeNumber[0]
	//내꺼 빙고판에서 삭제
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

	//상대방 빙고판도 삭제
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
	// 내 빙고갯수와
	// 상대방 빙고갯수를 세어주는역할
	
	_bingoCount[0] = 0;
	_bingoCount[1] = 0;

	//0, 1, 2, 3, 4 가 -1 이면 빙고
	if (_myBingo[0] == -1 && _myBingo[1] == -1 && _myBingo[2] == -1 && _myBingo[3] == -1 && _myBingo[4] == -1)
	{
		_bingoCount[0]++;
	}

	//5, 6, 7, 8, 9 가 -1 이면 빙고
	if (_myBingo[5] == -1 && _myBingo[6] == -1 && _myBingo[7] == -1 && _myBingo[8] == -1 && _myBingo[9] == -1)
	{
		_bingoCount[0]++;
	}
	//10, 11, 12, 13, 14 가 -1 이면 빙고
	//15, 16, 17, 18, 19 가 -1 이면 빙고
	//20, 21, 22, 23, 24 가 -1 이면 빙고

	// ...

	// 00 01 02 03 04
	// 05 06 07 08 09
	// 10 11 12 13 14
	// 15 16 17 18 19
	// 20 21 22 23 24
	
	//0, 5, 10, 15, 20 이 -1 이면 빙고
	//1, 6, 11, 16, 21 가 -1 이면 빙고
	//2, 7, 12, 17, 22 가 -1 이면 빙고
	//3, 8, 13, 18, 23 가 -1 이면 빙고
	//4, 9, 14, 19, 24 가 -1 이면 빙고


	//0, 6, 12, 18, 24 가 -1 이면 빙고
	//4, 8, 12, 16, 20 가 -1 이면 빙고
}