#pragma once

template <typename Data>
class MyVector
{
private:
	Data* _arr = nullptr;
	int _size = 0;
	int _capacity = 2;

public:
	void push_back(Data data);
	Data at(int index);

	//�Լ�
	//��ȯ�ڷ���(T) �Լ���([])  (�ŰԺ��� index)
	Data& operator[](int index);
	// ���۷���
	// ���� ���°Ծƴ϶�
	// ���� ����ü�� ��ȯ�̵˴ϴ�.

	void insert(int where, Data data);
	int size() { return _size; }
	int capacity() { return _capacity; }
public:
	MyVector() {
		_arr = new Data[_capacity];
	}

	~MyVector() {
		delete[] _arr;
		_arr = nullptr;
	}

};


template <typename Data>
void MyVector<Data>::push_back(Data data)
{
	// 0. _size�� �ϳ����Ѵ�.
	// 1. _size�� _capacity���� Ŀ����
	// 2.		_capacity = _capacity * 1.5;
	// 3.		���Ӱ� �����迭�� ������ְ� (newArr)
	// 4.		_arr������ newArr�� �����Ѵ�.
	// 5.		_arr�� delete�Ѵ�.
	// 6.		_arr�� newArr�� �����Ѵ�.
	// 7. �������ε����� data�� �־��ش�.

	//����� ������ ��������.
	//_size++�̰� ������ �ϳ� ������.

	++_size;
	if (_size > _capacity)
	{
		_capacity = _capacity * 1.5;
		Data* newArr = new Data[_capacity];
		for (int i = 0; i < _size - 1; i++)
		{
			newArr[i] = _arr[i];
		}
		delete[] _arr;

		_arr = newArr;
	}

	_arr[_size - 1] = data;
}


template <typename Data>
Data MyVector<Data>::at(int index)
{
	return _arr[index];
}

template <typename Data>
Data& MyVector<Data>::operator[](int index)
{
	return _arr[index];
}

template <typename Data>
void MyVector<Data>::insert(int where, Data data)
{
	// �����ڵ�

	// _size�� �ϳ� �ø���.
	// _capacity�� ������ ������
	// where ������ �����͸� �ڷ� ��ĭ �а�
	// where �ε����� data�� �ִ´�.

	// _capacity�� ������ ������
	// ���Ӱ� �迭�� ������ش�.
	// �ִ°� �ִ߳´�. (where ��, ��)

	++_size;
	if (_size <= _capacity)
	{
		for (int i = _size - 1; i >= where; i--)
		{
			_arr[i] = _arr[i - 1];
		}
	}
	else
	{
		_capacity *= 1.5;
		Data* newArr = new Data[_capacity];
		for (int i = 0; i < where; i++)
		{
			newArr[i] = _arr[i];
		}
		for (int i = _size - 1; i >= where; i--)
		{
			newArr[i] = _arr[i - 1];
		}
		_arr = newArr;
	}
	_arr[where] = data;

}