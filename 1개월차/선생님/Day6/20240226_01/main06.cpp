#include <iostream>

using namespace std;

void main()
{
	//�ݺ��� ��ȭ
	//for, do while, while

	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 1)	//Ȧ���϶� �������۾��ϵ���
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
}