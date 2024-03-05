#include <iostream>

using namespace std;

void main()
{
	int arr[5] = {};

	arr[0] = 0;
	arr[4] = 4;
	cout << arr << endl;

	int* ptr = arr;
	// 포인터 변수도 배열 행동이 가능
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", ptr[i]);
	}

	// 이중배열은 받을 수 없음
	// 이게 뭔말일까 수업 영상을 다시 한 번 보자(day8 영상)
	// int arr2[10][10] = {};
	// 이 이중배열은 포인터로 받을 수 없다고 영상에 나온다.
	// int* ptr2 = arr2;

	int value = 3;
	int* ptr3 = &value;
	int** ptr4 = &ptr3;

	// &value => value의 주소값
	// &(&value) => ????
	// - int** ptr4 = &ptr3;
	// ==> ptr3의 주소값
	// => ptr3의 값이 value의 주소값을 들고있었을 뿐이고
	// => ptr3의 주소는 따로 있다. 그래서 이걸 주소값의 주소값으로 표현할 수 있지만
	// int** ptr5 = &(&value); 이런건 없다 즉. 여기서의 주소값의 주소값이란 존재하지 않는다. 참 난해한 개념이다.

	// *이 여러개라고 어렵게 생각하지말고
	// 마지막 별 기준으로
	// 앞에 자료형을 가르키는 주소값
}