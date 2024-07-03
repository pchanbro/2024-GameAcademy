#include <iostream>
using namespace std;
#include "Windows.h"

int a = 0;
int b = 0;

void Run()
{
	cout << "Run" << endl;
}

void Run1(int argument1, int argument2)
{
	cout << "Run1 : " << argument1 << " , " << argument2 << endl;
}

int Add(int num1, int num2)
{
	return num1 + num2;
}

int Minus(int num1, int num2)
{
	return num1 - num2;
}

int Multiply(int num1, int num2)
{
	return num1 * num2;
}

float Divide(int num1, int num2)
{
	if (num2 == 0)
	{
		cout << "0���� ���� �� �����ϴ�. " << endl;
		return 0;
	}

	return (float)num1 / (float)num2;
}

int main()
{
	// �Լ�������

	// - �Լ������� -> ��¥ ���� ��ƴ�.
	//  �������Ҷ� ��ƴ� ��ƴ� ������ �״� ����� �ʾҴ� ����
	// �Լ� �����͸� ���� �����߱� �����̴�.

	// ������ : �ּҸ� ����Ű�� �ڷ���
	// �Լ� ������ : �Լ��� �ּҸ� ����Ű�� �ڷ���

	// - �Լ��� �޸𸮸� �����Ѵ�.

	// int���� 4byte �޸𸮸� �����Ѵ� �����.
	// �Լ��� 4byte�� �����Ѵ�. (����Լ��� 4byte ����)

	// �Լ��� �ּҸ� ����ߴٰ� ���߿� �� �� �ְڴ�.
	// -> �̰� �Լ� �����Ͷ�� �Ѵ�. (�ٸ� ������ '�ݹ�' �̶�� �Ѵ�)
	// �Լ������ʹ� C�� C++���� �����Ѵ�. 
	
	// �Լ�������(�ݹ�) : �Լ��� �ּҸ� ����ߴٰ� ���߿� ����ϴ� ���

	// �����Ͷ� �ϸ� ���ݱ��� * �� ����߾���.
	// int* float* char* bool* ���

	// �Լ������� : �Լ���ȯ�� ���ӽ����̽�::*������(�Ű�����)
	//			- ex) void (*myFunction1)(void) = &Run; �̷� ����
	// void������ : ġƮŰ �������� � �ּҵ� ���� �� �ִ�. 
	//			- ex) void *myPointer = &Run;

	cout << "Run() �Լ��� �ּ� : " << &Run << endl;
	void* myPointer = &Run;
	// void Run();

	void (*myFunction1)(void) = &Run; // �̰� ��¥ �Լ��������� ����

	cout << "myPointer : " << myPointer << endl;

	// �Լ��� ������� ����� �ϴ¹�:
	cout << "-----------------------" << endl;
	myFunction1();

	// ��������� �Լ������� ����
	

	// ���� 1. �Ű������� �ִ� �Լ��� �Լ������ͷ� �Ẹ��.
	// void Run1(int argument1, int argument2)
	// �Լ���ȯ�� ���ӽ����̽�::*������(�Ű�����)
	void (*myFunction2)(int /* ���� ���°� �̸��̶� ������ ���� �ǹ̾���*/, int) = &Run1;
	myFunction2(10, 10); // ���� ��� �� ���� �̷��� �־��ְ� ����ϸ� ��
	// �̷��� Run1(10,10); �� ����.

	// ���� 2. ��ȯ�ڷ����� �ִ� �Լ��� �Լ������ͷ� �Ẹ��.
	// int Add (int num1, int num2)
	int (*myFunction3)(int, int) = &Add;
	int addValue = myFunction3(2, 3); // Add(2,3)
	cout << "addValue : " << addValue << endl;

	// �ǽ� 
	// ���� �����
	// 0. ���� +(Add) -(Minus) *(Multiply) /(Division) �Լ��� �����.
	// 1. ���� �� ���� �Է¹޴´�.
	// 2. (+ - / *) �� �ϳ��� �� �� �ֵ��� �Է¹޴´�.
	// 3. 2���� �����ϸ�, �Լ������ͷ� 0������ ���� �Լ��� �ϳ� �޵��� �Ѵ�.
	// 4. �Լ������͸� ���� ��, ����� ����Ѵ�.

	int (*myFunction4)(int, int) = &Add;
	int (*myFunction5)(int, int) = &Minus;
	int (*myFunction6)(int, int) = &Multiply;
	float (*myFunction7)(int, int) = &Divide;
	int addValue2 = 0;
	int minusValue = 0;
	int multiplyValue = 0;
	float divisionValue = 0;

	while (true)
	{
		system("cls");
		cout << "���� ���� " << endl;
		int num3 = 0;
		int num4 = 0;
		cout << "�� ���� �Է��ϼ���" << endl;
		cout << "ù��° �� : ";
		cin >> num3;
		cout << "�ι�° �� : ";
		cin >> num4;

		char choice = 0;
		cout << "+ - / * �� �ϳ��� �Է��ϼ��� " << endl;
		cin >> choice;

		switch (choice)
		{
		case '+' :
			cout << "���ϱ�" << endl;
			addValue2 = myFunction4(num3, num4);
			cout << num3 << " " << choice << " " << num4 << " = " << addValue2 << endl;
			break;
		case '-':
			cout << "����" << endl;
			minusValue = myFunction5(num3, num4);
			cout << num3 << " " << choice << " " << num4 << " = " << minusValue << endl;
			break;
		case '*':
			cout << "���ϱ�" << endl;
			multiplyValue = myFunction6(num3, num4);
			cout << num3 << " " << choice << " " << num4 << " = " << multiplyValue << endl;
			break;
		case '/':
			cout << "������" << endl;
			divisionValue = myFunction7(num3, num4);
			cout << num3 << " " << choice << " " << num4 << " = " << divisionValue << endl;
			break;
		default:
			break;
		}
		system("pause");
	}
}