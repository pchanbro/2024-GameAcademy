#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	srand(time(NULL));

	int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
	printf("ù��° ���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &num1);
	printf("�ι�° ���ڸ� �Է��ϼ���(ù��° ���ں��� ū ���ڷ�) : ");
	scanf_s("%d", &num2);
	printf("����° ���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &num3);
	printf("�׹�° ���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &num4);

	int result = (rand() % (num2 - num1 + 1) + num1 - num3) * num4;
	printf("��� : %d", result);
}