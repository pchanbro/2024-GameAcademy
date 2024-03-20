// ������ �ڸ�Ʈ 
// 4�� �Լ� ���뼺�� ���ؼ�
// �迭�� �ʱ�ȭ ���ٶ� size�� �Ű������� �޾��ִ°��� ����.
// �ֳ��ϸ� ������ ���ؼ���� �ϸ� 
// �ٸ� �迭�� ũ�⵵ ���� ����� ���� ��ó�� 45��� �� �� ���� �����̴�.

#include <iostream>

using namespace std;

// �ζǻ�����

// 1. ���ӽ��� �˸���
void PrintStartLotto()
{
	printf("��������������������������������������������������������������������������\n");
	printf("��        Start Lotto Gerator        ��\n");
	printf("��������������������������������������������������������������������������\n");
	cout << endl;
}

// 2. 1 ~ 45���� ���� ���� �����.
void GenerateNumber(int *arr)
{
	for (int i = 0; i < 45; i++)
	{
		arr[i] = i + 1;
	}
}

// 3. array�� ���´�
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

// 4. �� �� 7���� �̴´�.
// �Ű������� int size�� �޾��ִ°� ����.
void Choose7Number(int* arr)
{
	for (int i = 0; i < 7; i++)
	{
		printf("%d��° ���� : %d\n", i + 1, arr[i]);
	}
}

void main()
{
	srand(time(NULL));
	// 1. ���ӽ��� �˸���
	PrintStartLotto();

	// 2. 1 ~ 45���� ���� ���� �����.
	int arr1[45] = {};
	GenerateNumber(arr1);

	// 3. array�� ���´�
	SuffleArr(arr1);

	// 4. �� �� 7���� �̴´�.
	Choose7Number(arr1);
}