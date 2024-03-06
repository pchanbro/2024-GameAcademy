#include <iostream>

using namespace std;

struct Card
{
	int Index;

	void Print();
	void Swap(Card& another);
};

Card _card[52] = {};

void main()
{
	// 카드게임
	// ♤A ~ ♧K 를 활용해서 여러가지 카드게임을 만든다.

	// 카드가 총 52장입니다.
	srand(time(NULL));

	for (int i = 0; i < 52; i++)
	{
		_card[i].Index = i;
	}

	
	for (int i = 0; i < 52; i++)
	{
		_card[i].Print();
		printf("\n");
	}

	
	// 카드 뭉치
	// 섞기
	for (int i = 0; i < 100000; i++)
	{
		int src = rand() % 52;
		int dst = rand() % 52;

		_card[src].Swap(_card[dst]);
	}

	for (int i = 0; i < 52; i++)
	{
		_card[i].Print();
		printf("\n");
	}

	
}

void Card::Print() 
{
	// 52장
	// Index의 값이
	//  0 ~ 12 스페이스 A ~ 스페이스 K 까지	(13으로 나누었을때 0)
	// 13 ~ 25 다이아 A  ~  다이아 K 까지		(13으로 나누었을때 1)
	// 26 ~ 38 하트 A   ~   하트 K 까지		(13으로 나누었을때 2)
	// 39 ~ 51 클로버 A  ~  클로버 K 까지		(13으로 나누었을때 3)

	// 문양 출력
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

	// 숫자( A ~ K)
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
	int temp = this->Index;
	this->Index = another.Index;
	another.Index = temp;
}