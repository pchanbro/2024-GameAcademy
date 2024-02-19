#include <iostream>

using namespace std;

void main()
{
	// 사칙연산
	// 초등학교때 배웠던 그거 맞습니다.

	// 곱하기 빼기 더하기 나누기

	// 정수의 사칙연산은 살짝 특별한게 있습니다.
	// 나누기가 조금 특별하고
	// 곱하기 빼기 더하기 나누기 + 나머짓값

	//-------------------------------------------------------------------------------------------------
	// 
	//변수명 규칙 (무조건 암기) (대부분의 회사에서 저처럼쓰거나 조금 달라집니다)
	// 영어로 시작합니다.
	// 한글은 사용하지 않습니다.
	// 소문자로 시작합니다.
	// 단어 두개를 조합할 일이 생기면 (스페이스 쓸일이 생기면) 대문자로 구분합니다.
	// 전문용어로는 카멜케이스
	int myNumber = 0; // my number ==> myNumber

	//한글은 왜 사용하지 않는가?
	// => 
	int 변수1 = 10;


	//소문자로 시작하는 이유
	int MyNumber = 0;
	//=> 이렇게 적어도 이쁜데요?
	// 사실 대문자로 시작하는 경우도있고
	// 모두 소문자로 적는경우도있고

	//이런 변수 규칙을 부르는 명명도 있습니다.
	//각자 쓸일이 있어요.
	// MyNumber 요런규칙도 저희 수업중에 이런경우에는 이런걸로 쓴다.

	//int my_number;
	//int MY_NUMBER;
	//int MyNumber;
	//int myNumber;
	//int MYNUMBER;
	//
	//-----------------------------------------------------------------------------------------------------


	int num1 = 10;
	int num2 = 3;
	//사칙연산

	int resultSum = num1 + num2;
	int resultSubtract = num1 - num2;
	int resultMultiply = num1 * num2;
	int resultDivide = num1 / num2; //나누었을때 몫
	int resultRemain = num1 % num2;	//나누었을때 나머지

	::printf("num1 + num2 = %d\n", resultSum);
	::printf("num1 - num2 = %d\n", resultSubtract);
	::printf("num1 * num2 = %d\n", resultMultiply);
	::printf("num1 / num2 = %d\n", resultDivide);
	::printf("num1 %% num2 = %d\n", resultRemain);
}