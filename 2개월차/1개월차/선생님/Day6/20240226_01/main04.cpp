#include <iostream>

using namespace std;

void main()
{
	// ����

	int a = 3;
	int b = 5;

	//a : 5, b : 3
	//
	//A�ſ� ��� �ֽ�
	//B�ſ� ��� �ֽ�
	//���� �ٲٷ��� ��� �ؾ��ұ�?

	//1. C���� ���εд�.
	//2. C�ſ� A�ſ� ��� �ֽ��� �ִ´�.
	//3. A�ſ� B�ſ� �ܱ� �ֽ��� �ִ´�.
	//4. B�ſ� C�ſ� ��� �ֽ��� �ִ´�.

	int temp = a;
	a = b;
	b = temp;

	printf("A : %d\n", a);
	printf("B : %d\n", b);

	// �ǽ�
	// �ζǻ�����
	// 1. 1 ~ 45���� ���� array�� �����.
	// 2. array�� ���´�
	// 3. ���� 7���� �̴´�.


	//A,B ���� 10000���ϸ� �����Դϴ�.
	int arr[100] = {};

	//1. �ʱ�ȭ
	for (int i = 0; i < 100; i++)
	{
		arr[i] = i;
	}

	//2. ����
	srand(time(NULL));

	//100000�� �������
	for (int i = 0; i < 100000; i++)
	{
		//A,B�� 100000�� SWAP�Ұǵ�
		//A, B�� ���� ������ 
		//���� �ε����Դϴ�.

		int firstIndex = rand() % 100;	// 0~99 ������ ���ڸ� �̴´� (arr ����)
		int secondIndex = rand() % 100;	// 0~99 ������ ���ڸ� �̴´� (arr ����)

		int temp = arr[firstIndex];
		arr[firstIndex] = arr[secondIndex];
		arr[secondIndex] = temp;
	}

	for (int i = 0; i < 100; i++)
	{
		printf("arr[i] : %d\n", arr[i]);
	}
	


	// ���� ���� !! 
	// 1. �ζǻ�����
	// 2. ���������� �ϳ����� (�迭���)
	// 3. 21�� ���� ��ȭ��������
}