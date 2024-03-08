// 여기에서 같은 이름의 헤더파일
// Card.h 에서 정의한 함수의 내용을 만들 것이다.
// 아무리 main에서 다른 파일을 include 해도 
// 새로운 cpp 파일에 오면 초기화 상태가 된다.
// 그래서 여기서도 Card.h를 선언 해줘야 한다.
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
		printf("◇");
		break;
	case 2:
		printf("♡");
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
	// this는 자기 자신을 가리키는 포인터다.
	int temp = this->Index;
	this->Index = another.Index;
	another.Index = temp;
}