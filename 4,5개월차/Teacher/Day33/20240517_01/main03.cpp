#include <iostream>
using namespace std;


//���⸦ ��ü��� �����ϰ�
// ��� / ���� �� �������ڽ��ϴ�. 
// 
// ��� (����ڰ� ��� ����Ұ��ΰ�?)
//  - ����1�� �Է��Ѵ�.  InputNumber1()
//  - ����2�� �Է��Ѵ�.  InputNumber2()
//  - �����ڸ� �Է��Ѵ�. InputOperator()
//  - ����� ����Ѵ�.   PrintResult()

// ����
//  - int _num1
//	- int _num2;
//  - int _oper;
//  - int _result;

class Calculator
{
public:
	void InputNumber1()
	{
		cin >> _num1;
	}
	void InputNumber2()
	{
		cin >> _num2;
	}
	void InputOperator()
	{
		cout << "(0 : +, 1 : -, 2 : *, 3 : /)";
		cin >> _oper;
	}
	void PrintResult()
	{
		//������
		Calculate();
		// ��� ���
		cout << "��� : " << _result << endl;
	}

public:
	//����ڿ��� ������ �ʿ䰡 ���� �Լ���
	void Add()
	{
		_result = _num1 + _num2;
	}
	void Subtract()
	{
		_result = _num1 - _num2;
	}
	void Multiply()
	{
		_result = _num1 * _num2;
	}
	void Divide()
	{
		_result = _num1 / _num2;
	}

	void Calculate()
	{
		switch (_oper)
		{
		case 0:
			calcFunction = &Calculator::Add;
			break;
		case 1:
			calcFunction = &Calculator::Subtract;
			break;
		case 2:
			calcFunction = &Calculator::Multiply;
			break;
		case 3:
			calcFunction = &Calculator::Divide;
			break;
		default:
			break;
		}

		//calcFunction
		// 
		//��? this�� ����ϴµ�?
		//(calc.*calcFunction)();
		cout << "�̰� ����?" << endl;
		((*this).*calcFunction)();
		cout << this->calcFunction << endl; // �̰� �ϸ� 1 ��µ�
		cout << "�̰� ���??" << endl;
		//��������Ͱ� ���� �Ⱬ�մϴ�.
	}

private:
	int _num1 = 0;
	int _num2 = 0;
	int _oper = 0;
	int _result = 0;

	//�Լ���ȯ�� (���ӽ����̽�::*������)(�ŰԺ���)
	void (Calculator::* calcFunction)(void) = nullptr;
};



void main()
{
	// ���⸦ Ŭ����ȭ�ؼ� �����ſ���.
	// �Լ������͸� ���� Ŭ���� ����Լ��� �غ����� �����ϴ�.

	Calculator calc;
	Calculator calc2;
	Calculator calc3;

	cout << "ù��° ���ڸ� �Է����ּ��� : ";
	calc.InputNumber1();

	cout << "�ι�° ���ڸ� �Է����ּ��� : ";
	calc.InputNumber2();

	cout << "�����ڸ� �Է����ּ��� : " ;
	calc.InputOperator();

	calc.PrintResult();

	void (Calculator:: * calcFunction)(void) = nullptr;

	calcFunction = &(Calculator::Add);
	
	//�긦 �����ų�� calc,calc2,calc3 �߿��� � ��ü�� Add �Լ��� ȣ���ų�ų�??
	//calcFunction();

	//����Լ��� �����ͷ� ������ � ��ü���� ���������� Ȯ���ϰ� �����������.

	//calc.calcFunction();
	// �̷��� ���� ������, �׳� calc�� �Լ����̴�.


	//����
	// �Լ������ʹ�  �ּҸ� ���
	//calc �� ��ü��
	// calcFunction���⿡ ����� �ּҷ� ���� ������Ѷ�.
	// *calcFunction
	//(calc.*calcFunction)();
	//((*this).*calcFunction)();

}
