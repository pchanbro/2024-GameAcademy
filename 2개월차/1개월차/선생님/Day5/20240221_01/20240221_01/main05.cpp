#include <iostream>

using namespace std;

void main()
{
	// 연산자
	// 사칙연산에 쓰이는 것은 아닙니다.

	// != == > < + - / * % 
	int a = 0;
	::printf("a : %d\n", a++);	// 0
	::printf("a : %d\n", a);	// 1
	::printf("a : %d\n", ++a);	// 2
	/*::printf("a : %d\n", a);
	::printf("a : %d\n", a += 3);
	::printf("a : %d\n", a);*/

	// a++
	// a를 1 증가시킨다.
	a = a + 1;

	// ++a
	// a를 1 증가시킨다.
	a = a + 1;

	// a--
	// --a

	// a += 3
	// a를 3증가시킨다
	a = a + 3;

	// += -= *= %= /=
	
	// a += 3 
	// a = a + 3
	
	// a -= 3
	// a = a - 3
	
	// a *= 3
	// a = a * 3

	// a /= 3
	// a = a / 3
	
	// a %= 3
	// a = a % 3
}