//아무리 main에서 다른 파일을 include해도
//새로운 cpp파일에 오면 초기화 상태가 된다.
#include "Card.h"
#include <iostream>


void Card::Print()
{
	switch (Index / 13)
	{
	case 0:
		printf("♤");
		break;
	case 1:
		printf("◆");
		break;
	case 2:
		printf("♥");
		break;
	case 3:
		printf("♧");
		break;
	default:
		break;
	}

	switch (Index % 13 + 1)
	{
	case 1:
		printf("A");
		break;
	case 11:
		printf("J");
		break;
	case 12:
		printf("Q");
		break;
	case 13:
		printf("K");
		break;
	default:
		printf("%d", Index % 13 + 1);
		break;
	}
}

void Card::Swap(Card& another)
{
	//this는 자기자신을 가르키는 포인터
	int temp = this->Index;
	this->Index = another.Index;
	another.Index = temp;
}