#include <iostream>

using namespace std;

int Add(int num1, int num2);

int Substract(int num1, int num2);

int Multiply(int num1, int num2);

float Divide(float num1, float num2);

void main()
{
	// 함수
	// 그냥 이렇게 쓰면 된다.
	// 함수의 형태
	// 반환자료형 함수명		(매개변수들) {}
	// void		 printHand	(int hand)  {}

	// 함수명으로 이름을 짓고, 매개변수로 함수의 옵션을 줄 수 있다.

	// 반환 자료형은 대체 무엇인가?
	// int bool 등등 return하는거



	// 함수 이어만들기

	// 계산기에 쓰이는 함수를 제작
	// Add
	// int Add(int num1, int num2);
	// 정수형을 반환하는 Add라는 함수
	// 여기에는 num1과 num2가 들어간다.
	// 기능 : num1과 num2를 더한값을 반환한다.

	// Substract
	// int Add(int num1, int num2);
	// 정수형을 반환하는 Subtract 함수
	// 여기에는 num1과 num2가 들어간다.
	// 기능 : num1값에 num2값을 뺀다.

	// Multiply

	// Divide

	int addResult = Add(2, 3);
	printf("더하기 결과 값 : %d\n", addResult);
	
	int substractResult = Substract(2, 3);
	printf("더하기 결과 값 : %d\n", substractResult);

	int multiplyResult = Multiply(2, 3);
	printf("더하기 결과 값 : %d\n", multiplyResult);

	float divideResult = Divide(2, 3);
	printf("더하기 결과 값 : %.2f\n", divideResult);
}

int Add(int num1, int num2)
{
	return num1 + num2;
}

int Substract(int num1, int num2)
{
	return num1 - num2;
}

int Multiply(int num1, int num2)
{
	return num1 * num2;
}

float Divide(float num1, float num2)
{
	return num1 / num2;
}