#pragma once

struct Card
{
	int index;

	void Print();
	void Swap(Card& another);
};

class SeodDa
{
private:
	int _playerMoney = 1000;
	Card _myCard[2] = {};
	Card _comCard[2] = {};
	int _cardIndex = 0;
	int _betMoney = 0;
public:
	SeodDa();
	~SeodDa();
	void GenerateCard(Card* deck);
	void SuffleDeck(Card* deck);
	bool IsContinue();
	bool IsBet();
	void GiveCard(Card* deck, Card& myCard, Card& comCard, int& index);
	void PrintfMyFirstCard(Card _myCard);
	int HowMuchBet();
	void PrintRusult(Card* myCard, Card* comCard);
};
