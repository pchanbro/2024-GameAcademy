#include <iostream>

using namespace std;

int Add(int num1, int num2);

int Substract(int num1, int num2);

int Multiply(int num1, int num2);

float Divide(float num1, float num2);

void main()
{
	// �Լ�
	// �׳� �̷��� ���� �ȴ�.
	// �Լ��� ����
	// ��ȯ�ڷ��� �Լ���		(�Ű�������) {}
	// void		 printHand	(int hand)  {}

	// �Լ������� �̸��� ����, �Ű������� �Լ��� �ɼ��� �� �� �ִ�.

	// ��ȯ �ڷ����� ��ü �����ΰ�?
	// int bool ��� return�ϴ°�



	// �Լ� �̾���

	// ���⿡ ���̴� �Լ��� ����
	// Add
	// int Add(int num1, int num2);
	// �������� ��ȯ�ϴ� Add��� �Լ�
	// ���⿡�� num1�� num2�� ����.
	// ��� : num1�� num2�� ���Ѱ��� ��ȯ�Ѵ�.

	// Substract
	// int Add(int num1, int num2);
	// �������� ��ȯ�ϴ� Subtract �Լ�
	// ���⿡�� num1�� num2�� ����.
	// ��� : num1���� num2���� ����.

	// Multiply

	// Divide

	int addResult = Add(2, 3);
	printf("���ϱ� ��� �� : %d\n", addResult);
	
	int substractResult = Substract(2, 3);
	printf("���ϱ� ��� �� : %d\n", substractResult);

	int multiplyResult = Multiply(2, 3);
	printf("���ϱ� ��� �� : %d\n", multiplyResult);

	float divideResult = Divide(2, 3);
	printf("���ϱ� ��� �� : %.2f\n", divideResult);
}

int Add(int num1, int num2)
{
	return num1 + num2;
}

int Substract(int num1, int num2)
{
	return num1 - num2;
}

int Multiply(int num1, int num2)
{
	return num1 * num2;
}

float Divide(float num1, float num2)
{
	return num1 / num2;
}