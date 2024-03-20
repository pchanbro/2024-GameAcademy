#include <iostream>

using namespace std;

void main()
{
	// 배열의 동적할당

	// 배열 = 포인터
	// 비슷하다
	// 동적할당을
	// 배열로도 할 수 있다.
	// 이차원포인터로 받는게 아니고
	// 그냥 똑같이 일차원 포인터로 배열 동적할당을 한다.

	// new int[크기]
	int* arr = new int[10];

	int count = 20;
	// int myArr[count]; 이게 안되지

	// 하지만 동적 할당이라면 얘기가 다르다
	// 런타임 도중에 메모리를 할당하는거라서, 그 때 맞는 배열크기를 적어도 문제가 되지않음
	int* myArr = new int[count];
	for (int i = 0; i < count; i++)
	{
		myArr[i] = i;
	}
	// 이렇게 쓰면 된다.

	// 삭제하는 방법
	// delete[] 주소값;
	delete[] myArr;

}