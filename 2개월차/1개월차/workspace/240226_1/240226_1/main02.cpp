#include <iostream>
#include <time.h>

using namespace std;

int _comHand1 = 0;
int _comHand2 = 0;
int _comHand3 = 0;
int _rank = 1;

// 1. ��ǻ�� ���� ���� ���ڸ� �̴´�. (0 ~ 99)
void ChooseNum()
{
	_comHand1 = rand() % 100;
	_comHand2 = rand() % 100;
	_comHand3 = rand() % 100;
}

// 2. ��ǻ�Ͱ� ���� ���ڸ� ����Ѵ�.
void PrintNum()
{
	cout << "COM1�� ���� : " << _comHand1 << endl;
	cout << "COM2�� ���� : " << _comHand2 << endl;
	cout << "COM3�� ���� : " << _comHand3 << endl;
}

// 3. ���� ���ڰ� ���� ���� �¸��Ѵ�.
void CompareNum()
{
	if (_comHand1 < _comHand2)
	{
		if (_comHand2 < _comHand3)
		{
			cout << "1�� : COM3!!" << endl;
			cout << "2�� : COM2!!" << endl;
			cout << "3�� : COM1!!" << endl;
		}
		else if (_comHand3 < _comHand2)
		{
			if (_comHand1 < _comHand3)
			{
				cout << "1�� : COM2!!" << endl;
				cout << "2�� : COM3!!" << endl;
				cout << "3�� : COM1!!" << endl;
			}
			else if (_comHand3 < _comHand1)
			{
				cout << "1�� : COM2!!" << endl;
				cout << "2�� : COM1!!" << endl;
				cout << "3�� : COM3!!" << endl;
			}
			else 
			{
				cout << "1�� : COM2!!" << endl;
				cout << "���� 2�� : COM1, COM3" << endl;
			}
		}
		else
		{
			cout << "���� 1�� : COM2, COM3!!" << endl;
			cout << "3�� : COM1" << endl;
		}
	}
	else if (_comHand2 < _comHand1)
	{
		if (_comHand1 < _comHand3)
		{
			cout << "1�� : COM3!!" << endl;
			cout << "2�� : COM1!!" << endl;
			cout << "3�� : COM2!!" << endl;
		}
		else if (_comHand3 < _comHand1)
		{
			if (_comHand2 < _comHand3)
			{
				cout << "1�� : COM1!!" << endl;
				cout << "2�� : COM3!!" << endl;
				cout << "3�� : COM2!!" << endl;
			}
			else if (_comHand3 < _comHand2)
			{
				cout << "1�� : COM1!!" << endl;
				cout << "2�� : COM2!!" << endl;
				cout << "3�� : COM3!!" << endl;
			}
			else
			{
				cout << "1�� : COM1!!" << endl;
				cout << "���� 2�� : COM2, COM3" << endl;
			}
		}
		else
		{
			cout << "���� 1�� : COM1, COM3!!" << endl;
			cout << "3�� : COM2" << endl;
		}
	}
	else
	{
		if (_comHand1 < _comHand3)
		{
			cout << "1�� : COM3!!" << endl;
			cout << "���� 2�� : COM1, COM2" << endl;
		}
		else if (_comHand3 < _comHand1)
		{
			cout << "���� 1�� : COM1, COM2 !!" << endl;
			cout << "3�� : COM3" << endl;
		}
	}
}

void main()
{
	// �ϴ� ������ ���� �ϳ� ����� ����
	
	srand(time(NULL));
	// 1. ��ǻ�� ���� ���� ���ڸ� �̴´�. (0 ~ 99)
	ChooseNum();
	// 2 ��ǻ�Ͱ� ���� ���ڸ� ����Ѵ�.
	PrintNum();
	// 3. ���� ���ڰ� ���� ���� �¸��Ѵ�.
	CompareNum();

}

// ���α׷� ������ �ַ� ��� �Ͼ�°�
// ������ 2���� �ƴ϶� 3���ε���?
// 3����� ���α׷��� �������
// ������� ���ڱ� 10���̼� �ϵ��� �������� 
// �׷��� ����µ� �󸶳� �ɸ���?


// �̷� �� ���� ������ �ٷ� : �迭