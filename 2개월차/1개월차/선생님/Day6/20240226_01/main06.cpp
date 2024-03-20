#include <iostream>

using namespace std;

void main()
{
	//반복문 심화
	//for, do while, while

	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 1)	//홀수일때 로직동작안하도록
		{
			continue;
		}

		printf("%d\n", i);
		if (i == 10)
		{
			break;
		}
	}


	printf("break는 탈출!\n");
}