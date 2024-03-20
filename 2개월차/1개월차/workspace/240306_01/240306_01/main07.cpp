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
	// ī�����
	// ��A ~ ��K �� Ȱ���ؼ� �������� ī������� �����.

	// ī�尡 �� 52���Դϴ�.
	srand(time(NULL));

	for (int i = 0; i < 52; i++)
	{
		_card[i].Index = i;
	}

	
	for (int i = 0; i < 52; i++)
	{
		_card[i].Print();
		printf("\n");
	}

	
	// ī�� ��ġ
	// ����
	for (int i = 0; i < 100000; i++)
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

	
}

void Card::Print() 
{
	// 52��
	// Index�� ����
	//  0 ~ 12 �����̽� A ~ �����̽� K ����	(13���� ���������� 0)
	// 13 ~ 25 ���̾� A  ~  ���̾� K ����		(13���� ���������� 1)
	// 26 ~ 38 ��Ʈ A   ~   ��Ʈ K ����		(13���� ���������� 2)
	// 39 ~ 51 Ŭ�ι� A  ~  Ŭ�ι� K ����		(13���� ���������� 3)

	// ���� ���
	switch (Index / 13)
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

	// ����( A ~ K)
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