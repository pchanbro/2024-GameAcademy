#include<iostream>
#include<vector>

using namespace std;

void CallByValue(int value);
void CallByReference(int& value2);
// 비추천
void CallByAddress(int* value3);

void main()
{
	// 함수!
	// 호출하는 용도로 사용했었다
	int value = 4;
	// 근데 함수 안에서는 값 증가가 안된다.
	
	//CallByValue(value);
	/*
	{
		int value1 = value;
		{
			value1++;
			printf("Hello World : %d\n", value1);
		}
	}
	*/

	// 그래서 여기는 그대로 4가 출력된다.
	printf("valuse :%d\n", value);

	//CallByReference(value);
	// 새롭게 메모리가 추가로 발생하지 않음
	// 참조한다.
	/*{
		int& value2 = value;
		{
			value2++;
			printf("Hello World! : %d\n", value2);
		}
	}*/

	// 포인터 -> 주소값
	// 일반 변수 => 변수의 주소값
	// &변수명
	//CallByAddress(&value);
	//{
	//	int* value3 = &value;
	//	{
	//		(*value3)++;
	//		printf("Hello World! : %d\n", value3);
	//	}
	//}

	
	printf("valuse :%d\n", value);

}

void CallByValue(int value1)
{
	// 함수에서 값을 증가시켜 출력하면 5가 출력되지만 이 변수는 main문의 value와는 다른 변수이다.
	value1++;
	printf("Hello World! : %d\n", value1);
}

void CallByReference(int& value2)
{
	
	value2++;
	printf("Hello World! : %d\n", value2);
}

void CallByAddress(int* value3)
{
	// value3 => 주소값
	(*value3)++;
	printf("Hello World! : %d\n", value3);
}