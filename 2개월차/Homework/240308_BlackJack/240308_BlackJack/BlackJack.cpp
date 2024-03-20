#include "BlackJack.h"
#include <iostream>
#include <Windows.h>

using namespace std;

BlackJack::BlackJack()
{
	srand(time(NULL));
	Card deck[52] = {}; // ��������� private�� �Űܶ�

	GenerateCard(deck);
	SuffleDeck(deck);
	
	while (IsContinue())
	{
		system("cls");

		isDeckAllUsed(deck);// �̸��� �ָ��ϴ� 
		// ������ �����ε� �̸��� ���� �� ���Ǿ��� 
		// �̴� ���� ��� ����

		Betting(); // �̰� ����ݾ� �Լ� �̸��� �����

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
	printf("���� ����\n");
}

void Card::Print()
{
	int cardShpae = this->Index / 13;
	int cardNumber = this->Index % 13 + 1;
	switch (cardShpae)
	{
	case 0:
		printf("��");
		break;
	case 1:
		printf("��");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("��");
		break;
	default:
		printf("���� �߻�");
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
	cout << "���� ������ : " << _playerMoney << endl;
	cout << "������ �ݾ��� �Է��ϼ��� :";
	cin >> _betMoney;

	while (_betMoney < 0 || _playerMoney < _betMoney)
	{
		cout << "���� �ݾ��� �߸� �Է��߽��ϴ�. ���� �ݾ� ������ �ٽ� �Է����ּ���" << endl;
		cout << "������ �ݾ��� �Է��ϼ��� :";
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
		// �� ���� �̷��� ���� private�� �迭 �ϳ� ����
		// �̸� �صֶ� 
		// for�� ���鼭 ��� ����� �ϴϱ� 
		// �ؿ� for�� �ȿ� �̰� ���̴� �������� ��� �̷���
		// �����ִ�. �׷��� �Ǹ�
		// ����ȭ�� �ȵǾ��ִ� ��
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

	printf("\n�� ī�� ���\n");
	for (int i = 0; i < myIndex; i++)
	{
		cardNumber = myCard[i].Index % 13 + 1;
		if ((21 < _myCardSum) && (cardNumber == 1))
		{
			_myCardSum -= 10;
		}
		printf("%d��° ī�� : ", cardNumber);
		myCard[i].Print();
		printf("\n");
	}
	
	printf("ī�� ���� �� : %d\n", _myCardSum);
	if (21 < _myCardSum)
	{
		printf("21�ʰ�...\n");
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

	printf("\n���� ī�� ���\n");
	for (int i = 0; i < dealerIndex; i++)
	{
		cardNumber = dealerCard[i].Index % 13 + 1;
		if ((21 < _delearCardSum) && (cardNumber == 1))
		{
			_delearCardSum -= 10;
		}
		printf("%d��° ī�� : ", cardNumber);
		dealerCard[i].Print();
		printf("\n");
	}

	printf("ī�� ���� �� : %d\n", _delearCardSum);
	if (21 < _delearCardSum)
	{
		printf("21�ʰ�...\n");
	}
}

void BlackJack::DoGetMoreCard(Card* deck)
{
	int choice = 0;
	while (_myCardSum <= 21)
	{
		printf("�� ī�带 �����ðڽ��ϱ�?? (0 : �޴´�, 1: �׸��Ѵ�) : ");
		cin >> choice;
		if (choice == 1)
		{
			break;
		}
		else
		{
			printf("�÷��̾ ī�带 1�� �޾ҽ��ϴ�.\n\n");
			GiveCard(deck, _myCard, _myIndex);
		}
		showMyCardNumber(_myCard, _myIndex);
	}
	printf("�÷��̾� �� ����\n\n");		
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
			printf("������ ī�带 1�� �޾ҽ��ϴ�.\n\n");
			GiveCard(deck, _dealerCard, _dealerIndex);
		}

		showDealerCardNumber(_dealerCard, _dealerIndex);
	}
	printf("���� �� ����\n\n");
}

void BlackJack::showResult()
{
	if (21 < _myCardSum)
	{
		cout << "�̹� ���� ��� : �÷��̾� �й�...." << endl;
	}
	else if ((21 < _delearCardSum) || (_delearCardSum < _myCardSum))
	{
		cout << "�̹� ���� ��� : �÷��̾� �¸�!!!" << endl;
		_playerMoney += _betMoney * 2;
	}
	else if (_myCardSum < _delearCardSum)
	{
		cout << "�̹� ���� ��� : �÷��̾� �й�...." << endl;
	}
	else
	{
		cout << "�̹� ���� ��� : ���º�" << endl;
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