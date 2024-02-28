#include <iostream>
#include <time.h>
using namespace std;

void main()
{
	// 되게 간단한 게임 하나 만들어볼게요

	// 1. 컴퓨터 두명이 랜덤 숫자를 뽑아서 (0~99)
	// 2. 랜덤숫자가 높은 쪽이 승리합니다.

	// 실습이 끝나면..
	// + 컴퓨터 세명 

	// 쉬는시간 포함해서 실습 완료하고 8시에 다시 모이겠습니다!

	srand(time(NULL));
	int comNum1 = 0, comNum2 = 0;
	comNum1 = rand() % 100;
	comNum2 = rand() % 100;

	if (comNum1 < comNum2)
	{
		cout << "com2 승리" << endl;
	}
	else if (comNum2 < comNum1)
	{
		cout << "com1 승리" << endl;
	}
	else
	{
		cout << "비겼습니다" << endl;
	}

	// 프로그램 수정이 주로 잦게 일어나는게
	// 정원이 2명이 아니라 3명인데요?
	// 3명까지 프로그램을 만들었다.
	// 사장님이 갑자기오셔서
	// 이거 10명하는 게임으로 바꾸면 얼마나걸려?


	//이럴때 사용하는 문법 : 배열
}