#include <iostream>

using namespace std;

void main()
{
	// 사칙연산
	// 초등학교때 배운 그거 맞다.

	// 곱하기 빼기 더하기 나누기

	// 정수의 사칙연산에는 나누기가 특별하며
	// 나머지값을 구하는 것 까지 존재한다.


	// 잠깐 팁 -----------------------------------------------------------------------------------------------------------------

	// 변수명 규칙 - 수업이 끝날 때 까지 지켜야 한다(무조건 암기) (대부분의 회사에서 비슷하게 사용, 약간의 차이가 있을 수 있다)
	// 1. 영어로 시작한다.
	// 
	// 2. 한글은 사용하지 않는다.
	// 2-1. 한글을 사용하지 않는 이유 : 한글 파일의 경우 깨져버릴 수 있기 때문에 프로젝트에 엄청난 영향을 준다.
	// 
	// 3. 소문자로 시작한다.
	// 3-1. 카멜케이스 같은 다른 경우에 대문자를 쓰던가 한다. 일단 여기서는 소문자로 시작함을 알아두자.
	// 
	// 4. 단어 두개를 조합할 일이 있다면 (스페이스 쓸일이 있으면) 대문자로 구분한다.

	int myNumber = 10; // 이런식으로
	
	// -------------------------------------------------------------------------------------------------------------------------

	int num1 = 10;
	int num2 = 4;
	//사칙연산

	int resultSum = num1 + num2;
	int resultSubtract = num1 - num2;
	int resultMultiply = num1 * num2;
	int resultDivide = num1 / num2; // 몫
	int resultRemain = num1 % num2; // 나머지 

	::printf("num1 + num2 = %d\n", resultSum);
	::printf("num1 - num2 = %d\n", resultSubtract);
	::printf("num1 * num2 = %d\n", resultMultiply);
	::printf("num1 / num2 = %d\n", resultDivide);
	::printf("num1 %% num2 = %d\n", resultRemain);



}