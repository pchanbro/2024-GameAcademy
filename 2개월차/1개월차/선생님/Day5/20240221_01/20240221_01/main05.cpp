#include <iostream>

using namespace std;

void main()
{
	// ������
	// ��Ģ���꿡 ���̴� ���� �ƴմϴ�.

	// != == > < + - / * % 
	int a = 0;
	::printf("a : %d\n", a++);	// 0
	::printf("a : %d\n", a);	// 1
	::printf("a : %d\n", ++a);	// 2
	/*::printf("a : %d\n", a);
	::printf("a : %d\n", a += 3);
	::printf("a : %d\n", a);*/

	// a++
	// a�� 1 ������Ų��.
	a = a + 1;

	// ++a
	// a�� 1 ������Ų��.
	a = a + 1;

	// a--
	// --a

	// a += 3
	// a�� 3������Ų��
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