#include <iostream>
using namespace std;
void main()
{
	// 포인터 - 2

	// 그래서 포인터가 무엇인가??
	// & * 사용법

	// 포인터 = 배열
	// 엄밀히말하면 조금 다릅니다.

	int arr[5] = {};

	arr[0] = 0;
	arr[4] = 4;
	cout << arr << endl;

	int* ptr = arr;
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", ptr[i]);
	}

	//이중배열은 받을 수 없음.
	//int arr2[10] = {};
	//int* ptr2 = arr2;

	int value = 3;
	int* ptr3 = &value;
	int* ptr3_1 = &value;
	int** ptr4 = &ptr3;

	//&value => value의 주소값
	//& (&value) => ????
	// - int** ptr4 = &ptr3;
	//  ==> ptr3의 주소값
	//  => ptr3의 값이 value의 주소값을 들고있었을 뿐이고
	//  => ptr3의 주소는 따로있습니다.
	//int** ptr5 = &(&value);

	// *이 여러개라고 어렵게 생각하지말고
	// 마지막별기준으로
	// 앞에 자료형을 가르키는 주소값

	//실제로 포인터로 뭘하는지에 대해서는
	// 다음번 포인터배울때 배울거에요!
	// 오히려 내용이 별거없어요.

	//저 주소값의 주소값
	// 이런 난해한 개념때문에
	// 다른언어에서는 포인터라는게 없습니다.
}