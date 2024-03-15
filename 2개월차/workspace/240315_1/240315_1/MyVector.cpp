// MyVector.h에 template라는걸 사용하자 여기에 빨간줄이 많이 생겼다
// 이렇게 생기면 MyVector.cpp를 빌드에서 제외하고
// MyVector.h에서 함수들을 직접 정의해주면 된다.
// cpp에서는 template는 안된다.

#include "MyVector.h"

MyVector::MyVector()
{
	_arr = new int[_capacity];
}

MyVector::~MyVector()
{
	delete[] _arr; // delete를 해도 _arr이 없어지는게 아니라 _arr이 가리키던 주소의 있던것이 사라지기 때문에
	_arr = nullptr; // _arr도 없애주기 위해 nullptr을 넣는다.
	// 근데 없어진건 아니고 nullptr상태가 되있는 거임
}

void MyVector::push_back(int data)
{
	// 1. size++한다.
	++_size;
	// 참고할 점 !!
	// _size++ 의 경우  ++_size보다 스텝이 하나 더 들어간다.
	// _size++의 경우
	// int temp = _size;
	// _size = _size +1;
	 
	// ++_size의 경우
	// _size = _size + 1;
	 
	// 2. _arr이 nullptr이면
	// 3.		_arr =new int[_size] 한다.
	if (_arr == nullptr)
	{
		_arr = new int[_size]; // _arr과 다른 위치의 새로운 int형 변수를 만들고
		// 그 주소값을 _arr에 넣어준다는 의미다.
		// 그래서 나중에 delete _arr 해주면 _arr이 제거되는게 아니라 _arr의 주소값이 가리키는 곳이 제거가 되는것
	}
	// 4. _arr이 nullptr이 아니면
	// 5.		새롭게 동적배열을 만들어주고 (newArr)
	// 6.		_arr내용을 newArr에 복사한다.
	// 7.		_arr을 delete한다.
	// 8.		_arr에 newArr를 대입한다.

	// 질문 
	// delete _arr 하고 다시 _arr = newArr 하는걸 보면 delete는 변수를 완전히 제거하는게 아니라 nullptr로 만들어주는 건가요 ?
	// 답변 
	// 포인터의 특성을 이해해라 여기서 _arr은 포인터 변수이기 때문에 _arr이 가리키던 주소의 값이 delete로 인해 사라진 것이고 _arr은 그대로 남아있다.
	// 참고로  벡터는 하나가 추가되면 새로운 공간을 찾아 전체가 다같이 이동하게 된다.
	else
	{
		int* newArr = new int[_size];
		// mem 뭐시기 있는데 나중에 배우자
		for (int i = 0; i < _size - 1; i++)
		{
			newArr[i] = _arr[i];
		}
		delete[] _arr; // 배열이니까 배열delete인 delete[]를 해준다.
		_arr = newArr;
	}
	// 9. 마지막 인덱스에 data를 넣어준다.
	_arr[_size - 1] = data;
}

int MyVector::at(int index)
{
	return _arr[index];
}