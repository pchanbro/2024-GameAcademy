#include <iostream>
using namespace std;


//반환자료형 함수명(매게변수들);
void CallByValue(int value1);
void CallByReference(int& value2);
//비 추천
void CallByAddress(int* value3);
void main()
{
	//함수!
	//호출하는 용도로 사용
	int value = 4;
	//::CallByValue(value);
	//{
	//	int value1 = value;
	//	{
	//		value1++;
	//		printf("Hello World! : %d\n", value1);
	//	}
	//}

	//::CallByReference(value);
	//{
	//	//새롭게 메모리가 추가로 발생하지 않음.
	//	//참조한다.
	//	int& value2 = value;
	//	{
	//		value2++;
	//		printf("Hello World! : %d\n", value2);
	//	}
	//}

	//포인터 => 주소값
	//일반 변수 => 변수의 주소값
	// &변수명
	//::CallByAddress(&value);
	/*{
		int* value3 = &value;
		{
			(*value3)++;
			printf("Hello World! : %d\n", *value3);
		}
	}*/

	printf("value : %d\n", value);
}

void CallByValue(int value1)
{
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
	//value3 => 주소값
	//주소값의 값으로 가서 ++ 해야함.
	(*value3)++;
	printf("Hello World! : %d\n", *value3);
}