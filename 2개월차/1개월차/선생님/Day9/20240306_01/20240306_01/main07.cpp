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
	// ♤A ~ ♧K 를 활용해서 여러가지 카드게임을 만들거에요.

	// 카드가 총 52장입니다.


	srand(time(NULL));

	for (int i = 0; i < 52; i++)
	{
		_card[i].Index = i;
	}
	// 52장
	// Index의 값이
	// 0 ~ 12 스페이스 A ~ 스페이스 K 까지 
	// 13 ~ 25 다이아 A ~ 다이아 K 까지
	// 26 ~ 38 하트 A ~ 하트 K 까지
	// 39 ~ 51 클로버 A ~ 클로버 K 까지
	//for (int i = 0; i < 52; i++)
	//{
	//	_card[i].Print();
	//	printf("\n");
	//}


	//카드 뭉치
	//섞기
	for (int i = 0; i < 10000; i++)
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


	// 숙제 
	// 섞은 카드를 5장을 뽑는데
	// 4장은 위에 오픈
	// 1장은 XX로 표현

	// 전광판
	// ♤A ♤K ♤3 ♤2 XX
	// 플레이어 현재 금액 : 1000
	
	// 1. 베팅 유무 선택 (금액포함)
	// 2. 베팅시 - 하이, 로우, 세븐 중에서 선택
	// 3. 하이를 고를시
	// 4. XX의 값이 7이상이면 포인트획득 (건돈의 2배) (700원 걸었으면 1700)
	// 5. 로우를 고를시
	// 6. XX의 값이 7이하면 포인트 획득 (건돈의 2배) (700원 걸었으면 1700)
	// 7. 세븐을 고를시
	// 8. XX의 값이 7이면 포인트 획득 (건돈의 10배) (700원 걸었으면 7700)
	// 9. 한판을 하면 전광판이 한장씩 밀림
	// 10. ♤K ♤3 ♤2 ♤7 XX
	// 11. 다음판 진행.
	// 12. 52장을 다쓸수있겠죠??
	// 13. 52장을 다쓰거나, 플레이어가 0원이 되면 게임종료

	// 게임할때마다 카드를 섞는것이아니라
	// 게임시작할때 한번만 섞음.!!
}

void Card::Print()
{
	// Index의 값이
	// 0 ~ 12 스페이스 A ~ 스페이스 K 까지  (13으로 나누었을때 0)
	// 13 ~ 25 다이아 A ~ 다이아 K 까지	  (13으로 나누었을때 1)
	// 26 ~ 38 하트 A ~ 하트 K 까지        (13으로 나누었을때 2)
	// 39 ~ 51 클로버 A ~ 클로버 K 까지     (13으로 나누었을때 3)

	//문양 출력
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
	}

	//숫자 (A ~ k)
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