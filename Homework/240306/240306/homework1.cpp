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

	// ���� 

	// 1. ī�� ����
	GenerateCard(_card);
	// 2. ī�� ����
	// �����Ҷ����� ī�带 ���°� �ƴ϶�
	// ���ӽ����Ҷ� �� ���� ���´�.
	SuffleCard(_card);

	// �ݺ�
	// 10. 52���� �پ��ų�, �÷��̾ 0���� �Ǹ� ���� ����
	// 11. ������ ����
	// 12. 52���� �� �� �� �ִ�.
	while (IsContinue(_player, _cardNum))
	{
		system("cls");

		// 3. ��Ȳ��(ī�� 5���� ���� �ݾ�) ���
		// ��A ��K ��3 ��2 XX
		// �÷��̾� ���� �ݾ� : 1000
		PrintCardState(_card, _player, _cardNum);

		// 4. ���� ���� ����
		if (IsBet())
		{
			// 5. ���ý� - ����, �ο�, ���� �߿��� ����
			// 6. ���� ���� �� XX�� ���� 7 �ʰ��̸� ����Ʈ ȹ�� (������ �ݾ��� 2��)
			// 7. �ο� ���� �� XX�� ���� 7 �̸��̸� ����Ʈ ȹ�� (������ �ݾ��� 2��)
			// 8. ���� ���� �� XX�� ���� 7�̸� ����Ʈ ȹ�� (������ �ݾ��� 11��)
			PrintBetResult(Betting(_player), _player, _card[_cardNum]);
		}
		else
		{
			printf("�������� �ʾҽ��ϴ�. ������ �����մϴ�\n");
		}
		
		// 9. �� ���� �ϸ� �������� ���徿 �и���.
		_cardNum++;

		system("pause");
	}
	printf("���� ����\n");
}

void Card::Print()
{
	switch (this->Index / 13)
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

	printf("�÷��̾� ���� �ݾ� : %d\n", player.Money);
}

bool IsBet() 
{
	int bet = 0;
	printf("���� �Ͻðڽ��ϱ�?? ( 0 : YES , 1 : NO) : ");
	scanf_s("%d", &bet);

	switch (bet)
	{
	case 0:
		return true;
	case 1:
		return false;
	default:
		printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���!\n");
		return IsBet();
	}
}

int Betting(Player& player)
{
	int bettingMoney = 0;
	printf("������ �ݾ� : ");
	scanf_s("%d", &bettingMoney);

	while (_player.Money < bettingMoney)
	{
		printf("���� �ݾ��� �������� �ʰ��Ͽ����ϴ�. ������ �ݾ��� �ٽ� �����ϼ���\n");
		printf("������ �ݾ� : ");
		scanf_s("%d", &bettingMoney);
	}

	_player.Money -= bettingMoney;

	printf("���� �ο� ������ �����ϼ��� ( 0 : ����, 1 : �ο�, 7 : ���� ) : ");
	scanf_s("%d", &_player.HighLowSevenChoice);

	while (
		(_player.HighLowSevenChoice != 0) &&
		(_player.HighLowSevenChoice != 1) &&
		(_player.HighLowSevenChoice != 7))
	{
		printf("�߸��� �����Դϴ�. ���̷ο켼���� �ٽ� �����ϼ���.\n");
		printf("���� �ο� ������ �����ϼ��� ( 0 : ����, 1 : �ο�, 7 : ���� ) : ");
		scanf_s("%d", &_player.HighLowSevenChoice);
	}

	return bettingMoney;
}

void PrintBetResult(int betMoney, Player& player, Card card)
{
	printf("ī�� ���� : ");
	card.Print();

	printf("\n���� ���� : ");
	switch (player.HighLowSevenChoice)
	{
	case 0:
		printf("����\n");
		if ((card.Index % 13 + 1) <= 7)
		{
			printf("YOU LOSE...\n");
		}
		else if (7 < (card.Index % 13 + 1))
		{
			printf("���̸� ���߼̽��ϴ�!!\n");
			player.Money += betMoney * 2;
		}
		break;
	case 1:
		printf("�ο�\n");
		if ((card.Index % 13 + 1) < 7)
		{
			printf("�ο츦 ���߼̽��ϴ�!!\n");
			player.Money += betMoney * 2;
		}
		else if (7 <= (card.Index % 13 + 1))
		{
			printf("YOU LOSE...\n");
		}
		break;
	case 7:
		printf("����\n");
		if ((card.Index % 13 + 1) == 7)
		{
			printf("������ ���߼̽��ϴ�!!\n");
			player.Money += betMoney * 11;
		}
		else
		{
			printf("YOU LOSE...\n");
		}
		break;
	default:
		printf("���� �߻�");
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
