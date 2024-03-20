// 2. while문 활용
// - 숫자맞추기 게임
// 숫자를 맞출 동안 반복
// 1. 컴퓨터가 랜덤숫자를 정한다. (1 ~ 100)
// 2. 내가 숫자를 입력
// 3-1. 랜덤수가 그 숫자보다 높다 : UP 출력
// 3-2. 랜덤수가 그 숫자보다 낮다 : DOWN 출력
// 3-3. 랜덤수가 같으면 게임 종료 (exit(0);)
#include <iostream>
#include <time.h>

using namespace std;

int _max = 100;
int _min = 1;
int _number = 0;

// 1. 컴퓨터가 랜덤숫자를 정한다. (1 ~ 100)
int GenerateNumber()
{
	int num = rand() % 100 + 1;
	return num;
}

// 2. 내가 숫자를 입력
// 3-1. 랜덤수가 그 숫자보다 높다 : UP 출력
// 3-2. 랜덤수가 그 숫자보다 낮다 : DOWN 출력
// 3-3. 랜덤수가 같으면 게임 종료 (exit(0);)
int ChooseNumber()
{
	int choice;
	cout << _min << " ~ " << _max << " 중 하나의 숫자를 선택하세요 : ";
	cin >> choice;

	return  choice;
}

void IsCorrect(int choiceNumber)
{
	if (choiceNumber == _number)
	{
		cout << _number << " 정답!!" << endl;
		exit(0);
	}
	else if (choiceNumber < _number)
	{
		cout << "UP" << endl;
		_min = choiceNumber;
	}
	else
	{
		cout << "DOWN" << endl;
		_max = choiceNumber;
	}
}

void main()
{
	srand(time(NULL));
	// 1. 컴퓨터가 랜덤숫자를 정한다. (1 ~ 100)
	_number = GenerateNumber();


	while (true)
	{
		// 2. 내가 숫자를 입력
		int num = ChooseNumber();

		// 3-1. 랜덤수가 그 숫자보다 높다 : UP 출력
		// 3-2. 랜덤수가 그 숫자보다 낮다 : DOWN 출력
		// 3-3. 랜덤수가 같으면 게임 종료 (exit(0);)
		IsCorrect(num);
	}
}