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

		printf("���� ����\n");
		system("pause");
	}
}

SeodDa::~SeodDa()
{
	printf("���� ����");
}

void Card::Print()
{
	switch (this->index / 10)
	{
	case 0:
		printf("���ڸ� ");
		break;
	case 1:
		printf("�Ϲ� ");
		break;
	default:
		printf("���� �߻�");
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
	printf("������ : %d\n", _playerMoney);
	printf("���� �Ͻðڽ��ϱ�?( 0 : ��, 1 : �ƴϿ� ) :");
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
		printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���...\n");
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
	printf("�� ù �� : ");
	_myCard.Print();
	printf("\n");
}

int SeodDa::HowMuchBet()
{
	int betMoney;
	printf("���� �ݾ��� �����ϼ��� : ");
	cin >> betMoney;

	if (_playerMoney < betMoney)
	{
		printf("�������� �ʰ��� �ݾ��Դϴ�. �ٽ� �����ϼ���\n");
		betMoney = HowMuchBet();
	}
	else if (betMoney < 0)
	{
		printf("0�� �̸��� ������ �� �����ϴ�. �ٽ� �����ϼ���\n");
		betMoney = HowMuchBet();
	}

	return betMoney;
}

void SeodDa::PrintRusult(Card* myCard, Card* comCard)
{
	printf("�� ��\n");
	for (int i = 0; i < 2; i++)
	{
		myCard[i].Print();
	}
	cout << endl;

	printf("��ǻ�� ��\n");
	for (int i = 0; i < 2; i++)
	{
		comCard[i].Print();
	}
	cout << endl;

	if ( // �÷��̾ 38 ����
		(((myCard[0].index + 1) == 3) && ((myCard[1].index + 1) == 8)) ||
		(((myCard[0].index + 1) == 8) && ((myCard[1].index + 1) == 3))
		)
	{
		printf("�÷��̾� �¸�!!\n");
		_playerMoney += _betMoney * 2;
		return;
	}
	else if ( // �÷��̾ 18���� Ȥ�� 13����
		(((myCard[0].index + 1) == 1) && ((myCard[1].index + 1) == 8)) ||
		(((myCard[0].index + 1) == 1) && ((myCard[1].index + 1) == 3)) ||
		(((myCard[0].index + 1) == 8) && ((myCard[1].index + 1) == 1)) ||
		(((myCard[0].index + 1) == 3) && ((myCard[1].index + 1) == 1))
		)
	{
		if (
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 8)) ||
			(((comCard[0].index + 1) == 8) && ((comCard[1].index + 1) == 3)) ||
			// ��ǻ�Ͱ� ������
			(((comCard[0].index + 1) == 4) && ((comCard[1].index + 1) == 7)) ||
			(((comCard[0].index + 1) == 7) && ((comCard[1].index + 1) == 4))
			)
		{
			printf("�÷��̾� �й�...\n");
			return;
		}
		else
		{
			printf("�÷��̾��� �¸�!!");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // �÷��̾� �嶯
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
			printf("�÷��̾� �й�...\n");
			return;
		}
		else
		{
			printf("�÷��̾� �¸�!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if (((myCard[0].index + 1) % 10) == ((myCard[1].index + 1) % 10)) // �÷��̾� n��
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
			// ������ ������
			(((comCard[0].index + 1) == 3) && ((comCard[1].index + 1) == 7)) ||
			(((comCard[0].index + 1) == 7) && ((comCard[1].index + 1) == 3)) ||
			// ��ǻ�͵� n���ε� ��ǻ���� n���� �÷��̾��� n������ ū ���
			(((comCard[0].index % 10) == (comCard[1].index % 10)) &&
				((myCard[1].index % 10) < (comCard[1].index % 10)))
			)
		{
			printf("�÷��̾� �й�...\n");
			return;
		}
		else
		{
			printf("�÷��̾� �¸�!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // �÷��̾� �˸�
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
			printf("�÷��̾� �й�...");
			return;
		}
		else
		{
			printf("�÷��̾� �¸�!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // �÷��̾� ����
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
			printf("�÷��̾� �й�...");
			return;
		}
		else
		{
			printf("�÷��̾� �¸�!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // �÷��̾� ����
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
			printf("�÷��̾� �й�...");
			return;
		}
		else
		{
			printf("�÷��̾� �¸�!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // �÷��̾� ���
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
			printf("�÷��̾� �й�...");
			return;
		}
		else
		{
			printf("�÷��̾� �¸�!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // �÷��̾� ���
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
			printf("�÷��̾� �й�...");
			return;
		}
		else
		{
			printf("�÷��̾� �¸�!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // �÷��̾� ����
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
			printf("�÷��̾� �й�...");
			return;
		}
		else
		{
			printf("�÷��̾� �¸�!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // �÷��̾� ����(9��)
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
			printf("�÷��̾� �й�...");
			return;
		}
		else
		{
			printf("�÷��̾� �¸�!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}
	else if ( // ���� �������� ���
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
			printf("�÷��̾� �¸�!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
		else
		{
			printf("�÷��̾� �й�...");
			return;
		}
	}
	else if ( // ���� ������ ���
		(((myCard[0].index + 1) == 3) && ((myCard[1].index + 1) == 7)) ||
		(((myCard[0].index + 1) == 7) && ((myCard[1].index + 1) == 3))
		)
	{
		if ((comCard[0].index % 10) == (comCard[1].index % 10))
		{
			printf("�÷��̾� �¸�!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
		else
		{
			printf("�÷��̾� �й�...");
			return;
		}
	}
	else if ( // �÷��̾� 0 ~ 8��
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
			// ���� ����(0��)�� ���
			(((myCard[0].index + 1) + (myCard[1].index + 1)) % 10 == 0) ||
			// ����� ���� �� ū ���
			(((myCard[0].index + 1) + (myCard[1].index + 1)) % 10) <
			(((comCard[0].index + 1) + (comCard[1].index + 1)) % 10)

			)
		{
			printf("�÷��̾� �й�...");
			return;
		}
		else if ( // ��ǻ�Ϳ� ���� ���� ���
			(((myCard[0].index + 1) + (myCard[1].index + 1)) % 10) ==
			(((comCard[0].index + 1) + (comCard[1].index + 1)) % 10)
			)
		{
			printf("�����ϴ�. ���� �ٽ� ����������.\n");
			_playerMoney += _betMoney;
			return;
		}
		else
		{
			printf("�÷��̾� �¸�!\n");
			_playerMoney += _betMoney * 2;
			return;
		}
	}	
}
