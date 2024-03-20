//include �����ϴ� ����
#include <iostream>

//namespace �����ϴ� ����
using namespace std;

//enum �����ϴ� ����
enum eHandName
{
	HAND_LEFT,
	HAND_RIGHT,

	HAND_END
};
enum eRockScissorPaper
{
	RSP_ROCK,
	RSP_SCISSOR,
	RSP_PAPER,

	RSP_END
};

//�Լ� ���漱�� �ϴ� ����
//�̷� �Լ��� �־�.
void ChooseMyHand();
void ChooseComHand();
void PrintHands();
void ChooseFinalMyHand();
void ChooseFinalComHand();
void PrintResult();
void PrintHand(int hand);

//���� ���� ���� 
// 0�� 1 �ܿ��� ��� define �̳� ����� �������ִ°� �����ϴ�.
int _myHand[HAND_END] = {};
int _comHand[HAND_END] = {};
int _myFinalHand = 0;
int _comFinalHand = 0;

void main()
{
	//���������� �ϳ�����

	// �Լ� �޳��� ��� ����ϸ鼭 ����帱�ſ���

	// ���������� �ϳ����� �����ڵ�
	// 1. ���� ���� �ΰ��� ���Ѵ�.
	//		ChooseMyHand()
	// 2. ���(��ǻ��)�� ���� �ΰ��� ���Ѵ�.
	//		ChooseComHand()
	//    - �̶� ��밡 ������ rand() % 3;
	// 3. ���� ���Ͱ� ��밡 ������ �����ش�.
	//		PrintHands()
	// 4. ���� ���������� ������ ����.
	//		ChooseFinalMyHand()
	// 5. ��밡 ���������� ������ ����.
	//		ChooseFinalComHand()
	// 6. ���к񱳸� �Ѵ�.
	//		PrintResult()


	// �����ڵ� ���ܴ����� �Լ��� ¥�°� ����.
	//   - ����������

	srand(time(NULL));
	::ChooseMyHand();
	::ChooseComHand();
	::PrintHands();
	::ChooseFinalMyHand();
	::ChooseFinalComHand();
	::PrintResult();

	//�Լ� ���漱��
	// main�Լ����� �Լ������� �������ָ�, main�Ʒ��� �Լ��� �����ص� ������ ����.

}

void ChooseMyHand()
{
	// ���� �ΰ��� �����ش�.
	printf("����ڰ� �޼տ� �� ���� ����ּ��� ����(0), ����(1), ��(2) : ");
	cin >> _myHand[HAND_LEFT];
	printf("����ڰ� �����տ� �� ���� ����ּ��� ����(0), ����(1), ��(2) : ");
	cin >> _myHand[HAND_RIGHT];
}

void ChooseComHand()
{
	//_comHand[HAND_LEFT]
	//_comHand[HAND_RIGHT] ���⿡ ������ ���� �־�����մϴ�.

	//�迭�� �����ִ� �̻�
	//�ݺ����̶� ���̽��ִ°� ���ƿ�.

	//comHand �迭ũ�⸸ŭ �ݺ��Ѵ�
	for (int i = 0; i < HAND_END; i++)
	{
		_comHand[i] = rand() % RSP_END;	//���������� �����̱�
	}
}

void PrintHands()
{
	// �� �հ� ������ ���� �����ش�
	printf("���� ���� �� : ");
	for (int i = 0; i < HAND_END; i++)
	{
		::PrintHand(_myHand[i]);
	}
	printf("\n");

	printf("��밡 ���� �� : ");
	for (int i = 0; i < HAND_END; i++)
	{
		::PrintHand(_comHand[i]);
	}
	printf("\n");


	// �÷��̾� 2��ŭ �ݺ��Ѵ�.
	// i = 0 : �÷��̾� ���
	// i = 1 : ���� ���
	//for (int i = 0; i < 2; i++)
	//{
	//	if (i == 0)
	//	{
	//		printf("���� ���� �� : ");
	//	}
	//	else if (i == 1)
	//	{
	//		printf("��밡 ���� �� : ");
	//	}

	//	//���� ������ŭ �ݺ��Ѵ�.
	//	for (int j = 0; j < HAND_END; j++)
	//	{
	//		int hand = 0;

	//		//i => �÷��̾� �ѹ�
	//		//i = 0 : �÷��̾�
	//		//i = 1 : ����
	//		if (i == 0)
	//		{
	//			hand = _myHand[j];
	//		}
	//		else if (i == 1)
	//		{
	//			hand = _comHand[j];
	//		}

	//		switch (hand)
	//		{
	//		case RSP_ROCK:
	//			printf("����\t");
	//			break;
	//		case RSP_SCISSOR:
	//			printf("����\t");
	//			break;
	//		case RSP_PAPER:
	//			printf("��\t");
	//			break;
	//		default:
	//			printf("UnKnown\t");
	//			break;
	//		}
	//	}
	//	printf("\n");
	//}


}

void ChooseFinalMyHand()
{
	//printf("ChooseFinalMyHand\n");
	printf("���� ���������� �� ���� �������ּ��� (0: �޼�, 1: ������) : ");
	int choose;
	cin >> choose;

	//_myFinalHand�� ���� �־��ش�.
	//_myFinalHand = _myHand[choose];

	if (choose == 0)
	{
		_myFinalHand = _myHand[HAND_LEFT];
	}
	else if (choose == 1)
	{
		_myFinalHand = _myHand[HAND_RIGHT];
	}


	//�޼��� ����
	//_myFinalHand = _myHand[0];
	//�������� ����
	//_myFinalHand = _myHand[1];
}

void ChooseFinalComHand()
{
	//printf("ChooseFinalComHand\n");

	//_comFinalHand ������ �������� �־��ش�.
	//_comHand[0], _comHand[1] �߿� �������� �ϳ� �־��ش�.
	int random = rand() % HAND_END;
	_comFinalHand = _comHand[random];
}

void PrintResult()
{
	printf("PrintResult\n");
	//���� ���Ͱ�
	//��밡 ������ �����ش�
	printf("���� ���������� ������ �� : ");
	::PrintHand(_myFinalHand);
	printf("\n");

	printf("��밡 ���������� ������ �� : ");
	::PrintHand(_comFinalHand);
	printf("\n");


	//���и� �˷��ش�.

	if (_myFinalHand == _comFinalHand)
	{
		printf("�����ϴ�.\n");
	}
	else if (
		(_myFinalHand == RSP_ROCK && _comFinalHand == RSP_SCISSOR) || 
		(_myFinalHand == RSP_SCISSOR && _comFinalHand == RSP_PAPER) || 
		(_myFinalHand == RSP_PAPER && _comFinalHand == RSP_ROCK))
	{
		printf("�̰���ϴ�.\n");
	}
	else
	{
		printf("�����ϴ�.\n");
	}
}


void PrintHand(int hand)
{
	switch (hand)
	{
	case RSP_ROCK:
		printf("��������\t");
		break;
	case RSP_SCISSOR:
		printf("����\t");
		break;
	case RSP_PAPER:
		printf("��\t");
		break;
	default:
		printf("UnKnown\t");
		break;
	}
}