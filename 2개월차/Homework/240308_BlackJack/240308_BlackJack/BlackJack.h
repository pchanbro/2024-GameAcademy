#pragma once

struct Card
{
	int Index;

	void Print();
	void Swap(Card& another);

};

class BlackJack
{
private:
	int _playerMoney = 1000;
	int _betMoney = 0;
	int _deckIndex = 0;
	Card _myCard[10] = {};
	Card _dealerCard[10] = {};
	int _myIndex = 0;
	int _dealerIndex = 0;
	int _myCardSum = 0;
	int _delearCardSum = 0;
public:
	// 함수는 웬만하면 매개변수를 포인터를 받으려고 하지 마라
	// 그건 C스타일이기 때문
	// 앞으로는 vector로 받아주려고 하자
	// 그니까 이제부터는 vector를 사용해라
	BlackJack();
	~BlackJack();
	void GenerateCard(Card* deck);
	void SuffleDeck(Card* deck);
	bool IsContinue();
	void Betting();
	void GiveCard(Card* deck, Card* card, int& index);
	void showMyCardNumber(Card* myCard, int myIndex);
	void showDealerCardNumber(Card* dealerCard, int dealerIndex);
	void DoGetMoreCard(Card* deck);
	void dealerGetCard(Card* deck);
	void showResult();
	void isDeckAllUsed(Card* deck);
};

