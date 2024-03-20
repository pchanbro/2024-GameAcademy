#include <iostream>

using namespace std;

void main()
{
	// 셔플

	// 1. 숫자가 1 ~ 100 까지 있는 통이 있다.
	int a = 3;
	int b = 5;

	// a 와 b 값을 바꾸도록 해봐라
	// 이렇게 생각해보자
	// A컵에 담긴 주스
	// B컵에 담긴 주스
	// 서로 바꾸려면 어떻게 해야할까?

	// 1. C컵을 새로둔다.
	// 2. C컵에 A컵에 담긴 주스를 넣는다.
	// 3. A컵에 B컵에 담긴 주스를 넣는다.
	// 4. B컵에 C컵에 담긴 주스를 넣는다.

	int temp = a;
	a = b;
	b = temp;

	printf("a : %d\n", a);
	printf("b : %d\n", b);

	srand(time(NULL));

	// 배열의 임의의 두 요소를 스왑 10000번하면 셔플할 수 있다.
	int arr[100] = {};

	for (int i = 0; i < 100; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 100000; i++)
	{
		// A, B를 100000번 SWAP할건데
		// A, B를 고르는 기준이 랜덤 인덱스이다.
		// 랜덤 인덱스입니다.

		int firstIndex = rand() % 100; // 0 ~ 99 사이의 숫자를 뽑는다(arr 범위)
		int secondIndex = rand() % 100;

		int temp = arr[firstIndex];
		arr[firstIndex] = arr[secondIndex];
		arr[secondIndex] = temp;
	}

	for (int i = 0; i < 100; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	// 실습
	// 로또생성기
	// 1. 1 ~ 45까지 적힌 볼을 만든다.
	// 2. array를 섞는다
	// 3. 그 중 7개를 뽑는다.

	cout << "로또생성기 시작 " << endl;

	int arr2[45] = {};

	for (int i = 0; i < 45; i++)
	{
		arr2[i] = i + 1;
	}

	for (int i = 0; i < 100000; i++)
	{
		int firstIndex = rand() % 45;
		int secondIndex = rand() % 45;

		int temp = arr2[firstIndex];
		arr2[firstIndex] = arr2[secondIndex];
		arr2[secondIndex] = temp;
	}

	for (int i = 0; i < 7 ;i++)
	{
		printf("%d번째 숫자 : %d\n", i + 1, arr2[i]);
	}

}