#include <iostream>

using namespace std;

// c++���� ��ȣ�ϴ� enum�� �̰�
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
	// => C++�� �����鼭 ���Ӱ� ���� ����

	printf("%d\n", RockScissorPaper::Rock);
	printf("%d\n", RockScissorPaper::Scissor);
	printf("%d\n", RockScissorPaper::Paper);

	// 2. enum�� ���ο� ���
	printf("%d\n", RSP_ROCK);
	printf("%d\n", RSP_SCISSOR);
	printf("%d\n", RSP_PAPER);

	// ��Ʈ ����
	int a = 10; // 1010
	int b = 3;	// 0011
	// & ����	// 0010
	// | ����	// 1011 = > 8 + 2 + 1 = 11

	printf("%d\n", a & b);
	printf("%d\n", a | b);
}