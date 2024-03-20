#include <iostream>

using namespace std;
int Add(int num1, int num2)
{
	printf("%d + %d 를 진행합니다.\n", num1, num2);

	int result = num1 + num2;
	return result;
}
int Subtract(int num1, int num2)
{
	return num1 - num2;
}
int Multiply(int num1, int num2)
{
	return num1 * num2;
}
int Devide(int num1, int num2)
{
	return num1 / num2;
}
void main()
{
	//함수 이어서

	//함수 
	// 그냥 이렇게 쓰면된다.
	// 형태가 이렇다.
	//함수의 형태
	//반환자료형 함수명		(매게변수들) {}
	//void		PrintHand	(int hand)  {}

	
	//함수명으로 이름을 짓고, 매게변수로 함수의 옵션을 줄수있다.

	//반환 자료형은 대체 무엇인가?


	//함수를 만들거에요.
	//계산기에 쓰이는 함수를 제작
	//Add
	// int Add(int num1, int num2);
	// 정수형을 반환하는 Add라는 함수
	// 여기에는 num1과 num2가 들어간다
	// 기능 : num1과 num2를 더한값을 반환한다.

	//함수는 동사로 시작하는게 좋습니다. 
	// (코드리뷰할때는 안되어있으면 항상 문제가 되어요)

	
	//Subtract
	//Multiply
	//Divide
	int addResult = Add(2, 3);
	printf("더하기 결과 값 : %d\n", addResult);

	//rand()
	// int rand();
	// 정수형을 반환하는 rand라는 함수
	// 여기에는 아무런 매게변수도 안들어간다.
	// 기능 : 랜덤수를 반환한다.
}