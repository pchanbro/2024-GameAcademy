#include <iostream>

// �̸��� ��� �빮�ڷ� ���°� �⺻
#define ARRAY_SIZE 100
#define MY_NUMBER 1
#define MY_GG =
#define ADD(a,b) a + b
//���⼭ \�� ���� �����ٱ��� �����ϰڴٴ� �ǹ�
#define ADD_AND_PRINT(a, b) printf("ADD Start : %d, %d\n", a, b);   \
							printf("ADD Result : %d\n", a + b);
using namespace std;

void main()
{
	// ��ũ��!
	// C++ ���� �����ϴ� ����
	 
	// ���� 
	// ���� #define �̸� ����(����, = �̷��� �� ��)
	// �̷��� �ϸ� '�̸�'�� '����'�� ��ü����

	// ������ MY_GG�� = �̶�� ������ �Ʒ��� ���� ��� ����
	int a MY_GG 1; // a�� 1 ����
	cout << a << endl; // 1 ��µ�

	int arr[ARRAY_SIZE] = {};

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("arr[i] = %d\n", arr[i]);
	}

	int b = ADD(2, 3);
	printf("b : %d\n", b);
}