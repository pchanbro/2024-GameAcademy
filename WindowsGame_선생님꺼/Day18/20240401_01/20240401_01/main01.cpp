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
	// => C++ �� �����鼭 ���Ӱ� ���� ����

	printf("%d\n", RockScissorPaper::Rock);
	printf("%d\n", RockScissorPaper::Scissor);
	printf("%d\n", RockScissorPaper::Paper);

	//2. enum�� ���ο� ���
	printf("%d\n", RSP_ROCK);
	printf("%d\n", RSP_SCISSOR);
	printf("%d\n", RSP_PAPER);


	//��Ʈ����
	int a = 10;	//1010
	int b = 3;	//0011
	// & ����	//0010
	// | ����	//1011 => 8 + 2 + 1 ==> 11


	printf("%d", a | b);
	int bb = 0;
	while (true)
	{
		bb = ::GetKeyState(VK_LEFT);
		if (0 < bb)
		{
			printf("�������� [%d]\n", bb);
		}
	}
}
