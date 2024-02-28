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