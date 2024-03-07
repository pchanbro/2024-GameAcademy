#include <iostream>
#include <Windows.h>

using namespace std;

struct Card
{
	int Index;

	void Print();
	void Swap(Card& another);
};

struct Player
{
	int Money = 1000;
	int HighLowSevenChoice = 0;
};

Card _card[52] = {};
Player _player;
int _cardNum = 4;

void GenerateCard(Card* card);
void SuffleCard(Card* card);
void PrintCardState(Card* card, Player player, int cardNum);
bool IsBet();
int Betting(Player& player);
void PrintBetResult(int betMoney, Player& player, Card card);
bool IsContinue(Player player, int cardNum);

void main()
{
	srand(time(NULL));

	// 숙제 

	// 1. 카드 생성
	GenerateCard(_card);
	// 2. 카드 셔플
	// 게임할때마다 카드를 섞는게 아니라
	// 게임시작할때 한 번만 섞는다.
	SuffleCard(_card);

	// 반복
	// 10. 52장을 다쓰거나, 플레이어가 0원이 되면 게임 종료
	// 11. 다음판 진행
	// 12. 52장을 다 쓸 수 있다.
	while (IsContinue(_player, _cardNum))
	{
		system("cls");

		// 3. 현황판(카드 5개와 현재 금액) 출력
		// ♤A ♤K ♤3 ♤2 XX
		// 플레이어 현재 금액 : 1000
		PrintCardState(_card, _player, _cardNum);

		// 4. 베팅 유무 선택
		if (IsBet())
		{
			// 5. 베팅시 - 하이, 로우, 세븐 중에서 선택
			// 6. 하이 선택 시 XX의 값이 7 초과이면 포인트 획득 (베팅한 금액의 2배)
			// 7. 로우 선택 시 XX의 값이 7 미만이면 포인트 획득 (베팅한 금액의 2배)
			// 8. 세븐 선택 시 XX의 값이 7이면 포인트 획든 (베팅한 금액의 11배)
			PrintBetResult(Betting(_player), _player, _card[_cardNum]);
		}
		else
		{
			printf("베팅하지 않았습니다. 다음판 진행합니다\n");
		}
		
		// 9. 한 판을 하면 전광판이 한장씩 밀린다.
		_cardNum++;

		system("pause");
	}
	printf("게임 종료\n");
}

void Card::Print()
{
	switch (this->Index / 13)
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

	switch (this->Index % 13 +1)
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
		printf("%d", this->Index % 13 + 1);
		break;
	}
}

void Card::Swap(Card& another)
{
	int temp = this->Index;
	this->Index = another.Index;
	another.Index = temp;
}

void GenerateCard(Card* card)
{
	for (int i = 0; i < 52; i++)
	{
		card[i].Index = i;
	}
}

void SuffleCard(Card* card)
{
	for (int i = 0; i < 100000; i++)
	{
		int src = rand() % 52;
		int dst = rand() % 52;

		card[src].Swap(card[dst]);
	}
}

void PrintCardState(Card* card, Player player, int cardNum)
{
	for (int i = cardNum - 4; i < cardNum; i++)
	{
		card[i].Print();
		printf("\t");
	}

	printf("XX\n");

	printf("플레이어 현재 금액 : %d\n", player.Money);
}

bool IsBet() 
{
	int bet = 0;
	printf("베팅 하시겠습니까?? ( 0 : YES , 1 : NO) : ");
	scanf_s("%d", &bet);

	switch (bet)
	{
	case 0:
		return true;
	case 1:
		return false;
	default:
		printf("잘못된 입력입니다. 다시 선택하세요!\n");
		return IsBet();
	}
}

int Betting(Player& player)
{
	int bettingMoney = 0;
	printf("베팅할 금액 : ");
	scanf_s("%d", &bettingMoney);

	while (_player.Money < bettingMoney)
	{
		printf("베팅 금액이 소지금을 초과하였습니다. 베팅할 금액을 다시 선택하세요\n");
		printf("베팅할 금액 : ");
		scanf_s("%d", &bettingMoney);
	}

	_player.Money -= bettingMoney;

	printf("하이 로우 세븐을 선택하세요 ( 0 : 하이, 1 : 로우, 7 : 세븐 ) : ");
	scanf_s("%d", &_player.HighLowSevenChoice);

	while (
		(_player.HighLowSevenChoice != 0) &&
		(_player.HighLowSevenChoice != 1) &&
		(_player.HighLowSevenChoice != 7))
	{
		printf("잘못된 선택입니다. 하이로우세븐을 다시 선택하세요.\n");
		printf("하이 로우 세븐을 선택하세요 ( 0 : 하이, 1 : 로우, 7 : 세븐 ) : ");
		scanf_s("%d", &_player.HighLowSevenChoice);
	}

	return bettingMoney;
}

void PrintBetResult(int betMoney, Player& player, Card card)
{
	printf("카드 오픈 : ");
	card.Print();

	printf("\n나의 선택 : ");
	switch (player.HighLowSevenChoice)
	{
	case 0:
		printf("하이\n");
		if ((card.Index % 13 + 1) <= 7)
		{
			printf("YOU LOSE...\n");
		}
		else if (7 < (card.Index % 13 + 1))
		{
			printf("하이를 맞추셨습니다!!\n");
			player.Money += betMoney * 2;
		}
		break;
	case 1:
		printf("로우\n");
		if ((card.Index % 13 + 1) < 7)
		{
			printf("로우를 맞추셨습니다!!\n");
			player.Money += betMoney * 2;
		}
		else if (7 <= (card.Index % 13 + 1))
		{
			printf("YOU LOSE...\n");
		}
		break;
	case 7:
		printf("세븐\n");
		if ((card.Index % 13 + 1) == 7)
		{
			printf("세븐을 맞추셨습니다!!\n");
			player.Money += betMoney * 11;
		}
		else
		{
			printf("YOU LOSE...\n");
		}
		break;
	default:
		printf("오류 발생");
		break;
	}
}

bool IsContinue(Player player, int cardNum)
{
	if (player.Money < 0 || 52 < cardNum + 1)
	{
		return false;
	}

	return true;
}
