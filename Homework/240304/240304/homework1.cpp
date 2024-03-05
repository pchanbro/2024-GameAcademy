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
	// ����
	// ���ھ߱�(4��)

	srand(time(NULL));
	// 1. ���ڸ� �����Ѵ�. (1������ 4��° ���ڴ� ��ġ�� �ʴ´�.)
	GenerateNumber(_answer, NUMBER_BASEBALL_DIGIT);
	// 1��° �ڸ����� 1 ~ 9 
	// 2��° �ڸ����� 0 ~ 9
	// 3��° �ڸ����� 0 ~ 9
	// 4��° �ڸ����� 0 ~ 9
	// �ݺ�
	
	// 7-1. 9ȸ�� ����Ǹ� ������ �����Ѵ�(���� �й�)
	// 7-2. ������ ���߸� ������ �����Ѵ�(���� �¸�)
	while (IsContinue(_round, _strike, _answer, NUMBER_BASEBALL_DIGIT))
	{
		// 2. ��ȸ���� Ȯ���Ѵ�.
		// 3. ���ڸ� �Է��Ѵ�.
		_input = EnterNumber(NUMBER_BASEBALL_DIGIT);
		// 4. Strike, Ball ��� (�ڸ���, ���� ������ Strike, ���� ������ Ball)
		PrintStirkeAndBall(_answer, _input, NUMBER_BASEBALL_DIGIT);
		// 5. ���� ����
		_round++;
		// 6. ���� ����Ȯ��
		IsInputRight(_strike);
	}
	

	// �ʹ� ���� ������ --> GotoXY ����ؼ� ���ְ� ����� ����
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
		printf("����!!\n");
		return false;
	}
	else if (_round == ROUND_END)
	{
		printf("9ȸ ����... ���� ����... ���� : " );
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
	cout << "������ �Է��ϼ���(�� �ڸ��� ���ڴ� ��ġ�� �ʽ��ϴ�.) :";
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