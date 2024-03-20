#include <iostream>

using namespace std;

void main()
{
	// 포인터 - 3
	// 사실상 마지막
	// 제일 중요하다.
	// 특히 C, C++에서는 더욱
	
	// 동적할당

	// 포인터 => 주소값
	int value = 0;
	int* ptr = &value;
	// ptr에 value의 주솟값을 넣었다.



	// 동적으로 런타임도중에 메모리를 생성할 수 있다.

	new int();
	// new 키워드를 활용하면 int라는 변수가 생성된다.
	// 아주 무시무시한 친구다... 메모리를 엄청나게 잡아먹을 수 있다.
	// 새롭게 값이 만들어졌으면, 주소가 나올 것.


	{
		int* myPtr = new int();
		// 이렇게하면, 새롭게 동적할당된 int 메모리가 myPtr에 주소값을 저장시킨다.
		delete myPtr; // 이걸 안하면 아래 주석과 같이 된다.
	}
	// 이 중괄호를 나가면 myPtr은 삭제가 되는데
	// new int를 통해 동적으로 만들어진 부분(메모리)이 남아 있다.
	// ==> 메모리 누수
	// 그래서 C++에서는 메모리 누수 작업이 매우 중요!!!


	// 동적 메모리 삭제 방법!!
	// delete 주소값;
	// 이건 중괄호에 묶어서 써주는게 좋다.
	{
		// new 자료형
		int* myPtr = new int();
		delete myPtr;
	}



	// 이론상 1틱당 4Byte 할당
	while (true)
	{
		// 항상 new와 delete는 따라다녀야 한다.
		int * myPtr = new int();
		delete myPtr;
	}
}