#include <iostream>
#include <time.h>

using namespace std;

int _comHand1 = 0;
int _comHand2 = 0;
int _comHand3 = 0;
int _rank = 1;

// 1. 컴퓨터 둘이 랜덤 숫자를 뽑는다. (0 ~ 99)
void ChooseNum()
{
	_comHand1 = rand() % 100;
	_comHand2 = rand() % 100;
	_comHand3 = rand() % 100;
}

// 2. 컴퓨터가 뽑은 숫자를 출력한다.
void PrintNum()
{
	cout << "COM1의 숫자 : " << _comHand1 << endl;
	cout << "COM2의 숫자 : " << _comHand2 << endl;
	cout << "COM3의 숫자 : " << _comHand3 << endl;
}

// 3. 랜덤 숫자가 높은 쪽이 승리한다.
void CompareNum()
{
	if (_comHand1 < _comHand2)
	{
		if (_comHand2 < _comHand3)
		{
			cout << "1위 : COM3!!" << endl;
			cout << "2위 : COM2!!" << endl;
			cout << "3위 : COM1!!" << endl;
		}
		else if (_comHand3 < _comHand2)
		{
			if (_comHand1 < _comHand3)
			{
				cout << "1위 : COM2!!" << endl;
				cout << "2위 : COM3!!" << endl;
				cout << "3위 : COM1!!" << endl;
			}
			else if (_comHand3 < _comHand1)
			{
				cout << "1위 : COM2!!" << endl;
				cout << "2위 : COM1!!" << endl;
				cout << "3위 : COM3!!" << endl;
			}
			else 
			{
				cout << "1위 : COM2!!" << endl;
				cout << "공동 2위 : COM1, COM3" << endl;
			}
		}
		else
		{
			cout << "공동 1위 : COM2, COM3!!" << endl;
			cout << "3위 : COM1" << endl;
		}
	}
	else if (_comHand2 < _comHand1)
	{
		if (_comHand1 < _comHand3)
		{
			cout << "1위 : COM3!!" << endl;
			cout << "2위 : COM1!!" << endl;
			cout << "3위 : COM2!!" << endl;
		}
		else if (_comHand3 < _comHand1)
		{
			if (_comHand2 < _comHand3)
			{
				cout << "1위 : COM1!!" << endl;
				cout << "2위 : COM3!!" << endl;
				cout << "3위 : COM2!!" << endl;
			}
			else if (_comHand3 < _comHand2)
			{
				cout << "1위 : COM1!!" << endl;
				cout << "2위 : COM2!!" << endl;
				cout << "3위 : COM3!!" << endl;
			}
			else
			{
				cout << "1위 : COM1!!" << endl;
				cout << "공동 2위 : COM2, COM3" << endl;
			}
		}
		else
		{
			cout << "공동 1위 : COM1, COM3!!" << endl;
			cout << "3위 : COM2" << endl;
		}
	}
	else
	{
		if (_comHand1 < _comHand3)
		{
			cout << "1위 : COM3!!" << endl;
			cout << "공동 2위 : COM1, COM2" << endl;
		}
		else if (_comHand3 < _comHand1)
		{
			cout << "공동 1위 : COM1, COM2 !!" << endl;
			cout << "3위 : COM3" << endl;
		}
	}
}

void main()
{
	// 일단 간단한 게임 하나 만들어 보자
	
	srand(time(NULL));
	// 1. 컴퓨터 둘이 랜덤 숫자를 뽑는다. (0 ~ 99)
	ChooseNum();
	// 2 컴퓨터가 뽑은 숫자를 출력한다.
	PrintNum();
	// 3. 랜덤 숫자가 높은 쪽이 승리한다.
	CompareNum();

}

// 프로그램 수정이 주로 잦게 일어나는게
// 정원이 2명이 아니라 3명인데요?
// 3명까지 프로그램을 만들었다
// 사장님이 갑자기 10명이서 하도록 만들어줘라 
// 그렇게 만드는데 얼마나 걸리냐?


// 이럴 때 쓰면 좋은게 바로 : 배열