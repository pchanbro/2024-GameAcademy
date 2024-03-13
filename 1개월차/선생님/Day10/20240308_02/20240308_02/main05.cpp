#include <iostream>

using namespace std;


void main()
{
	// 배열의 동적할당

	// 배열 = 포인터
	// 비슷하다라고 제가 수차례 언급했습니다.

	// 동적할당을
	// 배열로도 할수있는데
	// 이차원포인터로 받는게아니고
	// 그냥 똑같이 일차원 포인터로 배열 동적할당을 합니다.

	//new int[크기]
	int* arr = new int[10];

	int count = 20;
	//int myArr[count];

	//런타임 도중에 메모리를 할당하는거라서, 그때맞는 배열크기를 적어도 문제가 되지않음.
	int* myArr = new int[count];
	for (int i = 0; i < count; i++)
	{
		myArr[i] = i;
	}
	//이렇게 쓰면됩니다.

	//삭제하는 방법!!
	//delete[] 주소값;
	delete[] myArr;

}