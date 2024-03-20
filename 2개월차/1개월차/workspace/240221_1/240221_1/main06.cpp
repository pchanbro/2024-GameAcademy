#include <iostream>

using namespace std;

void main()
{
	// 반복문

	// 반복문이 무엇인가??
	// EX) 가위바위보 게임 10판 반복
	// 코드를 반복시키는 역할

	// 반복문의 종류
	// 3가지
	// for, while, do-while (사실 do-while은 알긴 알아야 하는데 딱히 쓸모없다)

	// 코드는 말로 바꿀 수 있어야 한다.
	// 말을 코드로 바꿀 수 있어야 한다.

	// for : 몇 번 반복한다.
	// while : ~하는 동안 반복한다.

	// for문법
	for (int i = 0; i < 5; i++)
	{
		printf("안녕하세요.\n");
	}

	// for(int i = 0 ; i < N ; i++)
	// N번 반복한다.

	// 1. int i 를 0으로 생성한다.
	// 2. 조건식이 참이면
	// 3. 중괄호 내용을 실행한다.
	// 4. i++을 실행한다.
	// 5. 2로 돌아간다.

	// i를 먼저쓰는 이유, int이기 때문에 그냥 앞글자 따서 i부터 씀
	for (int i = 0; i < 5; i++)
	{

	}


	// while문
	// 조건이 만족하는 동안 반복한다.
	// 1은 무한반복 도저히 탈출할 수 없다.

	// 1. 조건이 참이면
	// 2. 중괄호 내용을 실행한다.
	// 3. 1로 돌아간다.
	int count = 0;
	while (count < 5)
	{
		printf("count : %d\n", count);
		count++;
	}

	// 1.
	// 2. 조건식이 참이면
	// 3. 중괄호 내용을 실행한다.
	// 4. i++을 실행한다.
	// 5. 2로 돌아간다.
	count = 0;
	for (; count < 5;)
	{
		printf("count : %d\n", count);
		count++;
	}


	// do - while
	// do : 실행한다.
	// while : 조건이 참인동안 반복한다.
	count = 0;
	do
	{
		printf("do-while\n");
		count++;
	} while (count < 5);
}