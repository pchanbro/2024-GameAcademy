#include <iostream>
using namespace std;

enum eRockScissorPaper
{
	RSP_ROCK,
	RSP_SCISSOR,
	RSP_PAPER,

	RSP_END
};

//�ŰԺ���, �ƱԸ�Ʈ, �Ķ����
void PrintHand(int hand);

void main()
{
	//�Լ�!!
	// - ���뼺
	// ���� ������ִ� �Լ�
	::PrintHand(0);
}

void PrintHand(int hand)
{
	switch (hand)
	{
	case RSP_ROCK:
		printf("��������\t");
		break;
	case RSP_SCISSOR:
		printf("����\t");
		break;
	case RSP_PAPER:
		printf("��\t");
		break;
	default:
		printf("UnKnown\t");
		break;
	}
}