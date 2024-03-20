//�ƹ��� main���� �ٸ� ������ include�ص�
//���ο� cpp���Ͽ� ���� �ʱ�ȭ ���°� �ȴ�.
#include "Card.h"
#include <iostream>


void Card::Print()
{
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
	//this�� �ڱ��ڽ��� ����Ű�� ������
	int temp = this->Index;
	this->Index = another.Index;
	another.Index = temp;
}