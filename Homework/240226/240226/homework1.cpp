// 선생님 코멘트 
// 4번 함수 재사용성을 위해서
// 배열을 초기화 해줄때 size도 매개변수로 받아주는것이 좋다.
// 왜냐하면 재사용을 위해서라고 하면 
// 다른 배열의 크기도 지금 만들어 놓은 것처럼 45라고 할 수 없기 때문이다.

#include <iostream>

using namespace std;

// 로또생성기

// 1. 게임시작 알림판
void PrintStartLotto()
{
	printf("┌───────────────────────────────────┐\n");
	printf("│        Start Lotto Gerator        │\n");
	printf("└───────────────────────────────────┘\n");
	cout << endl;
}

// 2. 1 ~ 45까지 적힌 볼을 만든다.
void GenerateNumber(int *arr)
{
	for (int i = 0; i < 45; i++)
	{
		arr[i] = i + 1;
	}
}

// 3. array를 섞는다
void SuffleArr(int* arr)
{
	for (int i = 0; i < 100000; i++)
	{
		int firstIndex = rand() % 45;
		int secondIndex = rand() % 45;

		int temp = arr[firstIndex];
		arr[firstIndex] = arr[secondIndex];
		arr[secondIndex] = temp;
	}
}

// 4. 그 중 7개를 뽑는다.
// 매개변수로 int size도 받아주는게 좋다.
void Choose7Number(int* arr)
{
	for (int i = 0; i < 7; i++)
	{
		printf("%d번째 숫자 : %d\n", i + 1, arr[i]);
	}
}

void main()
{
	srand(time(NULL));
	// 1. 게임시작 알림판
	PrintStartLotto();

	// 2. 1 ~ 45까지 적힌 볼을 만든다.
	int arr1[45] = {};
	GenerateNumber(arr1);

	// 3. array를 섞는다
	SuffleArr(arr1);

	// 4. 그 중 7개를 뽑는다.
	Choose7Number(arr1);
}