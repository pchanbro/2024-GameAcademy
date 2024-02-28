#include <iostream>

using namespace std;

void main()
{
	// 셔플

	int a = 3;
	int b = 5;

	//a : 5, b : 3
	//
	//A컵에 담긴 주스
	//B컵에 담긴 주스
	//서로 바꾸려면 어떻게 해야할까?

	//1. C컵을 새로둔다.
	//2. C컵에 A컵에 담긴 주스를 넣는다.
	//3. A컵에 B컵에 단긴 주스를 넣는다.
	//4. B컵에 C컵에 담긴 주스를 넣는다.

	int temp = a;
	a = b;
	b = temp;

	printf("A : %d\n", a);
	printf("B : %d\n", b);

	// 실습
	// 로또생성기
	// 1. 1 ~ 45까지 적힌 array를 만든다.
	// 2. array를 섞는다
	// 3. 그중 7개를 뽑는다.


	//A,B 스왑 10000번하면 셔플입니다.
	int arr[100] = {};

	//1. 초기화
	for (int i = 0; i < 100; i++)
	{
		arr[i] = i;
	}

	//2. 셔플
	srand(time(NULL));

	//100000은 마음대로
	for (int i = 0; i < 100000; i++)
	{
		//A,B를 100000번 SWAP할건데
		//A, B를 고르는 기준이 
		//랜덤 인덱스입니다.

		int firstIndex = rand() % 100;	// 0~99 사이의 숫자를 뽑는다 (arr 범위)
		int secondIndex = rand() % 100;	// 0~99 사이의 숫자를 뽑는다 (arr 범위)

		int temp = arr[firstIndex];
		arr[firstIndex] = arr[secondIndex];
		arr[secondIndex] = temp;
	}

	for (int i = 0; i < 100; i++)
	{
		printf("arr[i] : %d\n", arr[i]);
	}
	


	// 오늘 숙제 !! 
	// 1. 로또생성기
	// 2. 가위바위보 하나빼기 (배열사용)
	// 3. 21일 숙제 심화버전까지
}