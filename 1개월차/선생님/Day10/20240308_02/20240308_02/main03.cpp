#include <iostream>

using namespace std;

void main()
{
	// 포인터 - 3
	// 사실상 마지막!!!
	// 제일 중요합니다.
	// 특히 C,C++에서!!

	// 동적할당
	

	// 포인터 => 주소값
	int value = 0;
	int* ptr = &value;
	//ptr에 value의 주솟값을 넣었다.

	//동적으로 런타임도중에 메모리를 생성할수있음.

	new int();
	//new 키워드를 활용하면 int라는 변수가 생성된다.
	//새롭게 값이 만들어졌으면, 주소가 나올 것.

	{
		int* myPtr = new int();
		//이렇게하면, 새롭게 동적할당된 int 메모리가 myPtr에 주소값을 저장시킨다.

	}

	// 중괄호 나가면
	// myPtr은 삭제가 됩니다.
	// myPtr은 정적메모리 이기 떄문에 삭제가 되지만,
	// new int() 로 만든 동적 메모리는 동적 메모리 이기때문에 삭제 안된다.
	//  ==> 메모리 누수
	//  그래서 C++에서는 메모리누수 막는 작업이 가장 중요함!!
	// 어? 그러면 삭제하는 방법이 있으니까, 누수라고 부르겠네요?
	
	// 동적 메모리 삭제하는 방법!!
	// delete 주소값;
	{
		//new 자료형();
		int* myPtr = new int();
		delete myPtr;
	}


	
	//이론상 1틱당 4byte 할당
	while (true)
	{
		//항상 new와 delete는 따라다녀야 한다.
		int * myPtr = new int();
		delete myPtr;
	}



}