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
	// ��A ~ ��K �� Ȱ���ؼ� �������� ī������� ����ſ���.

	// ī�尡 �� 52���Դϴ�.


	srand(time(NULL));

	for (int i = 0; i < 52; i++)
	{
		_card[i].Index = i;
	}
	// 52��
	// Index�� ����
	// 0 ~ 12 �����̽� A ~ �����̽� K ���� 
	// 13 ~ 25 ���̾� A ~ ���̾� K ����
	// 26 ~ 38 ��Ʈ A ~ ��Ʈ K ����
	// 39 ~ 51 Ŭ�ι� A ~ Ŭ�ι� K ����
	//for (int i = 0; i < 52; i++)
	//{
	//	_card[i].Print();
	//	printf("\n");
	//}


	//ī�� ��ġ
	//����
	for (int i = 0; i < 10000; i++)
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


	// ���� 
	// ���� ī�带 5���� �̴µ�
	// 4���� ���� ����
	// 1���� XX�� ǥ��

	// ������
	// ��A ��K ��3 ��2 XX
	// �÷��̾� ���� �ݾ� : 1000
	
	// 1. ���� ���� ���� (�ݾ�����)
	// 2. ���ý� - ����, �ο�, ���� �߿��� ����
	// 3. ���̸� ����
	// 4. XX�� ���� 7�̻��̸� ����Ʈȹ�� (�ǵ��� 2��) (700�� �ɾ����� 1700)
	// 5. �ο츦 ����
	// 6. XX�� ���� 7���ϸ� ����Ʈ ȹ�� (�ǵ��� 2��) (700�� �ɾ����� 1700)
	// 7. ������ ����
	// 8. XX�� ���� 7�̸� ����Ʈ ȹ�� (�ǵ��� 10��) (700�� �ɾ����� 7700)
	// 9. ������ �ϸ� �������� ���徿 �и�
	// 10. ��K ��3 ��2 ��7 XX
	// 11. ������ ����.
	// 12. 52���� �پ����ְ���??
	// 13. 52���� �پ��ų�, �÷��̾ 0���� �Ǹ� ��������

	// �����Ҷ����� ī�带 ���°��̾ƴ϶�
	// ���ӽ����Ҷ� �ѹ��� ����.!!
}

void Card::Print()
{
	// Index�� ����
	// 0 ~ 12 �����̽� A ~ �����̽� K ����  (13���� ���������� 0)
	// 13 ~ 25 ���̾� A ~ ���̾� K ����	  (13���� ���������� 1)
	// 26 ~ 38 ��Ʈ A ~ ��Ʈ K ����        (13���� ���������� 2)
	// 39 ~ 51 Ŭ�ι� A ~ Ŭ�ι� K ����     (13���� ���������� 3)

	//���� ���
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
	}

	//���� (A ~ k)
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