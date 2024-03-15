#include "SeodDa.h"
#include <iostream>
#include <Windows.h>

using namespace std;

SeodDa::SeodDa()
{
	srand(time(NULL));
	Card card[20] = {};

	GenerateCard(card);

	while (IsContinue())
	{
		system("cls");
		_cardIndex = 0;

		SuffleDeck(card);

		if (IsBet())
		{
			GiveCard(card, _myCard[0], _comCard[0], _cardIndex);
			PrintfMyFirstCard(_myCard[0]);

			_betMoney = HowMuchBet();
			_playerMoney -= _betMoney;

			GiveCard(card, _myCard[1], _comCard[1], _cardIndex);

			PrintRusult(_myCard, _comCard);
		}

		printf("라운드 종료\n");
		system("pause");
	}
}

SeodDa::~SeodDa()
{
	printf("게임 종료");
}

void Card::Print()
{
	switch (this->index / 10)
	{
	case 0:
		printf("열자리 ");
		break;
	case 1:
		printf("일반 ");
		break;
	default:
		printf("오류 발생");
		break;
	}

	printf("%d\n", (this->index % 10) + 1);
}

void Card::Swap(Card& another)
{
	int temp = this->index;
	this->index = another.index;
	another.index = temp;
}

void SeodDa::GenerateCard(Card* deck)
{
	for (int i = 0; i < 20; i++)
	{
		deck[i].index = i;
	}
}

void SeodDa::SuffleDeck(Card* deck)
{
	for (int i = 0; i < 100000; i++)
	{
		int src = rand() % 20;
		int dst = rand() % 20;

		deck[src].Swap(deck[dst]);
	}
}

bool SeodDa::IsContinue()
{
	if (_playerMoney <= 0)
	{
		return false;
	}
	return true;
}

bool SeodDa::IsBet()
{
	int betChoice = 0;
	printf("소지금 : %d\n", _playerMoney);
	printf("베팅 하시겠습니까?( 0 : 예, 1 : 아니오 ) :");
	cin >> betChoice;

	if (betChoice == 0)
	{
		return true;
	}
	else if (betChoice == 1)
	{
		return false;
	}
	else
	{
		printf("잘못된 선택입니다. 다시 선택하세요...\n");
		return IsBet();
	}
}

void SeodDa::GiveCard(Card* deck, Card& myCard, Card& comCard, int& index)
{
	myCard = deck[index];
	index++;
	comCard = deck[index];
	index++;
}

void SeodDa::PrintfMyFirstCard(Card _myCard)
{
	printf("내 첫 패 : ");
	_myCard.Print();
	printf("\n");
}

int SeodDa::HowMuchBet()
{
	int betMoney;
	printf("베팅 금액을 결정하세요 : ");
	cin >> betMoney;

	if (_playerMoney < betMoney)
	{
		printf("소지금을 초과한 금액입니다. 다시 선택하세요\n");
		betMoney = HowMuchBet();
	}
	else if (betMoney < 0)
	{
		printf("0원 미만을 베팅할 수 없습니다. 다시 선택하세요\n");
		betMoney = HowMuchBet();
	}

	return betMoney;
}

