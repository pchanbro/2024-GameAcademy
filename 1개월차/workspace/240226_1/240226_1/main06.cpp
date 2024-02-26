#include <iostream>

using namespace std;

void main()
{
	// 반복문 심화
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


	printf("break는 탈출!\n");

	// 오늘 숙제
	// 1. 로또생성기
	// 2. 가위바위보 하나빼기 (배열사용)
	// 3. 21일 숙제 심화버전까지 
}