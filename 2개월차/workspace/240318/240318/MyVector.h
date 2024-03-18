#pragma once

template <typename T>
class MyVector
{
private:
	T* _arr = nullptr;
	int _size = 0;
	int capacity = 2;

public:
	void push_back(T data);
	Data at(int index);

	Data& operator[] (int index);

	MyVector()
	{
		_arr = new T[_capacity];
	}
	~MyVector()
	{
		delete[] _arr;
		_arr = nullptr;
	}

};

template <typename T>
void MyVector<T>::push_back(T data)
{
	++_size;
	if (_capacity < _size)
	{
		_capacity = _capacity * 1.5;
		T* newArr = new T[_capacity];
		for (int i = 0; i < _size - 1; i++)
		{
			newArr[i] = _arr[i];
		}
		delete[] _arr;
		_arr = newArr;
	}
	_arr[capacity] = data;
}
