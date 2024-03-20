#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	srand(time(NULL));

	int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
	printf("첫번째 숫자를 입력하세요 : ");
	scanf_s("%d", &num1);
	printf("두번째 숫자를 입력하세요(첫번째 숫자보다 큰 숫자로) : ");
	scanf_s("%d", &num2);
	printf("세번째 숫자를 입력하세요 : ");
	scanf_s("%d", &num3);
	printf("네번째 숫자를 입력하세요 : ");
	scanf_s("%d", &num4);

	int result = (rand() % (num2 - num1 + 1) + num1 - num3) * num4;
	printf("결과 : %d", result);
}