#include <iostream>
#include <Windows.h>

using namespace std;

enum class RockScissorPaper
{
	Rock,
	Scissor,
	Paper,

	End
};

enum 
{
	RSP_ROCK,
	RSP_SCISSOR,
	RSP_PAPER,

	RSP_END
};

enum
{
	RSP_COUNT = static_cast<int>(RockScissorPaper::End)
};


void main()
{
	//1. enum class
	// => C++ 에 들어오면서 새롭게 생긴 문법

	printf("%d\n", RockScissorPaper::Rock);
	printf("%d\n", RockScissorPaper::Scissor);
	printf("%d\n", RockScissorPaper::Paper);

	//2. enum의 새로운 비밀
	printf("%d\n", RSP_ROCK);
	printf("%d\n", RSP_SCISSOR);
	printf("%d\n", RSP_PAPER);


	//비트연산
	int a = 10;	//1010
	int b = 3;	//0011
	// & 연산	//0010
	// | 연산	//1011 => 8 + 2 + 1 ==> 11


	printf("%d", a | b);
	int bb = 0;
	while (true)
	{
		bb = ::GetKeyState(VK_LEFT);
		if (0 < bb)
		{
			printf("누른느중 [%d]\n", bb);
		}
	}
}
