#include <iostream>

using namespace std;


// �ζǻ�����
// 1. 1 ~ 45���� ���� ���� �����.
// 2. array�� ���´�
// 3. �� �� 7���� �̴´�.

void PrintStartLotto()
{
	printf("��������������������������������������������������������������������������\n");
	printf("��        Start Lotto Gerator        ��\n");
	printf("��������������������������������������������������������������������������\n");
	cout << endl;
}

void GenerateNumber(int *arr1)
{
	for (int i = 0; i < 45; i++)
	{

	}
}

void main()
{
	PrintStartLotto();

	int arr1[45] = {};

	GenerateNumber(arr1);

	

	for (int i = 0; i < 45; i++)
	{
		arr1[i] = i + 1;
	}

	for (int i = 0; i < 100000; i++)
	{
		int firstIndex = rand() % 45;
		int secondIndex = rand() % 45;

		int temp = arr1[firstIndex];
		arr1[firstIndex] = arr1[secondIndex];
		arr1[secondIndex] = temp;
	}

	for (int i = 0; i < 7; i++)
	{
		printf("%d��° ���� : %d\n", i + 1, arr1[i]);
	}
}