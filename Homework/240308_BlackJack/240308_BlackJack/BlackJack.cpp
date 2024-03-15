#include "BlackJack.h"
#include <iostream>
#include <Windows.h>

using namespace std;

BlackJack::BlackJack()
{
	srand(time(NULL));
	Card deck[52] = {};

	GenerateCard(deck);
	SuffleDeck(deck);
	
	if (IsContinue())
	{
		Betting();

		_myIndex = 0;

		for (int i = 0; i < 2; i++)
		{
			GiveCard(deck, _myCard[i], _myIndex);
		}

		_dealerIndex = 0;
		for (int i = 0; i < 2; i++)
		{
			GiveCard(deck, _dealerCard[i], _dealerIndex);
		}

		showMyCard(_myCard, _myIndex);

	}
}

BlackJack::~BlackJack()
{
	printf("게임 종료\n");
}

void Card::Print()
{
	int cardShpae = this->Index / 13;
	int cardNumber = this->Index % 13 + 1;
	switch (cardShpae)
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
		printf("오류 발생");
		break;
	}

	switch (cardNumber)
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
		printf("%d", cardNumber);
		break;
	}
}

void Card::Swap(Card& another)
{
	int temp = this->Index;
	this->Index = another.Index;
	another.Index = temp;
}

void BlackJack::GenerateCard(Card* deck)
{
	for (int i = 0; i < 52; i++)
	{
		deck[i].Index = i;
	}
}

void BlackJack::SuffleDeck(Card* deck)
{
	for (int i = 0; i < 100000; i++)
	{
		int src = rand() % 52;
		int dst = rand() % 52;

		deck[src].Swap(deck[dst]);
	}

	_deckIndex = 0;
}

bool BlackJack::IsContinue()
{
	if (_playerMoney <= 0)
	{
		return false;
	}
	return true;
}

void BlackJack::Betting()
{
	cout << "베팅할 금액을 입력하세요 :";
	cin >> _betMoney;

	while (_betMoney < 0 || _playerMoney < _betMoney)
	{
		cout << "베팅 금액을 잘못 입력했습니다. 소지 금액 내에서 다시 입력해주세요" << endl;
		cout << "베팅할 금액을 입력하세요 :";
		cin >> _betMoney;
	}
}

void BlackJack::GiveCard(Card* deck, Card& card, int& index)
{
	card.Index = deck[_deckIndex].Index;
	_deckIndex++;
	index++;
}

void BlackJack::showMyCard(Card* myCard, int myIndex)
{
	printf("내 카드 출력\n");
	for (int i = 0; i < myIndex; i++)
	{
		printf("%d번째 카드 : ", myIndex);
		myCard[i].Print();
		printf("\n");
	}
}

void BlackJack::showDealerCard(Card* dealerCard, int dealerIndex)
{
	printf("딜러 카드 출력\n");
	for (int i = 0; i < dealerIndex; i++)
	{
		printf("%d번째 카드 : ", dealerIndex);
		dealerCard[i].Print();
		printf("\n");
	}
}