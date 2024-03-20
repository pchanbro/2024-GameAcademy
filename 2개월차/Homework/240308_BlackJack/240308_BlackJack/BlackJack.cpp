#include "BlackJack.h"
#include <iostream>
#include <Windows.h>

using namespace std;

BlackJack::BlackJack()
{
	srand(time(NULL));
	Card deck[52] = {}; // 헤더파일의 private로 옮겨라

	GenerateCard(deck);
	SuffleDeck(deck);
	
	while (IsContinue())
	{
		system("cls");

		isDeckAllUsed(deck);// 이름이 애매하다 
		// 내용은 셔플인데 이름은 덱이 다 사용되었나 
		// 이다 차라리 길게 쓰자

		Betting(); // 이건 명사잖아 함수 이름은 동사로

		_myIndex = 0;
		_myCardSum = 0;
		for (int i = 0; i < 2; i++)
		{
			GiveCard(deck, _myCard, _myIndex);
		}

		_dealerIndex = 0;
		_delearCardSum = 0;
		for (int i = 0; i < 2; i++)
		{
			GiveCard(deck, _dealerCard, _dealerIndex);
		}

		showMyCardNumber(_myCard, _myIndex);

		DoGetMoreCard(deck);

		dealerGetCard(deck);

		showResult();

		system("pause");

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
	cout << "현재 소지금 : " << _playerMoney << endl;
	cout << "베팅할 금액을 입력하세요 :";
	cin >> _betMoney;

	while (_betMoney < 0 || _playerMoney < _betMoney)
	{
		cout << "베팅 금액을 잘못 입력했습니다. 소지 금액 내에서 다시 입력해주세요" << endl;
		cout << "베팅할 금액을 입력하세요 :";
		cin >> _betMoney;
	}

	_playerMoney -= _betMoney;
}

void BlackJack::GiveCard(Card* deck, Card* card, int& index)
{
	isDeckAllUsed(deck);
	card[index].Index = deck[_deckIndex].Index;
	_deckIndex++;
	index++;
}

void BlackJack::showMyCardNumber(Card* myCard, int myIndex)
{
	_myCardSum = 0;
	int cardNumber = 0;
	for (int i = 0; i < myIndex; i++)
	{
		cardNumber = myCard[i].Index % 13 + 1;
		// 이 위에 이런거 차라리 private에 배열 하나 만들어서
		// 미리 해둬라 
		// for문 돌면서 계속 해줘야 하니까 
		// 밑에 for문 안에 이게 쓰이는 곳에서도 계속 이렇게
		// 쓰고있다. 그렇게 되면
		// 최적화가 안되어있는 것
		if (cardNumber == 1)
		{
			_myCardSum += 11;
		}
		else if (cardNumber <= 10)
		{
			_myCardSum += cardNumber;
		}
		else
		{
			_myCardSum += 10;
		}
	}

	printf("\n내 카드 출력\n");
	for (int i = 0; i < myIndex; i++)
	{
		cardNumber = myCard[i].Index % 13 + 1;
		if ((21 < _myCardSum) && (cardNumber == 1))
		{
			_myCardSum -= 10;
		}
		printf("%d번째 카드 : ", cardNumber);
		myCard[i].Print();
		printf("\n");
	}
	
	printf("카드 숫자 합 : %d\n", _myCardSum);
	if (21 < _myCardSum)
	{
		printf("21초과...\n");
	}
}

void BlackJack::showDealerCardNumber(Card* dealerCard, int dealerIndex)
{
	_delearCardSum = 0;
	int cardNumber = 0;
	for (int i = 0; i < dealerIndex; i++)
	{
		cardNumber = dealerCard[i].Index % 13 + 1;
		if (cardNumber == 1)
		{
			_delearCardSum += 11;
		}
		else if (cardNumber <= 10)
		{
			_delearCardSum += cardNumber;
		}
		else
		{
			_delearCardSum += 10;
		}
	}

	printf("\n딜러 카드 출력\n");
	for (int i = 0; i < dealerIndex; i++)
	{
		cardNumber = dealerCard[i].Index % 13 + 1;
		if ((21 < _delearCardSum) && (cardNumber == 1))
		{
			_delearCardSum -= 10;
		}
		printf("%d번째 카드 : ", cardNumber);
		dealerCard[i].Print();
		printf("\n");
	}

	printf("카드 숫자 합 : %d\n", _delearCardSum);
	if (21 < _delearCardSum)
	{
		printf("21초과...\n");
	}
}

void BlackJack::DoGetMoreCard(Card* deck)
{
	int choice = 0;
	while (_myCardSum <= 21)
	{
		printf("더 카드를 받으시겠습니까?? (0 : 받는다, 1: 그만한다) : ");
		cin >> choice;
		if (choice == 1)
		{
			break;
		}
		else
		{
			printf("플레이어가 카드를 1장 받았습니다.\n\n");
			GiveCard(deck, _myCard, _myIndex);
		}
		showMyCardNumber(_myCard, _myIndex);
	}
	printf("플레이어 턴 종료\n\n");		
}

void BlackJack::dealerGetCard(Card* deck)
{
	while (_delearCardSum < 21)
	{
		if (21 < _myCardSum)
		{
			break;
		}
		else if (_myCardSum < _delearCardSum)
		{
			break;
		}
		else
		{
			printf("딜러가 카드를 1장 받았습니다.\n\n");
			GiveCard(deck, _dealerCard, _dealerIndex);
		}

		showDealerCardNumber(_dealerCard, _dealerIndex);
	}
	printf("딜러 턴 종료\n\n");
}

void BlackJack::showResult()
{
	if (21 < _myCardSum)
	{
		cout << "이번 게임 결과 : 플레이어 패배...." << endl;
	}
	else if ((21 < _delearCardSum) || (_delearCardSum < _myCardSum))
	{
		cout << "이번 게임 결과 : 플레이어 승리!!!" << endl;
		_playerMoney += _betMoney * 2;
	}
	else if (_myCardSum < _delearCardSum)
	{
		cout << "이번 게임 결과 : 플레이어 패배...." << endl;
	}
	else
	{
		cout << "이번 게임 결과 : 무승부" << endl;
		_playerMoney += _betMoney;
	}
}

void BlackJack::isDeckAllUsed(Card* deck)
{
	if (51 < _deckIndex)
	{
		SuffleDeck(deck);
	}
}