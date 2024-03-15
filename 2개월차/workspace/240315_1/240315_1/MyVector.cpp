// MyVector.h�� template��°� ������� ���⿡ �������� ���� �����
// �̷��� ����� MyVector.cpp�� ���忡�� �����ϰ�
// MyVector.h���� �Լ����� ���� �������ָ� �ȴ�.
// cpp������ template�� �ȵȴ�.

#include "MyVector.h"

MyVector::MyVector()
{
	_arr = new int[_capacity];
}

MyVector::~MyVector()
{
	delete[] _arr; // delete�� �ص� _arr�� �������°� �ƴ϶� _arr�� ����Ű�� �ּ��� �ִ����� ������� ������
	_arr = nullptr; // _arr�� �����ֱ� ���� nullptr�� �ִ´�.
	// �ٵ� �������� �ƴϰ� nullptr���°� ���ִ� ����
}

void MyVector::push_back(int data)
{
	// 1. size++�Ѵ�.
	++_size;
	// ������ �� !!
	// _size++ �� ���  ++_size���� ������ �ϳ� �� ����.
	// _size++�� ���
	// int temp = _size;
	// _size = _size +1;
	 
	// ++_size�� ���
	// _size = _size + 1;
	 
	// 2. _arr�� nullptr�̸�
	// 3.		_arr =new int[_size] �Ѵ�.
	if (_arr == nullptr)
	{
		_arr = new int[_size]; // _arr�� �ٸ� ��ġ�� ���ο� int�� ������ �����
		// �� �ּҰ��� _arr�� �־��شٴ� �ǹ̴�.
		// �׷��� ���߿� delete _arr ���ָ� _arr�� ���ŵǴ°� �ƴ϶� _arr�� �ּҰ��� ����Ű�� ���� ���Ű� �Ǵ°�
	}
	// 4. _arr�� nullptr�� �ƴϸ�
	// 5.		���Ӱ� �����迭�� ������ְ� (newArr)
	// 6.		_arr������ newArr�� �����Ѵ�.
	// 7.		_arr�� delete�Ѵ�.
	// 8.		_arr�� newArr�� �����Ѵ�.

	// ���� 
	// delete _arr �ϰ� �ٽ� _arr = newArr �ϴ°� ���� delete�� ������ ������ �����ϴ°� �ƴ϶� nullptr�� ������ִ� �ǰ��� ?
	// �亯 
	// �������� Ư���� �����ض� ���⼭ _arr�� ������ �����̱� ������ _arr�� ����Ű�� �ּ��� ���� delete�� ���� ����� ���̰� _arr�� �״�� �����ִ�.
	// �����  ���ʹ� �ϳ��� �߰��Ǹ� ���ο� ������ ã�� ��ü�� �ٰ��� �̵��ϰ� �ȴ�.
	else
	{
		int* newArr = new int[_size];
		// mem ���ñ� �ִµ� ���߿� �����
		for (int i = 0; i < _size - 1; i++)
		{
			newArr[i] = _arr[i];
		}
		delete[] _arr; // �迭�̴ϱ� �迭delete�� delete[]�� ���ش�.
		_arr = newArr;
	}
	// 9. ������ �ε����� data�� �־��ش�.
	_arr[_size - 1] = data;
}

int MyVector::at(int index)
{
	return _arr[index];
}