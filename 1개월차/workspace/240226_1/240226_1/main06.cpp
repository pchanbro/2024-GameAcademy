#include <iostream>

using namespace std;

void main()
{
	// �ݺ��� ��ȭ
	// for, do while, hwile

	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		printf("%d\n", i);
		if (i == 10)
		{
			break;
		}
	}


	printf("break�� Ż��!\n");

	// ���� ����
	// 1. �ζǻ�����
	// 2. ���������� �ϳ����� (�迭���)
	// 3. 21�� ���� ��ȭ�������� 
}