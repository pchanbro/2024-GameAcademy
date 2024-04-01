#include <iostream>

using namespace std;

// c++에서 선호하는 enum은 이것
enum class RockScissorPaper
{
	Rock,
	Scissor,
	Paper,

	END
};

enum
{
	RSP_ROCK,
	RSP_SCISSOR,
	RSP_PAPER,

	END
};

enum
{
	RSP_COUNT = static_cast<int>(RockScissorPaper::END)
};

void main()
{
	// 1. enum class 
	// => C++에 들어오면서 새롭게 생긴 문법

	printf("%d\n", RockScissorPaper::Rock);
	printf("%d\n", RockScissorPaper::Scissor);
	printf("%d\n", RockScissorPaper::Paper);

	// 2. enum의 새로운 비밀
	printf("%d\n", RSP_ROCK);
	printf("%d\n", RSP_SCISSOR);
	printf("%d\n", RSP_PAPER);

	// 비트 연산
	int a = 10; // 1010
	int b = 3;	// 0011
	// & 연산	// 0010
	// | 연산	// 1011 = > 8 + 2 + 1 = 11

	printf("%d\n", a & b);
	printf("%d\n", a | b);
}