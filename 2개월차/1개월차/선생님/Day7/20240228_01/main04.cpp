#include <iostream>

using namespace std;
int Add(int num1, int num2)
{
	printf("%d + %d �� �����մϴ�.\n", num1, num2);

	int result = num1 + num2;
	return result;
}
int Subtract(int num1, int num2)
{
	return num1 - num2;
}
int Multiply(int num1, int num2)
{
	return num1 * num2;
}
int Devide(int num1, int num2)
{
	return num1 / num2;
}
void main()
{
	//�Լ� �̾

	//�Լ� 
	// �׳� �̷��� ����ȴ�.
	// ���°� �̷���.
	//�Լ��� ����
	//��ȯ�ڷ��� �Լ���		(�ŰԺ�����) {}
	//void		PrintHand	(int hand)  {}

	
	//�Լ������� �̸��� ����, �ŰԺ����� �Լ��� �ɼ��� �ټ��ִ�.

	//��ȯ �ڷ����� ��ü �����ΰ�?


	//�Լ��� ����ſ���.
	//���⿡ ���̴� �Լ��� ����
	//Add
	// int Add(int num1, int num2);
	// �������� ��ȯ�ϴ� Add��� �Լ�
	// ���⿡�� num1�� num2�� ����
	// ��� : num1�� num2�� ���Ѱ��� ��ȯ�Ѵ�.

	//�Լ��� ����� �����ϴ°� �����ϴ�. 
	// (�ڵ帮���Ҷ��� �ȵǾ������� �׻� ������ �Ǿ��)

	
	//Subtract
	//Multiply
	//Divide
	int addResult = Add(2, 3);
	printf("���ϱ� ��� �� : %d\n", addResult);

	//rand()
	// int rand();
	// �������� ��ȯ�ϴ� rand��� �Լ�
	// ���⿡�� �ƹ��� �ŰԺ����� �ȵ���.
	// ��� : �������� ��ȯ�Ѵ�.
}