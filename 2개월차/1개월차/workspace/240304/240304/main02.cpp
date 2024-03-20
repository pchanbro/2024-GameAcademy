#include <iostream>
#include <Windows.h>

using namespace std;

int _myBingo[5 * 5] = {};
int _comBingo[5 * 5] = {};
int _removeNumber[2] = {};
// 0, 0, 0, 0, 0, 0, ...(25개)
// 0번째 인덱스 ~ 4번째 인덱스 -> 첫번째줄
// 5번째 인덱스 ~ 9번째 인덱스 -> 두번째줄
// 10번째 인덱스 ~ 14번째 인덱스 -> 세번째줄
// 15번째 인덱스 ~ 19번째 인덱스 -> 네번째줄
// 20번째 인덱스 ~ 24번째 인덱스 -> 다섯번째줄

// 선생님이 빙고 만들 때 2차원 배열 안 쓴 이유
//	=> 인덱스 관리가 한 번 더 들어가야 해서 귀찮다.

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
	// 1. 내 빙고판 5x5를 만든다.
	//		- 빙고판을 만들 때, 1 ~ 25의 숫자가 랜덤으로 들어간다.
	//		- 변수에 값을 넣는 행위다.
	//		MMORPG의 캐릭터 커마를 할 때와 비슷함.
	// 2. 컴퓨터 빙고판 5x5를 만든다.
	//		- 빙고판을 만들 때, 1 ~ 25의 숫자가 랜덤으로 들어간다.
	// 3. 빙고판을 출력한다.
	// 4. 플레잉어와 컴퓨터가 숫자를 입력한다. (플레이어는 cin, 컴퓨터는 rand())
	// 5. 입력한 숫자가 x표시가 된다.
	//	_myBingo[~~~] = {1, ~ , 25}
	//		25를 입력 !
	//  _myBingo[~~~] = {1, ~ , -1} 
	// 6. 만약에 빙고가 3줄이 되면, 해당 유저가 승리한다.

	srand(time(NULL));

	GenerateMyBingo();
	GenerateComBingo();
	while (true)
	{
		system("cls");
		PrintBingo();
		InputRemoveNumber();
		RemoveBingoNumber();
		CheckBingoCount();

		if (_bingoCount[0] == 3)
		{
			printf("승리했습니다.\n");

			break;
			// break : 제일 가까운 반복문 탈출
			// return : 실행하고 있는 함수를 종료
			// exit(1) : 프로그램을 종료
		}
		if (_bingoCount[1] == 3)
		{
			printf("패배했습니다.\n");
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

	// 0 ~ 4	=> 1줄
	// 5 ~ 9	=> 2줄
	// 10 ~ 14	=> 3줄
	// 15 ~ 19	=> 4줄
	// 20 ~ 24	=> 5줄
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
	// 배열을 함수로 보낼일이 있으면
	// 보통 배열을 사용하지 않는다
	// 대신에 나중에 배울 vector를 많이쓴다.

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

	/*int count = 0;*/

	for (int i = 0; i < 25; i++)
	{
		if (_myBingo[i] == -1)
		{
			printf("\tX");
		}
		else
		{
			printf("\t%d", _myBingo[i]);
		}
		
		//5개를 찍을때마다 줄 띄움을 해줘야 함.
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
			printf("\tX");
		}
		else
		{
			printf("\t%d", _comBingo[i]);
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

	// 컴퓨터가 1 ~ 25까지 숫자주엥 하나 고르면 된다.
	_removeNumber[1] = rand() % 25 + 1;

	printf("내가 지울 숫자 : %d\n", _removeNumber[0]);
	printf("상대가 지울 숫자 : %d\n", _removeNumber[1]);
	system("pause");
}

void RemoveBingoNumber()
{
	// 상대방 빙고판과 내 빙고판의 크기가 다를 수 있기 때문에 따로 해주는게 좋다.

	// _removeNumber[0] 
	// 내꺼 빙고판에서 삭제
	for(int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (_myBingo[i] == _removeNumber[j])
			{
				_myBingo[i] = -1;
			}
		}
	}

	// 상대방 빙고판도 삭제
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
	// 내 빙고개수와
	// 상대방 빙고갯수를 세어주는 역할
	
	_bingoCount[0] = 0;
	_bingoCount[1] = 0;

	// 잘 생각해보기
	
}