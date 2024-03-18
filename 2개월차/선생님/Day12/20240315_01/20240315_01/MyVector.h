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

	//함수
	//반환자료형(T) 함수명([])  (매게변수 index)
	Data& operator[](int index);
	// 레퍼런스
	// 값이 가는게아니라
	// 변수 그자체가 반환이됩니다.

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
	// 0. _size를 하나더한다.
	// 1. _size가 _capacity보다 커지면
	// 2.		_capacity = _capacity * 1.5;
	// 3.		새롭게 동적배열을 만들어주고 (newArr)
	// 4.		_arr내용을 newArr에 복사한다.
	// 5.		_arr를 delete한다.
	// 6.		_arr에 newArr를 대입한다.
	// 7. 마지막인덱스에 data를 넣어준다.

	//어셈블리 구조로 보았을때.
	//_size++이게 스텝이 하나 더들어가요.

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
	// 수도코드

	// _size를 하나 늘린다.
	// _capacity가 여유가 있으면
	// where 이후의 데이터를 뒤로 한칸 밀고
	// where 인덱스에 data를 넣는다.

	// _capacity의 여유가 없으면
	// 새롭게 배열을 만들어준다.
	// 넣는건 잘넣는다. (where 전, 후)

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