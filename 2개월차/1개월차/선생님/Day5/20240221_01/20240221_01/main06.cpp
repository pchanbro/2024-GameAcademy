#include <iostream>

using namespace std;

void main()
{
	// 반복문
	
	// 반복문이 무엇인가??
	// 가위바위보게임만든거를
	//   - 10판 반복한다.
	// 코드를 반복시키는 역할

	//반복문 종류
	// 3가지 종류
	// for,		
	// while,	
	// do~while (제일 쓸모없음)

	//코드는 말로 바꿀수있어야한다.
	//말을 코드로 바꿀수있어야한다.

	//for : 몇번 반복한다. (몇번)
	//while : ~~하는 동안 반복한다. 

	//for문법
	for (int i = 0; i < 5; i++)
	{
		::printf("안녕하세요.\n");
	}

	//for (int i = 0; i < N; i++)
	// N번 반복한다.

	//1. int i 를 0으로 생성한다.
	//2. 조건식이 참이면
	//3. 중괄호 내용을 실행한다.
	//4. i++을 실행한다.
	//5. 2로 돌아간다.
	
	//i => int라서 i 
	for (int i = 0; i < 5; i++)
	{
	}


	// while문
	// 조건이 만족하는 동안 반복한다.
	// 1은 무한반복 도저히 탈출하지 않습니다.
	
	// 1. 조건이 참이면
	// 2. 중괄호 내용을 실행한다.
	// 3. 1로 돌아간다.
	int count = 0;
	while (count < 5)
	{
		::printf("count : %d\n", count);
		count++;
	}


	//1. 
	//2. 조건식이 참이면
	//3. 중괄호 내용을 실행한다.
	//4. i++을 실행한다.
	//5. 2로 돌아간다.
	count = 0;
	for (; count < 5;)
	{
		::printf("count : %d\n", count);
		count++;
	}


	//do-while
	//do : 한다
	//while : 조건이 참인동안 반복한다
	do
	{
		::printf("do-while\n");
	} while (1);

}