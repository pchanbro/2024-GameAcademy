#include <iostream>

using namespace std;

void main()
{
	// ����

	// 1. ���ڰ� 1 ~ 100 ���� �ִ� ���� �ִ�.
	int a = 3;
	int b = 5;

	// a �� b ���� �ٲٵ��� �غ���
	// �̷��� �����غ���
	// A�ſ� ��� �ֽ�
	// B�ſ� ��� �ֽ�
	// ���� �ٲٷ��� ��� �ؾ��ұ�?

	// 1. C���� ���εд�.
	// 2. C�ſ� A�ſ� ��� �ֽ��� �ִ´�.
	// 3. A�ſ� B�ſ� ��� �ֽ��� �ִ´�.
	// 4. B�ſ� C�ſ� ��� �ֽ��� �ִ´�.

	int temp = a;
	a = b;
	b = temp;

	printf("a : %d\n", a);
	printf("b : %d\n", b);

	srand(time(NULL));

	// �迭�� ������ �� ��Ҹ� ���� 10000���ϸ� ������ �� �ִ�.
	int arr[100] = {};

	for (int i = 0; i < 100; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 100000; i++)
	{
		// A, B�� 100000�� SWAP�Ұǵ�
		// A, B�� ���� ������ ���� �ε����̴�.
		// ���� �ε����Դϴ�.

		int firstIndex = rand() % 100; // 0 ~ 99 ������ ���ڸ� �̴´�(arr ����)
		int secondIndex = rand() % 100;

		int temp = arr[firstIndex];
		arr[firstIndex] = arr[secondIndex];
		arr[secondIndex] = temp;
	}

	for (int i = 0; i < 100; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	// �ǽ�
	// �ζǻ�����
	// 1. 1 ~ 45���� ���� ���� �����.
	// 2. array�� ���´�
	// 3. �� �� 7���� �̴´�.

	cout << "�ζǻ����� ���� " << endl;

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
		printf("%d��° ���� : %d\n", i + 1, arr2[i]);
	}

}