#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
	return num1 + num2;
}

int Subtract(int num1, int num2)
{
	return num1 - num2;
}

int Multiply(int num1, int num2)
{
	return num1 * num2;
}

int Divide(int num1, int num2)
{
	return num1 / num2;
}



void main()
{
	// ���� �ǽ�

	// �̷� ��ﶧ
	// [What, How], Why
	// �����̰� ��Ծ��°���
	// �Լ������Ϳ� ����

	// �Լ������͸� �־��°�?

	// ���� �Ⱬ�ѹ����� �ᰡ�鼭����, �Լ��� ����ϰ� �� ������ ����ؾ��ϳ�??
	// myFunction1(2, 3); ȣ���ϴ°ͺ���
	// Add(2,3); �� �ξ��� �������� ����.  << �̰Ŵ� ���ٸ��о 2�� 3�� ���Ѵ�.

	// ���°��߿� �Ѱ��� ���������� ���̴°�
	// ���� AI (����)
	// ������ �⺻��������� 
	//  -> void (����::*DoSomething)(void)  ��� ������ ���� 
	//    Ȱ���� �մϴ�.

	// Update������
	//   - �÷��̾ �� �ֺ��� �ִ� => DoSomething = &�����Ѵ�.
	//   - HP�� 30 ���ϴ� => DoSomething = &�޽��Ѵ�.
	//   - �÷��̾ ���Ÿ����� �����Ѵ� => DoSomething = &�����Ѵ�.

	// AI ����������
	// ��� ���ʹ� DoSomething() ���ุ�ϸ�, AI ������ �ϼ��� �ǰ���.

	// �ᱹ���� �־���??
	// DoSomething �����ϳ���, �ൿ�� ���� ��� �Լ��� �˾Ƽ� Ŀ���Ҽ��ִ�.

	

	// ����
	
	// ���� �����Լ�.
	int (*calculatorFunction)(int num1, int num2) = nullptr;
	int num1 = 0, num2 = 0;

	cout << "ù��° ���ڸ� �Է����ּ���. " << endl;
	cin >> num1;

	cout << "�ι�° ���ڸ� �Է����ּ���. " << endl;
	cin >> num2;

	int oper = 0;

	cout << "�����ڸ� �Է����ּ��� (+ : 0, - : 1, * : 2, / : 3)" << endl;
	cin >> oper;

	switch (oper)
	{
	case 0:
		calculatorFunction = &Add;
		break;
	case 1:
		calculatorFunction = &Subtract;
		break;
	case 2:
		calculatorFunction = &Multiply;
		break;
	case 3:
		calculatorFunction = &Divide;
		break;
	default:
		break;
	}

	if (calculatorFunction != nullptr)
	{
		cout << "��� : " << calculatorFunction(num1, num2) << endl;
	}
}