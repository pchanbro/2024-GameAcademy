#include <iostream>

using namespace std;

void main()
{
	// 포인터
	
	int value = 1;

	// 포인터 : 주소값
	// 포인터 기본
	// - 포인터는 주소값을 포함한 자료형
	// 포인터 자료형 뒤에 *을 붙임으로써 포인터를 쓸 수 있습니다.

	//&value : C5
	//*(C5) : 1

	// 변수 선언 시
	// 자료형 변수명 = 값;
	// 포인터는
	// 자료형* 변수명 = nullptr(혹은 NULL)
	int* myPtr = nullptr;
	myPtr = &value; // &연산자 : 해당 변수의 주소값을 가져옴
	cout << myPtr << endl;
	cout << &myPtr << endl; 
	cout << *(*(&myPtr)) << endl;
	cout << *myPtr << endl; // *연산자 : 해당 주소값의 값을 가져옴

	// *(&myPtr) == myPtr
	// 값이 같다.
	// 왜냐?
	// & => 해당 변수의 주소값을 나타내고
	// * => 해당 변수의 주소에 있는 값을 나타낸다.
}