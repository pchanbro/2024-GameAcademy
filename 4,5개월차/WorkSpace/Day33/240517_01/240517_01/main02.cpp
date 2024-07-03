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
	if (num2 == 0)
	{
		cout << "0���� ���� �� �����ϴ�. " << endl;
		return 0;
	}

	return (float)num1 / (float)num2;
}

void main()
{
	// ���� �ǽ�

	// �̷� ��ﶧ
	// [What, How], Why �� �������� �����ؾ��Ѵ�.
	// �����̰� ��� ���°���
	// �Լ������Ϳ� ����

	// �Լ������͸� �־��°�?

	// ���� �Ⱬ�� ������ �ᰡ�鼭����, �Լ��� ����ϰ� �� ������ ����ؾ��ϳ�??
	// myFunction1(2,3); ó�� ȣ���ϴ°ͺ��� 
	// Add(2,3); �� �ξ� �� �������� ����. << �̰Ŵ� ���ٸ� �о 2�� 3�� ���Ѵ�.

	// ���°��߿� �Ѱ��� ���������� ���̴°�
	// ���� AI
	// ������ �⺻���������
	//  -> void (��������::*DoSomething) (void) ��� ������ ����
	//    Ȱ���� �Ѵ�.

	// Update������
	//    - �÷��̾ �� �ֺ��� �ִ� => DoSomething = &�����Ѵ�.
	//    - HP�� 30 ���ϴ� => DoSomething = &�޽��Ѵ�.
	//    - �÷��̾ ���Ÿ����� �����Ѵ� => DoSomething = &�����Ѵ�.

	// AI ����������
	// ��� ���ʹ� DoSomething() ���ุ�ϸ�, AI ������ �ϼ��� �ȴ�.

	// �ᱹ���� �� ����??
	// DoSomething �����ϳ���, �ൿ�� ���� ��� �Լ��� �˾Ƽ� Ŀ���� �� �ִ�.

	// ����

	// ���� �����Լ�
	int (*calculatorFunction)(int num1, int num2) = nullptr;
	int num1 = 0, num2 = 0;

	cout << "ù��° ���ڸ� �Է����ּ��� : ";
	cin >> num1;

	cout << "�ι�° ���ڸ� �Է����ּ��� : ";
	cin >> num2;

	int oper = 0;

	cout << "�����ڸ� �Է����ּ��� ( + : 0, - : 1, * : 2, / : 3) :";
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