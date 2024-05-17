#include <iostream>
using namespace std;
#include "Windows.h"

int a = 0;
int b = 0;

void Run()
{
	cout << "Run" << endl;
}

void Run1(int argument1, int argument2)
{
	cout << "Run1 : " << argument1 << " , " << argument2 << endl;
}

int Add(int num1, int num2)
{
	return num1 + num2;
}

int Minus(int num1, int num2)
{
	return num1 - num2;
}

int Multiply(int num1, int num2)
{
	return num1 * num2;
}

float Divide(int num1, int num2)
{
	if (num2 == 0)
	{
		cout << "0으로 나눌 수 없습니다. " << endl;
		return 0;
	}

	return (float)num1 / (float)num2;
}

int main()
{
	// 함수포인터

	// - 함수포인터 -> 진짜 많이 어렵다.
	//  포인터할때 어렵다 어렵다 했지만 그닥 어렵진 않았던 이유
	// 함수 포인터를 빼고 수업했기 때문이다.

	// 포인터 : 주소를 가리키는 자료형
	// 함수 포인터 : 함수의 주소를 가리키는 자료형

	// - 함수도 메모리를 차지한다.

	// int형은 4byte 메모리를 차지한다 배웠다.
	// 함수도 4byte를 차지한다. (모든함수가 4byte 차지)

	// 함수의 주소를 기억했다가 나중에 쓸 수 있겠다.
	// -> 이걸 함수 포인터라고 한다. (다른 언어에서는 '콜백' 이라고 한다)
	// 함수포인터는 C랑 C++에만 존재한다. 
	
	// 함수포인터(콜백) : 함수의 주소를 기억했다가 나중에 사용하는 기법

	// 포인터라 하면 지금까지 * 를 사용했었다.
	// int* float* char* bool* 등등

	// 함수포인터 : 함수반환형 네임스페이스::*변수명(매개변수)
	//			- ex) void (*myFunction1)(void) = &Run; 이런 느낌
	// void포인터 : 치트키 느낌으로 어떤 주소든 담을 수 있다. 
	//			- ex) void *myPointer = &Run;

	cout << "Run() 함수의 주소 : " << &Run << endl;
	void* myPointer = &Run;
	// void Run();

	void (*myFunction1)(void) = &Run; // 이게 진짜 함수포인터의 형태

	cout << "myPointer : " << myPointer << endl;

	// 함수를 담았으니 사용을 하는법:
	cout << "-----------------------" << endl;
	myFunction1();

	// 여기까지가 함수포인터 기초
	

	// 응용 1. 매개변수가 있는 함수를 함수포인터로 써보자.
	// void Run1(int argument1, int argument2)
	// 함수반환형 네임스페이스::*변수명(매개변수)
	void (*myFunction2)(int /* 여기 들어가는건 이름이라 적으나 마나 의미없음*/, int) = &Run1;
	myFunction2(10, 10); // 실제 사용 시 값을 이렇게 넣어주고 사용하면 됨
	// 이러면 Run1(10,10); 와 같다.

	// 응용 2. 반환자료형이 있는 함수를 함수포인터로 써보자.
	// int Add (int num1, int num2)
	int (*myFunction3)(int, int) = &Add;
	int addValue = myFunction3(2, 3); // Add(2,3)
	cout << "addValue : " << addValue << endl;

	// 실습 
	// 계산기 만들기
	// 0. 각각 +(Add) -(Minus) *(Multiply) /(Division) 함수를 만든다.
	// 1. 숫자 두 개를 입력받는다.
	// 2. (+ - / *) 중 하나를 할 수 있도록 입력받는다.
	// 3. 2번을 실행하면, 함수포인터로 0번에서 만든 함수를 하나 받도록 한다.
	// 4. 함수포인터를 실행 후, 결과를 출력한다.

	int (*myFunction4)(int, int) = &Add;
	int (*myFunction5)(int, int) = &Minus;
	int (*myFunction6)(int, int) = &Multiply;
	float (*myFunction7)(int, int) = &Divide;
	int addValue2 = 0;
	int minusValue = 0;
	int multiplyValue = 0;
	float divisionValue = 0;

	while (true)
	{
		system("cls");
		cout << "계산기 시작 " << endl;
		int num3 = 0;
		int num4 = 0;
		cout << "두 수를 입력하세요" << endl;
		cout << "첫번째 수 : ";
		cin >> num3;
		cout << "두번째 수 : ";
		cin >> num4;

		char choice = 0;
		cout << "+ - / * 중 하나를 입력하세요 " << endl;
		cin >> choice;

		switch (choice)
		{
		case '+' :
			cout << "더하기" << endl;
			addValue2 = myFunction4(num3, num4);
			cout << num3 << " " << choice << " " << num4 << " = " << addValue2 << endl;
			break;
		case '-':
			cout << "빼기" << endl;
			minusValue = myFunction5(num3, num4);
			cout << num3 << " " << choice << " " << num4 << " = " << minusValue << endl;
			break;
		case '*':
			cout << "곱하기" << endl;
			multiplyValue = myFunction6(num3, num4);
			cout << num3 << " " << choice << " " << num4 << " = " << multiplyValue << endl;
			break;
		case '/':
			cout << "나누기" << endl;
			divisionValue = myFunction7(num3, num4);
			cout << num3 << " " << choice << " " << num4 << " = " << divisionValue << endl;
			break;
		default:
			break;
		}
		system("pause");
	}
}