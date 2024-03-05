#include <iostream>
#include <Windows.h>

#define ROUND_END 10
#define NUMBER_BASEBALL_DIGIT 4

using namespace std;

int _answer[NUMBER_BASEBALL_DIGIT] = {};
int _input = 0;
int _round = 1;
int _strike = 0;
int _ball = 0;
bool _userWin = false;

void GenerateNumber(int* answer, int digit);
bool IsContinue(int round, int strike, int* answer, int digit);
int EnterNumber(int digit);
bool IsInputCorrect(int input);
void PrintStirkeAndBall(int* answer, int input, int digit);
void IsInputRight(int strike);

void main()
{
	// 숙제
	// 숫자야구(4개)

	srand(time(NULL));
	// 1. 숫자를 생성한다. (1번부터 4번째 숫자는 겹치지 않는다.)
	GenerateNumber(_answer, NUMBER_BASEBALL_DIGIT);
	// 1번째 자리수는 1 ~ 9 
	// 2번째 자리수는 0 ~ 9
	// 3번째 자리수는 0 ~ 9
	// 4번째 자리수는 0 ~ 9
	// 반복
	
	// 7-1. 9회가 종료되면 게임을 종료한다(유저 패배)
	// 7-2. 정답을 맞추면 게임을 종료한다(유저 승리)
	while (IsContinue(_round, _strike, _answer, NUMBER_BASEBALL_DIGIT))
	{
		// 2. 몇회인지 확인한다.
		// 3. 숫자를 입력한다.
		_input = EnterNumber(NUMBER_BASEBALL_DIGIT);
		// 4. Strike, Ball 출력 (자릿수, 값이 같으면 Strike, 값만 같으면 Ball)
		PrintStirkeAndBall(_answer, _input, NUMBER_BASEBALL_DIGIT);
		// 5. 다음 라운드
		_round++;
		// 6. 정답 여부확인
		IsInputRight(_strike);
	}
	

	// 너무 쉽다 싶으면 --> GotoXY 사용해서 멋있게 만들어 보기
}

void GenerateNumber(int* answer, int digit)
{
	answer[0] = rand() % 9 + 1;

	for (int i = 1; i < digit; i++)
	{
		answer[i] = rand() % 10;

		for (int j = 0; j < i; j++)
		{
			while (answer[i] == answer[j])
			{
				answer[i] = rand() % 10;
				j = 0;
			}
		}
	}
}

bool IsContinue(int round, int strike, int* answer, int digit)
{
	if (_userWin == true)
	{
		printf("정답!!\n");
		return false;
	}
	else if (_round == ROUND_END)
	{
		printf("9회 종료... 게임 종료... 정답 : " );
		for (int i = 0; i < digit; i++)
		{
			printf("%d ", answer[i]);
		}
		return false;
	}

	return true;
}

int EnterNumber(int digit)
{
	int input;
	cout << "정답을 입력하세요(각 자리의 숫자는 겹치지 않습니다.) :";
	cin >> input;
	return input;
}

void PrintStirkeAndBall(int* answer, int input, int digit)
{
	_strike = 0;
	_ball = 0;
	int digitCheck = 1;

	for (int i = 1; i < digit; i++)
	{
		digitCheck *= 10;
	}

	for (int i = 0; i < digit; i++)
	{
		int value = input % (digitCheck * 10) / digitCheck;

		for (int j = 0; j < digit; j++)
		{
			if (value == answer[j])
			{
				if (i == j)
				{
					_strike++;
				}
				else
				{
					_ball++;
				}
			}
		}
		digitCheck /= 10;
	}

	cout << _strike << "STRIKE" << endl;
	cout << _ball << "BALL" << endl;
}

void IsInputRight(int strike)
{
	if (strike == 4)
	{
		_userWin = true;
	}
	else
	{
		_userWin = false;
	}
}