void SeodDa::PrintRusult(Card* myCard, Card* comCard)
{
	printf("내 패\n");
	for (int i = 0; i < 2; i++)
	{
		myCard[i].Print();
	}
	cout << endl;

	printf("컴퓨터 패\n");
	for (int i = 0; i < 2; i++)
	{
		comCard[i].Print();
	}
	cout << endl;

	if ( // 플레이어가 38 광땡
		(((myCard[0].index + 1) == 3) && ((myCard[1].index + 1) == 8)) ||
		(((myCard[0].index + 1) == 8) && ((myCard[1].index + 1) == 3))
		)
	{
		printf("플레이어 승리!!\n");
		_playerMoney += _betMoney * 2;
		return;
	}
	else if ( // 플레이어가 18광땡 혹은 13광땡
		(((myCard[0].index + 1) == 1) && ((myCard[1].index + 1) == 8)) ||
		(((myCard[0].index + 1) == 1) && ((myCard[1].index + 1) == 3)) ||
		(((myCard[0].index + 1) == 8) && ((myCard[1].index + 1) == 1)) ||
		(((myCard[0].index + 1) == 3) && ((myCard[1].index + 1) == 1))
		)
	{
		if (
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 3)) ||
			// 컴퓨터가 암행어사
			(((comCard[0].index + 1) == 4) && ((comCard[1].index + 1) == 7)) ||
			(((comCard[0].index + 1) == 7) && ((comCard[1].index + 1) == 4))
			)
		{
			printf("플레이어 패배...\n");
			return;
		}
		else
		{
			printf("플레이어의 승리!!");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // 플레이어 장땡
		(((myCard[0].index + 1) == 10) && ((myCard[1].index + 1) == 20)) ||
		(((myCard[0].index + 1) == 20) && ((myCard[1].index + 1) == 10))
		)
	{
		if (
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 1))
			)
		{
			printf("플레이어 패배...\n");
			return;
		}
		else
		{
			printf("플레이어 승리!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if (((myCard[0].index + 1) % 10) == ((myCard[1].index + 1) % 10)) // 플레이어 n땡
	{
		if (
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 10) && ((comCard[1].index + 1) == 20)) ||
			(((comCard[0].index + 1) == 20) && ((comCard[1].index + 1) == 10)) ||
			// 상대방이 땡잡이
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 7)) ||
			(((comCard[0].index + 1) == 7) && ((comCard[1].index + 1) == 3)) ||
			// 컴퓨터도 n땡인데 컴퓨터의 n값이 플레이어의 n값보다 큰 경우
			(((comCard[0].index % 10) == (comCard[1].index % 10)) &&
				((myCard[1].index % 10) < (comCard[1].index % 10)))
			)
		{
			printf("플레이어 패배...\n");
			return;
		}
		else
		{
			printf("플레이어 승리!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // 플레이어 알리
		(((myCard[0].index + 1) % 10 == 1) && ((myCard[1].index + 1) % 10 == 2)) ||
		(((myCard[0].index + 1) % 10 == 2) && ((myCard[1].index + 1) % 10 == 1))
		)
	{
		if (
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 10) && ((comCard[1].index + 1) == 20)) ||
			(((comCard[0].index + 1) == 20) && ((comCard[1].index + 1) == 10)) ||
			((comCard[0].index % 10) == (comCard[1].index % 10))
			)
		{
			printf("플레이어 패배...");
			return;
		}
		else
		{
			printf("플레이어 승리!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // 플레이어 독사
		(((myCard[0].index + 1) % 10 == 1) && ((myCard[1].index + 1) % 10 == 4)) ||
		(((myCard[0].index + 1) % 10 == 4) && ((myCard[1].index + 1) % 10 == 1))
		)
	{
		if (
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 10) && ((comCard[1].index + 1) == 20)) ||
			(((comCard[0].index + 1) == 20) && ((comCard[1].index + 1) == 10)) ||
			((comCard[0].index % 10) == (comCard[1].index % 10)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 2)) ||
			(((comCard[0].index + 1) % 10 == 2) && ((comCard[1].index + 1) % 10 == 1))
			)
		{
			printf("플레이어 패배...");
			return;
		}
		else
		{
			printf("플레이어 승리!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // 플레이어 구삥
		(((myCard[0].index + 1) % 10 == 1) && ((myCard[1].index + 1) % 10 == 9)) ||
		(((myCard[0].index + 1) % 10 == 9) && ((myCard[1].index + 1) % 10 == 1))
		)
	{
		if (
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 10) && ((comCard[1].index + 1) == 20)) ||
			(((comCard[0].index + 1) == 20) && ((comCard[1].index + 1) == 10)) ||
			((comCard[0].index % 10) == (comCard[1].index % 10)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 2)) ||
			(((comCard[0].index + 1) % 10 == 2) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 4)) ||
			(((comCard[0].index + 1) % 10 == 4) && ((comCard[1].index + 1) % 10 == 1))
			)
		{
			printf("플레이어 패배...");
			return;
		}
		else
		{
			printf("플레이어 승리!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // 플레이어 장삥
		(((myCard[0].index + 1) % 10 == 1) && ((myCard[1].index + 1) % 10 == 0)) ||
		(((myCard[0].index + 1) % 10 == 0) && ((myCard[1].index + 1) % 10 == 1))
		)
	{
		if (
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 10) && ((comCard[1].index + 1) == 20)) ||
			(((comCard[0].index + 1) == 20) && ((comCard[1].index + 1) == 10)) ||
			((comCard[0].index % 10) == (comCard[1].index % 10)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 2)) ||
			(((comCard[0].index + 1) % 10 == 2) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 4)) ||
			(((comCard[0].index + 1) % 10 == 4) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 9)) ||
			(((comCard[0].index + 1) % 10 == 9) && ((comCard[1].index + 1) % 10 == 1))
			)
		{
			printf("플레이어 패배...");
			return;
		}
		else
		{
			printf("플레이어 승리!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // 플레이어 장사
		(((myCard[0].index + 1) % 10 == 4) && ((myCard[1].index + 1) % 10 == 0)) ||
		(((myCard[0].index + 1) % 10 == 0) && ((myCard[1].index + 1) % 10 == 4))
		)
	{
		if (
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 10) && ((comCard[1].index + 1) == 20)) ||
			(((comCard[0].index + 1) == 20) && ((comCard[1].index + 1) == 10)) ||
			((comCard[0].index % 10) == (comCard[1].index % 10)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 2)) ||
			(((comCard[0].index + 1) % 10 == 2) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 4)) ||
			(((comCard[0].index + 1) % 10 == 4) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 9)) ||
			(((comCard[0].index + 1) % 10 == 9) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 0)) ||
			(((comCard[0].index + 1) % 10 == 0) && ((comCard[1].index + 1) % 10 == 1))
			)
		{
			printf("플레이어 패배...");
			return;
		}
		else
		{
			printf("플레이어 승리!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // 플레이어 세륙
		(((myCard[0].index + 1) % 10 == 4) && ((myCard[1].index + 1) % 10 == 6)) ||
		(((myCard[0].index + 1) % 10 == 6) && ((myCard[1].index + 1) % 10 == 4))
		)
	{
		if (
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 10) && ((comCard[1].index + 1) == 20)) ||
			(((comCard[0].index + 1) == 20) && ((comCard[1].index + 1) == 10)) ||
			((comCard[0].index % 10) == (comCard[1].index % 10)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 2)) ||
			(((comCard[0].index + 1) % 10 == 2) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 4)) ||
			(((comCard[0].index + 1) % 10 == 4) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 9)) ||
			(((comCard[0].index + 1) % 10 == 9) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 0)) ||
			(((comCard[0].index + 1) % 10 == 0) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 4) && ((comCard[1].index + 1) % 10 == 0)) ||
			(((comCard[0].index + 1) % 10 == 0) && ((comCard[1].index + 1) % 10 == 4))
			)
		{
			printf("플레이어 패배...");
			return;
		}
		else
		{
			printf("플레이어 승리!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // 플레이어 갑오(9끗)
		((myCard[0].index + 1) + (myCard[1].index + 1)) % 10 == 9
	)
	{
		if (
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 10) && ((comCard[1].index + 1) == 20)) ||
			(((comCard[0].index + 1) == 20) && ((comCard[1].index + 1) == 10)) ||
			((comCard[0].index % 10) == (comCard[1].index % 10)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 2)) ||
			(((comCard[0].index + 1) % 10 == 2) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 4)) ||
			(((comCard[0].index + 1) % 10 == 4) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 9)) ||
			(((comCard[0].index + 1) % 10 == 9) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 0)) ||
			(((comCard[0].index + 1) % 10 == 0) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 4) && ((comCard[1].index + 1) % 10 == 0)) ||
			(((comCard[0].index + 1) % 10 == 0) && ((comCard[1].index + 1) % 10 == 4)) ||
			(((comCard[0].index + 1) % 10 == 4) && ((comCard[1].index + 1) % 10 == 6)) ||
			(((comCard[0].index + 1) % 10 == 6) && ((comCard[1].index + 1) % 10 == 4))
			)
		{
			printf("플레이어 패배...");
			return;
		}
		else
		{
			printf("플레이어 승리!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // 내가 암행어사인 경우
		(((myCard[0].index + 1) == 4) && ((myCard[1].index + 1) == 7)) ||
		(((myCard[0].index + 1) == 7) && ((myCard[1].index + 1) == 4))
		)
	{
		if ( 
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 1))
			)
		{
			printf("플레이어 승리!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
		else
		{
			printf("플레이어 패배...");
			return;
		}
	}
	else if ( // 내가 땡잡이 경우
		(((myCard[0].index + 1) == 3) && ((myCard[1].index + 1) == 7)) ||
		(((myCard[0].index + 1) == 7) && ((myCard[1].index + 1) == 3))
		)
	{
		if ((comCard[0].index % 10) == (comCard[1].index % 10))
		{
			printf("플레이어 승리!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
		else
		{
			printf("플레이어 패배...");
			return;
		}
	}
	else if ( // 플레이어 0 ~ 8끗
		(((myCard[0].index + 1) + (myCard[1].index + 1)) % 10) < 9
	)
	{
		if (
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 1) && ((comCard[1].index + 1) == 3)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 1)) ||
			(((comCard[0].index + 1) == 10) && ((comCard[1].index + 1) == 20)) ||
			(((comCard[0].index + 1) == 20) && ((comCard[1].index + 1) == 10)) ||
			((comCard[0].index % 10) == (comCard[1].index % 10)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 2)) ||
			(((comCard[0].index + 1) % 10 == 2) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 4)) ||
			(((comCard[0].index + 1) % 10 == 4) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 9)) ||
			(((comCard[0].index + 1) % 10 == 9) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 1) && ((comCard[1].index + 1) % 10 == 0)) ||
			(((comCard[0].index + 1) % 10 == 0) && ((comCard[1].index + 1) % 10 == 1)) ||
			(((comCard[0].index + 1) % 10 == 4) && ((comCard[1].index + 1) % 10 == 0)) ||
			(((comCard[0].index + 1) % 10 == 0) && ((comCard[1].index + 1) % 10 == 4)) ||
			(((comCard[0].index + 1) % 10 == 4) && ((comCard[1].index + 1) % 10 == 6)) ||
			(((comCard[0].index + 1) % 10 == 6) && ((comCard[1].index + 1) % 10 == 4)) ||
			(((comCard[0].index + 1) + (comCard[1].index + 1)) % 10 == 9) ||
			// 내가 망통(0끗)인 경우
			(((myCard[0].index + 1) + (myCard[1].index + 1)) % 10 == 0) ||
			// 상대의 끗이 더 큰 경우
			(((myCard[0].index + 1) + (myCard[1].index + 1)) % 10) <
			(((comCard[0].index + 1) + (comCard[1].index + 1)) % 10)

			)
		{
			printf("플레이어 패배...");
			return;
		}
		else if ( // 컴퓨터와 끗이 같은 경우
			(((myCard[0].index + 1) + (myCard[1].index + 1)) % 10) ==
			(((comCard[0].index + 1) + (comCard[1].index + 1)) % 10)
			)
		{
			printf("비겼습니다. 돈을 다시 가져가세요.\n");
			_playerMoney += _betMoney;
			return;
		}
		else
		{
			printf("플레이어 승리!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}	
}
