#include <iostream>

//��� �빮�ڷ� ���°� �⺻.
#define ARRAY_SIZE 3
#define MY_NUMBER =
#define ADD(a, b) a + b
#define ADD_AND_PRINT(a, b) printf("ADD Start : %d, %d\n", a, b);	\
							printf("Add Result : %d\n", a + b);
using namespace std;

void main()
{
	//��ũ��!
	//C++ ���� �����ϴ� ����

	//����
									printf("asdf\n");
	int a MY_NUMBER 3;


	int b = ADD(2, 3);
	printf("b : %d\n", b);

	printf("a : %d\n", a);

	int arr[ARRAY_SIZE] = {};
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("arr[i] = %d\n", arr[i]);
	}


	ADD_AND_PRINT(100, 203);
}