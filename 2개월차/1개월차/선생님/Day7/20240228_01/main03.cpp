#include <iostream>
using namespace std;

enum eRockScissorPaper
{
	RSP_ROCK,
	RSP_SCISSOR,
	RSP_PAPER,

	RSP_END
};

//매게변수, 아규먼트, 파라메터
void PrintHand(int hand);

void main()
{
	//함수!!
	// - 재사용성
	// 손을 출력해주는 함수
	::PrintHand(0);
}

void PrintHand(int hand)
{
	switch (hand)
	{
	case RSP_ROCK:
		printf("▶바위◀\t");
		break;
	case RSP_SCISSOR:
		printf("가위\t");
		break;
	case RSP_PAPER:
		printf("보\t");
		break;
	default:
		printf("UnKnown\t");
		break;
	}
}